#include "tools.h"

template <typename T>
inline void destroy_n_elements(T *p, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i].~T();
    }
}

template<typename T>
class my_vector
{
    private:
        T *ptr_ = nullptr;
        size_t size_ = 0;
        size_t capacity_ = 0;
    public:
        void reserve(size_t c)
        {
            if (capacity_ >= c)
            {
                return;
            }

            T *new_ptr = (T *)malloc(c * sizeof(T));

            for (size_t i = 0; i < size_; ++i)
            {
                if constexpr (std::is_nothrow_move_constructible_v<T>)
                {
                    ::new (&new_ptr[i]) T(std::move(ptr_[i]));
                }
                else
                {
                    try
                    {
                        ::new (&new_ptr[i]) T(ptr_[i]);
                    }
                    catch (...)
                    {
                        destroy_n_elements(new_ptr, i);
                        free(new_ptr);
                        throw;
                    }
                }
            }
            destroy_n_elements(ptr_, size_);
            free(ptr_);
            ptr_ = new_ptr;
            capacity_ = c;
        }

        ~my_vector()
        {
            destroy_n_elements(ptr_, size_);
            free(ptr_);
        }
};

int main()
{
    {
        my_vector<int> mv;
    }
    {
        std::vector<int> v = {3, 1, 4};
        auto iter = v.begin();
        v.reserve(6);

        v = std::vector{3, 1, 40};
        std::copy(
            v.begin(),
            v.end(),
            std::back_inserter(v)
        );

        std::cerr << *iter << std::endl;

        auto end = v.end();

        /*
        * for (auto it = v.begin(); it != end; ++it)
        * {
        *     if (*it == 4)
        *     {
        *         v.erase(it);        // ERROR
        *     }
        *     else
        *     {
        *         ++it;
        *     }
        * }
        */
        v.erase(
            std::remove_if(v.begin(), v.end(),
                [] (auto&& elt) {
                    return elt == 4;
                }
            ),
            v.end()
        );
    }
}
