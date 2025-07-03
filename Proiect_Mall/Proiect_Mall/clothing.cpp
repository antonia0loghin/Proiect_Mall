#include "Clothing.h"

float Clothing::GetSellPrice() const {
	int sellPrice = InitialSellPrice;
	
	sellPrice += (float)sellPrice * careLevel * 0.1;
	
	if (isEcoFriendly) {
		sellPrice *= 1.2;
	}
	else sellPrice *= 0.9;
	if (isFormal) {
		sellPrice *= 1.15;
	}
	if (PremiumBrand) {
		sellPrice *= 2;
	}
	else sellPrice *= 0.95;
	if (isNatural) {
		sellPrice *= 1.5;
	}
	sellPrice *=1.1 * TrendFactor;
	return sellPrice;
}