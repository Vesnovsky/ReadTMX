#include "SingleTag.h"


SingleTag::SingleTag(const std::string & tag)
{
	this->tag = tag;
	
}

std::string SingleTag::getValue(const std::string & valueName) const
{
	std::string value;

	for (auto i =tag.find(valueName) + valueName.size() + 2; tag[i] != '\"'; i++)
	{
		value.push_back(tag[i]);
	}
	return value;
}

//std::string SingleTag::getSingeTags(const std::string & tagName)
//{
//	std::string kayTag;
//	std::string line;
//	std::ifstream in("TAG.xml");///заменяется
//	
//
//	auto npos = std::string::npos;
//
//	while (getline(in, line))
//	{
//		if (line.find("<" + tagName) != npos && line.find("/>") != npos) {
//
//			for (auto i = line.find("<") + 1; line[i] != ' '&& line[i] != '/'; i++) {
//				kayTag.push_back(line[i]);
//			}
//			singleTagsArray.emplace(kayTag, line);
//			
//			kayTag.clear();
//		}
//	}
//	return line;//////////////
//}
