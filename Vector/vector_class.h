#ifndef VECT_CLASS__
#define VECT_CLASS__H


#include<iostream>
#include<initializer_list>

template<typename T>
class Vector{
	private:
		size_t v_size;
		size_t v_capacity;
		T* v_arr;
	
	
	public:
		using value_type = T;
		using size_type = size_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;
	
		
	private:
		class Allocator{
			public:
				using value_type = T;
				using size_type = std::size_t;
				using pointer = value_type*;
				using const_pointer = const pointer;

			public:
				pointer allocate(size_type);
		}
	
	public:
		Vector();
		Vector(size_type);
		Vector(size_type, const_reference);
		//Vector(initializer_list<value_type>);
		Vector(const_reference);
		Vector(Vector&& rhv);	
	
	public:
		~Vector();

	
	public:
		const_reference operator=(const_reference);
		const_reference operator=(Vector&& rhv);	
		reference operator[](size_type);	
	
	public:
		void clear();
		reference front();
		reference back();
		reference at(size_type);
		void push_back(const_reference);
		void pop_back();
		reference front();
		void recap();
		bool empty();
		size_type capacity();
		size_type size();
		size_type max_size();
		const_pointer data()const;
		void insert(size_type, const_reference);
		void erase(size_type);
		void resize(size_type, const_reference);
			
};
#include"vector_class.hpp"
#endif
