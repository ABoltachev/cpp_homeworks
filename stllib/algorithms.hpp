#pragma once

template<typename Iter>
void sort(Iter begin, Iter end) {
    size_t const size = end - begin;
    for (size_t i = 0; i + 1 < size; ++i) {
        for (size_t j = 0; j + 1 < size - i; ++j) {
            if (begin[j + 1] < begin[j]) {
                swap(begin[j], begin[j + 1]);
            }
        }
    }
}

template<typename Iter>
Iter max(Iter begin, Iter end) {
    auto max = *begin;
    Iter result = begin;
    for (auto i = begin + 1; i < end; ++i) {
        if (max < *i) {
            max = *i;
            result = i;
        }
    }
    return result;
}

template<typename Iter>
Iter min(Iter begin, Iter end) {
    auto min = *begin;
    Iter result = begin;
    for (auto i = begin + 1; i < end; ++i) {
        if (*i < min) {
            min = *i;
            result = i;
        }
    }
    return result;
}

template<typename Iter, typename T>
Iter find(Iter begin, Iter end, T const& value) {
    for (auto i = begin; i < end; ++i) {
        if (*i == value) {
            return i;
        }
    }
        throw std::runtime_error("Element not found");
    return end;
}