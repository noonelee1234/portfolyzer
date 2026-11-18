#include "Asset.hpp"
#include "Stock.hpp"

asset::Asset::Asset(std::string name)
: name_(name)
{}

asset::Asset::Asset(std::string name, double value)
: name_(name), value_(value)
{}

asset::Asset::Asset(std::string name, std::string currency, double value)
: name_(name), currency_(currency), value_(value)
{}

asset::Asset::Asset(std::string name, 
	std::string currency, std::string description, double value)
: name_(name), currency_(currency), description_(description), value_(value)
{}

asset::Asset::Asset(const Asset &asset)
: name_(asset.name_), currency_(asset.currency_), 
	description_(asset.description_), value_(asset.value_)
{}

std::string asset::Asset::type(void) const
{
	return std::string("Asset");
}

asset::Asset::operator bool(void) const
{
	if (name_ == "")
		return false;
	return true;
}

bool asset::Asset::operator<(const Asset &rhs) const
{
	return name_ < rhs.name_;
}

bool asset::less_Asset::operator()(const Asset *lhs, const Asset *rhs) const
{
	return lhs->operator<(*rhs);
}
