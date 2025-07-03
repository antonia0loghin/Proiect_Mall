#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Product.h"
class Store
{
private:
	Store(const Store& O) = delete;
	Store& operator=(const Store& O) = delete;
	
protected: 
	friend class Mall;
	Store() = default;
	std::string Name;
	std::vector<Product *> Products;
	int Size;// size of the store, m^2
	int EmployeeCount; 
	Store(std::string name,  int size, int employeeCount) : Name(name), Products(), Size(size), EmployeeCount(employeeCount){}
	int GetSoldQuantity() const;
	int GetUnsoldQuantity() const;
	virtual void AddProduct(Product* product) {}
	float StockValue() const;
	float SoldValue() const;
	void Clean();
	float CalculateProfit() const;
	void Inventary();
	bool Sell();
	void PrintProducts() const;
	void Menu();
	virtual float GetEstimatedValue() const;
	friend class Mall;
public:
	virtual ~Store() {}
	
	
};

