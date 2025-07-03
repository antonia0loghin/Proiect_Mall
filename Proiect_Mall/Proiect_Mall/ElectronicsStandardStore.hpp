#include "ElectronicsStore.hpp"
#include "StandardStore.hpp"
class ElectronicsStandardStore : public ElectronicsStore, public StandardStore {  
private:  
    ElectronicsStandardStore(std::string name,  int size, int employeecount, float depreciationRate, 
        int warrantyPeriod, int techSupportLevel, int discountRate, float inventoryAgingIndex, bool isLocalBrand, float onlinePresenceScore)  
        : Store(name,  size, employeecount), 
        ElectronicsStore(depreciationRate, warrantyPeriod, techSupportLevel),  
          StandardStore(discountRate, inventoryAgingIndex, isLocalBrand, onlinePresenceScore) {}  

    ElectronicsStandardStore(const ElectronicsStandardStore& O) = delete;  
    ElectronicsStandardStore& operator=(const ElectronicsStandardStore& O) = delete; 
    friend class Mall;
    float GetEstimatedValue() const override {  
        return ElectronicsStore::GetEstimatedValue() * 0.85 + StandardStore::GetEstimatedValue() * 0.15;
    }  
};