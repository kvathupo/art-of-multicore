#pragma once
#include <string>

class Chopstick {
public:
    bool available {true};
    std::string owner;
    int priority;

    Chopstick() = default;
    Chopstick(int priority):
        priority{priority}
    {}
    Chopstick(const Chopstick&) = default;
    Chopstick& operator=(const Chopstick&) = default;
};
