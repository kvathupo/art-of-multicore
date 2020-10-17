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
        auto lower_chopstick = (left->priority < right->priority) ? left : right;
        auto higher_chopstick = (left->priority < right->priority) ? right : left;
        
        if (lower_chopstick->available) {
            lower_chopstick->available = false;
            lower_chopstick->owner = name;
            
            if (higher_chopstick->available) {
                higher_chopstick->available = false;
                higher_chopstick->owner = name;
            }
        } 

        bool can_eat = (right->owner == name && left->owner == name) ? true : false;
        is_eating = can_eat;
        if (!can_eat) 
            std::cout << name << " can't eat!\n";
    }

    void think() {
        is_eating = false;
        left->available = (left->available == false && left->owner == name) ? 
            true : left->available;
        right->available = (right->available == false && right->owner == name) ? 
            true : right->available;
    }
};
