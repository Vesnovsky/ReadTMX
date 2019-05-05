#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <fstream>
#include<unordered_map>


int main()
{
	//std::string line = "<layer id=\"1\" name=\"Слой тайлов 1\" width=\"10\" height=\"10\">";
	//std::string w = "height";
	//
	//std::string tmp;
	//for (auto i=line.find(w)+w.size()+2; line[i]!='\"'; i++)
	//{
	//	tmp.push_back(line[i]);
	//}
	//std::cout << tmp<<std::endl;
	std::string tag = "tile";
	std::string kayTag;
	std::string line;
	std::ifstream in("TAG.xml");

	std::unordered_multimap<std::string, std::string> tagsArray;
	
	auto npos = std::string::npos;
	while (getline(in, line))
	{
			if (line.find("<"+tag) != npos&&line.find("/>") != npos){
					
				for (auto i = line.find("<")+1; line[i] != ' '&& line[i] != '/'; i++){
					kayTag.push_back(line[i]);
				}
				tagsArray.emplace(kayTag, line);
				kayTag.clear();
			}
	}

	for (auto it = tagsArray.begin(); it != tagsArray.end(); it++)
		std::cout<< it->first << std::endl << it->second << std::endl << std::endl;

	
	std::system("pause");
}