#pragma once
#include "Store.h"
class Mall
{
private:
	Mall() = default;                         
	Mall(const Mall& O) = delete;
	Mall& operator=(const Mall& O) = delete;
	std::vector<Store*> Stores;
	float StockValue() const;
	float SoldValue() const;
	float EstimatedValue() const;
	float Inventary() const;
	void AddStore();
	void AddProductstoStore();
	void PrintStores() const;
	void StoreOptions();
public:
	static Mall& getInstance();
	void Menu();
	
};