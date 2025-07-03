#pragma once
#include "Wearable.h"
class Accesories : public Wearable
{
private:
	bool hasGemstones;
	bool isEngraved; //1-10, pretul creste proportional
	int Weight; //in grame, pretul creste proportional
	Accesories(int cod, float buyPrice, float sellPrice, bool premiumBrand, int trendFactor, bool ecoFriendly, bool hasGemstones, bool isEngraved, int weight) :
		Wearable(cod, buyPrice, sellPrice, premiumBrand, trendFactor, ecoFriendly), hasGemstones(hasGemstones), isEngraved(isEngraved), Weight(weight) {
	}
	friend class WearableStore;
	float GetSellPrice() const override;
public:
	virtual ~Accesories() = default;
};