
#include "core/process.hpp"
#include "model/vehicle.hpp"
#include "db/store.hpp"
#include "program.hpp"

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

int main() {

    // test classes
    model::Vehicle v;
    core::Process p;
    db::Store s;
    v.cost = 10.2;
    v.weight = 22.3;
    p.report(v);
    s.demo();

    // test lua wrapper 'sol'
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::coroutine, sol::lib::string, sol::lib::io);
    lua.script("print('bark bark bark!')");
    
    // test main
    program::foo();

    return 0;
}


