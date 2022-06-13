#include "Vector112.h"

Vector112::Vector112(int len, int val)
{
	this->len = len;
	this->arr = new int[this->len];
	for (int i = 0; i < len; i++)
	{
		this->arr[i] = val;
	}
}

Vector112::Vector112(const int* arr, int size)
{
	this->len = size;
	this->arr = new int[this->len];
	for (size_t i = 0; i < len; i++)
	{
		this->arr[i] = arr[i];
	}
}

Vector112::Vector112(Vector112&& vec)
{
	//конструктор перемещения
	this->arr = vec.arr;
	this->len = vec.len;
	vec.arr = nullptr;
	vec.len = 0;
}

Vector112::Vector112(const Vector112& vec) //:Vector112(vec.arr, vec.len) {}
{
	this->len = vec.len;
	this->arr = new int[this->len];
	for (size_t i = 0; i < len; i++)
	{
		this->arr[i] = vec.arr[i];
	}
}

Vector112& Vector112::operator=(const Vector112& vec)
{
	if (this == &vec) //защита от самоприсваивания
		return *this;
	this->~Vector112(); //вызов деструктора
	this->len = vec.len; //копирование конструктора копирования
	this->arr = new int[this->len];
	for (size_t i = 0; i < len; i++)
	{
		this->arr[i] = vec.arr[i];
	}
	return *this;
}

Vector112& Vector112::operator=(Vector112&& vec)
{
	swap(this->arr, vec.arr);
	swap(this->len, vec.len);
	return *this;
}

Vector112::~Vector112()
{
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->arr = nullptr;
		this->len = 0;
	}
}

void Vector112::push_back(int val)
{
	if (this->arr == nullptr) {
		this->arr = new int[1];
		this->arr[0] = val;
		this->len = 1;
		return;
	}
	int* n_arr = new int[++this->len];
	for (size_t i = 0; i < this->len - 1; i++)
	{
		n_arr[i] = this->arr[i];
	}
	n_arr[this->len - 1] = val;
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::pop_back()
{
	if (this->arr == nullptr)
		return;
	if (this->len == 1) {
		this->~Vector112();
		return;
	}
	int* n_arr = new int[--this->len];
	for (int i = 0; i < this->len; i++)
	{
		n_arr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::push_front(int val)
{
	if (this->arr == nullptr) {
		this->arr = new int[1];
		this->arr[0] = val;
		this->len = 1;
		return;
	}
	int* n_arr = new int[++this->len];
	for (size_t i = 0; i < this->len - 1; i++)
	{
		n_arr[i+1] = this->arr[i];
	}
	n_arr[0] = val;
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::pop_front()
{
	if (this->arr == nullptr)
		return;
	if (this->len == 1) {
		this->~Vector112();
		return;
	}
	int* n_arr = new int[--this->len];
	for (int i = 0; i < this->len; i++)
	{
		n_arr[i] = this->arr[i+1];
	}
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::print() const
{
	for (int i = 0; i < this->len; i++)	{
		cout << this->arr[i] << " ";
	}
	cout << endl;
}

void Vector112::printMaxElem() const
{
	if (this->empty())
	{
		cout << "Array is empty" << endl;
		return;
	}
	int max = this->arr[0];
	for (int i = 0; i <this->len; i++)
	{
		if (this->arr[i] > max)
			max = this->arr[i];
	}
	cout << "max = " << max << endl;
}

void Vector112::printMinElem() const
{
	if (this->empty())
	{
		cout << "Array is empty" << endl;
		return;
	}
	int min = this->arr[0];
	for (int i = 0; i < this->len; i++)
	{
		if (this->arr[i] < min)
			min = this->arr[i];
	}
	cout << "min = " << min << endl;
}

void Vector112::insert(int index, int val)
{
	if (index > this->len || index < 0)
		return;
	if (index == this->len) {
		this->push_back(val);
		return;
	}
	if (index == 0) {
		this->push_front(val);
		return;
	}
	int* n_arr = new int[this->len + 1];
	for (int i = 0; i < this->len; i++) {
		if (i < index)
			n_arr[i] = this->arr[i];
		else
			n_arr[i + 1] = this->arr[i];
	}
	n_arr[index] = val;
	this->len++;
	delete[]this->arr;
	this->arr = n_arr;
}

void Vector112::erase(int index)
{
	if (index > this->len || index < 0)
		return;
	if (index == this->len-1) {
		this->pop_back();
		return;
	}
	if (index == 0) {
		this->pop_front();
		return;
	}
	int* n_arr = new int[this->len - 1];
	for (int i = 0; i < this->len; i++) {
		if (i < index)
			n_arr[i] = this->arr[i];
		else if (i == index)
			continue;
		else
			n_arr[i-1] = this->arr[i];
	}
	this->len--;
	delete[]this->arr;
	this->arr = n_arr;
}

void Vector112::remove(int val)
{
	if (this->empty())
		return;
	int cnt = 0;
	for (int i = 0; i <this->len; i++)
	{
		if (this->arr[i] == val)
			cnt++;
	}
	if (cnt == 0)
		return;
	if (cnt == this->len) {
		this->~Vector112();
		return;
	}
	int* n_arr = new int[this->len - cnt];
	for (int i = 0, k=0; i < this->len; i++)
	{
		if (this->arr[i] != val) {
			n_arr[k++] = arr[i];
		}
	}
	this->len-=cnt;
	delete[]this->arr;
	this->arr = n_arr;
}

void Vector112::clear()
{
	this->~Vector112();
}

bool Vector112::empty() const
{
	return this->arr==nullptr;
}

int Vector112::operator[](int index) const
{
	return this->arr[index];
}

int& Vector112::operator[](int index)
{
	return this->arr[index];
}

ostream& operator<<(ostream& out, const Vector112& arr)
{
	arr.print();
	return out;
}

istream& operator>>(istream& in, Vector112& arr)
{
	int new_len;
	cout << "How many elements: ";
	in >> new_len; 

	int* new_arr = new int[new_len];
	for (size_t i = 0; i < new_len; i++)
	{
		cout << "Enter " << i << " element: ";
		in >> new_arr[i]; 
	}
	arr = Vector112(new_arr, new_len);
	delete[] new_arr;
	return in;
}
