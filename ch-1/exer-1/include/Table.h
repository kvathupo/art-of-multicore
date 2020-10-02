#pragma once
#include <string>
#include <memory>
#include <unordered_map>

class Table {
    std::vector<std::unique_ptr<Person>> table;
    std::vector<std::shared_ptr<Chopstick>> utensils;

public:
    Table() = default;
    Table(int size):
        table{std::vector<std::unique_ptr<Person>> (size)},
        utensils{std::vector<std::shared_ptr<Chopstick>> (size)} {
        for (auto i = 0; i < size; i++) {
            utensils[i] = std::make_shared<Chopstick>();
        }
    }

    void add(std::string name) {
        table[index] = std::make_unique<Person>(name, j);
    }
};
