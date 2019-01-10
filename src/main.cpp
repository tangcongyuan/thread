#include "thread_guard.h"
#include "threadsafe_queue.h"
#include <future>
#include <thread>
#include <iostream>
#include <string>

void print() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
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

void demo_threadsafe_queue() {
    threadsafe_queue<int> queue{};
    std::thread t1(push1, std::ref(queue));
    std::thread t2(push2, std::ref(queue));
    t1.join(); t2.join();

    while(!queue.empty()) {
        std::cout << "Poping data: " << *queue.try_pop() << std::endl;
    }
}

std::string return_some_string() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return std::string("back from future");
}

int main(int argc, char** argv) {
    // std::thread thread(print);
    // thread.join();
    // f();
    std::cout << "Your computer has " << std::thread::hardware_concurrency() << " cores." << std::endl; 

    // demo_threadsafe_queue();

    std::future<std::string> future_string = std::async(std::launch::async, return_some_string);
    std::cout << "String will be retured from future." << std::endl;
    std::cout << "String from future is: " << future_string.get() << std::endl;

    return 0;
}
