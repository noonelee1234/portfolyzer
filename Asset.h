#ifndef _ASSET_H
#define _ASSET_H

class Asset	//자산
{
private:
	const char* asset_type;	//자산 유형: 주식, 미국채 등
	const char* asset_currency;	//기초자산의 통화 코드
	// const char* trade_currency;	//거래 통화 코드
	double value;	//평가금액(KRW)

public:
	double get_value(void) const;
};

#endif