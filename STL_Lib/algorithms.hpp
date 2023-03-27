#ifndef COLLECTIONS_ALGORITHMS_HPP
#define COLLECTIONS_ALGORITHMS_HPP

#include <cstdio>

namespace AlgorithmsLib {
    template<class T>
    [[maybe_unused]] void sort(T& collection, size_t size)
    {
        // O (n * log(n))

        for(size_t step = size/2; step > 0; step /= 2)
        {
            for (size_t i = step; i < size; ++i)
            {
                size_t j = i;
                while  (j >= step && collection[j-step] > collection[i])
                {
                    // swap
                    auto temp = collection[j];
                    collection[j] = collection[j-step];
                    collection[j-step] = temp;

                    j -= step;
                }
            }
        }
    }

    template <class T>
    [[maybe_unused]] auto max(const T& collection, size_t size) {
        auto max_elem = collection[0];
        for (size_t i = 1; i < size; ++i)
            if (collection[i] > max_elem)
                max_elem = collection[i];
        return max_elem;
    }

    template <class T>
    [[maybe_unused]] auto max(const T& collection) { // Set max
        return collection.top();
    }
    template <class T>
    [[maybe_unused]] auto min(const T& collection) { // Set min
        return collection.min();
    }

    template <class T>
    [[maybe_unused]] auto min(const T& collection, size_t size) {
        auto min_elem = collection[0];
        for (size_t i = 1; i < size; ++i)
            if (collection[i] < min_elem)
                min_elem = collection[i];
        return min_elem;
    }

    template <class T, class Type>
    [[maybe_unused]] auto find(const T& collection, size_t size, Type element) {
        for (size_t i = 1; i < size; ++i)
            if (collection[i] == element)
                return &collection[i];

        throw std::runtime_error("Element wasn't found");
    }

    template <class T, class Type>
    [[maybe_unused]] auto find(const T& collection, Type element)  {
        return &(collection.get(element)->data);
    }
}

#endif //COLLECTIONS_ALGORITHMS_HPP
