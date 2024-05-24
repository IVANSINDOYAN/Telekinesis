#include"vector_class.h"
#include<iostream>

int main(){
	int a = 5;
	int &b = a;
	if(&a == &b)
	std::cout << &a << " "<< &b;	
}
