#include "Portfolio.hpp"
#include <fstream>

asset::Portfolio::Portfolio(std::string name)
: name_(name)
{}

asset::Portfolio::Portfolio(fs::path path)
{
	if (!fs::is_regular_file(path))
	{
		name_ = std::string("");
		return;
	}

	std::ifstream file(path);
	std::string content;

	// 첫줄을 이름으로, "$이름" 또는 "이름"의 형식을 따른다.
	std::getline(file, content);
	if (content[0] == '$') name_ = content.substr(1);
	else name_ = content;
	
	// 자산군 추가
	if (file.get() != '#') return;
	std::istringstream content_stream;
	while (std::getline(file, content, '#'))
	{
		content_stream.str(content);
		AssetClass assetClass(content_stream);

		auto res = add_assetClass(assetClass);
		if (res.second)
		{
			value_ += assetClass.value();
			size_++;
		}
	}
}

std::pair<asset::Portfolio::assetClass_iterator, bool>
		asset::Portfolio::add_assetClass(const AssetClass &assetClass)
{
	auto temp_res = assetClasses_.insert(assetClass);
	if (temp_res.second)
	{
		value_ += assetClass.value();
		size_++;
	}
	
	return std::pair<assetClass_iterator, bool>
			(assetClass_iterator(temp_res.first), temp_res.second);
}

asset::Portfolio::assetClass_iterator::assetClass_iterator(std::set<AssetClass>::iterator itr)
: itr_(itr)
{}

asset::Portfolio::iterator::iterator(
		assetClass_iterator assetClass_itr, AssetClass::iterator asset_itr)
: assetClass_itr_(assetClass_itr), asset_itr_(asset_itr)
{}
