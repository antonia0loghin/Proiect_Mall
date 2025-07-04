#pragma once
#include "Product.h"
class Wearable : public Product
{
private: 
	Wearable(const Wearable& O) = delete;
	Wearable& operator=(const Wearable& O) = delete;
	Wearable() = default;
protected:
	bool PremiumBrand; 
	int TrendFactor; //0-10
	bool isEcoFriendly;
	Wearable(int cod, float buyPrice, float sellPrice, bool premiumBrand, int trendFactor, bool ecoFriendly)
		: Product(cod, buyPrice, sellPrice*1.15), PremiumBrand(premiumBrand), TrendFactor(trendFactor), isEcoFriendly(ecoFriendly) {
	}
public:
    virtual ~Wearable() override {}
};