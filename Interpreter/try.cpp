#include<iostream>
#include<unordered_map>
#include<unordered_set>

int main()
{
	/*std::pair<int, char>ch;
	std::unordered_map<std::string, int>iter;
	iter.insert({"a", 5});
	iter.insert({"a", 6});
	ch = {5, 'v'};
	for(auto& i : iter){
		std::cout << i.second << std::endl;
	}
	if(ch.first == 5)
	std::cout << ch.second;*/
	for(int i = 0; i < 10; ++i){
		if(i == 5){
		i = 7;
		continue;
		}
		std::cout << i;
	}
	


}
