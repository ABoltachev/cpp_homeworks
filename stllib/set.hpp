//    * set и методы для него(для реализации использовать простое бинарное дерево, соответственно использовать можно только с данными, которые имеют оператор < ) :
//    size(возвращает размер)
//    empty(возвращает true если пустой)
//    top(возвращает большее значение)
//    find(поиск элемента, true - нашли, false - нет)
//    insert(вставка(копирование))
//    emplace(вставка(перемещение))
//    clear(очистка)
//    присваивание(копирование и перемещением)
//    конструкторы(конструктор без аргументов; копирования; перемещения; конструктор с std::inizialized_list)
#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <stdexcept>

namespace lib {
	template <typename T>
	class Set 
	{
	private:
		struct Node 
		{
			T value;
			Node* right;
			Node* left;
		};
		size_t m_size;
		Node* head;
	public:
		Set();

		Set(const Set& set);
		Set(Set&& set);
		Set(std::initializer_list<T> list);

		Set& operator=(const Set& set);
		Set& operator=(Set&& set);

		size_t size();
		bool empty();

		T top();
		T min();
		bool find(const T& elem);
		T& find_v(const T& elem);
		void insert(const T& elem);
		void insert_r(Node*& head, const T& elem);

		void emplace(T&& elem);
		void emplace_r(Node*& head, T&& elem);

		void clear();

		~Set() = default;
	};

}
#include "set.tpp"

#endif 
