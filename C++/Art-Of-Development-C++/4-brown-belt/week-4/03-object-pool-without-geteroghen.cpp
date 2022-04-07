#include "tools.h"

template <class T>
class ObjectPool {
    public:
        T* Allocate();
        T* TryAllocate();

        void Deallocate(T* object);

        size_t GetSizeAllocated()
        {
            return allocated.size();
        }

        size_t GetSizeReleased()
        {
            return free.size();
        }

    private:
        // Убрали свой компаратор
        std::queue<std::unique_ptr<T>> free;
        std::unordered_set<std::unique_ptr<T>> allocated;  // Изменили на unordered_set
};

template <typename T>
T* ObjectPool<T>::Allocate()
{
    if (free.empty())
    {
      free.push(std::make_unique<T>());
    }
    auto ptr = std::move(free.front());
    free.pop();
    T* ret = ptr.get();
    allocated.insert(move(ptr));
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

// Убрали функции сравнения, они больше не нужны

template <typename T>
void ObjectPool<T>::Deallocate(T* object)
{
    // Добавили создание временного unique_ptr
    std::unique_ptr<T> ptr(object);
    auto it = allocated.find(ptr);
    ptr.release();
    if (it == allocated.end())
    {
      throw std::invalid_argument("");
    }
    free.push(move(allocated.extract(it).value()));
}

void TestObjectPool()
{
    ObjectPool<std::string> pool;

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
    std::string* p4 = new std::string("fourth");
    try
    {
        pool.Deallocate(p4);
        ASSERT_EQUAL(0, 1);
    }
    catch (std::exception& ex)
    {
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
        std::cout << "Allocating object #" << i << std::endl;
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
