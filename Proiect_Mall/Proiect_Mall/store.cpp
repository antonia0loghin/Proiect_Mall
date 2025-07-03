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


float Store::StockValue() const {
	float totalValue = 0;
	for (const auto& product : Products) {
		if(!product->GetIsSold()) {
			totalValue += product->GetBuyPrice();
		}
	}
	return totalValue;
}

float Store::SoldValue() const {
	float totalValue = 0;
	for (const auto& product : Products) {
		if (product->GetIsSold()) {
			totalValue += product->GetSellPrice();
		}
	}
	return totalValue;
}
void Store::PrintProducts() const {
	for (const auto& product : Products) {
		std::cout << "Product Code: " << product->GetCod() 
				  << ", Sold: " << (product->GetIsSold() ? "Yes" : "No") 
				  << ", Buy Price: " << product->GetBuyPrice() 
			<< ", Sell Price: " << product->GetSellPrice() << "\n";
	}
}
bool Store::Sell() {
	int productCode;
	PrintProducts();
	std::cout << "Introduceti codul produsului pe care doriti sa il vindeti: ";
	std::cin >> productCode;
	for (auto& product : Products) {
		if (product->GetCod() == productCode && !product->GetIsSold()) {
			bool isSold=product->Sell();
			if (isSold)
			{
				std::cout << "Produsul a fost vandut cu succes!" << "\n";
				return true;
			}
		}
	}
	std::cout << "Produsul nu a fost gasit sau este deja vandut." << "\n";
	return false;
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

float Store::CalculateProfit() const {
	float totalProfit = 0;
	for(const auto& product : Products) {
		if (product->GetIsSold()) {
			totalProfit+=product->GetSellPrice() - product->GetBuyPrice();
		}
	}
	return totalProfit;
}

void Store::Inventary() {
	for (const auto& product : Products) {
		std::cout << "Product Code: " << product->GetCod() 
				  << ", Sold: " << (product->GetIsSold() ? "Yes" : "No") 
				  << ", Buy Price: " << product->GetBuyPrice() 
				  << ", Sell Price: " << product->GetSellPrice() << "\n";
	}
}

float Store::GetEstimatedValue() const 
{
	return Size * 250 + EmployeeCount * 4000;
	return 1;
}

void Store::Menu()
{
    int option;
    do {
        std::cout << "\nMeniu\n";
        std::cout << "1. Afiseaza produse\n";
        std::cout << "2. Vinde produs\n";
        std::cout << "3. Elimina produse vandute\n";
        std::cout << "4. Afiseaza inventar\n";
        std::cout << "5. Numar produse vandute\n";
        std::cout << "6. Numar produse nevandute\n";
        std::cout << "7. Valoare din stoc\n";
        std::cout << "8. Valoare vanduta\n";
        std::cout << "9. Profit\n";
        std::cout << "10. Valoare estimata\n";
		std::cout << "11. Adaugati produs";
        std::cout << "0. Exit\n";
        std::cin >> option;

        switch (option) {
            case 1:
                PrintProducts();
                break;
            case 2:
                Sell();
                break;
            case 3:
                Clean();
                std::cout << "Produse eliminate.\n";
                break;
            case 4:
                Inventary();
                break;
            case 5:
                std::cout << "Cantitate vanduta: " << GetSoldQuantity() << "\n";
                break;
            case 6:
                std::cout << "Cantitate nevanduta: " << GetUnsoldQuantity() << "\n";
                break;
            case 7:
                std::cout << "Valoare din stoc: " << StockValue() << "\n";
                break;
            case 8:
                std::cout << "Valoare vanduta: " << SoldValue() << "\n";
                break;
            case 9:
                std::cout << "Profit: " << CalculateProfit() << "\n";
                break;
            case 10:
                std::cout << "Valoare estimata: " << GetEstimatedValue() << "\n";
                break;
			case 11:
				AddProduct(nullptr); 
            case 0:

                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (option != 0);
}

