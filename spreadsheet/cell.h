#ifndef __CELLCHLP__
#define __CELLCHLP__

#include <iostream>
#include <cstring>
class cell{
	private:
		std::string storage{};

	public:
		cell();
		cell(std::string);
		cell(int);
		cell(double);
		cell(cell&& rhv);
		cell(cell& rhv);


	public:
		~cell();
	
	public:
		operator int();
		operator double();
		operator std::string();

	public:
		const cell& operator=(cell&& rhv);
		const cell& operator=(cell& rhv);
	
	public:
		void print();
		friend std::ostream& operator<<(std::ostream&, const cell&);
		friend std::istream& operator>>(std::istream&,  cell&);
};

std::ostream& operator<<(std::ostream& out, const cell& c){
	out << c.storage;
	return out;
}

std::istream& operator>>(std::istream& cin, cell& c){
	cin >> c.storage;
	return cin;
	
}


#endif
