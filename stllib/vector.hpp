#include <iostream>
#include <memory>

template<typename T>
class Vector {
public:
    // Constructors
    Vector();
    Vector(size_t size, const T& default_value = T());
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other);
    Vector(std::initializer_list<T> il);

    // Destructor
    ~Vector();

    // Assignment operators
    Vector<T>& operator=(const Vector<T>& other);
    Vector<T>& operator=(Vector<T>&& other);

    // Capacity
    size_t size() const;
    bool empty() const;
    void resize(size_t size, const T& default_value = T());
    void clear();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Modifiers
    void push_back(const T& value);
    void emplace_back(T&& value);

private:
    std::unique_ptr<T[]> data_;
    size_t size_;
    size_t capacity_;

    void ExpandIfNeeded();
};
