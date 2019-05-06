#pragma once
#include <string>
#include <fstream>
#include<unordered_map>
#include<vector>

//using singleTags = std::vector<SingleTag>;

class SingleTag
{
public:
	SingleTag(const std::string & tag);
	std::string getValue(const std::string &valueName) const;
	
private:
	std::string tag;
};

