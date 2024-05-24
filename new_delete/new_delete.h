#ifndef __NEW__DELETE__
#define __NEW__DELETE__
#include<iostream>

void* operator_new(size_t);

void operator_delete(void*);

template<typename T>
	T* T_new();

template<typename T>
	void T_delete(T*);

template<typename T>
	T* T_new_arr(size_t count);

template<typename T>
	void T_delete_arr(T*, size_t size);
#endif
