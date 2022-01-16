#include <iostream>

#include "spdlog/spdlog.h"
#include "webview.h"
#include <args.hxx>
#include <cpp-terminal/base.hpp>
#include <sol/sol.hpp>
#include <taskflow/taskflow.hpp>
#include <toml.hpp>
#include <workflow/WFHttpServer.h>
#include <zmq.hpp>

#include "core/process.hpp"
#include "db/store.hpp"
#include "model/vehicle.hpp"
#include "program.hpp"

#define SOL_ALL_SAFETIES_ON 1

int main(int argc, char *argv[])
{
    // configuration
    try
    {
        auto config = toml::parse_file("config.toml");
        std::string_view library_name = config["version"].value_or("0.0.0");
        cout << "Version: " << library_name << endl;
    }
    catch (toml::parse_error &e)
    {
        spdlog::error("toml::parse_file 'config.toml'", e.what());
    }

    // options
    args::ArgumentParser parser("This the prolog main program.",
                                "This goes after the options.");
    args::Group group(
        parser, "This group is all exclusive:", args::Group::Validators::Xor);
    args::Flag demo(group, "demo", "run demo", {'d', "demo"});
    args::Flag task(group, "task", "run task", {'t', "task"});
    args::Flag server(group, "server", "run server", {'s', "server"});
    args::Flag web(group, "web", "view web", {'w', "web"});
    args::Flag msg(group, "msg", "run messaging demo", {'m', "msg"});

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
        spdlog::error("args::ParseError", e.what());
        // std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    if (demo)
    {
        spdlog::info("Welcome to prolog::demo");
        std::string title = "Running " + color(Term::style::bold) + "Demo" +
                            color(Term::style::reset) + ".\n";
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
        lua.open_libraries(sol::lib::base, sol::lib::coroutine,
                           sol::lib::string, sol::lib::io);
        lua.script("print('bark bark bark!')");

        // test main
        program::foo();
    }
    if (task)
    {
        spdlog::info("Welcome to prolog::task");
        tf::Executor executor;
        tf::Taskflow taskflow("simple");

        auto [A, B, C, D] = taskflow.emplace(
            []() { std::cout << "TaskA\n"; }, []() { std::cout << "TaskB\n"; },
            []() { std::cout << "TaskC\n"; }, []() { std::cout << "TaskD\n"; });

        A.precede(B, C); // A runs before B and C
        D.succeed(B, C); // D runs after  B and C

        executor.run(taskflow).wait();
    }
    if (server)
    {
        spdlog::info("Welcome to prolog::server");
        cout << "Running webserver on port 8888" << endl;
        cout << "Press [Enter] to stop." << endl;

        WFHttpServer server(
            [](WFHttpTask *task) {
                task->get_resp()->append_output_body(
                    "<html>Hello World!</html>");
            });

        if (server.start(8888) == 0)
        {              // start server on port 8888
            getchar(); // press "Enter" to end.
            server.stop();
        }
    }
    if (web)
    {
        spdlog::info("Welcome to prolog::web");
        webview::webview w(true, nullptr);
        w.set_title("prolog webview");
        w.set_size(480, 320, WEBVIEW_HINT_NONE);
        w.navigate("https://github.com/webview/webview");
        w.run();
    }
    if (msg)
    {
        spdlog::info("Welcome to prolog::msg");
        zmq::context_t ctx;
        zmq::socket_t sock(ctx, zmq::socket_type::push);
        sock.bind("inproc://test");
        sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
    }
    return 0;
}
