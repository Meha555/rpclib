#include "rpc/server.h"
#include "proto_data.h"
#include <iostream>

int main() {
    rpc::server srv(rpc::constants::DEFAULT_PORT);
    std::cout << "registered on  port " << srv.port() << std::endl;

    srv.bind("echo", [](std::string const& s, const proto::Person &p) {
        return std::make_pair(s, p);
    });

    srv.run();
    return 0;
}
