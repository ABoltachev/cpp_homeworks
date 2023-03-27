#pragma once

namespace HW_2 {

    // Array
    template<typename Type, size_t size>
    const Type& max(const Array<Type, size>& object) {
        if (object.size() == 0) {
            throw "Array is empty";
        }
        Type max = object[0];
        for (int i = 1; i < object.size(); i++) {
            if (max < object[i]) {
                max = object[i];
            }
        }
        return max;
    }

    template<typename Type, size_t size>
    const Type& min(const Array<Type, size>& object) {
        if (object.size() == 0) {
            throw "Array is empty";
        }
        Type min = object[0];
        for (int i = 1; i < object.size(); i++) {
            if (min > object[i]) {
                min = object[i];
            }
        }
        return min;
    }

    template<typename Type, size_t size>
    Type& find(const Array<Type, size>& object, const Type& value) {
        for (int i = 0; i < object.size(); i++) {
            if (object[i] == value) {
                return object[i];
            }
        }
        throw std::runtime_error("There is no such an element in the array");
    }

    template<typename Type, size_t size>
    void sort(Array<Type, size>& object, int l, int r) {
        if (r == 0) {
            r = object.size() - 1;
        }
        int l_before = l, r_before = r;
        Type p = object[(l + r) / 2];
        while (l <= r) {
            while (object[l] < p) {
                l++;
            }
            while (object[r] > p) {
                r--;
            }
            if (l <= r) {
                std::swap(object[l], object[r]);
                l++;
                r--;
            }
        }
        if (r > l_before) {
            sort(object, l_before, r);
        }
        if (l < r_before) {
            sort(object, l, r_before);
        }
    }


    // Vector
    template<typename Type>
    const Type& max(const Vector<Type>& object) {
        if (object.size() == 0) {
            throw "Vector is empty";
        }
        Type max = object[0];
        for (int i = 1; i < object.size(); i++) {
            if (max < object[i]) {
                max = object[i];
            }
        }
        return max;
    }

    template<typename Type>
    const Type& min(const Vector<Type>& object) {
        if (object.size() == 0) {
            throw "Vector is empty";
        }
        Type min = object[0];
        for (int i = 1; i < object.size(); i++) {
            if (min > object[i]) {
                min = object[i];
            }
        }
        return min;
    }

    template<typename Type>
    Type& find(const Vector<Type>& object, const Type& value) {
        for (int i = 0; i < object.size(); i++) {
            if (object[i] == value) {
                return object[i];
            }
        }
        throw std::runtime_error("There is no such an element in the vector");
    }

    template<typename Type>
    void sort(Vector<Type>& object, int l, int r) {
        if (r == 0) {
            r = object.size() - 1;
        }
        int l_before = l, r_before = r;
        Type p = object[(l + r) / 2];
        while (l <= r) {
            while (object[l] < p) {
                l++;
            }
            while (object[r] > p) {
                r--;
            }
            if (l <= r) {
                std::swap(object[l], object[r]);
                l++;
                r--;
            }
        }
        if (r > l_before) {
            sort(object, l_before, r);
        }
        if (l < r_before) {
            sort(object, l, r_before);
        }

    }
}