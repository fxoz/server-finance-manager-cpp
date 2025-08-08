//
// Created by Lynx on 2025-08-08.
//

#ifndef SERVERHARDWARE_H
#define SERVERHARDWARE_H
#include <cmath>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <sstream>

#include "StorageHardware.h"
#include "utils.h"

enum RAM_TYPE {
    DDR4,
    DDR5
};

class ServerHardware {
private:
    void hasBeenSplit(int nTimes) {
        _splitN = nTimes;
    }

protected:
    std::string _cpu;
    bool _onlyIPv6;
    bool _isDedicated;
    int _threads;
    int _ramMb;
    std::vector<StorageHardware> _storage;
    float _bandwidthTb; // -1 for unlimited
    int _splitN = 0;

    float _eurMonthly;
    float _eurOneTime;
public:
    ServerHardware(int isDedicated, bool onlyIPv6, std::string cpu, int threads, int ramMb, std::vector<StorageHardware> storage, float bandwidthTb, float eurMonthly, float eurOneTime) :
        _isDedicated(isDedicated), _onlyIPv6(onlyIPv6), _cpu(cpu), _threads(threads), _ramMb(ramMb), _storage(storage), _bandwidthTb(bandwidthTb), _eurMonthly(eurMonthly), _eurOneTime(eurOneTime) {};

    friend std::ostream& operator<<(std::ostream& os, const ServerHardware& server) {
        os << "[" + (server._splitN ?  std::to_string(server._splitN) + "x split ~ " : "")
        + std::to_string(server._threads) + "T"  + "/" + prettyMb(server._ramMb)
        + " | " + multiStorageToString(server._storage)
        + " | " + server._cpu + " | "
        + (server._bandwidthTb == -1 ? "inf" : std::to_string(server._bandwidthTb) + "TB")
        + " Bandw. @ "
        + actualPriceString(server._eurMonthly) + "/mo"
        + " | " + actualPriceString(server._eurOneTime) + "/setup"
        + "] ";
        return os;
    };

    ServerHardware split(int n=-1) {
        n = (n < 1 ? _threads : n);

        int storageGb = floor(totalStorageGb(_storage)/(float)n);

        hasBeenSplit(n);

        ServerHardware splitInstance = ServerHardware{
            _isDedicated, _onlyIPv6, _cpu, _threads/n, _ramMb/n, {dummyStorageWithGb(storageGb)}, (_bandwidthTb == -1 ? -1 : _bandwidthTb/n), _eurMonthly/n, _eurOneTime/n
        };

        splitInstance.hasBeenSplit(n);
        return splitInstance;
    }

    ServerHardware splitAuto() {
        return split(-1);
    }

    float calculatePriceMonths(int months) {
        return _eurMonthly*months + _eurOneTime;
    }

    float calculatePriceYears(int years) {
        return _eurMonthly*(years*12) + _eurOneTime;
    }
};


#endif //SERVERHARDWARE_H
