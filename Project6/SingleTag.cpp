#include "SingleTag.h"


SingleTag::SingleTag()
{
	
}

std::string SingleTag::getValue(const std::string & valueName,const std::string&tagName)
{
	std::string value;
	auto it = singleTagsArray.find(tagName);

	for (auto i = it->second.find(valueName) + valueName.size() + 2; it->second[i] != '\"'; i++)
	{
		value.push_back(it->second[i]);
	}
	return value;
}

std::string SingleTag::getSingeTags(const std::string & tagName)
{
	std::string kayTag;
	std::string line;
	std::ifstream in("TAG.xml");///заменяется
	

	auto npos = std::string::npos;

	while (getline(in, line))
	{
		if (line.find("<" + tagName) != npos && line.find("/>") != npos) {

			for (auto i = line.find("<") + 1; line[i] != ' '&& line[i] != '/'; i++) {
				kayTag.push_back(line[i]);
			}
			singleTagsArray.emplace(kayTag, line);
			
			kayTag.clear();
		}
	}




	return line;//////////////
}
