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

	//�������� � �����
	void push_back(int val);
	//������� � �����
	void pop_back();
	//�������� � ������
	void push_front(int val);
	//������� ������
	void pop_front();
	//�����
	void print() const;
	//����� ������������� ��������
	void printMaxElem() const;
	//����� ������������ ��������
	void printMinElem() const;
	//������� �������� � ������
	void insert(int index, int val);
	//�������� ���������� �������
	void erase(int index);
	//�������� ��� ��������� �������� val
	void remove(int val);
	inline int size() const { return this->len; }
	void clear();
	bool empty() const;
	int operator[](int index) const;
	int& operator[](int index);
	friend ostream& operator<<(ostream& out, const Vector112& arr);
	friend istream& operator>>(istream& in, Vector112& arr);
};

