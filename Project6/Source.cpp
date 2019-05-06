#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <fstream>
#include<unordered_map>


int main()
{
	//std::string line = "<layer id=\"1\" name=\"Ñëîé òàéëîâ 1\" width=\"10\" height=\"10\">";
	//std::string w = "height";
	//
	//std::string tmp;
	//for (auto i=line.find(w)+w.size()+2; line[i]!='\"'; i++)
	//{
	//	tmp.push_back(line[i]);
	//}
	//std::cout << tmp<<std::endl;
	std::string tag = "<image source=\"ÑËÎÈ / Tileset.png\" width=\"700\" height=\"300\"/>";
	std::string tagName;
	std::string keyTag;
	std::string line;
	std::ifstream in("TAG.xml");
	std::unordered_multimap<std::string, std::string> tagsArray;

	auto npos = std::string::npos;
	
	for (auto i = tag.find("<") + 1; i < tag.find(" "); i++)
	{
		tagName.push_back(tag[i]);
	}
	

	if (tag.find("/>")!=npos){
		while (getline(in, line))
		{
			if (line.find("<" + tagName) != npos && line.find("/>") != npos) {

				for (auto i = line.find("<") + 1; line[i] != ' '&& line[i] != '/'; i++) {
					keyTag.push_back(line[i]);
				}
				tagsArray.emplace(keyTag, line);
				keyTag.clear();
			}
		}
	}
	else {
		while (getline(in, line)){
			if (line.find("<" + tagName) != npos) {
				//tagsArray.emplace(tagName, line);
				while (getline(in, line) && line.find("</" + tagName + ">") == npos) {
					if (line.find("<") != npos && line.find("/>") == npos && line.find("</") == npos) {

						for (auto i = line.find("<") + 1; line[i] != ' '&& line[i] != '>'; i++) {
							keyTag.push_back(line[i]);
						}
						tagsArray.emplace(keyTag, line);
						while (getline(in, line) && line.find("</") != npos) {}
		
						keyTag.clear();
					}
				}
			}
		}
	}
	



	for (auto it = tagsArray.begin(); it != tagsArray.end(); it++)
		std::cout<< it->first << std::endl << it->second << std::endl << std::endl;

	
	std::system("pause");
}
