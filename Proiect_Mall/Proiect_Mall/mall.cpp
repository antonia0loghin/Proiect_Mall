#include "Mall.h"
#include <iostream>
#include "ElectronicsStandardStore.hpp"
#include "ElectronicsLuxuryStore.hpp"
#include "WearableStandardStore.hpp"
#include "WearableLuxuryStore.hpp"
float  Mall::StockValue() const
{
    float totalStockValue = 0;
    for (const auto& store : Stores) 
    {
        totalStockValue += store->StockValue();
    }
    return totalStockValue;
}

float Mall::SoldValue() const
{
    float totalSoldValue = 0;
    for (const auto& store : Stores)
    {
        totalSoldValue += store->SoldValue();
    }
    return totalSoldValue;
}
float Mall::EstimatedValue() const
{
    float totalEstimatedValue = 0;
    for (const auto& store : Stores)
    {
        totalEstimatedValue += store->GetEstimatedValue();
    }
    return totalEstimatedValue;
}
void Mall::AddStore()
{
    Store* store;
	std::string name;
	int size, employeeCount;
	std::cout << "Introduceti numele magazinului, dimensiunea (m^2) si numarul de angajati: ";
	std::cin >> name >> size >> employeeCount;
    bool Category; //(1-electronic, 0-wearable)
	std::cout << "Introduceti categoria magazinului (1-electronic, 0-wearable): ";
	std::cin >> Category;
    if (Category)
    {
        float depreciationRate;
        int warrantyPeriod, techSupportLevel;
        std::cout << "Introduceti rata de depreciere (0-1), perioada de garantie (luni) si nivelul de suport tehnic (1-5): ";
        std::cin >> depreciationRate >> warrantyPeriod >> techSupportLevel;
		bool isStandard; // (1 - standard, 0 - luxury)
		std::cout << "Introduceti daca este magazin standard (1) sau de lux (0): ";
        std::cin >> isStandard;
        if (isStandard)
        {
			int discountRate;
			float inventoryAgingIndex, onlinePresenceScore;
			bool isLocalBrand;
			std::cout << "Introduceti rata de discount (0-100), indicele de vechime al inventarului (1-10), daca este marca locala (1/0) si scorul de prezenta online (1-100): ";
            std::cin >> discountRate >> inventoryAgingIndex >> isLocalBrand >> onlinePresenceScore;
            store = new ElectronicsStandardStore(name, size, employeeCount, depreciationRate, warrantyPeriod, techSupportLevel, discountRate, inventoryAgingIndex, isLocalBrand, onlinePresenceScore);
        }
        else
        {
			int brandPrestigeIndex, storeAmbienceScore;
			float customerLoyaltyRate;
			std::cout << "Introduceti indicele de prestigiu al brandului (1-10), scorul de ambianta al magazinului (1-100) si rata de fidelizare a clientilor (1-5): ";
			std::cin >> brandPrestigeIndex >> storeAmbienceScore >> customerLoyaltyRate;
			store = new ElectronicsLuxuryStore(name, size, employeeCount, depreciationRate, warrantyPeriod, techSupportLevel, brandPrestigeIndex, storeAmbienceScore, customerLoyaltyRate);
        }
    }
    else
    {
		int collectionCount, ownBrandPercentage, yearlyEvents;
		bool isDiverse;
		std::cout << "Introduceti numarul de colectii lansate pe an, procentul de marca proprie (1-100), daca este diversificat (1/0) si numarul de evenimente anuale: ";
		std::cin >> collectionCount >> ownBrandPercentage >> isDiverse >> yearlyEvents;
        bool isStandard; // (1 - standard, 0 - luxury)
        std::cout << "Introduceti daca este magazin standard (1) sau de lux (0): ";
        std::cin >> isStandard;
        if (isStandard)
        {
            int discountRate;
            float inventoryAgingIndex, onlinePresenceScore;
            bool isLocalBrand;
            std::cout << "Introduceti rata de discount (0-100), indicele de vechime al inventarului (1-10), daca este marca locala (1/0) si scorul de prezenta online (1-100): ";
            std::cin >> discountRate >> inventoryAgingIndex >> isLocalBrand >> onlinePresenceScore;
			store = new WearableStandardStore(name, size, employeeCount, collectionCount, ownBrandPercentage, isDiverse, yearlyEvents, discountRate, inventoryAgingIndex, isLocalBrand, onlinePresenceScore);
        }
        else
        {
            int brandPrestigeIndex, storeAmbienceScore;
            float customerLoyaltyRate;
            std::cout << "Introduceti indicele de prestigiu al brandului (1-10), scorul de ambianta al magazinului (1-100) si rata de fidelizare a clientilor (1-5): ";
            std::cin >> brandPrestigeIndex >> storeAmbienceScore >> customerLoyaltyRate;
			store = new WearableLuxuryStore(name, size, employeeCount, collectionCount, ownBrandPercentage, isDiverse, yearlyEvents, brandPrestigeIndex, storeAmbienceScore, customerLoyaltyRate);
        }
    }
	Stores.push_back(store);

}
void Mall::AddProductstoStore()
{
        if (Stores.empty())
    {
        std::cout << "Nu exista magazine in mall. Adaugati mai intai un magazin." << "\n";
        return;
    }
    
    int storeIndex;
    std::cout << "Introduceti indexul magazinului la care doriti sa adaugati produse (0 - " << Stores.size() - 1 << "): ";
    std::cin >> storeIndex;
    if (storeIndex < 0 || storeIndex >= Stores.size())
    {
        std::cout << "Index invalid." << "\n";
        return;
    }
    Store* selectedStore = Stores[storeIndex];
	bool continueAdding = true;
    while (continueAdding)
    {
        selectedStore->AddProduct(nullptr); // Aici ar trebui sa se adauge un produs real, dar pentru simplitate folosim nullptr
        std::cout << "Doriti sa adaugati un alt produs? (1 - da, 0 - nu): ";
        std::cin >> continueAdding;
    }
}
void Mall::PrintStores() const
{
    if (Stores.empty())
    {
        std::cout << "Nu exista magazine in mall. Adaugati mai intai un magazin." << "\n";
        return;
    }
    if (Stores.empty())
    {
        std::cout << "Nu exista magazine in mall." << "\n";
        return;
    }
    
    for(int i=0;i<Stores.size();++i)
    {
		auto& store = Stores[i];
        std::cout <<i<< " Nume Magazin: " << store->Name << ", Dimensiune: " << store->Size 
                  << " m^2, Numar Angajati: " << store->EmployeeCount 
                  << ", Valoare Stoc: " << store->StockValue() 
                  << ", Valoare Vanzari: " << store->SoldValue() 
                  << ", Valoare Estimata: " << store->GetEstimatedValue() << "\n";
        store->PrintProducts();
	}
}

void Mall::StoreOptions()
{
    if (Stores.empty())
    {
        std::cout << "Nu exista magazine in mall. Adaugati mai intai un magazin." << "\n";
        return;
    }
    PrintStores();
    int storeIndex;
    std::cout << "Introduceti indexul magazinului la care doriti sa adaugati produse (0 - " << Stores.size() - 1 << "): ";
    std::cin >> storeIndex;
    if (storeIndex < 0 || storeIndex >= Stores.size())
    {
        std::cout << "Index invalid." << "\n";
        return;
    }
    Store* selectedStore = Stores[storeIndex];

	selectedStore->Menu();

}

void Mall::Menu()
{
    int optiune = -1;
    while (optiune != 0)
    {
        std::cout << "\nMeniu Mall\n";
        std::cout << "1. Adauga magazin\n";
        std::cout << "2. Adauga produse intr-un magazin\n";
        std::cout << "3. Afiseaza magazinele\n";
        std::cout << "4. Optiuni magazin\n";
        std::cout << "5. Afiseaza valoare totala stoc\n";
        std::cout << "6. Afiseaza valoare totala vanzari\n";
        std::cout << "7. Afiseaza valoare totala estimata\n";
        std::cout << "0. Iesire\n";
        std::cout << "Introduceti optiunea: ";
        std::cin >> optiune;

        switch (optiune)
        {
        case 1:
            AddStore();
            break;
        case 2:
            AddProductstoStore();
            break;
        case 3:
            PrintStores();
            break;
        case 4:
            StoreOptions();
            break;
        case 5:
            std::cout << "Valoare totala stoc: " << StockValue() << "\n";
            break;
        case 6:
            std::cout << "Valoare totala vanzari: " << SoldValue() << "\n";
            break;
        case 7:
            std::cout << "Valoare totala estimata: " << EstimatedValue() << "\n";
            break;
        case 0:
            std::cout << "Iesire din meniu.\n";
            break;
        default:
            std::cout << "Optiune invalida. Incercati din nou.\n";
            break;
        }
    }
}
Mall& Mall::getInstance() {
    static Mall instance;  
    return instance;
}