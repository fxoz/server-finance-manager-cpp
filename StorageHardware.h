//
// Created by Lynx on 2025-08-08.
//

#ifndef STORAGEHARDWARE_H
#define STORAGEHARDWARE_H

enum STORAGE_TYPE {
    HDD,
    HDD_CACHED,
    SSD,
    NVMe,
    UNKNOWN,
};

struct StorageHardware {
    int gb;
    STORAGE_TYPE type;
    //StorageHardware(int gb, STORAGE_TYPE type) : gb(gb), type(type) {};
};

#endif //STORAGEHARDWARE_H
