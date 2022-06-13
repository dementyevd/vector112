#pragma once
#include <iostream>
using namespace std;
class Vector112
{
	int* arr = nullptr;
	int len = 0;
public:
	Vector112() = default;
	Vector112(int len, int val = 0);
	Vector112(const int* arr, int size);

	Vector112(Vector112&& vec);
	Vector112& operator=(Vector112&& vec);
	Vector112(const Vector112& vec);
	Vector112& operator=(const Vector112& vec);
	
	~Vector112();

	//добавить в конец
	void push_back(int val);
	//удалить с конца
	void pop_back();
	//добавить в начало
	void push_front(int val);
	//удалить первый
	void pop_front();
	//вывод
	void print() const;
	//вывод максимального элемента
	void printMaxElem() const;
	//вывод минимального элемента
	void printMinElem() const;
	//вставка элемента в индекс
	void insert(int index, int val);
	//удаление указанного индекса
	void erase(int index);
	//удаление все вхождения значения val
	void remove(int val);
	inline int size() const { return this->len; }
	void clear();
	bool empty() const;
	int operator[](int index) const;
	int& operator[](int index);
	friend ostream& operator<<(ostream& out, const Vector112& arr);
	friend istream& operator>>(istream& in, Vector112& arr);
};

