#include "Phone.h"

float Phone::GetSellPrice() const
{
	float price = InitialSellPrice;
	price += 30 * cameraMegapixels;
	if (isWirelessChargeable) price = price * 2;
	if (isWaterResistant) price *= 1.1;
	
	
	price += price * (float)(storageGb / 128) * 0.1;

	if (has5G) price *= 1.5;

	price += price * (float)(ramGb / 4) * 0.05;
	
	return price;
}