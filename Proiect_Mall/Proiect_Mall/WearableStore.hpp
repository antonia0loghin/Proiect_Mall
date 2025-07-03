#pragma once
#include "store.h"
#include <iostream>
#include "Clothing.h"
#include "Accesories.h"

class WearableStore : virtual public Store {
private:
	friend class store;
	WearableStore(const WearableStore& O) = delete;
	WearableStore& operator=(const WearableStore& O) = delete;
	WearableStore() = default;
	
	int CollectionCount; //colectii lansate pe an
	int OwnBrandPercentage; //procent din vanzari cu marca proprie  1-100
	bool isDiverse; //daca vinde produse de marimi diverse
	int YearlyEvents; //numarul de evenimente de moda anuale
	void AddProduct(Product* product) override {
		int cod;
		float buyPrice, sellPrice;
		std::cout << "Introduceti codul (numar), pretul de cumparare si de vanzare al produsului: ";
		std::cin >> cod >> buyPrice >> sellPrice;
		bool premiumBrand, ecoFriendly;
		int trendFactor;
		std::cout << "Introduceti daca este marca premium, eco-friendly (1/0) si factorul de trend (0-10): ";
		std::cin >> premiumBrand >> ecoFriendly >> trendFactor;
		bool wearableType; // (1 - clothing, 0 - accesories)
		std::cout << "Introduceti tipul de produs (1 - imbracaminte, 0 - accesorii): ";
		std::cin >> wearableType;
		if (wearableType) {
			bool isNatural, isFormal;
			int careLevel;
			std::cout << "Introduceti daca este natural, formal si nivelul de ingrijire (1-5): ";
			std::cin >> isNatural >> isFormal >> careLevel;
			product = new Clothing(cod, buyPrice, sellPrice, premiumBrand, trendFactor, ecoFriendly, isNatural, careLevel, isFormal);
		}
		else {
			bool hasGemstones, isEngraved;
			int weight;
			std::cout << "Introduceti daca are pietre pretioase, este gravat si greutatea (in grame): ";
			std::cin >> hasGemstones >> isEngraved >> weight;
			product = new Accesories(cod, buyPrice, sellPrice, premiumBrand, trendFactor, ecoFriendly, hasGemstones, isEngraved, weight);
		}
		Products.push_back(product);

	}
protected:
	WearableStore( int collectionCount, int ownBrandPercentage, bool isDiverse, int yearlyEvents)
		:  CollectionCount(collectionCount), OwnBrandPercentage(ownBrandPercentage), isDiverse(isDiverse), YearlyEvents(yearlyEvents) {
	}
	float GetEstimatedValue() const override {
		float Sv = StockValue();
		float P = SoldValue();
		float Base = StockValue() * 0.7 + SoldValue() * 0.3;
	    float CollectionFactor = 1 + CollectionCount * 0.4;
		float BrandFactor = OwnBrandPercentage / 100 * 1.25;
		float DiversityFactor = isDiverse ? 1.05 : 0.7;
		float EventFactor = 1 + YearlyEvents * 0.15;
		return Base * CollectionFactor * BrandFactor * DiversityFactor * EventFactor;
	}
	
	
};