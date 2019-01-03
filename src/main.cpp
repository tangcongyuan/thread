#include <iostream>
#include <thread>

void print() {
    std::cout << "Hello concurrent world!" << std::endl;
}

int main(int argc, char** argv) {
    std::thread thread(print);
    thread.join();
    return 0;
}
