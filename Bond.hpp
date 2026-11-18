#ifndef _BOND_HPP
#define _BOND_HPP

#include "Asset.hpp"

namespace asset
{
class Bond : public Asset
{	
public:
	using Asset::Asset;
	
	virtual std::string type(void) const
	{ 
		return std::string("Bond"); 
	}
};
} // namespace asset

#endif