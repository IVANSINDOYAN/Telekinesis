#include<iostream>
#include"stack.h"
//constructors
template<typename T, typename container>
	Stack<T, container>::Stack()
	:ob()
	{}

template<typename T, typename container>
	Stack<T, container>::Stack(const Stack<T, container>& rhv)
		:ob(rhv.ob)
		{}

template<typename T, typename container>
	Stack<T, container>::Stack(Stack<T, container>&& rhv){
		if(!(ob.empty)){ob.clear();};
		ob = rhv.ob;
		rhv.ob = nullptr;
	}

template<typename T, typename container>
	Stack<T, container>::Stack(std::initializer_list<T> init){
		for(const_reference i : init){
			ob.push_back(i);
		}
	}

//destructor
template<typename T, typename container>
	Stack<T, container>::~Stack(){
		~ob();
	}
		
//assignments
template<typename T, typename container>
	const Stack<T, container>&
	Stack<T, container>::operator=(Stack<T, container>& rhv){
			if(this != &rhv){
				this->ob.clear();
				this->ob = rhv.ob;
				rhv.ob = nullptr;

			}
			return *this;
		}

template<typename T, typename container>
	const Stack<T, container>&
	Stack<T, container>:: operator=(Stack<T, container>&& rhv){
		if(this !=&rhv){
			this->ob.clear();
			this->ob = rhv.ob;
			rhv.ob = nullptr;
		}
		return *this;
	
	}

//member methods
template<typename T, typename container>
	bool
	Stack<T, container>::empty(){
		return this->ob.empty();
	}


template<typename T, typename container>
	typename Stack<T, container>::size_type
	Stack<T, container>::size(){
		return this->ob.size();
	}

template<typename T, typename container>
	void
	Stack<T, container>::push(const_reference val){
		this->ob.push_back(val);
	}

template<typename T, typename container>
	typename Stack<T, container>::reference 
	Stack<T, container>::pop(){
		this->ob.pop_back();
	}

template<typename T, typename container>
	typename Stack<T, container>::reference
	Stack<T, container>::top(){
		return this->ob.back();
	}

template<typename T, typename container>
	void
	Stack<T, container>::swap(Stack<T, container>& other){
		std::swap(*this, other);
	}



//global comparison functions
template<typename T, typename container>
        bool
        ::operator==(const Stack<T, container>& lhv, const Stack<T, container>& rhv){
                return lhv.size() == rhv.size();
        }

template<typename T, typename container>
        bool
        ::operator!=(const Stack<T, container>& lhv, const Stack<T, container>& rhv){
                return lhv.size() != rhv.size();
        }

template<typename T, typename container>
        bool
        ::operator>(const Stack<T, container>& lhv, const Stack<T, container>& rhv){
                return lhv.size() > rhv.size();
        }

template<typename T, typename container>
        bool
        ::operator<(const Stack<T, container>& lhv, const Stack<T, container>& rhv){
                return lhv.size() < rhv.size();
        }

template<typename T, typename container>
        bool
        ::operator>=(const Stack<T, container>& lhv, const Stack<T, container>& rhv){
                return lhv.size() >= rhv.size();
        }

template<typename T, typename container>
        bool
        ::operator<=(const Stack<T, container>& lhv, const Stack<T, container>& rhv){
                return lhv.size() <= rhv.size();
        }






