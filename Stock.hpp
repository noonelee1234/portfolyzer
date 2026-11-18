#ifndef _STOCK_HPP
#define _STOCK_HPP

#include "Asset.hpp"

namespace asset
{
class Stock : public Asset
{	
public:
	using Asset::Asset;
	
	virtual std::string type(void) const
	{ 
		return std::string("Stock"); 
	}
};
} // namespace asset

#endif