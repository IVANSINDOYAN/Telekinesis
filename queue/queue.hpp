#include<iostream>
#include"queue.h"


//constructors
template<typename T, typename container >
	queue<T, container>::queue()
		:ob()
		{}

template<typename T, typename container>
	queue<T, container>::queue(const queue<T, container>& rhv)
		:ob{rhv.ob}
		{}



template<typename T, typename container>
	queue<T, container>::queue(queue<T, container>&& rhv)
		{
			if(this != &rhv){
			ob.clear();
			ob = rhv.ob;
			rhv.ob = nullptr;		
			}
	
		}




template<typename T, typename container>
	queue<T, container>::queue(std::initializer_list<T> init){
		for(const_reference i: init){
			ob.push(i);
		}
	}






//destructor
template<typename T, typename container>
	queue<T, container>::~queue()
		{
			~ob();
		}





// member methods
template<typename T, typename container>
	void
	queue<T, container>::push(const_reference val)
		{
			ob.push_back(val);
		}



template<typename T, typename container>
	const queue<T, container>&
	queue<T, container>::operator=(const queue<T, container>& rhv){
		if(this != &rhv){
			ob.clear();
			ob(rhv.ob);
		}
		return *this;
	}


template<typename T, typename container>
	const queue<T, container>& 
	queue<T, container>::operator=(queue<T, container>&& rhv){
	if(this != &rhv){
		ob.clear();
		ob(rhv.ob);
	}
	return *this;
}


template<typename T, typename container>
	typename queue<T, container>::reference
	queue<T, container>::operator[](size_type index){
		return ob[index];
	}


template<typename T, typename container>
	bool
	queue<T, container>::empty(){
		return ob.empty();
	}

template<typename T, typename container>
	typename queue<T, container>::size_type 
	queue<T, container>::size(){
		return ob.size();
	}

template<typename T, typename container>
	typename queue<T, container>::reference
	queue<T, container>::front(){
		return ob.front();
	}

template<typename T, typename container>
	typename queue<T, container>::reference 
	queue<T, container>::back(){
		return ob.back();
	}

template<typename T,typename container>
	void
	queue<T, container>::swap(queue<T, container>& rhv) noexcept{
		std::swap(ob, rhv.ob);
	}

template<typename T, typename container>
	void
	queue<T, container>:: pop(){
		ob.pop_front();
	}





/*
//global comparison functions
template<typename T, typename container>
	bool
	::operator==(const queue<T, container>& lhv, const queue<T, container>& rhv){
		return lhv.size() == rhv.size();
	}

template<typename T, typename container>
	bool
	::operator!=(const queue<T, container>& lhv, const queue<T, container>& rhv){
		return lhv.size() != rhv.size();
	}

template<typename T, typename container>
        bool
        ::operator>(const queue<T, container>& lhv, const queue<T, container>& rhv){
                return lhv.size() > rhv.size();
        }

template<typename T, typename container>
        bool
        ::operator<(const queue<T, container>& lhv, const queue<T, container>& rhv){
                return lhv.size() < rhv.size();
        }

template<typename T, typename container>
        bool
        ::operator>=(const queue<T, container>& lhv, const queue<T, container>& rhv){
                return lhv.size() >= rhv.size();
        }

template<typename T, typename container>
        bool
        ::operator<=(const queue<T, container>& lhv, const queue<T, container>& rhv){
                return lhv.size() <= rhv.size();
        }
*/
