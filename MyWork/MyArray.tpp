#ifndef MY_ARRAY_CPP
#define MY_ARRAY_CPP


namespace MyStdLib 
{

    template<typename T, size_t arr_size>
    void copy_arr(MyArray<T, arr_size>& a, const MyArray<T, arr_size>& b) {
        for(int i = 0; i < arr_size; ++i) {
            a.m_arr[i] = b.m_arr[i];
        }
    }

    template<typename T, size_t arr_size>
    size_t MyArray<T, arr_size>::size() const { return this->m_size; };

    template<typename T, size_t arr_size>
    bool MyArray<T, arr_size>::empty() const { return this->m_size == 0; };
 
    template<typename T, size_t arr_size>
    MyArray<T, arr_size>::MyArray(const MyArray<T, arr_size>& arr) {
        copy_arr(*this, arr);
    }       

    template<typename T, size_t arr_size>
    MyArray<T, arr_size>::MyArray(const std::initializer_list<T>& values) {
        auto it = values.begin();
        int i;
        for(i = 0; (it != values.end()) && (i < arr_size); ++i) {
            this->m_arr[i] = *(it++);
        }

    } // Забивает значениями по максимуму

    template<typename T, size_t arr_size>
    MyArray<T, arr_size>& MyArray<T, arr_size>::operator=(const MyArray<T, arr_size>& other) {
        if (this != &other) {
            copy_arr(*this, other);
        }
        return *this;
    }

    template<typename T, size_t arr_size>
    void MyArray<T, arr_size>::display_temp() const {
        std::cout << std::endl << *this << std::endl;
    }

    template<typename T, size_t arr_size>
    T& MyArray<T, arr_size>::operator[](size_t ind) {
        if (ind >= arr_size) {
            throw std::out_of_range{"Out of range"};
        }
        return this->m_arr[ind];
    }

    template<typename T, size_t arr_size>
    const T& MyArray<T, arr_size>::operator[](size_t ind) const {
        if (ind >= arr_size) {
            throw std::out_of_range{"Out of range"};
        }
        return this->m_arr[ind];
    }

    template<typename T, size_t arr_size>
    std::ostream& operator<<(std::ostream& out, const MyArray<T, arr_size>& arr) {
        out << "MyArray { ";
        for (int i = 0; i < arr_size; ++i) {
            out << arr.m_arr[i];
            if (i + 1 != arr_size) {
                out << ", ";
            }
        }
        out << " };";
        return out;
    }
} // namespace MyStdLib


#endif