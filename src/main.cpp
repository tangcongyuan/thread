#include "thread_guard.h"
#include "threadsafe_queue.h"
#include <thread>
#include <iostream>

void print() {
    std::cout << "Hello concurrent world!" << std::endl;
}

void push1(threadsafe_queue<int>& queue) {
    for(int i = 0; i < 500; i++)
        queue.push(2 * i);
}

void push2(threadsafe_queue<int>& queue) {
    for(int i = 0; i < 500; i++)
        queue.push(2 * i + 1);
}

int main(int argc, char** argv) {
    // std::thread thread(print);
    // thread.join();
    // f();
    std::cout << "Your computer has " << std::thread::hardware_concurrency() << " cores." << std::endl; 

    threadsafe_queue<int> queue{};
    std::thread t1(push1, std::ref(queue));
    std::thread t2(push2, std::ref(queue));
    t1.join(); t2.join();

    while(!queue.empty()) {
        std::cout << "Poping data: " << *queue.try_pop() << std::endl;
    }

    return 0;
}
