#pragma once
#include <string>

class Product
{
private:
    
    Product(const Product& O) = delete;
    Product& operator=(const Product& O) = delete;
    Product() = default;

protected:
    int Cod;
    bool IsSold;
    const float BuyPrice;
    const float InitialSellPrice;
    Product(int cod, float buyPrice, float sellPrice)
		: Cod(cod), IsSold(false), BuyPrice(buyPrice), InitialSellPrice(sellPrice) {
	}
    virtual float GetSellPrice() const = 0;
    const float GetInitialSellPrice() const;
    const float GetBuyPrice() const;
    bool Sell();
    int GetCod() const;
    bool GetIsSold() const;
    friend class Store;
public:
    
    virtual ~Product() {}
    
};
