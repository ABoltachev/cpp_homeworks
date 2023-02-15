#pragma once

template<typename T>
const T& algo::max(const container::vector<T> &object) {
    if (object.size() == 0) {
        throw "Vector is empty";
    }
    T max = object[0];
    for (int i = 1; i < object.size(); i++) {
        if (max<object[i]) {
            max = object[i];
        }
    }
    return max;
}

template<typename T, size_t size>
const T& algo::max(const container::array<T, size> &object) {
    if (object.size() == 0) {
        throw "Array is empty";
    }
    T max = object[0];
    for (int i = 1; i < object.size(); i++) {
        if (max<object[i]) {
            max = object[i];
        }
    }
    return max;
}

template<typename T>
const T& algo::max(const container::set<T> &object) {
    return object.top();
}


template<typename T>
const T& algo::min(const container::vector<T> &object) {
    if (object.size() == 0) {
        throw "Vector is empty";
    }
    T max = object[0];
    for (int i = 1; i < object.size(); i++) {
        if (max > object[i]) {
            max = object[i];
        }
    }
    return max;
}

template<typename T, size_t size>
const T& algo::min(const container::array<T, size> &object) {
    if (object.size() == 0) {
        throw "Array is empty";
    }
    T max = object[0];
    for (int i = 1; i < object.size(); i++) {
        if (max > object[i]) {
            max = object[i];
        }
    }
    return max;
}

template<typename T>
const T& algo::min(const container::set<T> &object) {
    return object.buttom();
}

template<typename T>
T& algo::find(const container::vector<T> &object, const T &element) {
    for (int i = 0; i < object.size(); i++) {
        if (object[i] == element) {
            return object[i];
        }
    }
    throw std::runtime_error("There is no such an element in the vector");
}

template<typename T, size_t size>
T& algo::find(const container::array<T, size> &object, const T &element) {
    for (int i = 0; i < object.size(); i++) {
        if (object[i] == element) {
            return object[i];
        }
    }
    throw std::runtime_error("There is no such an element in the array");
}


template<typename T>
void algo::sort(container::vector<T> &object, int l, int r) {
    if (r == 0) {
        r = object.size() - 1;
    }
    int l_before = l, r_before = r;
    T p = object[(l + r) / 2];
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

template<typename T, size_t size>
void algo::sort(container::array<T, size> &object, int l, int r) {
    if (r == 0) {
        r = object.size() - 1;
    }
    int l_before = l, r_before = r;
    T p = object[(l + r) / 2];
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



