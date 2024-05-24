#ifndef __SPREADSHEET__
#define __SPREADSHEET__
#include<iostream>
#include"cell.hpp"
class spreadsheet{
	private:
		cell** ob{};
		int row_size{};
		int col_size{};

	private:
		class column;
	public:
		spreadsheet();
		spreadsheet(int);
		spreadsheet(int, int);
		spreadsheet(const spreadsheet&);
		spreadsheet(spreadsheet&&);

	public:
		~spreadsheet();


	public:
		const spreadsheet& operator=(const spreadsheet&);
		const spreadsheet& operator=(spreadsheet&& rhv);
		column operator[](size_t);
		const column operator[](size_t) const;

	public:
		void clear();
		void print();
		void delete_row(size_t);
		void delete_col(size_t);
		void delete_rows(std::initializer_list<size_t>);
		void delete_cols(std::initializer_list<size_t>);
		
	public:
		size_t row();
		size_t col();


	public:
		void resize_row(int);
		void resize_col(int);
		void resize(int, int);
};

class spreadsheet::column{
	private:
		cell* col{};
	public:
		column() = delete;

	public:
		column(cell* col)
			:col{col}
			{}

	public:
		const column& operator=(const column&) = delete;
		const column& operator=(column&&) = delete;

	public:
		cell& operator[](size_t index){
			return this->col[index];
		}
		
		
		const cell& operator[](size_t index) const{
			return this->col[index];
		}
};
#endif
