#include "WearableStore.hpp"
#include "LuxuryStore.hpp"
#include "Store.h"
class WearableLuxuryStore : public WearableStore, public LuxuryStore
{
private:
	WearableLuxuryStore(std::string name, int size, int employeecount, int CollectionCount, int OwnBrandPercentage, bool isDiverse, int YearlyEvents,
		int brandPrestigeIndex, int storeAmbienceScore, float customerLoyaltyRate)
		: Store(name, size, employeecount), WearableStore(CollectionCount, OwnBrandPercentage, isDiverse, YearlyEvents),
		LuxuryStore( brandPrestigeIndex, storeAmbienceScore, customerLoyaltyRate) {
	}
	WearableLuxuryStore(const WearableLuxuryStore& O) = delete;
	WearableLuxuryStore& operator=(const WearableLuxuryStore& O) = delete;
	friend class Mall;
	float GetEstimatedValue() const override {
		return Store::GetEstimatedValue()+LuxuryStore::GetEstimatedValue() * 0.85 + WearableStore::GetEstimatedValue() * 0.15;
	}
};