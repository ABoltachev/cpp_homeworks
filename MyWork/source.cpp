#include <iostream>
#include <cstddef>
#include "algorithm.hpp"

template<typename T>
void foo(T val) {
    std::cout << val << std::endl;
}

int main() {
    // ---------- MyArray ----------
    
    MyStdLib::MyArray<int, 10> arr {1, 2, 3, 4, 5}; // Конструктор со списком
    MyStdLib::MyArray<int, 10> arr2 = arr; // Конструктор копирования
    MyStdLib::MyArray<int, 0> arr_empty;
    std::cout << "arr: " << arr << std::endl;
    std::cout << "arr2: " << arr2 << std::endl;
    std::cout << "arr_empty: " << arr_empty << std::endl;
    arr2 = arr; // оператор присвоения
    std::cout << "arr.size(): "<< arr.size() << std::endl; // метод size()
    std::cout << "arr_empty.empty(): " << arr_empty.empty() << std::endl; // метод empty()
    arr[7] = 999; // индекс
    arr2[2] = arr[7]; // индекс
    std::cout << "arr2[2]: " << arr2[2] << std::endl; // индекс

    arr.display_temp(); // Альтернативный способ вывода
    arr2.display_temp();

    // ------------------------------
    std::cout << "\n---------- MyVector ----------\n" << std::endl;
    // ---------- MyVector ----------

    MyStdLib::MyVector<int> v1(3, -1); // конструктор по умолчанию
    MyStdLib::MyVector<int> v2(10, 5); // конструктор с арг: (size, init)
    MyStdLib::MyVector<int> v3(v2); // конструктор по копирования 
    MyStdLib::MyVector<int> v4 = std::move(v1); // конструктор перемещения
    MyStdLib::MyVector<int> v5 {1, 2, 3, 4, 5}; // Конструктор со списком

    std::cout << "v1: " << v1 << std::endl; 
    std::cout << "v2: " << v2 << std::endl; 
    std::cout << "v3: " << v3 << std::endl;  
    std::cout << "v4: " << v4 << std::endl; 
    std::cout << "v5: " << v5 << std::endl; 

    v3[0] = -999;
    v2.push_back(999); // добавляем в конец
    std::cout << "v2 after pushing 999 back: " << v2 << std::endl; 
    std::cout << "v3[0] = -999: " << v3 << std::endl;  

    std::cout << "v3.size: " << v3.size() << std::endl;
    std::cout << "v1.empty: " << v1.empty() << std::endl;
    std::cout << "v3.empty: " << v3.empty() << std::endl;

    v5.clear();
    std::cout << "v5 after cleaning: " << v5 << std::endl; 
    v2.resize(5, 100);
    std::cout << "v2 after v2.resize(5, 100): " << v2 << std::endl;

    MyStdLib::MyVector<int> v6;
    v6 = std::move(v2);
    std::cout << "v2 -> move -> v6: " << v6 << " and v2: " << v2 << std::endl;
    
    // ------------------------------
    std::cout << "\n---------- MySet ----------\n" << std::endl;
    // ---------- MySet ----------

    MyStdLib::MySet<int> s {9, 2, 5, 1, 0, 1, -1, 1, 1};
    MyStdLib::MySet<int> ts {9, 2, 5, 1, 0, 1, -1, 1, 1};
    MyStdLib::MySet<int> s2;
    std::cout << "MySet<int> s {9, 2, 5, 1, 0, 1, -1, 1, 1} -> " << s << std::endl;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "empty: " << s.empty() << std::endl;
    std::cout << "top: " << s.top() << std::endl;
    std::cout << "bottom: " << s.bottom() << std::endl;
    std::cout << "elem_find(2): " << s.elem_find(2) << std::endl;
    std::cout << "bool_find(-3): " << s.bool_find(-3) << std::endl;
    std::cout << "bool_find(2): " << s.bool_find(-3) << std::endl;

    MyStdLib::MySet<int> s3(s); // Конструктор копирования
    std::cout << "init s3(s): " << s3 << std::endl;
    std::cout << "checking s after previous copying: " << s << std::endl;

    MyStdLib::MySet<int> s4 = std::move(s3); // Конструктор перемещения
    std::cout << "init s4 = std::move(s3): " << s4 << std::endl;
    std::cout << "checking s3 after previous moving: " << s3 << std::endl;


    s.clear();
    s.emplace(1);
    s.emplace(2);
    s.emplace(3);
    s.emplace(4);
    std::cout << "s after cleaning and some emplaces: " << s << std::endl;
    s2 = std::move(s);
    std::cout << std::endl << "s2 = std::move(s);" << std::endl;
    std::cout << "s after moving: " << s << std::endl;
    std::cout << "s2 after moving: " << s2 << std::endl;
    s = s2;
    std::cout << std::endl << "s = s2;" << std::endl;
    std::cout << "s after copying: " << s << std::endl;
    std::cout << "s2 after copying: " << s2 << std::endl;

    std::cout << std::endl;
    std::cout << "max(s2): " << MyStdLib::max(s2) << std::endl;
    std::cout << "min(s2): " << MyStdLib::min(s2) << std::endl;
    std::cout << "find(s2, 2): " << MyStdLib::find(s2, 2) << std::endl;
    // std::cout << "find(s2, 5): " << MyStdLib::find(s2, 5) << std::endl;
    // the line above throws an exception: run_time



    // ------------------------------
    std::cout << "\n---------- Algorithms ----------\n" << std::endl;
    // ---------- Algorithms ----------

    std::cout << arr << std::endl;
    std::cout << "max(Array): " << MyStdLib::max(arr) << std::endl;
    std::cout << "min(Array): " << MyStdLib::min(arr) << std::endl;
    std::cout << "find(Array, 4): " << MyStdLib::find(arr, 4) << std::endl;
    MyStdLib::find(arr, 4) += 1;
    std::cout << "find(Array, 4) += 1. Now Array: " << arr << std::endl;
    std::cout << "sorted(Array): " << MyStdLib::sort(arr) << std::endl;


    MyStdLib::MyVector<int> vector {5, 4, 3, 2, 1};
    std::cout << std::endl << vector << std::endl;
    std::cout << "max(Vector): " << MyStdLib::max(vector) << std::endl;
    std::cout << "min(Vector): " << MyStdLib::min(vector) << std::endl;
    std::cout << "sort(Vector): " << MyStdLib::sort(vector) << std::endl;
    MyStdLib::find(vector, 4) += 1;
    std::cout << "find(Vector, 1) -= 1, now Vector: " << vector << std::endl;


    std::cout << std::endl << "set {9, 2, 5, 1, 0, 1, -1, 1, 1}: " << ts << std::endl;
    std::cout << "max(set): " << MyStdLib::max(ts) << std::endl;
    std::cout << "min(set): " << MyStdLib::min(ts) << std::endl;
    MyStdLib::find(ts, 1) -= 1;
    std::cout << "find(set, 1) -= 1, now set: " << ts << std::endl;

    const MyStdLib::MyArray<int, 5> carr {2, 3, 4, 5, 3};
    std::cout << std::endl << "const carr[2]: " << carr[2] << std::endl;

    const MyStdLib::MyVector<int> cvec {2, 3, 4, 5, 3};
    std::cout << "const cvec[2]: " << cvec[2] << std::endl;

    return 0;
}





    // // ---------- MyArray ----------
    
    // MyStdLib::MyArray<int, 10> arr {1, 2, 3, 4, 5}; // Конструктор со списком
    // MyStdLib::MyArray<int, 10> arr2 = arr; // Конструктор копирования
    // MyStdLib::MyArray<int, 0> arr_empty;
    // arr2 = arr; // оператор присвоения
    // std::cout << arr.size() << std::endl; // метод size()
    // std::cout << arr_empty.empty() << std::endl; // метод empty() ???
    // arr[7] = 999; // индекс
    // arr2[2] = arr[7]; // индекс
    // std::cout << arr2[2] << std::endl; // индекс
    // std::cout << "[" << arr << "]" << std::endl;

    // arr.display_temp();
    // arr2.display_temp();

    // // ------------------------------
    // std::cout << "\n---------- MyVector ----------\n" << std::endl;
    // // ---------- MyVector ----------

    // MyStdLib::MyVector<int> v1(3, -1); // конструктор по умолчанию
    // MyStdLib::MyVector<int> v2(10, 5); // конструктор с арг: (size, init)
    // MyStdLib::MyVector<int> v3(v2); // конструктор по копирования 
    // MyStdLib::MyVector<int> v4 = std::move(v1); // конструктор перемещения
    // MyStdLib::MyVector<int> v5 {1, 2, 3, 4, 5};

    // v2.push_back(999); // добавляем в конец
    // std::cout << "v3.size: " << v3.size() << std::endl;
    // std::cout << "v1.empty: " << v1.empty() << std::endl;
    // std::cout << "v3.empty: " << v3.empty() << std::endl;
    // v3[0] = -999;
    // std::cout << v1 << std::endl; 
    // std::cout << v2 << std::endl; 
    // std::cout << v3 << std::endl;  
    // std::cout << v4 << std::endl; 
    // std::cout << v5 << std::endl; 
    // v5.clear();
    // std::cout << v5 << std::endl; 
    // v2.resize(5, 100);
    // std::cout << v2 << std::endl;

    // MyStdLib::MyVector<int> v6;
    // v6 = std::move(v2);
    // std::cout << v6 << std::endl;
    
    // // ------------------------------
    // std::cout << "\n---------- MySet ----------\n" << std::endl;
    // // ---------- MySet ----------

    // MyStdLib::MySet<int> s {9, 2, 5, 1, 0, 1, -1, 1, 1};
    // MyStdLib::MySet<int> s2;
    // std::cout << s << std::endl;
    // std::cout << "size: " << s.size() << std::endl;
    // std::cout << "empty: " << s.empty() << std::endl;
    // std::cout << "top: " << s.top() << std::endl;
    // std::cout << "bottom: " << s.bottom() << std::endl;
    // std::cout << "elem_find(2): " << s.elem_find(2) << std::endl;
    // std::cout << "bool_find(-3): " << s.bool_find(-3) << std::endl;

    // MyStdLib::MySet<int> s3(s); // Конструктор копирования
    // std::cout << "init s3(s): " << s3 << std::endl;
    // std::cout << "checking s after previous moving: " << s << std::endl;

    // MyStdLib::MySet<int> s4 = std::move(s3); // Конструктор перемещения
    // std::cout << "init s4 = std::move(s3): " << s4 << std::endl;
    // std::cout << "checking s3 after previous moving: " << s3 << std::endl;


    // s.clear();
    // s.emplace(1);
    // s.emplace(2);
    // s.emplace(3);
    // s.emplace(4);
    // std::cout << "s after cleaning and some emplaces: " << s << std::endl;
    // s2 = std::move(s);
    // std::cout << "s after moving: " << s << std::endl;
    // std::cout << "s2 after moving: " << s2 << std::endl;
    // s = s2;
    // std::cout << "s after copying: " << s << std::endl;
    // std::cout << "s2 after copying: " << s2 << std::endl;

    // std::cout << "max(s2): " << MyStdLib::max(s2) << std::endl;
    // std::cout << "min(s2): " << MyStdLib::min(s2) << std::endl;
    // std::cout << "find(s2, 2): " << MyStdLib::find(s2, 2) << std::endl;
    // std::cout << "find(s2, 5): " << MyStdLib::find(s2, 5) << std::endl;



    // // ------------------------------
    // std::cout << "\n---------- Algorithms ----------\n" << std::endl;
    // // ---------- Algorithms ----------

    // std::cout << "max(Array): " << MyStdLib::max(arr) << std::endl;
    // std::cout << "min(Array): " << MyStdLib::min(arr) << std::endl;
    // MyStdLib::find(arr, 4) += 1;
    // std::cout << "find(Array): " << arr << std::endl;
    // std::cout << "sorted(Array): " << MyStdLib::sort(arr) << std::endl;

    // MyStdLib::find(v4, -1) += 1;
    // std::cout << "Vector: " << v4 << std::endl;
    // std::cout << "max(Vector): " << MyStdLib::max(v4) << std::endl;
    // std::cout << "min(Vector): " << MyStdLib::min(v4) << std::endl;
    // MyStdLib::MyVector v_for_sort {5, 4, 3, 2, 1};
    // std::cout << "Vector for sort: " << v_for_sort << std::endl;
    // std::cout << "sort(Vector): " << MyStdLib::sort(v_for_sort) << std::endl;
    // v4.emplace_back(4);
    // std::cout << "Vector4: " << v4 << std::endl;