#include "Accesories.h"
float Accesories::GetSellPrice() const {
	float sellPrice = InitialSellPrice;
	if (isEcoFriendly) {
		sellPrice *= 1.15;
	}
	if (hasGemstones) {
		sellPrice *= 3;
	}
	else sellPrice *= 0.85;
	if (isEngraved) {
		sellPrice *= 1.5;
	}
	sellPrice += Weight * 10; // Example: weight adds 2 per gram to the price
	if (PremiumBrand) {
		sellPrice *= 2;
	}
	else sellPrice *= 0.75;
	sellPrice *= TrendFactor * 0.1;
	return sellPrice;
}