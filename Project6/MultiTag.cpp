#include "MultiTag.h"

MultiTag::MultiTag(const std::string& tag,  std::istream& inStream)
{
	this->tag = tag;
	std::string tagName;
	std::string keyTag;
	std::string line;

	auto npos = std::string::npos;

	for (auto i = tag.find("<") + 1; i < tag.find(" "); i++)
	{
		tagName.push_back(tag[i]);
	}


	if (tag.find("/>") != npos) {
		parseSingleTag(tagName, inStream);
	}
	else {
		parserMultiTag(tagName, inStream);
	}
}

multiTags& MultiTag::getMultiTags(const std::string & tagName) const
{
	auto it= multiTagsArray.find(tagName);
	if (it!=multiTagsArray.end())
	{
		return it->second.begin;
	}
	else {
		/////////////
	}
	
	
}

singleTags & MultiTag::getSingleTags(const std::string & tagName) const
{
	auto it = singleTagsArray.find(tagName);
	if (it != singleTagsArray.end())
	{
		return it->second.begin;
	}
	else {
		/////////////
	}
}


std::string MultiTag::getValue(const std::string & valueName, const std::string &tagName) const
{
	std::string value;

	for (auto i = tag.find(valueName) + valueName.size() + 2; tag[i] != '\"'; i++)
	{
		value.push_back(tag[i]);
	}
	return value;
}



void MultiTag::parserMultiTag(std::string tagName, std::istream & inStream)
{
	std::string keyTag;
	std::string line;

	auto npos = std::string::npos;

	while (getline(inStream, line)) {
		if (line.find("<" + tagName) != npos) {
			while (getline(inStream, line) && line.find("</" + tagName + ">") == npos) {
				if (line.find("<") != npos && line.find("/>") == npos && line.find("</") == npos) {

					for (auto i = line.find("<") + 1; line[i] != ' '&& line[i] != '>'; i++) {
						keyTag.push_back(line[i]);
					}
					auto it = multiTagsArray.find(keyTag);
					if (it != multiTagsArray.end()) {
						it->second.push_back(MultiTag::MultiTag(line, inStream));
					}
					else {
						//std::vector<MultiTag> a{ MultiTag::MultiTag(line,inStream) };
						multiTagsArray.emplace(keyTag, multiTags{ MultiTag::MultiTag(line, inStream)});
					}
					while (getline(inStream, line) && line.find("</") != npos) {}

					keyTag.clear();
				}
			}
		}
	}
}

void MultiTag::parseSingleTag(std::string tagName, std::istream & inStream)
{
	std::string keyTag;
	std::string line;
	auto npos = std::string::npos;

	while (getline(inStream, line))
	{
		if (line.find("<" + tagName) != npos && line.find("/>") != npos) {

			for (auto i = line.find("<") + 1; line[i] != ' '&& line[i] != '/'; i++) {
				keyTag.push_back(line[i]);
			}
			auto it = singleTagsArray.find(keyTag);
			if (it != singleTagsArray.end()) {
				it->second.push_back(SingleTag::SingleTag(line));
			}
			else {
				//std::vector<SingleTag> a{ SingleTag::SingleTag(line) };
				singleTagsArray.emplace(keyTag, singleTags{ SingleTag::SingleTag(line)});
			}

			keyTag.clear();
		}
	}
}







