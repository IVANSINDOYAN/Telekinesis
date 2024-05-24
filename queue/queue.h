#ifndef __QUEUE__
#define __QUEUE__

#include<iostream>
#include<vector>
#include<initializer_list>

template<typename T, typename container = std::vector<T>>
class queue{
	private:
		container ob;

	public:
		using value_type = T;
		using size_type = size_t;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;

	public:
		queue();
		queue(const queue<T, container>&);
		queue(queue<T, container>&&);
		queue(std::initializer_list<T>);

	public:
		~queue();

	public:
		void push(const T&);
		const queue<T, container>& operator=(const queue<T, container>&);
		const queue<T, container>& operator=(queue<T, container>&&);
		T& operator[](size_t index);
		bool empty();
		size_t size();
		T& front();
		T& back();
		void swap(queue<T, container>& rhv) noexcept;
		void pop();


	
};


//global functions 
template<typename T, typename container >
	bool
	operator==(const queue<T, container>&, const queue<T, container>&);


template<typename T, typename container>
	bool
	operator!=(const queue<T, container>& lhv, const queue<T, container>& rhv);


template<typename T, typename container>
	bool
	operator>(const queue<T, container>&, const queue<T, container>&);


template<typename T, typename container>
	bool
	operator<(const queue<T, container>&, const queue<T, container>&);


template<typename T, typename container>
	bool
	operator>=(const queue<T, container>&, const queue<T, container>&);


template<typename T, typename container>
        bool
        operator<=(const queue<T, container>&, const queue<T, container>&);
#endif
