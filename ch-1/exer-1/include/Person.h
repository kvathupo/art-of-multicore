#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "Chopstick.h"

class Person {
public:
    std::shared_ptr<Chopstick> left;
    std::shared_ptr<Chopstick> right;
    const std::string name;
    bool is_eating {false};

    Person(std::string name):
        left{nullptr},
        right{nullptr},
        name{name}
    {}
    Person(std::string name, std::shared_ptr<Chopstick> left):
        left{left},
        right{nullptr},
        name{name}
    {}
    Person(std::string name, std::shared_ptr<Chopstick> left,
        std::shared_ptr<Chopstick> right):
        left{left},
        right{right},
        name{name}
    {}

    // methods
    void eat() {
        if (left->available) {
            left->available = false;
            left->owner = name;
        } 
        if (right->available) {
            right->available = false;
            right->owner = name;
        }

        bool can_eat = (right->owner == name && left->owner == name) ? true : false;
        is_eating = can_eat;
        if (!can_eat) 
            std::cout << name << " can't eat!\n";
    }

    void think() {
        if (is_eating) {
            left->available = true;
            right->available = true;
            is_eating = false;
        } else {
            std::cout << name << " tried to start thinking without a meal!\n";
        }
    }
};
