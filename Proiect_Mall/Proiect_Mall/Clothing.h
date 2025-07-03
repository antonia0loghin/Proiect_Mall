#pragma once
#include "Wearable.h"

class Clothing : public Wearable
{

private:
	bool isNatural;
	int careLevel; //1-5, pretul creste proportional 
	bool isFormal;
	Clothing(int cod, float buyPrice, float sellPrice, bool premiumBrand, int trendFactor, bool ecoFriendly, bool isNatural, int careLevel, bool isFormal) :
		Wearable(cod, buyPrice, sellPrice, premiumBrand, trendFactor, ecoFriendly), isNatural(isNatural), careLevel(careLevel), isFormal(isFormal) {
	}
	float GetSellPrice() const override;
	friend class WearableStore;
public:
	virtual ~Clothing() = default;
};