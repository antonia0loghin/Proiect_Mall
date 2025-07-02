#pragma once
#include "Wearable.h"
class Accesories : protected Wearable
{
private:
	bool hasGemstones;
	bool isEngraved; //1-10, pretul creste proportional
	int Weight; //in grame, pretul creste proportional

public:
	Accesories(int cod, int buyPrice, int sellPrice, bool premiumBrand, int trendFactor, bool ecoFriendly, bool hasGemstones, bool isEngraved, int weight) :
		Wearable(cod, buyPrice, sellPrice, premiumBrand, trendFactor, ecoFriendly), hasGemstones(hasGemstones), isEngraved(isEngraved), Weight(weight) {
	}
	int GetSellPrice() const override {
	}
	virtual ~Accesories() = default;
};