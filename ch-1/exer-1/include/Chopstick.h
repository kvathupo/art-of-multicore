#pragma once
#include <string>

class Chopstick {
public:
    bool available {true};
    std::string owner;

    Chopstick() = default;
};
