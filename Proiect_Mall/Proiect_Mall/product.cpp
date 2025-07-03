#include "Product.h"


int Product::GetCod() const {
	return Cod;
}

bool Product::GetIsSold() const {
	return IsSold;
}

bool Product::Sell() {
	if (IsSold)
	{
		return 0;
	}
	else
	{
		IsSold = true;
		return 1;
	}
}

const float Product::GetInitialSellPrice() const {
	return InitialSellPrice;
}
const float Product::GetBuyPrice() const {
	return BuyPrice;
}

