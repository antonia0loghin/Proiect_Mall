#include "WearableStore.hpp"
#include "StandardStore.hpp"
class WearableStandardStore : public WearableStore, public StandardStore {
private:
	WearableStandardStore(std::string name,  int size, int employeeCount, int CollectionCount, int OwnBrandPercentage, bool isDiverse, int YearlyEvents,
		int discountRate, float inventoryAgingIndex, bool isLocalBrand, float onlinePresenceScore)
		: Store(name, size, employeeCount), WearableStore(CollectionCount, OwnBrandPercentage, isDiverse, YearlyEvents),
		StandardStore(discountRate, inventoryAgingIndex, isLocalBrand, onlinePresenceScore) {
	}
	WearableStandardStore(const WearableStandardStore& O) = delete;
	WearableStandardStore& operator=(const WearableStandardStore& O) = delete;
	friend class Mall;
	float GetEstimatedValue() const override {
		return Store::GetEstimatedValue() + WearableStore::GetEstimatedValue() * 0.55 + StandardStore::GetEstimatedValue() * 0.45;
	}
};