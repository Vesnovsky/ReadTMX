#include "MultiTag.h"



MultiTag::MultiTag()
{
}

multiTags& MultiTag::getMultiTags(const std::string & tagName)
{
	std::string kayTag;
	std::string line;
	std::ifstream inStream("TAG.xml");///////����������


	auto npos = std::string::npos;
	while (getline(inStream, line))
	{
		if (line.find("<" + tagName) != npos) {
			multiTagsArray.emplace(tagName, line);

			while (getline(inStream, line) && line.find("</" +tagName + ">") == npos) {
				if (line.find("<") != npos && line.find("/>") == npos && line.find("</") == npos) {

					for (auto i = line.find("<") + 1; line[i] != ' '&& line[i] != '>'; i++) {
						kayTag.push_back(line[i]);
					}
					multiTagsArray.emplace(kayTag, line);
					while (getline(inStream, line) && line.find("</") != npos) {}

					kayTag.clear();
				}
			}
		}
	}

	return ;
}

std::string MultiTag::getValue(const std::string & valueName, const std::string &tagName) const
{
	std::string value;
	auto it = multiTagsArray.find(tagName);

	for (auto i = it->second.find(valueName) + valueName.size() + 2; it->second[i] != '\"'; i++)/////////////////////////�� ���� ����� ������� 
	{
		value.push_back(it->second[i]);
	}
	return value;
}




