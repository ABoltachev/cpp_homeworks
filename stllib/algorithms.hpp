/*
На вход каждого алгоритма подается контейнер, который вы реализовали
 * sort (простая сортировка, либо пузырьком, либо вставками)
 * max; min (поиск максимума и минимума соответственно)
 * find (поиск элемента, возвращает ссылку на элемент, либо бросает исключение runtime_error, если не нашло элемент)

Доп задание (доп бал):
    Реализовать функцию range (аналог функции из Python) по аналогии с функцией enumerate с семинара
    Должно быть 2 перегрузки
     * range(int stop)
     * range(int start, int stop, int step=1)
*/

#include <iterator>

namespace hw
{
    template<typename Iterator>
    void sort(Iterator begin, Iterator end)
    {
        for(auto it = begin; it != end-1; ++it)
        {
            auto min = it;
            for(auto jt = it+1; jt != end; ++jt)
            {
                if(*jt < *min)
                    min = jt;
            }
            auto temp = *it;
            *it = *min;
            *min = temp;
        }
    }

    template<typename Iterator>
    Iterator max(Iterator begin, Iterator end)
    {
        auto res = begin;
        for(auto it = begin; it != end; ++it)
            if(*it > *res)
                res = it;
        
        return res;
    }

    template<typename Iterator, typename Key>
    Iterator find(Iterator begin, Iterator end, const Key& key)
    {
        auto it = begin;
        for(; it != end and *it != key; ++it);
        return it;
    }
}