#pragma once
#include "electronics.h"
class laptop: public Electronics
{
private:
	bool hasDedicatedGpu;
	bool hasSSD;
	int coolingFanCount; // 1-5, pretul creste proportional
	laptop(int cod, float buyPrice, float sellPrice, bool waterResistant, int storageGb, int ramGb, bool hasDedicatedGpu, bool hasSSD, int coolingFanCount)
		: Electronics(cod, buyPrice, sellPrice, waterResistant, storageGb, ramGb), hasDedicatedGpu(hasDedicatedGpu), hasSSD(hasSSD), coolingFanCount(coolingFanCount) {
	}
	float GetSellPrice() const override;
	friend class ElectronicsStore;
public:
	virtual ~laptop() = default;
};