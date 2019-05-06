#pragma once
#include <string>
#include <fstream>
#include<unordered_map>
#include<vector>

//using singleTags = std::vector<SingleTag>;

class SingleTag
{
public:
	SingleTag();
	/*singleTags&*/std::string getSingeTags(const std::string &tagName);
	std::string getValue(const std::string &valueName, const std::string&tagName);
	
private:
	std::unordered_multimap<std::string, std::string> singleTagsArray;
};

