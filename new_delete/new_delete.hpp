#include<iostream>
#include"new_delete.h"
#include<stdexcept>


void* operator_new(size_t size){
	void* ptr = malloc(size);
	if(!ptr){
		throw std::bad_alloc();
	}
	return ptr;
}


void operator_delete(void* ptr){
	if(ptr){
		std::free(ptr);
	}
}

template<typename T>
	T* T_new(){
		void* ptr = operator_new(sizeof(T));
		return new(ptr)T;
	}


template<typename T>
	void T_delete(T* ptr){
		if(ptr){
			ptr-> ~T();
			operator_delete(ptr);
		}
	}

template<typename T>
	T* T_new_arr(size_t count){
		T* ptr = static_cast<T*>(operator_new(count * sizeof(T)));
		for(int i = 0; i < count; ++i){
			new(ptr[i])T;
		}
		return ptr;
	}

template<typename T>
	void T_delete_arr(T* ptr, size_t size){
		if(!ptr){
			throw std::exception("The array doesn't exist");
		}
		for(int i = 0; i < size; ++i){
			T_delete(ptr[i]);
		}
		ptr = nullptr;
	}
