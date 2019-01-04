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
    return 0;
}
