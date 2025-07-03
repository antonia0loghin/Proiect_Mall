#include "ElectronicsStore.hpp"
#include "LuxuryStore.hpp"

class ElectronicsLuxuryStore : public ElectronicsStore, public LuxuryStore
{
private:
	ElectronicsLuxuryStore(std::string name,  int size, int employeecount, float depreciationRate, int warrantyPeriod, int techSupportLevel,
		int brandPrestigeIndex, int storeAmbienceScore, float customerLoyaltyRate) :
		Store(name,  size, employeecount),
		ElectronicsStore(depreciationRate, warrantyPeriod, techSupportLevel),
		LuxuryStore(brandPrestigeIndex, storeAmbienceScore, customerLoyaltyRate) {
	}
	ElectronicsLuxuryStore(const ElectronicsLuxuryStore& O) = delete;
	ElectronicsLuxuryStore& operator=(const ElectronicsLuxuryStore& O) = delete;
	friend class Mall;
	float GetEstimatedValue() const override {
		return Store::GetEstimatedValue() + LuxuryStore::GetEstimatedValue() * 0.7 + ElectronicsStore::GetEstimatedValue() * 0.3;
	}

};