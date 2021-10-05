#include "profile.h"
#include "test_runner.h"

template<typename T>
std::vector<T> generate_data(size_t size,
                                  T min = std::numeric_limits<T>::min(),
                                  T max =std::numeric_limits<T>::max());
template<typename S>
void Swap(S &first, S &second) {
    S temp = first;
    first = second;
    second = temp;
}

template<typename P>
P partition(vector<P> &array, P &start, P &end) {
    int iteration = start + 1; //next element after start
    int pivot = array[start];

    for (P it = iteration; it <= end; ++it){
        if (array[it] < pivot) {
            Swap(array[iteration], array[it]);
            ++iteration;
        }
    }

    Swap(array[start], array[iteration - 1]);

    return iteration - 1;
}
template<typename P>
P rand_partition(vector<P> &array, P &start, P &end) {
    //chooses position of pivot randomly by using rand() function .
    int random = start + rand( ) % (end - start + 1) ;

    swap (array[random] , array[start]);        //swap pivot with 1st element.
    return partition(array, start ,end);       //call the above partition function
}

template<typename T>
void quick_sort_tval(vector<T> &array, T start, T end, bool FLAG) {
    if (FLAG){
        if (start < end) {
            T pivot = rand_partition(array, start, end);
            quick_sort_tval(array, start, (pivot - 1), FLAG);
            quick_sort_tval(array, (pivot + 1), end, FLAG);
        }
    } else {
        if (start < end) {
            T pivot = partition(array, start, end);
            quick_sort_tval(array, start, (pivot - 1), FLAG);
            quick_sort_tval(array, (pivot + 1), end, FLAG);
        }
    }

}

template<typename T>
void quicksort(vector<T> &array, bool FLAG) {
    int first = 0,
        last  = array.size() - 1;
    quick_sort_tval(array, first, last, FLAG);
}

int main() {
    {
        std::vector<int> RandomVector = generate_data<int>(100'000'000, -100'000, 100'000);
        //cout << RandomVector << endl;
        std::vector<int> RandomSortedVector(begin(RandomVector), end(RandomVector));
        sort(begin(RandomSortedVector), end(RandomSortedVector));

        {
            LOG_DURATION("Quicksort (random partial) of 100'000'000");
            quicksort(RandomVector, true);
        }

        ASSERT_EQUAL(RandomVector, RandomSortedVector);
    }
    {
        std::vector<int> RandomVector = generate_data<int>(100'000'000, -100'000, 100'000);
        //cout << RandomVector << endl;
        std::vector<int> RandomSortedVector(begin(RandomVector), end(RandomVector));
        sort(begin(RandomSortedVector), end(RandomSortedVector));   // Quicksort (random partial) of 100'000: 15722 ms

        {
            LOG_DURATION("Quicksort (first element partial) of 100'000'000");
            quicksort(RandomVector, false);                         // Quicksort (first element partial) of 100'000: 14790 ms
        }

        ASSERT_EQUAL(RandomVector, RandomSortedVector);
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
