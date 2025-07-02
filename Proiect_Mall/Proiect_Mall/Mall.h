#pragma once
#include "Store.h"
class Mall
{
private:
	std::vector<Store*> Stores;
public:
	int StockValue() const;
	int SoldValue() const;

};