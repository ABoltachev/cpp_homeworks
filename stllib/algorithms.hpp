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
#include <math.h>

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

    template<int stop, int start = 0, int step = 1>
    class range
    {
    public:
        class iterator : public std::iterator<std::random_access_iterator_tag,int>
        {
        private:
            int current;
        public:
            iterator() = delete;
            iterator(int current);
            iterator& operator++();
            iterator operator++(int);
            bool operator==(const iterator& other);
            bool operator!=(const iterator& other);
            int operator*() const;
        };

        int operator[](int i) const;
        int size() const;

        iterator begin() const;
        iterator end() const;
    };

    template<int stop,int start,int step>
    range<stop,start,step>::iterator::iterator(int current) : current(current) {}

    template<int stop,int start,int step>
    typename range<stop,start,step>::iterator& range<stop,start,step>::iterator::operator++()
    {
        if(std::abs(this->current-start)+std::abs(this->current-stop) > std::abs(start-stop))
            throw std::runtime_error("Iterator out of range");
        this->current = step > 0 ? std::min(this->current+step,stop) : std::max(this->current+step,stop);
        return *this;
    }

    template<int stop,int start,int step>
    typename range<stop,start,step>::iterator range<stop,start,step>::iterator::operator++(int)
    {
        auto temp = *this;
        ++(*this);
        return temp;
    }

    template<int stop,int start,int step>
    int range<stop,start,step>::iterator::operator*() const { return current; }

    template<int stop,int start,int step>
    bool range<stop,start,step>::iterator::operator==(const range<stop,start,step>::iterator& other) { return this->current == other.current; }

    template<int stop,int start,int step>
    bool range<stop,start,step>::iterator::operator!=(const range<stop,start,step>::iterator& other) { return this->current != other.current; }

    template<int stop,int start,int step>
    int range<stop,start,step>::size() const { return std::ceil((stop-start)/double(step)); }

    template<int stop,int start,int step>
    int range<stop,start,step>::operator[](int i) const { if(i >= this->size()) throw std::invalid_argument("Index out of range"); return start + i*step; }

    template<int stop,int start,int step>
    typename range<stop,start,step>::iterator range<stop,start,step>::begin() const { return iterator(start); }

    template<int stop,int start,int step>
    typename range<stop,start,step>::iterator range<stop,start,step>::end() const { return iterator(stop); }
}