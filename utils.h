//
// Created by Lynx on 2025-08-08.
//

#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

#include "StorageHardware.h"

const int TerabyteInMb = 1024*1024;

inline std::string prettyMb(int mb) {
    if (mb >= TerabyteInMb && !(mb % TerabyteInMb)) {
        return std::to_string(mb/TerabyteInMb) + "T";
    }

    if (mb >= 1024 && !(mb % 1024)) {
        return std::to_string(mb/1024) + "G";
    }
    return std::to_string(mb) + "M";
}

inline int totalStorageGb(std::vector<StorageHardware> multiStorage) {
    int totalGb = 0;

    for (auto &storage : multiStorage) {
        totalGb += storage.gb;
    }
    return totalGb;
}

inline std::string multiStorageToString(std::vector<StorageHardware> multiStorage) {
    int totalGb = totalStorageGb(multiStorage);
    return prettyMb(totalGb*1024) + " (total)";
}

inline StorageHardware dummyStorageWithGb(int gb) {
    return StorageHardware{gb, UNKNOWN};
}

inline float actualPrice(float price) { // ceil & set precision to 2
    return std::ceil(price * 100) / 100.0f;
}

inline std::string actualPriceString(float price) { // ceil & set precision to 2 -> string + EUR
    std::ostringstream out;
    out << std::fixed << std::setprecision(2) << ceil(price * 100) / 100.0f << " EUR";
    return out.str();
}
