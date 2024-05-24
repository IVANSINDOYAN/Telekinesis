#include "cell.h"
#include <iostream>
#include <cstring>

//constructor
cell::cell()
	:storage{""}
	{std::cout << "default constructor" << std::endl;}


cell::cell(std::string str)
	:storage{str}
	{std::cout <<"string constructor" << std::endl;}


cell::cell(int i)
	:cell(std::to_string(i))
	{std::cout<< "int ctor" << std::endl;}	


cell::cell(double d)
	:cell(std::to_string(d))
	{}

cell::cell(cell&& rhv)
	:storage{rhv.storage}
	{std::cout <<"temporary ctor";}	

cell::cell(cell& rhv)
	:storage{rhv.storage}
	{ std::cout <<" lvalue ctor";}

//destructor
cell::~cell(){std::cout << "destructor" << std::endl;}

//conversion operators
cell::operator int(){
	std::cout<< "operator int" << std::endl;	
	return stoi(this->storage);
	}

cell::operator double(){
	return std::stod(this->storage);
}

cell::operator std::string(){
	return this->storage;
}




//assignment operations
const cell&
cell::operator=(cell&& rhv){
	std::cout << "&& operator=" << std::endl;
	if(this != &rhv){
		this->storage = rhv.storage;
	}
	return *this;
}


const cell&
cell::operator=(cell& rhv){
	std::cout<< "lvalue opertor=" << std::endl;
	if(this != &rhv){
		this->storage = rhv.storage;
	}
	return *this;
}

//member methods
void cell::print(){
	std::cout<< storage << std::endl;
}

