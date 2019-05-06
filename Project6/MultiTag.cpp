#include "MultiTag.h"





MultiTag::MultiTag(const std::string& tag,  std::istream& inStream)
{
	//std::string keyTag;
	//std::string line;
	//std::string tagName;
	//auto npos = std::string::npos;
	//while (getline(inStream, line)){
	//	if (line.find("<" + tagName) != npos) {
	//		multiTagsArray.emplace(tagName, line);

	//		while (getline(inStream, line) && line.find("</" + tagName + ">") == npos) {
	//			if (line.find("<") != npos && line.find("/>") == npos && line.find("</") == npos) {

	//				for (auto i = line.find("<") + 1; line[i] != ' '&& line[i] != '>'; i++) {
	//					keyTag.push_back(line[i]);
	//				}
	//				multiTagsArray.emplace(keyTag, line);
	//				while (getline(inStream, line) && line.find("</") != npos) {}

	//				keyTag.clear();
	//			}
	//		}
	//	}
	//}
}

void MultiTag::getMultiTags(const std::string & tagName) const
{

	std::ifstream inStream("TAG.xml");///////заменяется
	return ;
}

std::string MultiTag::getValue(const std::string & valueName, const std::string &tagName) const
{
	std::string value;
	//auto it = multiTagsArray.find(tagName);

	//for (auto i = it->second.find(valueName) + valueName.size() + 2; it->second[i] != '\"'; i++)/////////////////////////от куда брать строкку 
	//{
	//	value.push_back(it->second[i]);
	//}
	return value;
}




