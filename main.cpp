#include <iostream>

#include "ServerHardware.h"

int main() {
    ServerHardware dediHetznerStorage{
        true, false, "Ryzen 7 3700X", 16, 64*1024, {StorageHardware{16*1024, HDD}}, -1, 48.43, 39
    };
    std::cout << dediHetznerStorage << "Server costs " << dediHetznerStorage.calculatePriceYears(5) << " EUR/5 years.\n";
    std::cout << dediHetznerStorage.splitAuto() << "Server costs " << dediHetznerStorage.splitAuto().calculatePriceYears(5) << " EUR/5 years.\n";

    std::cout << "\n\n";

    ServerHardware dediHetznerUltraStorage{
        true, false, "Core i7-6700", 8, 64*1024, {StorageHardware{16*1024, HDD}}, -1, 61.52, 39
    };
    std::cout << dediHetznerStorage << "Server costs " << dediHetznerStorage.calculatePriceYears(5) << " EUR/5 years.\n";
    std::cout << dediHetznerStorage.splitAuto() << "Server costs " << dediHetznerStorage.splitAuto().calculatePriceYears(5) << " EUR/5 years.\n";

    return 0;
}
