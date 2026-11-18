#ifndef _ASSET_HPP
#define _ASSET_HPP

#include <string>

namespace asset
{
class Asset	//자산
{
private:
	std::string name_;
	std::string currency_;		// 기초자산의 통화 코드
	std::string description_;	// 설명: 금현물, 미국 중기채 등
	double value_ = 0;			// 평가금액(KRW)

public:
	Asset(std::string name);
	Asset(std::string name, double value);
	Asset(std::string name, std::string currency, double value = 0);
	Asset(std::string name, std::string currency, std::string discription, double value = 0);
	Asset(const Asset& asset);

	std::string name(void) const 		{ return name_; }
	std::string currency(void) const 	{ return currency_; }
	std::string description(void) const { return description_; }
	double value(void) const			{ return value_; }
	void set_value(double value) 		{ value_ = value; }
	
	// virtual void discern(void) = 0;		// 이름에서 거래통화 등 속성을 유추하여 설정 
	virtual std::string type(void) const = 0;	// 자산 유형(클래스 이름과 같음) 반환

	operator bool(void) const;		// name_이 ""일시 0을, 이외의 경우 1 반환
	bool operator<(const Asset& rhs) const;
};

struct less_Asset
{ 
	bool operator() (const Asset* lhs, const Asset* rhs) const;
};

//const char* discernAssetType(void);
	//자산 이름으로 자산 유형을 유추, 유추할 수 없으면 nullptr 반환
}

#endif