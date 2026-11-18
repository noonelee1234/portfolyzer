#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <sstream>
#include <typeinfo>
#include <filesystem>
#include "AssetClass.hpp"
#include "Stock.hpp"
#include "Portfolio.hpp"
// using namespace std::literals;

class A
{
	int a = 0;

	public:
	A(int p): a(p) { std::cout << "A" << std::endl;}
	~A() { std::cout << "~A" << std::endl;}
	int get() const {return a;}
	void set(int p) {a = p;}
	bool operator<(const A& p) const { return a < p.get();}
};
class B
{
	A a;
	public:
	B() : a(5) {std::cout << "B" << std::endl;}
	~B() {std::cout << "~B" << std::endl;}
};

using namespace asset;

struct compare
{
	bool operator() (const Asset* lhs, const Asset* rhs) const
	{
		return lhs->name() < rhs->name();
	}
};


int main(void)
{
	std::string str("abc");
	std::istringstream iss(str);
	
	return 0;
}