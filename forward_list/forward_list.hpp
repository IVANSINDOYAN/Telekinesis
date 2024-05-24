#include<iostream>
#include"forward_list.h"

//constructors
template<typename T>
	Forward_list<T>::Forward_list()
		:Node{}
		,head{nullptr}
		,f_size{}
		{}

template<typename T>
	Forward_list<T>::Forward_list(const Forward_list<T>& rhv)
		:Forward_list()
		{
			if(rhv.head == nullptr){
				return;
			}else{
				Node* tptr = rhv.head;
				while(tptr){
					this->push_back(tptr->data);
					tptr = rhv.next;
			
				}
			}
		}


template<typename T>
	Forward_list<T>::Forward_list(std::initializer_list<T> init)
		:Forward_list()
		{
			for(const_reference i : init){
				this->push_back(i);
			}
		}

//??
template<typename T>
	Forward_list<T>::Forward_list(Forward_list<T>&& rhv){
		this->head = rhv.head;
		rhv.head = nullptr;
	}

//destructor
template<typename T>
	Forward_list<T>::~Forward_list(){
		this->clear();
	}




//assignments
template<typename T>
	const Forward_list<T>&
	Forward_list<T>::operator=(const Forward_list<T>& rhv){
		if(this == &rhv){
			return rhv;
		}
		this->clear();
		Node* tptr = rhv.head;
		while(tptr){
			this.push_back(tptr.data);
			tptr = tptr->next;
		}
		return *this;



	}

template<typename T>
	const Forward_list<T>&
	Forward_list<T>::operator=(Forward_list<T>&& rhv){
		if(this == &rhv){
			return *this;
		}
		this->clear();
		this->head = rhv.head;
		this->f_size = rhv.f_size;
	        this->val = rhv.val;
		this->next = rhv.next;	
		rhv.head = nullptr;
		rhv.next = nullptr;
		return *this;

	}

/*
template<typename T>
typename Forward_list<T>::reference operator[](size_t index){
	if(index >= f_size){
		throw std::exception(1);
	}
	Node* tptr = this->head;
	for(size_t i = 0; i <= index; ++i){
		tptr = tptr->next;
	}
	return tptr.val;

}

*/

//member methods
template<typename T>
	void
	Forward_list<T>::push_back(const_reference val){
			Node* newnode = new Node(val);
			if(this->head == nullptr){
				this->head = newnode;
			        ++this->f_size;	
				return;
			}
			Node *tptr = this->next;
			while(tptr){
				tptr = tptr->next;
			}
			tptr->next = newnode;
			tptr->next->next = nullptr;
			tptr = nullptr;
			++f_size;
	}


template<typename T>
	void
	Forward_list<T>::pop_back(){
		if(this->head->next == nullptr){
			this->clear();
			this->head = nullptr;
		}
		Node* tptr = this->head;
		while(tptr->next->next != nullptr){
			tptr = tptr->next;
		}
		delete tptr->next;
		tptr->next = nullptr;
		tptr = nullptr;
		--this->f_size;
	}

template<typename T>
	void
	Forward_list<T>::clear(){
		if(this->head && this->head->next == nullptr){
			delete this->head;
			this->head = nullptr;
		}
			Node* tptr = this->head;
			while(tptr){
				delete tptr;
				tptr = tptr->next;
			}
			this->head = nullptr; 

	}

template<typename T>
	bool
	Forward_list<T>::empty(){
		return this->f_size == 0;
	}


template<typename T>
	void
	Forward_list<T>::erase(size_t index){
		if(index >= f_size){
			throw std::out_of_range();
		}
		if(index == 0){
			delete this->head;
			this->head = this->next;
			--this->f_size;
			return;
		}
		Node* tptr = this->head;
		for(int i = 0; i <= index - 1; ++i){
			tptr = tptr->next;
		}
		Node* indexptr = tptr->next;
		delete tptr;
		tptr = indexptr;
		--f_size;

	}


template<typename T>
	typename Forward_list<T>::size_type
	Forward_list<T>::size(){
		return this->f_size;
	}

template<typename T>
	void
	Forward_list<T>::insert(size_type index, const_reference val){
		if(index >= f_size){
			throw std::out_of_range();
		}
		if(this-> head == nullptr){
			this->push_back(val);
			return;
		}
		Node *tptr = this->head;
		for(int i = 0; i < index; ++i){
			tptr = tptr->next;
		}
		if(tptr->next == nullptr){
			this->push_back(val);
		}
		Node* tempptr = tptr->next->next;
		tptr->next = new Node(val);
		tptr->next->next = tempptr;
		tptr = nullptr;
		tempptr = nullptr;
	}

template<typename T>
	void
	Forward_list<T>::print(){
		Node* tptr = this->head;
		while(tptr){
			std::cout<< tptr->val << " ";
			tptr = tptr->next;
		}
		tptr = nullptr;
	}

template<typename T>
	void
	Forward_list<T>::push_front(const_reference val){
		Node* tptr = this->head;
		this->head = new Node(val);
		this->head->next = tptr;
		tptr = nullptr;
	}

template<typename T>
	void
	Forward_list<T>::pop_front(){
		if(this->head == nullptr){
			throw std::exception();
		}
		if(this->head->next == nullptr){
			delete this->head;
			this->head = nullptr;
		}
		if(this->next){
			Node* tptr = this->head->next;
			this->next = nullptr;
			delete this->head;
			this->head = tptr;
		}
	}

template<typename T>
	typename Forward_list<T>::reference
	Forward_list<T>::front(){
		if(this->head == nullptr){
			throw std:: exception();
		}
		return head->val;
	}
