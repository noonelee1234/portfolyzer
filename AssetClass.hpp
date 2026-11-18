#ifndef _ASSETCLASS_HPP
#define _ASSETCLASS_HPP

#include "Asset.hpp"
#include <set>
#include <sstream>

namespace asset
{
class AssetClass // 자산군
{
private:
	std::string name_;
	std::set<Asset*, less_Asset> assets_;
	size_t size_ = 0;
	double value_ = 0;

	static Asset* new_Asset(std::string type, std::string name, 
			std::string curr, std::string desc, double value);
	static Asset* new_Asset(const Asset& asset);

public:
	class iterator
	{
	private:
		std::set<Asset*, less_Asset>::iterator itr_;
	
	public:
		iterator(std::set<Asset*, less_Asset>::iterator itr);
		bool operator!=(const iterator& itr) const;
		iterator& operator++(void);
		const Asset& operator*(void);	// const?;
	};

	AssetClass(std::string name);
	AssetClass(std::istringstream& input);
	~AssetClass();

	std::string name(void) const	{ return name_; }
	double value(void) const		{ return value_; }

	std::pair<iterator, bool> add_asset(const Asset& asset);

	iterator begin(void) const;
	iterator end(void) const;
	iterator find(const std::string name) const;
	
	bool operator< (const AssetClass& rhs) const;
};
} // namespace asset

#endif