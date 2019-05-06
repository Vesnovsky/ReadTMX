#pragma once
#include <string>
#include <istream>
#include<unordered_map>
#include<vector>
#include"SingleTag.h"

using multiTags = std::vector<MultiTag>;
using singleTags = std::vector<SingleTag>;
class MultiTag
{
public:
	MultiTag(const std::string& tag, std::istream& inStream);
	multiTags& getMultiTags(const std::string &tagName) const;
	std::string getValue(const std::string &valueName, const std::string &tagName) const;

	singleTags& getSingleTags(const std::string &tagName) const;


private:
	std::unordered_multimap<std::string, std::vector<MultiTag>> multiTagsArray;
	std::unordered_multimap<std::string, std::vector<SingleTag>> singleTagsArray;
	std::string tag;

	void parserMultiTag(std::string tagName, std::istream& inStream);
	void parseSingleTag(std::string tagName, std::istream& inStream);

	

};

