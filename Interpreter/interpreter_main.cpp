#include<iostream>
#include<fstream>
#include<sstream>
#include<istream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<string>

namespace checktypes{// checking the types of fundamental objects
	                bool isint(std::string str){
                        if(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')){
				if(str.size() == 1 && str[0] >= '0' && str[0] <= '9'){
                                        return true;
                                }
                                else if(str.size() == 1 && (str[0] < '0' || str[0] > '9')){
                                        return false;
                                }

                                int i = 0;
                                for(i = 1; i < str.size(); ++i){
                                        if(str[i] >= '0' && str[i] <= '9'){
                                                continue;
                                        }
                                        return false;
                                }

                                return true;
                        }
			return false;
                }


                /*bool isdouble(std::string str){
                        if((str.size() <= 3 && str[0] < '0' || str[0] > '9')){
                                return false;
                        }

                        if(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')){
                                if(str[0] == '+' || str[0] == '-' && (str[1] < '0' || str[1] > '9')){
                                                return false;
                                }
                                int dotcount = 0;
                                        for(int i = 1; i < str.size(); ++i){
                                                if((str[i] >= '0' && str[i] <= '9') || str[i] == '.'){
                                                        if(str[i] == '.'){
                                                                ++dotcount;
                                                                if(dotcount > 1){
                                                                        return false;
                                                                }
                                                        }
                                                        continue;
                                                }
                                                return false;
                                        }
                                        return true;

                        }
			return false;
                }*/



		bool isdouble(std::string str){
			if(str.size() == 1 && (str[0] < '0' || str[0] > '9')){
				return false;
			}
			if(str[0] != '+' && str[0] != '-' && (str[0] < '0' || str[0] > '9')){
				return false;
			}

			if((str[0] == '+' || str[0] == '-') && str[1] == '.'){
                                return false;
                        }

			int dotcount = 0;
			for(int i = 1; (i != '\0' && i < str.size()); ++i){
				if(str[i] == '.'){
					++dotcount;
					if(dotcount > 1){
						return false;
					}
					continue;

				}
				if(str[i] < '0' || str[i] > '9'){
					return false;
				}
			}
		       if(str[str.size() - 1] == '.'){
		       	return false;
		       }	
			return true;
		}




                bool isbool(std::string str){
                        if(str == "tru" || str == "fols"){
                                return true;
                        }
                        return false;
                }




                bool isstring(std::string str){
                        if(str.front() == '"' && str.back() == '"'){
                                return true;
                        }
                        return false;
                }



                bool isarray(std::string str){
                        if(str.front() == '{' && str.back() == '}'){
                                int strbracecount = 0;
                                for(int i = 1; i < str.size() - 1; ++i){
                                        if(str[i] == '"'){
                                                ++strbracecount;
                                        }
                                }
                                if(strbracecount == 0 || strbracecount % 2){
                                        return false;
                                }
                                return true;
                        }
                        return false;
                }


		/*double retdouble(std::string str){
			std::string resultstr = {""};
			if(str[0] != '+' && str[0] != '-' && (str[0] < '0' || str[0] > '9')){
                                throw std::invalid_argument("Not a valid input for dabl");
                        }

			if((str[0] == '+' || str[0] == '-') && str[1] == '.'){
				throw std::invalid_argument("Not a valid input for dabl");
			}

                        int dotcount = 0;
			int i = 0;
			if(str[i] == '+'){
				++i;
			}
                        for( ; (i != '\0' && i < str.size()); ++i){
                                if(str[i] == '.'){
                                        ++dotcount;
                                        if(dotcount > 1){
                                                return false;
                                        }
                                        continue;

                                }
                                if(str[i] < '0' || str[i] > '9'){
                                        return false;
                                }
                        }
                        
			if(str[str.size() - 1] == '.'){
                        	return false;
                        }
                        
			return true;
                	

		}*/




		double retdouble(std::string str){
                        std::string resultstr = {""};
                        if(str[0] != '+' && str[0] != '-' && (str[0] < '0' || str[0] > '9')){
                                throw std::invalid_argument("Not a valid input for dabl");
                        }

                        if((str[0] == '+' || str[0] == '-') && str[1] == '.'){
                                throw std::invalid_argument("Not a valid input for dabl");
                        }

                        int dotcount = 0;
                        int i = 0;
                        if(str[i] == '+'){
                                ++i;
                        }
                        for( ; (i != '\0' && i < str.size()); ++i){
                                if(str[i] == '.'){
                                        ++dotcount;
                                        if(dotcount > 1){
                                                throw std::invalid_argument("Not a valid input for dabl");
                                        }
                                        continue;

                                }
                                if(str[i] < '0' || str[i] > '9'){
                                        throw std::invalid_argument("Not a valid input for dabl");
                                }
                        }

                        if(str[str.size() - 1] == '.'){
                                throw std::invalid_argument("Not a valid input for dabl");
                        }

                        return stod(str);


                }


}

class interpreter;

class object{
	public:
		std::string name{};
		void* value{};
		int count{};

	public:
		object(std::string n, void* v, int c)
			:name{n}
			,value{v}
			,count{c}
			{}

	
	public:
		virtual ~object(){
			this->name = {""};
			this->count = 0;
			this->value = nullptr;
		}
	
	
	
	public:
		virtual void Delete(){
			this->~object();
		}
		
		virtual std::string __str__(){
			return "object";
		}

		
		
		virtual object* __add__(object*){
			throw std::invalid_argument("Not possible to add the given types");
		}

		
		
		virtual object* __sub__(object*){
			throw std::invalid_argument("Not possible to subtract the given types");
		}

		
		
		virtual object* __mul__(object*){
			throw std::invalid_argument("Not possible to multiply the given types");
		}


		virtual object* __div__(object*){
			throw std::invalid_argument("Not possible to divide the given types");
		}

		virtual object* __call__(){
			throw std::invalid_argument("Call operator is not defined for the given type");
		}


};


class INT : public object{
	public:
		INT()
		:object("iint", new int(0), 0)
		{std::cout <<"int ctor";}

		INT(object* optr)
			:INT()
			{
				if(optr->name == "iint"){
					*(int*)this->value = *(int*)optr->value;
				}

				else if(optr->name == "dabl"){
					*(int*)this->value = *(double*)optr->value;
				}

				else if(optr->name == "bul"){
					*(int*)this->value = *(bool*)optr->value;
				}

				else if(optr->name == "istring"){
					std::string str = *(std::string*)optr->value;
					for(int i = 0; i < str.size(); ++i){
						if(str[i] >= '0' && str[i] <= '9' || str[0] == '+' || str[0] == '-'){
								continue;
						}
						else{
							throw std::invalid_argument("Not possible to convert to iint");
						}
						*(int*)this->value = stoi(str);
					}
				}
			}


		INT(std::string v)
			:INT()
			{	
				*(int*)this->value = stoi(v);
			}
	
	
	public:
		~INT(){
			this->name = {""};
			delete static_cast<int*>(this->value);
			this->count = 0;
			this->value = nullptr;
			std::cout << "int dtor";
		}




	public:
		void Delete(){
                        this->~INT();
                }

		
		std::string __str__(){
			return std::to_string(*(static_cast<int*>(this->value)));
		}

		
		object* __add__(object* rptr){
			if(rptr->name == "iint"){
				return new INT(new object("iint", new int((*(int*)this->value) + (*(int*)rptr->value)), 0));
			}

			else if(rptr->name == "dabl"){
                                return new INT(new object("iint", new int((*(int*)this->value) + (*(double*)rptr->value)), 0));
                        }

			else if(rptr->name == "bul"){
                                return new INT(new object("iint", new int((*(int*)this->value) + (*(bool*)rptr->value)), 0));
                        }

			else{
				throw std::invalid_argument("Not possible to add to type iint");
			}


		}


		
		
		object* __sub__(object* rptr){
			if(rptr->name == "iint"){
				return new INT(new object("iint", new int(*(static_cast<int*>(this->value)) 
				- (*(static_cast<int*>(rptr->value)))), 0));
			}

			else if(rptr->name == "dabl"){
				return new INT(new object("iint", new int(*(static_cast<int*>(this->value))
                                - (*(static_cast<double*>(rptr->value)))), 0));

			}

			else if(rptr->name == "bul"){
				return new INT(new object("iint", new int(*(static_cast<int*>(this->value))
                                - (*(static_cast<bool*>(rptr->value)))), 0));

			}

			else{ throw std::invalid_argument("Not possible to subtract the given types");}
		}



		object* __mul__(object* rptr){
			if(rptr->name == "iint"){
				return new INT(new object("iint", new int((*(static_cast<int*>(this->value)))
				* (*(static_cast<int*>(rptr->value)))), 0));
			}

			else if(rptr->name == "dabl"){
				return new INT(new object("iint", new int((*(static_cast<int*>(this->value)))
                                * (*(static_cast<double*>(rptr->value)))), 0));
			}

			else if(rptr->name == "bul"){
				return new INT(new object("iint", new int((*(static_cast<int*>(this->value)))
                                * (*(static_cast<bool*>(rptr->value)))), 0));
			}

			else{ throw std::invalid_argument("Not possible to multiply the given types"); }
		}



		object* __div__(object* rptr){
			if(rptr->name == "iint"){
				return new INT(new object("iint", new int((*(static_cast<int*>(this->value)))
                                / (*(static_cast<int*>(rptr->value)))), 0));
			}

			else if(rptr->name == "dabl"){
                                return new INT(new object("iint", new int((*(static_cast<int*>(this->value)))
                                / (*(static_cast<double*>(rptr->value)))), 0));
                        }

                        else if(rptr->name == "bul"){
                                return new INT(new object("iint", new int((*(static_cast<int*>(this->value)))
                                / (*(static_cast<bool*>(rptr->value)))), 0));
                        }

                        else{ throw std::invalid_argument("Not possible to divide the given types"); }
                
		}

};



class DOUBLE : public object{
	public:
		DOUBLE()
			:object("dabl", new double(0.0), 0)
			{std::cout << "double ctor";}


		DOUBLE(object* optr)
			:DOUBLE()
			{
				if(optr->name == "dabl"){
					*(double*)this->value = *(double*)optr->value;
				}

				else if(optr->name == "iint"){
					*(double*)this->value = *(int*)optr->value;
				}

				else if(optr->name == "bul"){
					*(double*)this->value = *(bool*)optr->value;
				}

				else if(optr->name == "istring"){
					std::string str = *(std::string*)optr->value;
					int dotcount = 0;
                                        for(int i = 0; i < str.size(); ++i){
                                                if(str[i] >= '0' && str[i] <= '9' || str[i] == '.' || str[0] == '+' || str[0] == '-'){
                                                        if(str[i] == '.'){
								++dotcount;
								if(dotcount > 1){
									throw std::invalid_argument("2 or more dots in a decimal number");
								}
							}        
							continue;
                                                }
                                                else{
                                                        throw std::invalid_argument("Not possible to convert the given istring to dabl");
                                                }

                                                *(int*)this->value = stod(str);
                                        }

				}
			}




		DOUBLE(std::string v)
                        :DOUBLE()
                        {
                                *(double*)this->value = stod(v);
                        }
	



	public:
                ~DOUBLE(){
                        this->name = {""};
                        delete static_cast<double*>(this->value);
                        this->count = 0;
                        this->value = nullptr;
			std::cout <<"double dtor";
                }





	public:	
		void  Delete(){
                        this->~DOUBLE();
                }

		
		std::string __str__(){
			return std::to_string(*(double*)this->value);
		}
		

		
		
		object* __add__(object* rptr){
			if(rptr->name == "dabl"){
				return new DOUBLE(new object("dabl", new double((*(double*)this->value) + (*(double*)rptr->value)), 0));
			}

			else if(rptr->name == "iint"){
                                return new DOUBLE(new object("dabl", new double((*(double*)this->value) + (*(int*)rptr->value)), 0));
                        }

			else if(rptr->name == "bul"){
                                return new DOUBLE(new object("dabl", new double((*(double*)this->value) + (*(bool*)rptr->value)), 0));
                        }

			else{
				throw std::invalid_argument("Not possible to add to type dabl");
			}


		}


		
		object* __sub__(object* rptr){
			if(rptr->name == "dabl"){
				return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
				- (*(static_cast<double*>(rptr->value)))), 0));
			}

			else if(rptr->name == "iint"){
				return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
                                - (*(static_cast<int*>(rptr->value)))), 0));

			}

			else if(rptr->name == "bul"){
				return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
                                - (*(static_cast<bool*>(rptr->value)))), 0));

			}

			else{ throw std::invalid_argument("Not possible to subtract the given types"); }
		}



		object* __mul__(object* rptr){
			if(rptr->name == "dabl"){
				return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
                                * (*(static_cast<double*>(rptr->value)))), 0));
			}

			else if(rptr->name == "iint"){
				return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
                                * (*(static_cast<int*>(rptr->value)))), 0));

			}

			else if(rptr->name == "bul"){
				return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
                                * (*(static_cast<bool*>(rptr->value)))), 0));

			}

			else{ throw std::invalid_argument("Not possible to multiply the given types"); }
		}



		object* __div__(object* rptr){
                        if(rptr->name == "dabl"){
                                return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
                                / (*(static_cast<double*>(rptr->value)))), 0));
                        }

                        else if(rptr->name == "iint"){
                                return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
                                / (*(static_cast<int*>(rptr->value)))), 0));

                        }

                        else if(rptr->name == "bul"){
                                return new DOUBLE(new object("dabl", new double((*(static_cast<double*>(this->value)))
                                / (*(static_cast<bool*>(rptr->value)))), 0));

                        }

                        else{ throw std::invalid_argument("Not possible to divide the given types"); }
                }
	

};



class BOOL : public object{
	public:
		BOOL()
		:object("bul", new bool(0), 0)
		{}


		BOOL(object* optr)
			:BOOL()
			{
				if(optr->name == "bul"){
					*(bool*)this->value = *(bool*)optr->value;
				}

				else if(optr->name == "iint"){
					*(bool*)this->value = *(int*)optr->value;

				}

				else if(optr->name == "dabl"){
					*(bool*)this->value = *(double*)optr->value;

				}

				else if(optr->name == "istring"){
					*(bool*)this->value = !(((std::string*)optr->value)->empty());
				}

			}



		BOOL(std::string str)
			:BOOL()
			{
				bool flag;
				if(str == "tru"){
					flag = true;
				}
				else if(str == "fols"){
					flag = false;
				}
				*(static_cast<bool*>(this->value)) = flag;
			}


	
	
	public:
                ~BOOL(){
                        this->name = {""};
                        delete static_cast<bool*>(this->value);
                        this->count = 0;
                        this->value = nullptr;
                }

	
	
	
	public:
		void Delete(){
                        this->~BOOL();
                }


		std::string __str__(){
			return std::to_string(*(bool*)this->value);
		}



		object* __add__(object* rptr){
                        if(rptr->name == "bul"){
                                return new BOOL(new object("bul", new bool((*(bool*)this->value) + (*(bool*)rptr->value)), 0));
                        }

                        else if(rptr->name == "iint"){
                                return new BOOL(new object("bul", new bool((*(bool*)this->value) + (*(int*)rptr->value)), 0));
                        }

                        else if(rptr->name == "dabl"){
                                return new BOOL(new object("bul", new bool((*(bool*)this->value) + (*(double*)rptr->value)), 0));
                        }

                        else{
                                throw std::invalid_argument("Not possible to add to type bul");
                        }


                }



		object* __sub__(object* rptr){
			if(rptr->name == "bul"){
				return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value))) 
				- (*(static_cast<bool*>(rptr->value)))) , 0));
			}

			else if(rptr->name == "iint"){
				return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value)))
                                - (*(static_cast<int*>(rptr->value)))) , 0));
			}

			else if(rptr->name == "dabl"){
				return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value)))
                                - (*(static_cast<double*>(rptr->value)))) , 0));

			}

			else{ throw std::invalid_argument("Not possible to subtract the given types"); }


		}



		object* __mul__(object* rptr){
			if(rptr->name == "bul"){
				return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value)))
                                * (*(static_cast<bool*>(rptr->value)))), 0));
			}

			else if(rptr->name == "iint"){
				return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value)))
                                * (*(static_cast<int*>(rptr->value)))), 0));
			}

			else if(rptr->name == "dabl"){
				return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value)))
                                * (*(static_cast<double*>(rptr->value)))), 0));
			}

			else{ throw std::invalid_argument("Not possible to multiply the given types"); }
		}



		object* __div__(object* rptr){
                        if(rptr->name == "bul"){
                                return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value)))
                                / (*(static_cast<bool*>(rptr->value)))), 0));
                        }

                        else if(rptr->name == "iint"){
                                return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value)))
                                / (*(static_cast<int*>(rptr->value)))), 0));
                        }

                        else if(rptr->name == "dabl"){
                                return new BOOL(new object("bul", new bool((*(static_cast<bool*>(this->value)))
                                / (*(static_cast<double*>(rptr->value)))), 0));
                        }

                        else{ throw std::invalid_argument("Not possible to divide the given types"); }
                }



};


class STRING : public object{
	public:
		STRING()
		:object("istring", new std::string(""), 0)
		{}

	public:
		STRING(object* optr)
			:STRING()
			{
				if(optr->name == "istring"){
					*(std::string*)this->value = *(std::string *)optr->value;
				}

				else{
					*(std::string*)this->value = optr->__str__();
				}
			}

		

		STRING(std::string str)
			:object("istring", new std::string(str), 0)
			{std::cout << "string ctor";}
	
	
	
	
	public:
                ~STRING(){
                        this->name = {""};
                        delete static_cast<std::string*>(this->value);
                        this->count = 0;
                        this->value = nullptr;
			std::cout << "string dtor";
                }

	
	
	
	public:
		void  Delete(){
			this->~STRING();
                }

		
		std::string __str__(){
			return *(std::string*)this->value;
		}



		object* __add__(object* rptr){
			if(rptr->name == "istring"){
				return new STRING(new object("istring", 
				new std::string(*((std::string*)this->value) + (*(std::string*)(rptr->value))), 0));
			}

			else if(rptr->name == "iint"){
				return new STRING(new object("istring",
				new std::string((*(std::string*)this->value) + std::to_string(*(int*)rptr->value)), 0));
			}

			else if(rptr->name == "dabl"){
				return new STRING(new object("istring",
                                new std::string((*(std::string*)this->value) + std::to_string(*(double*)rptr->value)), 0));
			}

			else if(rptr->value == "bul"){
				return new STRING(new object("istring",
                                new std::string((*(std::string*)this->value) + std::to_string(*(bool*)rptr->value)), 0));
			}

			else{
				throw std::invalid_argument("Not possible to add to type istring");
			}
		}

};




class FUNCTION : public object{
	public:
		FUNCTION()
			:object("fanqshn", new std::string, 0)
			{}

		FUNCTION(std::string str)
			:object("fanqshn", new std::string(str), 0)
			{}

	public:
                ~FUNCTION(){
                        this->name = {""};
                        delete static_cast<std::string*>(this->value);
                        this->count = 0;
                        this->value = nullptr;
                }

	
		
	public:
		void  Delete(){
                        this->~FUNCTION();
                }

				
		std::string __str__(){
                        return *(std::string*)this->value;
                }

		
		object* __call__(){
			interpreter *ob;//(*(static_cast<std::string*>(this->value)));
		}
};


class ARRAY : public object{
	public:
		ARRAY()
			:object("@rey", new std::vector<object*>, 0)
		{}

		ARRAY(object* optr)
			:ARRAY()
			{
				if(optr->name == "@rey"){
					*(object*)this->value = *(object*)optr->value;
				}
				else{
					throw std::invalid_argument("Not possible to create an array from another type");
				}
			}



		ARRAY(std::string str)
			:object("@rey", new std::vector<object*>, 0)
			{
				int strbracecount = 0;
				std::string separatingstrings = {""};
				for(int i = 1; i < str.size() - 1; ++i){
					if(str[i] == '"'){
						++strbracecount;
					}
					if(strbracecount != 0){
						separatingstrings  += str[i];
					}
					
					if(strbracecount > 1 && separatingstrings.size() >= 3){
						std::string unbracedstring = separatingstrings.substr(1, separatingstrings.size() - 2);
						if(checktypes::isint(unbracedstring)){
							((std::vector<object*>*)this->value)->push_back(new INT(unbracedstring));
						}

						else if(checktypes::isdouble(unbracedstring)){
                                                        ((std::vector<object*>*)this->value)->push_back(new DOUBLE(unbracedstring));
                                                }

						else if(checktypes::isbool(unbracedstring)){
                                                        ((std::vector<object*>*)this->value)->push_back(new BOOL(unbracedstring));
                                                }

						else if(checktypes::isstring(unbracedstring)){
                                                        ((std::vector<object*>*)this->value)->push_back(new STRING(unbracedstring));
                                                }

						else if(checktypes::isarray(unbracedstring)){
                                                        ((std::vector<object*>*)this->value)->push_back(new ARRAY(unbracedstring));
                                                }




						strbracecount = 0;
						separatingstrings.erase();
					}
				}
			}
			


	public:
		~ARRAY(){
                        this->name = {""};
                        for(int i = 0; i < static_cast<std::vector<object*>*>(this->value)->size(); ++i){
				(*(static_cast<std::vector<object*>*>(this->value)))[i]->Delete();
			}
                        this->count = 0;
                        this->value = nullptr;
			delete (static_cast<std::vector<object*>*>(this->value));
			value = nullptr;
                }


	
	
	
	public:
		void  Delete(){
                        this->~ARRAY();
                }

		
		//not working properly
		object* __add__(object* rptr){
			if(rptr->name == "@rey"){
				object *ptr = new ARRAY(this);
				for(int i = 0; i < ((std::vector<object*>*)rptr->value)->size(); ++i){
					((std::vector<object*>*)ptr->value)->push_back(((*(std::vector<object*>*)rptr->value))[i]);
				}
				return ptr;
			}

			else{
				throw std::invalid_argument("Not possible to add to type @rey");
			}
		}


};




class interpreter{


//tokenizeing stage     
        public:
                std::vector<std::string> strings;
                std::vector<std::vector<std::string>> tokens;
		std::vector<std::string>condstrings;

        public:
                interpreter()
			:strings{}
			,tokens{}
			,vars{}
		{
			getfile();
			for(std::string& s : strings){
				tokens.push_back(tokenize(s));
			}
			evaluate();
                }


		interpreter(std::string str)
			:strings{}
			,tokens{}
			,vars{}
			{
				getfile(str);
				for(std::string& s : strings){
                                	tokens.push_back(tokenize(s));
                        	}
				evaluateforfunc();

			}
		
		
		void addtokens(int n, std::string str){
			std::cout << "addtokens" << "         " << str << "             "<< n;	
			getcondfile(str);
				for(auto& s : condstrings){
					//std::cout << s << std::endl;
					tokens.emplace(tokens.begin() + n, tokenize(s));
				}
				condstrings.clear();
			}


	public:
		~interpreter(){
			strings = {""};
			tokens = {};
			for(auto& v: vars){
				v.second->Delete();
			}
			vars = {};
		}


        public:
                void getfile()
                {
                std::string filename;
                std::cin >> filename;
                std::ifstream file(filename);
                        if(!file.is_open()){
                                std::cerr << "Couldn't open the file";
                                return;
                        }

                        else if(file.is_open()){
                                std::string filestring;
                                        while(std::getline(file, filestring, '$'), !file.eof()){
                                                strings.push_back(filestring);

                                        }
                        }
                file.close();
                }


		void getcondfile(std::string str){
			for(int i = 0; str[i] != '\0' && i < str.size(); ++i){
				std::string tmptoken = {""};
				if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){
					continue;
				}
				while(str[i] != '`'){
					tmptoken += str[i];
					if(str[i] == '\0'){
						throw std::invalid_argument("Syntax error generation in a loop/if/else/for statement");
					}
					++i;
				}
				if(!tmptoken.empty()){
					condstrings.push_back(tmptoken);
				}
			}
		
		}



		void getfile(std::string str){
			std::istringstream inputstream(str);
			std::string filestring;
                        while(std::getline(inputstream, filestring, '`')){
                        	strings.push_back(filestring);

                        }

		}



                std::vector<std::string> tokenize(std::string stringss){
			std::vector<std::string>tokens;
			if(stringss.size()){
                                        for(int j = 0; stringss[j] != '\0' && j <= stringss.size(); ++j){
                                                if(stringss[j] == ' ' || stringss[j] == '\t' || stringss[j] == '\n'){
                                                        continue;
                                                }
                                                
                    
						if(tokens.size() == 3){
							std::string retstr(1, '"');
							retstr += ('#' + tokens[2] + stringss.substr(j - 1) + '"');
							tokens[2] = retstr;
							break;
						}
						
						std::string tmptoken{""};
						std::string tmptoken2{""};
                                                while(stringss[j] != ' ' && stringss[j] != '\t' && stringss[j] != '\0'
                                                	&& stringss[j] != '\n'){
                                                        if(stringss[j] == '.' && (j >= 1) && (stringss[j - 1] < '0' 
							|| stringss[j - 1] > '9') ){
								break;
							}

							if(stringss[j] == '('){
								tmptoken2 += '"';
								while(stringss[j] != ')' ){
									tmptoken2 += stringss[j];
									++j;
									if(j == stringss.size()){
										throw std::invalid_argument("No enclosing parenthes");
									}
								}
								tmptoken2 += ')';
								tmptoken2 += '"';
								break;
							}

							if(stringss[j] == '{'){
								tmptoken2 += '"';
								while(stringss[j] != '}'){
									tmptoken2 += stringss[j];
                                                                        ++j;
                                                                        if(j == stringss.size()){
                                                                                throw std::invalid_argument("No enclosing bracket");
                                                                        }
                                                                }
                                                                tmptoken2 += '}';
                                                                tmptoken2 += '"';
                                                                break;

							}

							if(stringss[j] == '.' && (j == 0 || j == (stringss.size() - 1) || (stringss[j + 1] == 
							' ' || stringss[j + 1] == '\t' || stringss[j - 1] == ' ' || stringss[j - 1] == '\t'))){
								throw std::invalid_argument("Wrong usage of operator '.'");
							}
							tmptoken += stringss[j];
                                                        ++j;
                                                }
                                                if (!tmptoken.empty()){
							tokens.push_back(tmptoken);
							tmptoken.clear();
						}
						if(!tmptoken2.empty()){
							tokens.push_back(tmptoken2);
							tmptoken2.clear();
						}

						if(stringss[j] == '.'){
                                                        tmptoken = ".";
							tokens.push_back(tmptoken);
							tmptoken.clear();
							continue;
                                                }



                                        }
                                
                        }
			return tokens;
                }
//endof tokenizing stage
	public:
		std::unordered_map<std::string, object*> vars;
	

	public:
		bool validvar_name(std::string str){
			for(int i = 0; str[i] != '\0'; ++i){
				if(str.empty()){
					return false;
				}
				
				if(str[i] == ' ' || str[i] == '.' || str[i] == '=' || (str[i] >= '0' && str[i] <= '9') || str[i] == ','){
					return false;
				}
				
				if(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}'){
					return false;
				}

				if(str[i] == ':' || str[i] == ';' || str[i] == '"' || str[i] == '<' || str[i] == '>' || str[i] == '?'){
					return false;
				}
				
				if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '!'){
					return false;
				}

				if(str[i] == '|' || str[i] == '%' || str[i] == '&' || str[i] == '~' || str[i] == '	' || str[i] == '#'){
					return false;
				}
			}

			if(str == "ifor" || str == "vayl" || str == "iif" || str == "els" || str == "input" || str == "output"){
				return false;
			}
			return true;
		}




		void evaluate(){
			 std::pair<std::string, int>conditernumber;
			for(int i = 0; i < tokens.size(); ++i){
				if(tokens[i][1] == "=" && tokens[i].size() == 3){

						if(tokens[i][2] == "output" && tokens[i][1] == "=" && tokens[i].size() == 3){
                                                        bool flag = false;
							for(auto& v : vars){
								if(v.first == tokens[i][0]){
									std::cout << v.second->__str__() << std::endl;
									flag = true;
									break;
								}
							}
                                                        if(!flag){
								std::cout << tokens[i][0];
                                                        }
							continue;
                                                }

						if(!validvar_name(tokens[i][0])){
                                                        throw std::invalid_argument("Not valid variable name");
                                                }


						if(tokens[i][2] == "input"){
                                                        std::string inputstr = {};
                                                        std::cin >> inputstr;
                                                        if(reassignobject(tokens[i][0], inputstr)){
                                                                continue;
                                                        }
                                                        else{
                                                                vars.insert({tokens[i][0], check_and_createobject(inputstr)});
                                                                continue;
                                                        }
                                                }
						if(tokens[i][1] == "=" && tokens[i].size() == 3 && (tokens[i][2])[1] == '#'){
							double d = exprresult(arithmetics((tokens[i][2]).substr(2,(tokens[i][2]).size() - 3)));
							if(reassignobject(tokens[i][0],std::to_string(d))){
								continue;
							}
							vars.insert({tokens[i][0], new DOUBLE(std::to_string(d))});
							continue;
						}
						
						if(reassignobject(tokens[i][0], tokens[i][2])){
							continue;
						}
								
						if(checktypes::isint(tokens[i][2])){
							vars.insert({tokens[i][0], new INT(tokens[i][2])});
							continue;
						}
						else if(checktypes::isdouble(tokens[i][2])){
							vars.insert({tokens[i][0], new DOUBLE(tokens[i][2])});
							continue;
						}
						else if(checktypes::isbool(tokens[i][2])){
							vars.insert({tokens[i][0], new BOOL(tokens[i][2])});
							continue;
						}
						else if(checktypes::isstring(tokens[i][2])){
							vars.insert({tokens[i][0], new STRING(tokens[i][2])});
							continue;
						}
						else if(checktypes::isarray(tokens[i][2])){
							vars.insert({tokens[i][0], new ARRAY(tokens[i][2])});
							continue;

						}
						else{
							//needs to be changed if the program starts to support functions
							throw std::invalid_argument("syntax error generation");
						}
					}
                        
				if(tokens[i][0] == "iif" && tokens[i].size() == 3){
					if(checkcondition(tokens[i][1])){
						std::cout << "mtav checkcondition";
						std::cout << "tokens beforeresize" << tokens.size();
						/*if(i == (tokens.size() - 1)){
							tokens.resize(tokens.size());
							std::cout << "tokens resize" << tokens.size();
						}*/
						addtokens(i + 1, (tokens[i][2]).substr(2, (tokens[i][2]).size() - 4));
						std::cout << "tokens addedtokenssize" << tokens.size();

					}
                                	continue;
				}
			//------------------------------------------------------------------------------------------------------
			
				
				if(tokens[i][0] == "vayl" && tokens[i].size() == 3){
					if(checkcondition(tokens[i][1]) && conditernumber.first == tokens[i][2]){
						i = conditernumber.second;
						continue;
					}
					if(checkcondition(tokens[i][1])){
                                                int tempsize = tokens.size();
						addtokens(i + 1, (tokens[i][2]).substr(2, (tokens[i][2]).size() - 4));
						conditernumber = {tokens[i][2], i};

						/*if(i + tokens.size() - tempsize + 1 == tokens.size()){
							tokens.resize(1);	
						}*/
						tokens.emplace(tokens.begin() + i + tokens.size() - tempsize + 1, tokens[i]);
                                        }
                                        continue;

				}
				
				if(tokens[i][0] == "elsif" ){
                                if(checkcondition(tokens[i][1])){
                                        if(i == (tokens.size() - 1)){
                                                tokens.resize(tokens.size());
                                        }
                                        addtokens(i + 1, (tokens[i][2]).substr(2, (tokens[i][2]).size() - 4));

                                }
                                continue;
                        }


			if(validvar_name(tokens[i][0]) && tokens[i].size() == 3){
				
				vars.insert({tokens[i][0], new FUNCTION(tokens[i][2])});
	 
			}


		}

	}




	  	object* evaluateforfunc(){
                        for(int i = 0; i < tokens.size(); ++i){
                                if(tokens[i][1] == "=" && tokens[i].size() == 3){

                                                if(tokens[i][2] == "output" && tokens[i][1] == "=" && tokens[i].size() == 3){
                                                        bool flag = false;
                                                        for(auto& v : vars){
                                                                if(v.first == tokens[i][0]){
                                                                        std::cout << v.second->__str__() << std::endl;
                                                                        flag = true;
                                                                        break;
                                                                }
                                                        }
                                                        if(!flag){
                                                                std::cout << tokens[i][0];
                                                        }
                                                        continue;
                                                }
                                                if(!validvar_name(tokens[i][0])){
                                                        throw std::invalid_argument("Not valid variable name");
                                                }
                                                if(tokens[i][2] == "input"){
                                                        std::string inputstr = {};
                                                        std::cin >> inputstr;
                                                        if(reassignobject(tokens[i][0], inputstr)){
                                                                continue;
                                                        }
                                                        else{
                                                                vars.insert({tokens[i][0], check_and_createobject(inputstr)});
                                                                continue;
                                                        }
                                                }
                                                if(tokens[i][1] == "=" && tokens[i].size() == 3 && (tokens[i][2])[1] == '#'){
                                                        double d = exprresult(arithmetics((tokens[i][2]).substr(2,(tokens[i][2]).size() - 3)));
                                                        if(reassignobject(tokens[i][0],std::to_string(d))){
                                                                continue;
                                                        }
                                                        vars.insert({tokens[i][0], new DOUBLE(std::to_string(d))});
                                                        continue;
                                                }
                                                if(reassignobject(tokens[i][0], tokens[i][2])){
                                                        continue;
                                                }

                                                if(checktypes::isint(tokens[i][2])){
                                                        vars.insert({tokens[i][0], new INT(tokens[i][2])});
                                                        continue;
                                                }
                                                else if(checktypes::isdouble(tokens[i][2])){
                                                        vars.insert({tokens[i][0], new DOUBLE(tokens[i][2])});
                                                        continue;
                                                }
                                                else if(checktypes::isbool(tokens[i][2])){
                                                        vars.insert({tokens[i][0], new BOOL(tokens[i][2])});
                                                        continue;
                                                }
                                                else if(checktypes::isstring(tokens[i][2])){
                                                        vars.insert({tokens[i][0], new STRING(tokens[i][2])});
                                                        continue;
                                                }
                                                else if(checktypes::isarray(tokens[i][2])){
                                                        vars.insert({tokens[i][0], new ARRAY(tokens[i][2])});
                                                        continue;

                                                }
                                                else{
                                                        //needs to be changed if the program starts to support functions
                                                        throw std::invalid_argument("syntax error generation");
                                                }
                                        }
			                        if(tokens[i][0] == "iif" ){
                                			if(checkcondition(tokens[i][1])){
                                        			if(i == (tokens.size() - 1)){
                                                			tokens.resize(tokens.size());
                                        			}	
                                        			addtokens(i + 1, (tokens[i][2]).substr(2, (tokens[i][2]).size() - 4));

                                			}
                                			continue;
                        			}
                        if(tokens[i][0] == "elsif" ){
                                if(checkcondition(tokens[i][1])){
                                        if(i == (tokens.size() - 1)){
                                                tokens.resize(tokens.size());
                                        }
                                        addtokens(i + 1, (tokens[i][2]).substr(2, (tokens[i][2]).size() - 4));

                                }
                                continue;
                        }


                        if(tokens[i][0] == "ret" && tokens[i].size() == 2){
                                bool flag = false;
                                for(auto& v : vars){
                                        if(v.first == tokens[i][1]){
                                                return v.second;
                                        }
                                }

                                return check_and_createobject(tokens[i][1]);

                        }

                        if(tokens[i][0] == "ret" && tokens[i].size() == 1){
                                //return check_and_createobject("nand");

                        }


                	}	

        	}





		std::vector<std::string> tokenizecondition(std::string str){
			std::vector<std::string>condtokens;
			std::vector<std::string>arithmeticcondtokens;
			for(int i = 0; str[i] != '\0' && i < str.size(); ++i){
				std::string tmptoken = {""};
				while(str[i] != ' ' && str[i] != '\t'  && str[i] != '\3' && i < str.size()){
					tmptoken += str[i];
					++i;
				}
				if(!tmptoken.empty()){
					condtokens.push_back(tmptoken);
				}

			}

			for(std::string& c : condtokens){
                                //std::cout << "*****" << c << "*****";
                                for(auto& v : vars){
                                        if(v.first == c){
                                                c = v.second->__str__();
						//std::cout << "cccccccc" << c;
                                                break;
                                        }
                                }


                        }


			std::string arithmetictoken = {"#"};
			
			bool flag = false;

			if(condtokens.size() >= 3){
				for(int i = 0; i < condtokens.size(); ++i){
					if((condtokens[i] == "==" || condtokens[i] == ">" || condtokens[i] == "<" || 
					condtokens[i] == "<=" || condtokens[i] == ">=" || condtokens[i] == "!=") && condtokens.size() == 3){
						arithmetictoken.clear();
						return condtokens;
					}
						
					arithmetictoken += condtokens[i] + " ";

					if((condtokens[i] == "==" || condtokens[i] == ">" || condtokens[i] == "<" || condtokens[i]                                                     == "<=" || condtokens[i] == ">=" || condtokens[i] == "!=") && condtokens.size() >= 4
					&& i < condtokens.size() - 1){
						
						if(flag){throw std::invalid_argument("Inproper usage of equality operations");}

						while(arithmetictoken[arithmetictoken.size() - 1] == ' ' || arithmetictoken[arithmetictoken.                                                   size() - 1] == '=' || arithmetictoken[arithmetictoken.size() - 1] == '>' ||                                                                    arithmetictoken[arithmetictoken.size() - 1] == '<' 
						|| arithmetictoken[arithmetictoken.size() - 1] == '!'){
							arithmetictoken.erase(arithmetictoken.size() - 1);
						}
						flag = true;
						arithmeticcondtokens.push_back(arithmetictoken);
						arithmeticcondtokens.push_back(condtokens[i]);
						arithmetictoken.clear();
						arithmetictoken += '#';
					}
			}

				if(flag){
					arithmeticcondtokens.push_back(arithmetictoken);
					return arithmeticcondtokens;

				}else{
					arithmeticcondtokens.push_back(arithmetictoken);
                                        return arithmeticcondtokens;

				}

			}
			return condtokens;

		}





		
		bool checkcondition(std::string str){
			std::string strsub = str.substr(2, str.size() - 4);
			std::vector<std::string> condtokens = tokenizecondition(strsub);
			std::vector<object*>condvars;
			for(std::string& c : condtokens){
				//std::cout << "/"<<c << "/";
			}
			

				if(condtokens.size() == 1 && checktypes::isbool(condtokens[0])){
					if(condtokens[0] == "tru"){
						return true;
					}
					return false;
				}

				if(condtokens.size() == 1 && checktypes::isint(condtokens[0])){
                                        if(stoi(condtokens[0]) == 0){
                                                return false;
                                        }
                                        return true;
                                }
//-------------------------------------------------------
				if(condtokens.size() == 1 && checktypes::isdouble(condtokens[0])){
                                        if(checktypes::retdouble(condtokens[0]) == 0){
                                                return false;
                                        }
                                        return true;
                                }

				if(condtokens.size() == 1 && checktypes::isstring(condtokens[0])){
                                        if(((condtokens[0]).substr(1, (condtokens[0]).size() - 2)).empty()){
                                                return false;
                                        }
                                        return true;
                                }

				if(condtokens.size() == 1 && condtokens[0][0] == '#'){
					return exprresult(arithmetics(((condtokens[0].substr(1)))));
				}



				if(condtokens.size() == 3 && (condtokens[1] == "==" || condtokens[1] == ">" || condtokens[1] == "<"
				  || condtokens[1] == ">=" || condtokens[1] == "<=" || condtokens[1] == "!=")){
					/*if(condtokens[0][0] == '#'){
					condvars.push_back
						(check_and_createobject(std::to_string(exprresult(arithmetics(condtokens[0].substr(1))))));
					}else{
						condvars.push_back(check_and_createobject(condtokens[0]));
					}
					if(condtokens[2][0] == '#'){
					condvars.push_back
						 (check_and_createobject(std::to_string(exprresult(arithmetics(condtokens[2].substr(1))))));

              				}else{
                                        	condvars.push_back(check_and_createobject(condtokens[2]));
                                        }*/
					if(condtokens[0][0] == '#'){
						condtokens[0] = condtokens[0].substr(1);
					}

					if(condtokens[2][0] == '#'){
                                                condtokens[2] = condtokens[2].substr(1);
                                        }
					
					if(condtokens[1] == "=="){
						return exprresult(arithmetics(condtokens[0])) == exprresult(arithmetics(condtokens[2]));
					}

					if(condtokens[1] == ">"){
                                                return exprresult(arithmetics(condtokens[0])) > exprresult(arithmetics(condtokens[2]));
                                        }

					if(condtokens[1] == "<"){
                                                return exprresult(arithmetics(condtokens[0])) < exprresult(arithmetics(condtokens[2]));
                                        }

					if(condtokens[1] == "<="){
                                                return exprresult(arithmetics(condtokens[0])) <= exprresult(arithmetics(condtokens[2]));
                                        }

					if(condtokens[1] == ">="){
                                                return exprresult(arithmetics(condtokens[0])) >= exprresult(arithmetics(condtokens[2]));
                                        }
					
					if(condtokens[1] == "!="){
                                                return exprresult(arithmetics(condtokens[0])) != exprresult(arithmetics(condtokens[2]));
                                        }


				}
			
                }
	
		

		int opprecedence(char c){
			if(c == '*' || c == '/'){
				return 2;
			}
			if(c == '+' ||  c == '-'){
				return 1;
			}
			return 0;
		}


		std::vector<std::string> arithmetics(std::string str){
			std::stringstream ss(str);
			std::string part;
			std::vector<std::string>postexpr;
			std::stack<char>opstack;
			while(ss >> part){
				for(auto& v : vars){
					if(v.first == part){
						part = v.second->__str__();
						break;
					}
				}
				
				if(checktypes::isint(part) || checktypes::isdouble(part)){
					postexpr.push_back(part);
				}
				else if(part[0] == '('){
					opstack.push(part[0]);
				}
				else if(part[0] == ')'){
					while(!opstack.empty() && opstack.top() != '('){
						postexpr.push_back(std::string(1, opstack.top()));
						opstack.pop();
					}
					opstack.pop();
				}
				else if(part[0] == '+' || part[0] == '-' || part[0] == '*' || part[0] == '/'){
					while(!opstack.empty() && opprecedence(opstack.top()) > opprecedence(part[0])){
						postexpr.push_back(std::string(1, opstack.top()));
						opstack.pop();
					}
					opstack.push(part[0]);
				}
				else{
					throw std::invalid_argument("Not valid arithmetic expression, be careful to whitespaces");
				}
			}

			while(!opstack.empty()){
				postexpr.push_back(std::string(1, opstack.top()));
				opstack.pop();
			}
			return postexpr;
		
		
		}	
		
		


		double exprresult(std::vector<std::string> expr){
			std::stack<double> tempstack;
			for(std::string& e : expr){
				if(checktypes::isint(e) || checktypes::isdouble(e)){
					tempstack.push(std::stod(e));
				}
				else if(e == "+" || e == "-" || e == "*" || e == "/"){
					double a = tempstack.top();
					tempstack.pop();
					double b = tempstack.top();
					tempstack.pop();

					switch(e[0]){
						case '+':
							tempstack.push(a + b);
							std::cout << tempstack.top() << "nshan + nshany	";
							break;
						case '-':
							tempstack.push(b - a);
							std::cout << tempstack.top() << " nshan - nshany      ";
							break;
						case '/':
							tempstack.push(b / a);
							std::cout << tempstack.top() << "   nshan / nshany    ";
							break;
						case '*':
							tempstack.push(a * b);
							std::cout << tempstack.top() << "   nshan * nshany    ";
							break;
					}
				}
				
			}
			return tempstack.top();
		}	
		


		object* check_and_createobject(std::string objectvalue){
			if(checktypes::isint(objectvalue)){
                        	return new INT(objectvalue);
                        }

                        else if(checktypes::isdouble(objectvalue)){
                        	return new DOUBLE(objectvalue);
                        }

                        else if(checktypes::isbool(objectvalue)){
                        	return  new BOOL(objectvalue);
                        }

                        else if(checktypes::isstring(objectvalue)){
                                return new STRING(objectvalue);
                        }

                        else if(checktypes::isarray(objectvalue)){
                                return new ARRAY(objectvalue);
			}
			
			else{
//needs to be changed if the program starts to support functions
                                throw std::invalid_argument("syntax error generation");
                        }

		}



		bool reassignobject(std::string objname, std::string objvalue){
			if(!vars.empty()){
                                for(auto& k : vars){
                                	if(objname == k.first){
                                                for(auto& search_var : vars){
							if(objvalue == search_var.first){
								if(k.second == search_var.second){
									return true;
								}
								if(k.second->count <= 1){
									k.second->Delete();
								}
								else{--k.second->count;}
								k.second = search_var.second;
								++(search_var.second->count);
								return true;
							}
						}
						
						
						for(auto& v : vars){
                                                	if(objvalue == (v.second->__str__())){
                                                                if(k.second == v.second){
									return true;
								}
								if(k.second->count <= 1){
                                                                	k.second->Delete();
                                                                }
                                                                else{--k.second->count;}
                                                                k.second = v.second;
                                                                ++(v.second->count);
                                                                return true;
                                                        }
                                                }
                              
                                                if(k.second->count <= 1){
                                                	k.second->Delete();
                                                }else{--(k.second->count);}

                                                k.second = check_and_createobject(objvalue);
                                                	return true;
                                        }

                                }
				return false;
                        }
			return false;

		}
		



                void printstrings(){
                        for(int i = 0; i < strings.size(); ++i){
                                std::cout << strings[i]  << std::endl;
                        }
                }





                void printtokens(){
                        for(int i = 0; i < tokens.size(); ++i){
				for(int j = 0; j < tokens[i].size(); ++j){
						std::cout << tokens[i][j] << "	";
                                }
                                std::cout << std::endl;
                        }
			
                }


		  void printvars(){
			  for(auto iter = vars.begin(); iter != vars.end(); ++iter){
			std::cout << std::endl << iter->first << "  " << iter->second->name << "    " << iter->second->__str__() << std::endl;
                        }
			std::cout << "string's size" << strings.size() << std::endl;
			std::cout << "token's size" << tokens.size() << std::endl;
			
			std::cout << "vars' size" << vars.size();
                }




};






int main(){
	/*ARRAY __add__
	object *ob = new INT;
	object *obj = new INT;
	*(int*)ob->value = 1;
	*(int*)obj->value = 2;
	std::vector<object*>vec{ob, obj};
	object* aptr = new ARRAY(new object("@rey", &vec, 0));


	object *obl = new INT;
        object *objl = new INT;
        *(int*)obl->value = 3;
        *(int*)objl->value = 4;
        std::vector<object*>vecl{ob, obj};
        object* aptrl = new ARRAY(new object("@rey", &vecl, 0));
	object* optr = aptr->__add__(aptrl);
	std::cout << *(int*)(((*(std::vector<object*>*)optr->value)[1])->value);
	*/

	//object* aptr = new ARRAY(std::vector<object*>(ob,obj));
	//obb.__add__(obj);
	interpreter ob;
	/*std::cout << "----------------------------------"<< std::endl;
	ob.printtokens();
	std::cout << "----------------------------------"<< std::endl;
	*/
	//std::cout << std::endl << ob.exprresult(ob.arithmetics("5 * 6 - ( ( 7 + 3 ) / 2 )"));
	
	
	
	
	std::cout << "------------------------" << std::endl;
	ob.printstrings();
	std::cout << "------------------------" << std::endl;
	ob.printtokens();
	std::cout << "------------------------";	
	ob.printvars();



}


