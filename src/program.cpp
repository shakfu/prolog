
#include "core/process.hpp"
#include "model/vehicle.hpp"
#include "program.hpp"

int main() {
    model::Vehicle v;
    core::Process p;
    v.cost = 10.2;
    v.weight = 22.3;
    p.report(v);
    program::foo();
    return 0;
}


