#ifndef PROTO_DATA_H
#define PROTO_DATA_H

#include <ostream>
#include <string>
#include "rpc/msgpack.hpp"

namespace proto
{

enum Gender {
    MALE = 0,
    FEMALE = 1
};

struct Email
{
    std::string domain;
    std::string account;
    MSGPACK_DEFINE(domain, account)
};

struct Person
{
    std::string name;
    int age;
    Gender sex;
    Email email;

    MSGPACK_DEFINE(name, age, sex, email);
};

inline std::ostream &operator<<(std::ostream &os, const Email &email)
{
    os << "Email: (" << email.domain << " " << email.account << ")";
    return os;
}

inline std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << "Person: (" << person.name << " " << person.age << " " << (person.sex == Gender::MALE ? "male" : "female") << " " << person.email << ")";
    return os;
}

}

// global namespace
MSGPACK_ADD_ENUM(proto::Gender);

#endif // PROTO_DATA_H