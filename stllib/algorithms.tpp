#ifndef ALGORITHMS_TPP
#define ALGORITHMS_TPP


namespace ArrayAlgorithms {

    template <typename aT, size_t T_size>
    void sort(Array<aT, T_size>& arr) {
        // Bubble sort :)
        size_t n = arr.size();
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    aT dop = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = dop;
                }
            }
        }
    }

    template <typename aT, size_t T_size>
    const aT& max(const Array<aT, T_size>& arr) {
        aT maxima = arr[0];
        for (size_t i = 1; i < T_size; ++i) {
            if (arr[i] > maxima)
                maxima = arr[i];
        }
        return maxima;
    }

    template <typename aT, size_t T_size>
    const aT& min(const Array<aT, T_size>& arr) {
        aT minima = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < minima)
                minima = arr[i];
        }
        return minima;
    }

    template <typename aT, size_t T_size>
    aT& find(Array<aT, T_size>& arr, const aT& value) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == value)
                return arr[i];
        }
        throw std::runtime_error("Error: Element was not found...");
    }

}
namespace VectorAlgorithms {

    template<typename vT>
    void sort(Vector<vT>& vect) {
        // Bubble sort :)
        size_t n = vect.size();
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - i - 1; ++j) {
                if (vect[j] > vect[j + 1]) {
                    vT dop = vect[j];
                    vect[j] = vect[j + 1];
                    vect[j + 1] = dop;
                }
            }
        }
    }

    template<typename vT>
    const vT& max(const Vector<vT>& vect) {
        vT maxima = vect[0];
        for (size_t i = 1; i < vect.size(); ++i) {
            if (vect[i] > maxima)
                maxima = vect[i];
        }
        return maxima;
    }

    template<typename vT>
    const vT& min(const Vector<vT>& vect) {
        vT minima = vect[0];
        for (size_t i = 1; i < vect.size(); ++i) {
            if (vect[i] < minima)
                minima = vect[i];
        }
        return minima;
    }

    template<typename vT>
    vT& find(Vector<vT>& vect, const vT& value) {
        for (size_t i = 0; i < vect.size(); ++i) {
            if (vect[i] == value)
                return vect[i];
        }
        throw std::runtime_error("Error: Element was not found...");
    }
}

#endif