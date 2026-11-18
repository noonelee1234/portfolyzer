#ifndef _ETF_HPP
#define _ETF_HPP

#include "Asset.hpp"

namespace asset
{
class ETF : public Asset
{	
public:
	using Asset::Asset;
	
	virtual std::string type(void) const
	{ 
		return std::string("ETF"); 
	}
};
} // namespace asset

#endif