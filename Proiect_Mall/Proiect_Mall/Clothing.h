#pragma once
#include "Wearable.h"

class Clothing : protected Wearable
{

private:
	bool isNatural;
	int careLevel; //1-5, pretul creste proportional 
	bool isFormal;

public:
	Clothing(int cod, int buyPrice, int sellPrice, bool premiumBrand, int trendFactor, bool ecoFriendly, bool isNatural, int careLevel, bool isFormal) :
		Wearable(cod, buyPrice, sellPrice, premiumBrand, trendFactor, ecoFriendly), isNatural(isNatural), careLevel(careLevel), isFormal(isFormal) {
	}
	int GetSellPrice() const override;
	virtual ~Clothing() = default;
};