#include "Clothing.h"

int Clothing::GetSellPrice() const {
	int sellPrice = InitialSellPrice;
	
	sellPrice += careLevel * 10; 
	
	if (isEcoFriendly) {
		sellPrice += 50; 
	}
	
	if (isFormal) {
		sellPrice += 40; // Example: formal clothing adds a flat 40 to the price
	}

	if (PremiumBrand) {
		sellPrice *= 2;
	}

	if (isNatural) {
		sellPrice *= 3; // Example: natural materials add a flat 30 to the price
	}
	sellPrice = sellPrice*TrendFactor/10; // Example: trend factor adds a flat 5 per point
	return sellPrice;
}