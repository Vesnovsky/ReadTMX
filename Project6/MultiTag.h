#pragma once
#include <string>
#include <fstream>
#include<unordered_map>

using multiTags = std::vector<MultiTag>;


class MultiTag
{
public:
	MultiTag();//inputStream
	multiTags& getMultiTags(const std::string &tagName);
	std::string getValue(const std::string &valueName, const std::string &tagName) const;

private:
	std::unordered_multimap<std::string, std::string> multiTagsArray;
	

};

