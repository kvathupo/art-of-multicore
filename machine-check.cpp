#include <iostream>
#include <thread>

int main() {
    std::cout << "I can run " << std::thread::hardware_concurrency() << 
        " threads!\n";

    return 0;
}
