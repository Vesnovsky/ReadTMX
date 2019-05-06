#pragma once
#include <string>
#include <istream>
#include<unordered_map>
#include<vector>
#include"SingleTag.h"

//using multiTags = std::vector<MultiTag>;


class MultiTag
{
public:
	MultiTag(const std::string& tag, std::istream& inStream);// заменяется на InputStream
	/*multiTags&*/ void getMultiTags(const std::string &tagName) const;
	std::string getValue(const std::string &valueName, const std::string &tagName) const;

private:
	std::unordered_multimap<std::string, std::vector<MultiTag>> multiTagsArray;
	std::unordered_multimap<std::string, std::vector<SingleTag>> singleTagsArray;
	

};

