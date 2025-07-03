#pragma once
#include "Product.h"
class Electronics : public Product
{
private:
	Electronics(const Electronics& E) = delete;
	Electronics& operator=(const Electronics& E) = delete;
	Electronics() = default;

protected:
	int storageGb;
	int ramGb;
	bool isWaterResistant;
	Electronics(int cod, float buyPrice, float sellPrice, bool waterResistant, int storageGb, int ramGb)
		: Product(cod, buyPrice, sellPrice*1.05), isWaterResistant(waterResistant), storageGb(storageGb), ramGb(ramGb) {
	}

};