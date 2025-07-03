#pragma once
#include "Store.h"
class LuxuryStore : virtual public Store {
private:
	LuxuryStore(const LuxuryStore& O) = delete;
	LuxuryStore& operator=(const LuxuryStore& O) = delete;
	LuxuryStore() = default;
	int brandPrestigeIndex; // indicele de prestigiu al brandului, 1-10
	int storeAmbienceScore; // scorul de ambianta al magazinului, 1-100
	float customerLoyaltyRate; // rata de fidelizare a clientilor, 1-5
protected:
	LuxuryStore( int brandPrestigeIndex, int storeAmbienceScore, float customerLoyaltyRate)
		: brandPrestigeIndex(brandPrestigeIndex), storeAmbienceScore(storeAmbienceScore), customerLoyaltyRate(customerLoyaltyRate) {
	}
	float GetEstimatedValue() const override {
		float Sv = StockValue();
		float P = SoldValue();
		float Base = StockValue() * 0.6 + SoldValue() * 0.4; 
		float PrestigeFactor = 1 + brandPrestigeIndex * 0.2; 
		float AmbienceFactor = 1 + (storeAmbienceScore * 0.01) * 2;
		float LoyaltyFactor = 1 + customerLoyaltyRate  * 0.5; 
		return Base * PrestigeFactor * AmbienceFactor * LoyaltyFactor;
	}
};