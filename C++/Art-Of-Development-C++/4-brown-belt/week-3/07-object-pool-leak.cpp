#include "test_runner.h"

#include <algorithm>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool
{
    public:
        T* Allocate();
        T* TryAllocate();

        void Deallocate(T* object);

        ~ObjectPool();

        size_t GetSizeAllocated()
        {
            return allocated.size();
        }
        size_t GetSizeReleased()
        {
            return free.size();
        }


    private:
        set<T*> allocated;
        queue<T*> free;
};

template <typename T>
T* ObjectPool<T>::Allocate()
{
    if (free.empty())
    {
        free.push(new T);
    }
    auto ret = free.front();
    free.pop();
    try
    {
        allocated.insert(ret);
    }
    catch (const bad_alloc&)
    {
        delete ret;
        throw;
    }
    return ret;
}

template <typename T>
T* ObjectPool<T>::TryAllocate()
{
    if (free.empty())
    {
        return nullptr;
    }
    return Allocate();
}

template <typename T>
void ObjectPool<T>::Deallocate(T* object)
{
    if (allocated.find(object) == allocated.end())
    {
        throw invalid_argument("");
    }
    allocated.erase(object);
    free.push(object);
}

template <typename T>
ObjectPool<T>::~ObjectPool()
{
    for (auto x : allocated)
    {
        delete x;
    }
    while (!free.empty())
    {
        auto x = free.front();
        free.pop();
        delete x;
    }
}


void TestObjectPool()
{
    ObjectPool<string> pool;

    // --------------------------------------------------------------------------------------------//
    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();                  // alloc: 3, real: 0
    ASSERT_EQUAL(pool.GetSizeAllocated(), 3U);
    ASSERT_EQUAL(pool.GetSizeReleased(), 0U);
    // --------------------------------------------------------------------------------------------//
    *p1 = "first";
    *p2 = "second";
    *p3 = "third";                              // alloc: 3, real: 0
    // --------------------------------------------------------------------------------------------//
    pool.Deallocate(p2);                        // alloc: 2, real: 1  {first, third}  {second}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2U);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1U);
    // --------------------------------------------------------------------------------------------//
    ASSERT_EQUAL(*pool.Allocate(), "second");   // alloc: 3, real: 0  {first, third, second}  {}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 3U);
    ASSERT_EQUAL(pool.GetSizeReleased(), 0U);
    // --------------------------------------------------------------------------------------------//
    pool.Deallocate(p3);                        // alloc: 2, real: 1  {first, second}  {third}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2U);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1U);
    // --------------------------------------------------------------------------------------------//
    pool.Deallocate(p1);                        // alloc: 1, real: 2  {second}  {third, first}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 1U);
    ASSERT_EQUAL(pool.GetSizeReleased(), 2U);
    // --------------------------------------------------------------------------------------------//
    ASSERT_EQUAL(*pool.Allocate(), "third");   // alloc: 2, real: 1  {second, *third}  {first}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2U);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1U);
    // --------------------------------------------------------------------------------------------//
    ASSERT_EQUAL(*pool.Allocate(), "first");   // alloc: 3, real: 0  {second, third, *first}  {}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 3U);
    ASSERT_EQUAL(pool.GetSizeReleased(), 0U);
    // --------------------------------------------------------------------------------------------//
    pool.Deallocate(p1);                       // alloc: 2, real: 1  {second, third}  {first}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2U);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1U);
    // --------------------------------------------------------------------------------------------//
    string* p4 = new string("fourth");
    try
    {
        pool.Deallocate(p4);
        ASSERT_EQUAL(0, 1);
    } catch (exception& ex){
        ASSERT_EQUAL(1, 1);
    }
}

int global_counter = 0;

struct Counted
{
    Counted() { ++global_counter; }
    ~Counted() { --global_counter; }
};

void TestObjectPoolLeak()
{
    ObjectPool<Counted> pool;

    ASSERT_EQUAL(global_counter, 0);
    for (int i = 0; i < 1000; ++i)
    {
        cout << "Allocating object #" << i << endl;
        pool.Allocate();
    }
    ASSERT_EQUAL(global_counter, 1000);
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    RUN_TEST(tr, TestObjectPoolLeak);
    ASSERT_EQUAL(global_counter, 0);
    return 0;
}
