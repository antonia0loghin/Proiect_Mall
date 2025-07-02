#include "Accesories.h"
int Accesories::GetSellPrice() const {
	int sellPrice = InitialSellPrice;
	if (isEcoFriendly) {
		sellPrice += 50;
	}
	if (hasGemstones) {
		sellPrice += 500; 
	}
	if (isEngraved) {
		sellPrice *= 3;
	}
	sellPrice += Weight * 10; // Example: weight adds 2 per gram to the price
	if (PremiumBrand) {
		sellPrice *= 2;
	}
	sellPrice = sellPrice * TrendFactor / 10;
	return sellPrice;
}