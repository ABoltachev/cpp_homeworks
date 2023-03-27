
template<class T>
Vector<T>::Vector()
{
	arr = new T[1];
	SIZE = 0;
	CAPACITY = 1;
}

template<class T>
Vector<T>::Vector(size_t size, const T& value)
	:arr(new T[size]), SIZE(size), CAPACITY(size)
{
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = value;
	}
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
	:arr(new T[CAPACITY]), SIZE(other.SIZE),
	CAPACITY(other.CAPACITY)
{
	for (int i = 0; i < SIZE; ++i) 
	{
		arr[i] = other.arr[i];
	}
}

template<class T>
Vector<T>::Vector(Vector&& other)
{
	arr = other.arr;
	SIZE = other.SIZE;
	CAPACITY = other.CAPACITY;
	other.arr = nullptr;
	other.SIZE = 0;
	other.CAPACITY = 0;
}

template<class T>
Vector<T>::Vector(std::initializer_list<T> init_list)
	:arr(new T[SIZE]), SIZE(init_list.size()), CAPACITY(SIZE)
{
	size_t count = 0;
	for (const auto i : init_list)
	{
		arr[count] = i;
		count++;
	}
}

template<class T>
size_t Vector<T>::size() const
{
	return SIZE;
}

template<class T>
bool Vector<T>::empty() const
{
	return SIZE == 0;
}

template<class T>
void Vector<T>::addmemory()
{
	CAPACITY *= 2;
	T* z = arr;
	arr = new T[CAPACITY];
	for (size_t i = 0; i < SIZE; ++i) {
		arr[i] = z[i];
	}
	delete[] z;
}

template<class T>
void Vector<T>::push_back(const T& value)
{
	if (SIZE > CAPACITY) {
		addmemory();
	}
	arr[SIZE++] = value;
}

template<class T>
void Vector<T>::emplace_back(T&& value)
{
	if (SIZE == CAPACITY)
		resize(CAPACITY * 2);
	arr[SIZE++] = std::move(value);
}

template<class T>
void Vector<T>::resize(size_t& size, const T& value)
{
	if (size > CAPACITY) {
		addmemory();
	}
	for (size_t i = SIZE; i < size; ++i) {
		arr[i] = value;
	}
	SIZE = size;
}

template<class T>
void Vector<T>::clear()
{
	delete[] arr;
	arr = nullptr;
	SIZE = 0;
	CAPACITY = 0;
}

template<class T>
T& Vector<T>::operator[](size_t index)
{
	return arr[index];
}

template<class T>
const T& Vector<T>::operator[](size_t index) const
{
	return arr[index];
}

template<class T>
Vector<T>& Vector<T>::operator= (const Vector& other)
{
	if (&other == this) {
		return *this;
	}
	delete[] arr;
	arr = new T[other.CAPACITY];
	for (int i = 0; i < other.CAPACITY; ++i) {
		arr[i] = other.arr[i];
	}
	SIZE = other.SIZE;
	CAPACITY = other.CAPACITY;
	return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
	if (this != &other) {
		delete[] arr;
		arr = other.arr;
		SIZE = other.SIZE;
		CAPACITY = other.CAPACITY;

		other.arr = nullptr;
		other.size = 0;
		other.capacity = 0;
	}
	return this;
}

template<class T>
Vector<T>::~Vector()
{
	delete[] arr;
}