#include <iostream>

#include <sol/sol.hpp>
#include <cpp-terminal/base.hpp>
#include <args.hxx>
#include <workflow/WFHttpServer.h>
#include <taskflow/taskflow.hpp>
#include <toml.hpp>

#include "core/process.hpp"
#include "model/vehicle.hpp"
#include "db/store.hpp"
#include "program.hpp"

#define SOL_ALL_SAFETIES_ON 1

int main(int argc, char* argv[]) {
    // configuration
    auto config = toml::parse_file("config.toml");
    std::string_view library_name = config["version"].value_or("0.0.0");
    cout << "Version: " << library_name << endl; 

    args::ArgumentParser parser("This the prolog main program.", "This goes after the options.");
    args::Group group(parser, "This group is all exclusive:", args::Group::Validators::Xor);
    args::Flag demo(group, "demo", "run demo", {'d', "demo"});
    args::Flag task(group, "task", "run task", {'t', "task"});
    args::Flag server(group, "server", "run server", {'s', "server"});
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help)
    {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    if (demo) {
        std::string title = "Running " 
            + color(Term::style::bold) 
            + "Demo"
            + color(Term::style::reset)
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
    }
    if (task) {
        tf::Executor executor;
        tf::Taskflow taskflow("simple");

        auto [A, B, C, D] = taskflow.emplace(
            []() { std::cout << "TaskA\n"; },
            []() { std::cout << "TaskB\n"; },
            []() { std::cout << "TaskC\n"; },
            []() { std::cout << "TaskD\n"; }
        );

        A.precede(B, C);  // A runs before B and C
        D.succeed(B, C);  // D runs after  B and C

        executor.run(taskflow).wait();
    }
    if (server) {
        cout << "Running webserver on port 8888" << endl;
        cout << "Press [Enter] to stop." << endl;

        WFHttpServer server([](WFHttpTask *task) {
            task->get_resp()->append_output_body("<html>Hello World!</html>");
        });

        if (server.start(8888) == 0) { // start server on port 8888
            getchar(); // press "Enter" to end.
            server.stop();
        }

    }

    return 0;

}


