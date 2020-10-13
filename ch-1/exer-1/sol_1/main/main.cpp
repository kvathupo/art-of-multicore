#include <vector>
#include <thread>
#include <atomic>
#include <string>
#include <memory>
#include "Chopstick.h"
#include "Person.h"
#include "Table.h"

void what_do(std::atomic<Table>& table, std::string name, int offset) {
    for (auto i = 0; i < 3; i++) {
        table.eat(name);
        std::this_thread::sleep_for(offset);
        if (table.get(name)->is_eating) {
            table.think(name);
            return;
        }
    }
}

int main() {
    std::vector<std::string>> v {"Burke",
            "Darwin",
            "Descartes",
            "Plato"};
    std::atomic<Table> tbl(v);

    std::thread t1(what_do, tbl, "Burke", 1);
    std::thread t2(what_do, tbl, "Darwin", 2);
    std::thread t3(what_do, tbl, "Descartes", 1.5);
    std::thread t4(what_do, tbl, "Plato", 1.25);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    return 0;
}
