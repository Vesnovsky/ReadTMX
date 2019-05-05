#pragma once
#include <string>
#include <fstream>
#include<unordered_map>

using singleTags = std::vector<SingleTag>;

class SingleTag
{
public:
	SingleTag();
	singleTags& getSingeTags(const std::string &tagName);
	std::string getValue(const std::string &valueName, const std::string&tagName);
	
private:
	std::unordered_multimap<std::string, std::string> singleTagsArray;
};

