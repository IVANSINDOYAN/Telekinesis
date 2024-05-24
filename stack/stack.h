#ifndef __STACK__
#define __STACK__

#include<iostream>
#include<initializer_list>
#include<vector>
template<typename T, typename container = std::vector<T>>
	class Stack{
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
			 Stack();
			 Stack(const Stack&);
			 Stack(Stack&&);
			 Stack(std::initializer_list<T>);

		public:
			 ~Stack();
		
		public:
			 const Stack<T, container>& operator=(Stack<T, container>&);
			 const Stack<T, container>& operator=(Stack<T, container>&&);
			 
		public:
			 bool empty();
			 size_t size();
			 void push(const T&);
			 T& pop();
			 T& top();
			 void swap(Stack<T, container>&);


	};

#endif


//global comparison functions
template<typename T, typename container>
        bool
        operator==(const Stack<T, container>& lhv, const Stack<T, container>& rhv);

template<typename T, typename container>
        bool
        operator!=(const Stack<T, container>& lhv, const Stack<T, container>& rhv);

template<typename T, typename container>
        bool
        operator>(const Stack<T, container>& lhv, const Stack<T, container>& rhv);

template<typename T, typename container>
        bool
        operator<(const Stack<T, container>& lhv, const Stack<T, container>& rhv);

template<typename T, typename container>
        bool
        operator>=(const Stack<T, container>& lhv, const Stack<T, container>& rhv);

template<typename T, typename container>
        bool
        operator<=(const Stack<T, container>& lhv, const Stack<T, container>& rhv);






