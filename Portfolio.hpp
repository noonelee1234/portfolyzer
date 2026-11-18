#ifndef _PORTFOLIO_HPP
#define _PORTFOLIO_HPP

#include "AssetClass.hpp"
#include <set>
#include <filesystem>

namespace asset
{
namespace fs = std::filesystem;
class Portfolio
{
private:
	std::string name_;
	std::set<AssetClass> assetClasses_;
	size_t size_ = 0;	// 자산의 개수
	double value_ = 0;

public:
	class assetClass_iterator
	{
	private:
		std::set<AssetClass>::iterator itr_;
		
	public:
		assetClass_iterator(std::set<AssetClass>::iterator itr);
		const AssetClass& operator*(void);
	};

	class iterator
	{
	private:
		assetClass_iterator assetClass_itr_;
		AssetClass::iterator asset_itr_;

	public:
		iterator(assetClass_iterator assetClass_itr, AssetClass::iterator asset_itr);
		const Asset& operator*(void);
	};

	Portfolio(std::string name);
	Portfolio(fs::path path);

	std::pair<iterator, bool> add_asset(assetClass_iterator itr, const Asset& asset);
	std::pair<assetClass_iterator, bool> add_assetClass(const AssetClass &assetClass);
};
} // namespace asset

#endif