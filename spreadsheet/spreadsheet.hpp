#include"spreadsheet.h"
#include<iostream>

//constructors
spreadsheet::spreadsheet()
	:ob{}
	,row_size{}
	,col_size{}
	{}


spreadsheet::spreadsheet(int size)
	:ob{}
	,row_size{size}
	,col_size{size}
	{
		ob = new cell*[size];
		for(int i = 0; i < size; ++i){
			ob[i] = new cell[size];
		}

	}


spreadsheet::spreadsheet(int row, int col)
	:ob{}
	,row_size{row}
	,col_size{col}
	{
		ob = new cell*[row];
		for(int i = 0; i < row; ++i){
			ob[i] = new cell[col];
		}
	}


spreadsheet::spreadsheet(const spreadsheet& rhv)
	:spreadsheet(rhv.row_size, rhv.col_size)
	{
		for(int i = 0; i < rhv.row_size; ++i){
			for(int j = 0; j < rhv.col_size; ++j){
				this->ob[i][j] = rhv.ob[i][j];
			}
		}
	}

spreadsheet::spreadsheet(spreadsheet&& rhv)
	:ob{rhv.ob}
	,row_size{rhv.row_size}
	,col_size{rhv.col_size}
	{
		rhv.ob = nullptr;
		rhv.row_size = 0;
		rhv.col_size = 0;
	}


//destructor
spreadsheet::~spreadsheet(){
	for(int i = 0; i < this->row_size; ++i){
		delete []ob[i];
		ob[i] = nullptr;
	}
	delete ob;
	ob = nullptr;
}


//assignment operations
const spreadsheet& 
spreadsheet::operator=(const spreadsheet& rhv){
	if(this != &rhv){
		this->clear();
		this->row_size = rhv.row_size;
		this->col_size = rhv.col_size;

		this->ob = new cell*[row_size];
		for(int i = 0; i < this->row_size; ++i){
			this->ob[i] = new cell[col_size];
		}

		for(int i = 0; i < row_size; ++i){
			for(int j = 0; j < col_size; ++j){
				this->ob[i][j] = rhv.ob[i][j];
			}
		}
		
	}
	return *this;
}


const spreadsheet&
spreadsheet::operator=(spreadsheet&& rhv){
	if(this != &rhv){
		this->clear();
		this->ob = rhv.ob;
		this->row_size = rhv.row_size;
		this->col_size = rhv.col_size;
		for(int i = 0; i < rhv.row_size; ++i){
			rhv.ob[i] = nullptr;
		}
		rhv.ob = nullptr;
		rhv.row_size = 0;
		rhv.col_size = 0;
	}
	return *this;
}


spreadsheet::column
spreadsheet::operator[](size_t index){
	if(index>= row_size){
		throw std::exception();
	}
	return static_cast<spreadsheet::column>(this->ob[index]);
}


/*const spreadsheet::column
spreadsheet::operator[](size_t index) const{
	if(index >= row_size){
		throw std::exception();
	}
	return column(this->ob[index]);
}
*/

//member methods
void spreadsheet::clear(){
	for(size_t i = 0; i < this->row_size; ++i){
		delete[]this->ob[i];
	}
	this->row_size = 0;
	this->col_size = 0;
	this->ob = nullptr;
}


void spreadsheet::print(){
	for(size_t i = 0; i < this->row_size; ++i){
		for(size_t j = 0; j < this->col_size; ++j){
			std::cout << this->ob[i][j] <<' ';
		}
		std::cout << std::endl;
	}
}



void spreadsheet::delete_row(size_t index){
	if(index >= this->col_size ){
		throw std::exception();
	}
	for(size_t i = 0; i < this->row_size; ++i){
		for(size_t j = index; j < this->col_size - 1; ++j){
			this->ob[i][j] = this->ob[i][j + 1];
		}
		
	}
}

void spreadsheet::delete_col(size_t index){
	if(index >= this->row_size){
		throw std::exception();
	}
	for(int j = index; j < this->row_size - 1; ++j){
		for(size_t i = 0; i < this->col_size; ++i){
			this->ob[j][i] = this->ob[j + 1][i];
		}
	}
	delete this->ob[row_size];
	--this->row_size;
}


void spreadsheet::delete_rows(std::initializer_list<size_t> init){
	for(size_t i : init){
		this->delete_row(i);
	}
}


void spreadsheet::delete_cols(std::initializer_list<size_t> init){
	for(size_t i : init){
                this->delete_col(i);
        }

}





size_t spreadsheet::row(){
	return this->row_size;
}


size_t spreadsheet::col(){
	return this->col_size;
}




void spreadsheet::resize_row(int i){
	int k = i < 0 ? -i : i;
	if(k > this->col_size && i < 0){
		throw std::exception();
	}
	*this = spreadsheet(this->row_size, k);
}


void spreadsheet::resize_col(int i){
	int k = i < 0 ? -i : i;
	if(k > row_size && i < 0){
		throw std::exception();
	}
	*this = spreadsheet(k, this->col_size);
}

void spreadsheet::resize(int r, int c){
	int tmpr = r < 0 ? -r : r;
	int tmpc = c < 0 ? -c : c;
	if((tmpr > this-> row_size && r < 0) || (tmpc > this-> col_size && c < 0)){
		throw std::exception();
	}
	*this = spreadsheet(tmpr, tmpc);
}
