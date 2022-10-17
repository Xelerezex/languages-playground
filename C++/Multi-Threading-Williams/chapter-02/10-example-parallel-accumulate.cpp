#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

// Структура, которая будет считать сумму чисел на каком-то отрезке
template<typename Iterator, typename T>
struct accumulate_block
{
    void operator() (Iterator first, Iterator last, T& result)
    {
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate (Iterator first, Iterator last, T init)
{
    // Проверка размера контейнера. Нужно, что б было больше
    // нуля
    const unsigned long length = std::distance(first, last);
    if (!length)
    {
        return init;
    }

    // Высчитываем максимальное количество потоков
    // нужное для входящего объема данных
    const unsigned long min_per_thread = 25;
    const unsigned long max_threads = (length + min_per_thread - 1) / min_per_thread;

    // Количество потоков, которое может быть
    // максимально на машине
    const unsigned long hardware_threads = std::thread::hardware_concurrency();

    // Выбираем минимально пригодное количество потоков
    // Либо апаратное количество, либо высчитаное
    const unsigned long num_threads = std::min (
        hardware_threads != 0 ? hardware_threads : 2,
        max_threads
    );

    // Размер блока обработки данных
    const unsigned long block_size = length / num_threads;

    // Результаты суммы по блокам
    std::vector<T>           results(num_threads);
    // Контейнер с потоками
    std::vector<std::thread> threads(num_threads - 1);

    Iterator block_start = first;
    for (unsigned long iter = 0; iter < (num_threads - 1); ++iter)
    {
        // Сдвигаем block_end ы конец текущего блока
        Iterator block_end = block_start;
        std::advance(block_end, block_size);

        threads[iter] = std::thread(
            accumulate_block<Iterator, T>(),
            block_start,
            block_end,
            std::ref(results[iter])
        );

        block_start = block_end;
    }

    // Обработкой последнего блока займется основной поток
    accumulate_block<Iterator,T>()(block_start, last, results[num_threads - 1]);

    // Не забываем вызвать join для всех потоков
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    // Возвращаем сумму сумм всех блоков
    return std::accumulate(results.begin(), results.end(), init);
}

int main()
{
    std::vector<int> container;

    for (int iter = 0; iter < 10'000'000; ++iter)
    {
        container.push_back(69);
    }

    unsigned long int summ = parallel_accumulate(container.begin(), container.end(), 5);

    std::cout << summ << std::endl;
}
