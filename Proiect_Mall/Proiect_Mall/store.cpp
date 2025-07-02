#include "Store.h"
#include <iostream>
int Store::GetSoldQuantity() const {
	int totalSold = 0;
	for (const auto& product : Products) {
		totalSold += product->GetIsSold();
	}
	return totalSold;
}

int Store::GetUnsoldQuantity() const {
	int totalUnsold = 0;
	for (const auto& product : Products) {
		if (product->GetIsSold()) {
			totalUnsold++;
		}
	}
	return totalUnsold;
}

void Store::AddStock(std::vector<Product *> Comandate) {
	for (const auto& product : Comandate) {
		Products.push_back(product);
	}
}

int Store::StockValue() const {
	int totalValue = 0;
	for (const auto& product : Products) {
		if(!product->GetIsSold()) {
			totalValue += product->GetBuyPrice();
		}
	}
	return totalValue;
}

int Store::SoldValue() const {
	int totalValue = 0;
	for (const auto& product : Products) {
		if (product->GetIsSold()) {
			totalValue += product->GetSellPrice();
		}
	}
	return totalValue;
}

bool Store::Sell(int quantity) {
	if(GetUnsoldQuantity() < quantity) {
		std::cout << "Not enough unsold products to sell." << "\n";
		return 0;

	}
	else
	{
		int soldCount = 0;
		for (auto& product : Products) {
			if (!product->GetIsSold() && soldCount < quantity) {
				product->Sell();
				soldCount++;
			}
			if (soldCount >= quantity) {
				break;
			}
		}
		return 1;
	}
}

void  Store::Clean()
{
	for (auto it = Products.begin(); it != Products.end();) {
		if ((*it)->GetIsSold()) {
			it = Products.erase(it);
		} else {
			++it;
		}
	}
}

int Store::CalculateProfit() const {
	for(const auto& product : Products) {
		if (product->GetIsSold()) {
			return product->GetSellPrice() - product->GetBuyPrice();
		}
	}
}

void Store::Inventary() {
	for (const auto& product : Products) {
		std::cout << "Product Code: " << product->GetCod() 
				  << ", Sold: " << (product->GetIsSold() ? "Yes" : "No") 
				  << ", Buy Price: " << product->GetBuyPrice() 
				  << ", Sell Price: " << product->GetSellPrice() << std::endl;
	}
}

