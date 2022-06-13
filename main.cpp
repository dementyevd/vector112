#include "Vector112.h"

void main() {
	Vector112 v(5,3);
	//перемещение
	Vector112 v2 = move(v);
	/*v.push_back(5);
	v.print();
	v.push_front(10);
	v.print();*/
	cout << v;
	v.remove(3);
	v.print();
	
}