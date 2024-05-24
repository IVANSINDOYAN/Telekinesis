#ifndef FORWARD__LIST__H
#define FORWARD__LIST__H


#include<iostream>
#include<initializer_list>
template<typename T>
class Forward_list{
	private:
		struct Node{
			T val{};
			Node* next{};
			Node(T& val)
				:val{val}
				,next{nullptr}
				{}
		};
		Node* head{};
		size_t f_size{};

	public:
		using value_type = T;
		using size_type = size_t;
		using reference = value_type&;
	        using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

	public:
		Forward_list();
		Forward_list(std::initializer_list<T>);
		Forward_list(const Forward_list<T>&);
		Forward_list(Forward_list<T>&& rhv);
	
	public:
		~Forward_list();
	
	public:
		const Forward_list<T>& operator=(const Forward_list<T>&);
		const Forward_list<T>& operator=(Forward_list<T>&&);
		T& operator[](size_t index);


	public:
		void push_back(const T&);
		void pop_back();
		void clear();
		bool empty();
		void erase(size_t index);
		size_t size();
		void insert(size_t, const T&);
		void print();
		void push_front(const T&);
		void pop_front();
		T& front();
};


#endif

