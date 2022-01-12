
#include "core/process.hpp"
#include "model/vehicle.hpp"
#include "db/store.hpp"
#include "program.hpp"

int main() {
    model::Vehicle v;
    core::Process p;
    db::Store s;
    v.cost = 10.2;
    v.weight = 22.3;
    p.report(v);
    s.demo();
    program::foo();
    return 0;
}


