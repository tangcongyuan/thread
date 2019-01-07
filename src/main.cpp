#include "thread_guard.h"
#include <thread>
#include <iostream>

void print() {
    std::cout << "Hello concurrent world!" << std::endl;
}

int main(int argc, char** argv) {
    // std::thread thread(print);
    // thread.join();
    f();
    std::cout << "Your computer has " << std::thread::hardware_concurrency() << " cores." << std::endl;
    return 0;
}
