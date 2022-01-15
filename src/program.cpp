#include <iostream>

#include <sol/sol.hpp>
#include <cpp-terminal/base.hpp>
#include "argh.h"

#include "core/process.hpp"
#include "model/vehicle.hpp"
#include "db/store.hpp"
#include "program.hpp"

#define SOL_ALL_SAFETIES_ON 1

using Term::bg;
using Term::color;
using Term::color24_bg;
using Term::color24_fg;
using Term::fg;
using Term::style;
using Term::Terminal;


int main(int argc, char* argv[]) {

    argh::parser cmdl;
    cmdl.parse(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);

    if (cmdl["-v"])
        cout << "Verbose, I am." << endl;

    if (cmdl[{"-d", "--demo"}]) {
        std::string title = "Running " 
            + color(style::bold) 
            + "Demo"
            + color(style::reset)
            + ".\n"; 
        cout << title << endl;

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

    } else {
        cout << "Positional args:\n";
        for (auto& pos_arg : cmdl)
            cout << '\t' << pos_arg << endl;

        cout << "Positional args:\n";
        for (auto& pos_arg : cmdl.pos_args())
            cout << '\t' << pos_arg << endl;

        cout << "\nFlags:\n";
        for (auto& flag : cmdl.flags())
            cout << '\t' << flag << endl;

        cout << "\nParameters:\n";
        for (auto& param : cmdl.params())
            cout << '\t' << param.first << " : " << param.second << endl;        
    }

    return EXIT_SUCCESS;
}


