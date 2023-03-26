#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
namespace algo{
template<typename iterator> iterator max_element(iterator begin, iterator end) {
    if (begin == end) return begin;
    iterator maximal = begin;
    while (++begin != end) if (*maximal < *begin) maximal = begin;
    return maximal;
}
template<typename iterator, typename Type>  inline iterator
find(iterator begin, iterator end, const Type& key)
{
    while (begin != end && (*begin != key)) ++begin;
    if(begin == end) throw std::runtime_error("\n!Элемент не был найден.!\n");
    else return begin;
}

template<typename iterator> inline void sort(iterator begin, iterator end) {
    for (iterator i = begin; i != end; ++i)
        for (iterator j = begin; j < i; ++j)
            if (*i < *j)
                std::iter_swap(i, j);
}}
#endif
