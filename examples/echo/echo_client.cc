#include "proto_data.h"
#include "rpc/client.h"
#include <iostream>

using namespace std::string_literals;

int main() {
    rpc::client c("localhost", rpc::constants::DEFAULT_PORT);

    std::string text;
    while (std::getline(std::cin, text)) {
        if (!text.empty()) {
            auto result = c.call("echo", text,
                                 proto::Person{"Tom"s, // name
                                        20,     // age
                                        proto::Gender::MALE,      // sex
                                        proto::Email{
                                            "gmail.com"s,    // domain
                                            "tom@gmail.com"s // account
                                        }})
                              .as<std::pair<std::string, proto::Person>>();
            std::cout << "> " << result.first << ", " << result.second
                      << std::endl;
        }
    }
}
