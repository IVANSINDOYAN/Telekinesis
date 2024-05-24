#ifndef VECT__CLASS__HPP
#define VECT__CLASS__HPP


#include<iostream>
#include"vector_class.h"
#include<initializer_list>
	template<typename T>//Allocator
	Vector<T>::pointer
	Vector<T>::Allocator::allocate(size_type count){
	
	}



	template<typename T>//default constructor
	Vector<T>::Vector()
		:this->v_size{0}
		,this->v_capacity = 0
		,this->v_arr = nullptr
		{std::cout << "Default constructor";}

	template<typename T>//parametric constructor
	Vector<T>::Vector(size_type size)
		:this->v_size{size}
		,this->v_capacity{2 * size}
		,this->v_arr{new value_type[this->v_capacity]}
		{std::cout << "parametric constructor";}

	/*template<typename T>//parametric constructor with insertion of values
	Vector<T>::Vector(size_type size, const_reference val)
		:Vector(size)
		{
			for(size_type i = 0; i < size; ++i){
				v_arr[i] = val;
			}
			std::cout << v_arr[3];
		}

	template<typename T>//parametric constructor with an argument of initializer list
		Vector<T>::Vector(std::initializer_list<value_type> init)
			:v_size{init.size()}
			,v_capacity{2 * v_size}
			,v_arr{new value_type[v_capacity]}
			{
				int temp = 0;
				for(const_reference i : init){
					v_arr[temp] = i;
					++temp;
				}
				std::cout << v_arr[3];
			}

	template<typename T>// copy constructor
	Vector<T>::Vector(const_reference rhv)
		:this->v_size{rhv.v_size}
		,this->v_capacity{rhv.v_capacity}
		,this->v_arr{new value_type[this->v_capacity]}
		{
			for(size_type i = 0; i < rhv.size; ++i){
				this->v_arr[i] = rhv.v_arr[i];
			}
			std::cout << this-> v_arr[2];
		}

	template<typename T>// move constructor
	Vector<T>::Vector(Vector&& rhv)
		:this->v_size{rhv.v_size}
		,this->v_capacity{rhv.v_capacity}
		,this->v.arr{rhv.v_arr}
		{
			rhv.v_size = 0;
			rhv.v_capacity = 0;
			rhv.v_arr = nullptr;
			
		}	

	
	template<typename T>//destructor
        Vector<T>::~Vector(){
                clear();
        }


	template<typename T>//copy assignment
	Vector<T>::const_reference
	Vector<T>::operator=(const_reference rhv){
		if(this != &rhv){
			this->clear();
			this->v_size = rhv.v_size;
			this->v_capacity = rhv.v_capacity;
			this->v_arr = new value_type[rhv.v_capacity];
			for(size_type i = 0; i < rhv.v_size; ++i){
				this->v_arr[i] = rhv.v_arr[i];
			}
		}
		return *this;
	}

	
	template<typename T>//move assignment
	Vector<T>::const_reference
	Vector<T>::operator=(Vector&& rhv){
		if(this != &rhv){
			this->clear();
			this->v_size = rhv.v_size;
			this->v_capacity = rhv.v_capacity;
			this->v_arr = rhv.v_arr;
			rhv.v_size = 0;
			rhv.v_capacity = 0;
			rhv.v_arr = nullptr;
		}
		return *this;
	}


	template<typename T>//operator[]
	Vector<T>::reference
	Vector<T>::operator[](size_type index){
		return this->v_arr[index];
	}


	template<typename T>//clear method
	void
	Vector<T>::clear() noexcept{
		this->v_size = 0;
		this->v_capacity = 0;
		delete []this->v_arr;
		this->v_arr = nullptr;
	}

	template<typename T>//the method front returns reference to the first element of the vector
	Vector::reference
	Vector<T>::front(){
		return this->v_arr[0];
	}


	template<typename T>//the method at returns the value kept in the received index 
	Vector::reference
	Vector<T>::at(size_type index){
		return this->v_arr[index];
	}

	template<typename T>//the method push_back puts the given value at the end of the vector,before it calls the recap method
	void
	Vector<T>::push_back(const_reference val){
		this->recap();
		this->v_arr[this->v_size] = val;
		++this->v_size;
	}

	template<typename T>//the method pop_back decreents the size of the vector 
	void
	Vector<T>::pop_back(){
		if(this->v_size){
			--this->v_size;
		}
	}

	template<typename T>//the method front returns a reference on the first element of the vector
	Vector<T>::reference
	Vector<T>::front(){
		return this->v_arr[0];
	}

	template<typename T>//the method back returns a reference on the last element of the vector
	Vector<T>::reference
	Vector<T>::back(){
		return this->v_arr[size -1];
	}

	template<typename T>//the method recap enlarges the capacity twice if the size becomes equal the capacity of the vector
	void
	Vector<T>::recap(){
		if(this->v_size == this->v_capacity){
			v_capacity *= 2;
			pointer tmp = new value_type[v_capacity];
			for(size_type i = 0; i < v_size; ++i){
				tmp[i] = v_arr[i];
			}
			delete this->v_arr;
			this ->v_arr = tmp;
			tmp = nullptr;
				
		}

	}


	template<typename T>//the method returns a boolean value confirming if the vector type obect is empty or not
	bool
	Vector<T>::empty(){
		return this->v_size == 0;
	}

	
	template<typename T>//the method capacity returns the capacity value of the vector
	Vector<T>::size_type
	Vector<T>::capacity(){
		return this->v_capacity;
	}


	template<typename T>//the method size returns the size of the vector
	Vector::size_type
	Vector<T>::size(){
		return this->v_size;
	}

	
	template<typename T>//the method max_size returns the maximum possible count of elements which are possible to keep in the vector  
	Vector<T>::size_type
	Vector<T>::max_size(){
		return std::max(size_type)/sizeof(value_type);
	}


	template<typename T>//data method returns a pointer to the member pointer of the vector
	Vector<T>::const_pointer
	Vector<T>::data()const{
		return this->v_arr;
	}


	template<typename T>//the insert method inserts the given value to the given index incrementing the size of the vector
	void
	Vector<T>::insert(size_type index, const_reference val){
		if(index >= this->v_size || index < 0){
			throw std::out_of_range("out of range");
			this->recap();
			for(int i = this->v_size; i >= index; --i){
				this->v_arr[i] = v_arr[i - 1];
			}
			this->v_arr[index] = val;
			++this->v_size;
		}
	}


	template<typename T>//the erase method erases the element stored in the given index
	void
	Vector<T>::erase(size_type index){
		if(index >= size || index < 0){
			throw std::out_of_range;
		}
		for(size_type i = index; i < this->v_size - 1; ++i ){
			this-> v_arr[i] = this->v_arr[i + 1];
		}
		--this->v_size;
	}


	template<typename T>//the method resize either enlarges or shortens the size of the vector,it does nothing 
	void                //if the given count and size are equal
	Vector<T>::resize(size_type count, const_reference val){
		if(count < this->v_size){
			this->v_size = count;
			}else if(count > this->v_size){
				this->v_capacity = 2 * count;
				pointer tmp = new value_type[this->v_capacity];
				for(size_type i = 0;i < this->v_size; ++i){
					tmp[i] = v_arr[i];
				}
				for(size_type i = this->v_size; i < count; ++i){
					tmp[i] = val;
				}
				delete[]this->v_arr;
				this->varr = tmp;
				tmp = nullptr;
				this->v_size = count;


			}
		}
	}
*/

#endif
