#ifndef INCLUDE_CORE_PROCESS_H
#define INCLUDE_CORE_PROCESS_H

#include <string>

#include "model/vehicle.hpp"

using namespace std;


namespace core {

class Process {
    public:
        void report(model::Vehicle v);
};

}

#endif
