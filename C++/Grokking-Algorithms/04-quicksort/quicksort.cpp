#include "profile.h"
#include "test_runner.h"
//-----------------------------------------------------------------------------------//
template<typename T>
std::vector<T> generate_data(size_t size,
                                  T min = std::numeric_limits<T>::min(),
                                  T max =std::numeric_limits<T>::max());
template<typename S>
void Swap(S &first, S &second);

template<typename P>
int partition(vector<P> &array, int &start, int &end);

template<typename P>
P rand_partition(vector<P> &array, P &start, P &end);

template<typename T>
void quicksort_rand(vector<T> &array, int start, int end);

template<typename T>
void quicksort(vector<T> &array, int start, int end);

template <typename T>
void SortContainer(vector<T>& pointers, bool FLAG);
//-----------------------------------------------------------------------------------//

template<typename S>
void Swap(S &first, S &second) {
    S temp = first;
    first = second;
    second = temp;
}


template<typename P>
int partition(vector<P> &array, int &start, int &end) {                // [4, 1, 5, 2, 7, 9, 8]
    int iteration = start + 1; //next element after start              //  ^  ^
    P pivot = array[start];                                            //  P

    for (int it = iteration; it <= end; ++it){                         // 1 [1, 5, 2, 7, 2, 8]
        if (array[it] < pivot) {                                       //    ^it & iteration
            Swap(array[iteration], array[it]);                         // 2 [1, 5, 2, 7, 2, 8]
            ++iteration;                                               //    ^  ^it
        }                                                              // 3 [5, 1, 2, 7, 2, 8]
    }                                                                  //       ^it & iteration
                                                                       // 4 [5, 1, 2, 7, 2, 8]
    Swap(array[start], array[iteration - 1]);                          //       ^  ^it
                                                                       // 5 [5, 1, 2, 7, 2, 8]
    return iteration - 1;                                              //       ^     ^it
                                                                       // 4 [5, 7, 2, 1, 2, 8]
}                                                                      //       ^     ^it
                                                                       // 6 [5, 7, 2, 1, 2, 8]
                                                                       //          ^     ^it
                                                                       // 7 [5, 7, 2, 1, 2, 8]
template<typename T>                                                   //          ^        ^it
void quicksort(vector<T> &array, int start, int end) {                 // 8 [5, 7, 8, 1, 2, 2]
    if (start < end) {                                                 // 9 [7, 5, 8, 1, 2, 2]  Swap(array[start], array[iteration - 1]);
        int pivot = partition(array, start, end);
        quicksort(array, start, (pivot - 1));
        quicksort(array, (pivot + 1), end);
    }
}


int main() {
    {
        std::vector<int> RandomVector = generate_data<int>(100'000'000, -100'000, 100'000);
        //cout << RandomVector << endl;
        std::vector<int> RandomSortedVector(begin(RandomVector), end(RandomVector));
        sort(begin(RandomSortedVector), end(RandomSortedVector));

        {
            LOG_DURATION("Quicksort (random partial) of 100'000'000");
            SortContainer(RandomVector, true);
        }

        ASSERT_EQUAL(RandomVector, RandomSortedVector);
    }
    {
        std::vector<int> RandomVector = generate_data<int>(100'000'000, -100'000, 100'000);
        //cout << RandomVector << endl;
        std::vector<int> RandomSortedVector(begin(RandomVector), end(RandomVector));
        sort(begin(RandomSortedVector), end(RandomSortedVector));       // Quicksort (random partial) of 100'000: 15722 ms

        {
            LOG_DURATION("Quicksort (first element partial) of 100'000'000");
            SortContainer(RandomVector, false);                         // Quicksort (first element partial) of 100'000: 14790 ms
        }

        ASSERT_EQUAL(RandomVector, RandomSortedVector);
    }
}
//-----------------------------------------------------------------------------------//

template<typename P>
P rand_partition(vector<P> &array, P &start, P &end) {
    //chooses position of pivot randomly by using rand() function .
    int random = start + rand( ) % (end - start + 1) ;

    Swap(array[random] , array[start]);        //swap pivot with 1st element.
    return partition(array, start ,end);       //call the above partition function
}

template<typename T>
void quicksort_rand(vector<T> &array, int start, int end) {
    if (start < end) {
        int pivot = rand_partition(array, start, end);
        quicksort_rand(array, start, (pivot - 1));
        quicksort_rand(array, (pivot + 1), end);
    }
}

template <typename T>
void SortContainer(vector<T>& container, bool FLAG) {
    if (!FLAG){
        int first = 0,
            last  = container.size() - 1;
        quicksort(container, first, last);
    } else {
        int first = 0,
            last  = container.size() - 1;
        quicksort_rand(container, first, last);
    }
}

template<typename T>
std::vector<T> generate_data(size_t size, T min, T max) {
    std::uniform_int_distribution<T> distribution(min, max);
    std::default_random_engine generator;

    std::vector<T> data(size);
    std::generate(data.begin(), data.end(), [&]() { return distribution(generator); });
    return data;
}
