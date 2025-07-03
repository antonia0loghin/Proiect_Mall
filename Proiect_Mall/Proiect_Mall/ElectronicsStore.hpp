#pragma once
#include "Store.h"
#include "Phone.h"
#include "Laptop.h"
#include <iostream>
class ElectronicsStore : virtual public Store
{
private:
	float depreciationRate; //rata anuala de depreciere valori in intervalul 0-1
	int warrantyPeriod; //perioada de garantie in luni
	int techSupportLevel; //nivelul de suport tehnic, 1-5, pretul creste proportional
	ElectronicsStore(const ElectronicsStore& O) = delete;
	ElectronicsStore& operator=(const ElectronicsStore& O) = delete;
	ElectronicsStore() = default;
protected:
	ElectronicsStore(float depreciationRate, int warrantyPeriod, int techSupportLevel)
		: depreciationRate(depreciationRate), warrantyPeriod(warrantyPeriod), techSupportLevel(techSupportLevel) {}
	float GetEstimatedValue() const override {
		float Sv = StockValue();
		float P = SoldValue();

		float Base = Sv * (1 - depreciationRate) + SoldValue();

		float warantyFactor = 1 + warrantyPeriod / 36 * 0.2;

		float TechSupportFactor = 1 + (techSupportLevel - 1) / 4 * 0.3;
		
		return Base*warantyFactor * TechSupportFactor;
	}
	 void AddProduct(Product* product) override {
		 int cod;
		 float buyPrice, sellPrice;
		 std::cout << "Introduceti codul (numar), pretul de cumparare si de vanzare al produsului: ";
		 std::cin >> cod >> buyPrice >> sellPrice;
		 int storageGb, ramGb;
		 bool iswaterResistant;
		 std::cout << "Introduceti capacitatea de stocare (GB), RAM (GB) si daca este rezistent la apa (1/0): ";
		 std::cin >> storageGb >> ramGb >> iswaterResistant;

		 std::cout << "Introduceti daca produsul este telefon sau laptop (1/0): ";
		 bool device;
		 std::cin >> device;// (1 - telefon, 0 - laptop)
		 if (device)
		 {
			 int cameraMegapixels;
			 bool has5G, isWirelessChargeable;
			 std::cout << "Introduceti numarul de megapixeli al camerei, daca are 5G si daca se incarca wireless (1/0): ";
			 std::cin >> cameraMegapixels >> has5G >> isWirelessChargeable;

			 product = new Phone(cod, buyPrice, sellPrice, iswaterResistant, storageGb, ramGb, cameraMegapixels, has5G, isWirelessChargeable);
		 }
		 else
		 {
			 bool hasDedicatedGpu, hasSSD;
			 int coolingFanCount;
			 std::cout << "Introduceti daca are GPU dedicat, SSD (1/0) si numarul de ventilatoare de racire (1-5): ";
			 std::cin >> hasDedicatedGpu >> hasSSD >> coolingFanCount;
			 
			 product = new laptop(cod, buyPrice, sellPrice, iswaterResistant, storageGb, ramGb, hasDedicatedGpu, hasSSD, coolingFanCount);
		 }
		 Products.push_back(product);
	 }
	 friend class Mall;
};