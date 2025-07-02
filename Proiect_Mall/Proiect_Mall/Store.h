#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Product.h"
class Store
{
private:
    
	Store() = default;
	Store(const Store& O) = delete;
	Store& operator=(const Store& O) = delete;

protected: 
	std::string Name;
	std::vector<Product *> Products;

	Store(std::string name, std::vector<Product *> P) : Name(name), Products(P) {}
public:
	int GetSoldQuantity() const;
	int GetUnsoldQuantity() const;
	void AddStock(std::vector<Product *> Comandate);
	int StockValue() const;
	int SoldValue() const;
	bool Sell(int quantity);
	void Clean();
	int CalculateProfit() const;
	void Inventary();
	virtual ~Store() {}
	
};

