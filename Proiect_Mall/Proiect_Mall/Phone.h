#pragma once
#include "Electronics.h"
class Phone : public Electronics {
private:
	int cameraMegapixels;
	bool has5G;
	bool isWirelessChargeable;
	Phone(int cod, float buyPrice, float sellPrice, bool waterResistant, int storageGb, int ramGb, int cameraMegapixels, bool has5G, bool isWirelessChargeable)
		: Electronics(cod, buyPrice, sellPrice, waterResistant, storageGb, ramGb), cameraMegapixels(cameraMegapixels), has5G(has5G), isWirelessChargeable(isWirelessChargeable) {
	}
	float GetSellPrice() const override;
	friend class ElectronicsStore;
public:
	virtual ~Phone() = default;
};