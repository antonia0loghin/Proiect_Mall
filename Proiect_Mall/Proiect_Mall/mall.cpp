#include "Mall.h"

int Mall::StockValue() const
{
    int totalStockValue = 0;
    for (const auto& store : Stores) 
    {
        totalStockValue += store->StockValue();
    }
    return totalStockValue;
}

int Mall::SoldValue() const
{
    int totalSoldValue = 0;
    for (const auto& store : Stores)
    {
        totalSoldValue += store->SoldValue();
    }
    return totalSoldValue;
}