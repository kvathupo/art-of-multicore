#pragma once
#include <string>
#include <memory>
#include <cassert>
#include <vector>
#include <stdexcept>
#include "Chopstick.h"
#include "Person.h"

class Table {
    std::vector<std::unique_ptr<Person>> people;
    std::vector<std::shared_ptr<Chopstick>> utensils;
    size_t num_chairs {0};

public:
    Table() = default;
    Table(std::vector<std::string> names):
        people{std::vector<std::unique_ptr<Person>> (names.size())},
        utensils{std::vector<std::shared_ptr<Chopstick>> (names.size())},
        num_chairs{names.size()}
    {
        for (auto i = 0; i < names.size(); i++) {
            utensils[i] = std::make_shared<Chopstick>();
            if (i == 0) {
                people[i] = std::make_unique<Person>(names[i], utensils[i]);
            } else if (i == names.size() - 1) {
                // Wrap around to the first utensil
                people[i] = std::make_unique<Person>(names[i], utensils[i], utensils[0]);
                people[i - 1]->right = utensils[i];
            } else {
                people[i] = std::make_unique<Person>(names[i], utensils[i]);
                people[i - 1]->right = utensils[i];
            }
        }
    }

    // Get by name
    const std::unique_ptr<Person>& get(std::string name) {
        for (const auto& person : this->people) {
            if (person->name == name) {
                return person;
            }
        }
        throw std::runtime_error(name + " does not exist!");
    }
    // Eat by name
    void eat(std::string name) {
        for (const auto& person : this->people) {
            if (person->name == name) {
                person->eat();
            }
        }
    }
    // Eat by index
    void eat(int idx) {
        assert(idx < this->people.size());

        this->people[idx]->eat();
    }
    // Think by name
    void think(std::string name) {
        for (const auto& person : this->people) {
            if (person->name == name) {
                person->think();
            }
        }
    }
    // Think by index
    void think(int idx) {
        assert(idx < this->people.size());

        this->people[idx]->think();
    }
};
