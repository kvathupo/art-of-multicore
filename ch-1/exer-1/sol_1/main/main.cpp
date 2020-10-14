#include <vector>
#include <string>
#include <memory>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>
#include "Chopstick.h"
#include "Person.h"
#include "Table.h"

std::mutex g;

void what_do(std::atomic<Table*>& table, std::string name, int offset) {
    for (auto i = 0; i < 3; i++) {
        auto table_ptr = table.load();
        g.lock();
        table_ptr->eat(name);
        g.unlock();
        table.store(table_ptr);

        std::this_thread::sleep_for(std::chrono::milliseconds(offset));
        if (table.load()->get(name)->is_eating) {
            table_ptr = table.load();
            g.lock();
            table_ptr->think(name);
            g.unlock();
            table.store(table_ptr);
            return;
        }
    }
}

int main() {
    std::vector<std::string> v {"Burke",
            "Darwin",
            "Descartes",
            "Plato"};
    std::atomic<Table*> tbl = new Table(v);

    std::thread t1(what_do, std::ref(tbl), "Burke", 1);
    std::thread t2(what_do, std::ref(tbl), "Darwin", 2);
    std::thread t3(what_do, std::ref(tbl), "Descartes", 1.5);
    std::thread t4(what_do, std::ref(tbl), "Plato", 1.25);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    tbl.load()->print_status();
    delete tbl;
    
    return 0;
}
