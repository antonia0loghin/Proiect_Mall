#include "laptop.h"
float laptop::GetSellPrice() const {
	float price = InitialSellPrice;
	if (isWaterResistant) price *= 1.25;
	if (hasDedicatedGpu) price *= 1.5;

	price += price * (float)(storageGb / 512) * 0.1;

	price += price * (float)(ramGb / 8) * 0.05;

	price += 50 * coolingFanCount;
	if (hasSSD) price *= 1.2;
	else price *= 0.85;
	return price;
}