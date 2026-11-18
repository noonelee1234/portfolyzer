#include "AssetClass.hpp"
#include "Stock.hpp"

asset::AssetClass::AssetClass(std::string name)
: name_(name)
{}

asset::AssetClass::AssetClass(std::istringstream& input)
{
	std::string line;
	std::istringstream line_stream;
	Asset* asset;

	// 첫줄을 이름으로, "#이름" 또는 "이름"의 형식을 따른다.
	std::getline(input, line);
	if (line[0] == '#') name_ = line.substr(1);
	else name_ = line;

	// 자산 추가, "@자산유형:이름:통화:설명:가치"의 형식을 따른다.
	std::string type, name, curr, desc;
	double value = 0;	
	while (std::getline(input, line))
	{
		if (line[0] != '@') break;

		line_stream.clear();
		line_stream.str(line.substr(1));
		std::getline(line_stream, type, ':');
		std::getline(line_stream, name, ':');
		std::getline(line_stream, curr, ':');
		std::getline(line_stream, desc, ':');
		line_stream >> value;

		if (!line_stream) break;

		asset = new_Asset(type, name, curr, desc, value);
		if (!asset) break;
		assets_.insert(asset);
		value_ += value;
		size_++;
	}
}

asset::AssetClass::~AssetClass()
{
	for (Asset* e : assets_) delete e;
}

std::pair<asset::AssetClass::iterator, bool> 
		asset::AssetClass::add_asset(const Asset &asset)
{
	auto temp_res = assets_.insert(new_Asset(asset));
	if (temp_res.second)
	{
		value_ += asset.value();
		size_++;
	}
	
	return std::pair<iterator, bool>(iterator(temp_res.first), temp_res.second);
}

bool asset::AssetClass::operator<(const AssetClass &rhs) const
{
	return name_ < rhs.name_;
}

asset::Asset *asset::AssetClass::new_Asset(std::string type, 
		std::string name, std::string curr, std::string desc, double value)
{
	Asset* asset;

	if (type == "Stock")
		asset = new Stock(name, curr, desc, value);
	else
		asset = nullptr;

	return asset;
}

asset::Asset *asset::AssetClass::new_Asset(const Asset &asset)
{
	return new_Asset(asset.type(), asset.name(), 
			asset.currency(), asset.description(), asset.value());
}

asset::AssetClass::iterator::iterator(std::set<Asset *, less_Asset>::iterator itr)
: itr_(itr)
{}