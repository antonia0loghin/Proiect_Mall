#pragma once
#include "Store.h"
class StandardStore : virtual public Store {
private:
	StandardStore(const StandardStore& O) = delete;
	StandardStore& operator=(const StandardStore& O) = delete;
	StandardStore() = default;
	int discountRate; // rata de discount aplicata in medie, 0-100
	float InventoryAgingIndex; // indicele de vechime al inventarului, 1-10
	bool isLocalBrand; // daca vinde produse de marca locala
	float onlinePresenceScore; // scorul de prezenta online, 1-100

protected:
	StandardStore( int discountRate, float inventoryAgingIndex, bool isLocalBrand, float onlinePresenceScore)
		:  discountRate(discountRate), InventoryAgingIndex(inventoryAgingIndex), isLocalBrand(isLocalBrand), onlinePresenceScore(onlinePresenceScore) {
	}
	float GetEstimatedValue() const override {
		float Sv = StockValue();
		float P = SoldValue();
		float Base = StockValue() * 0.5 + SoldValue() * 0.5; // 50% stock, 50% sold
		float DiscountFactor = 1 - discountRate *0.01; 
		float AgingFactor = 1 - InventoryAgingIndex * 0.1;
		float LocalBrandFactor = isLocalBrand ? 1.2 : 1.0; 
		float OnlinePresenceFactor = 1 + onlinePresenceScore * 0.01 * 3;
		return Base * DiscountFactor * AgingFactor * LocalBrandFactor * OnlinePresenceFactor;
	}
};