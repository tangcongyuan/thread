#include <thread>
#include <iostream>

class thread_guard {
    std::thread thread;
public:
    explicit thread_guard(std::thread t_): thread(std::move(t_)) {
        if(!thread.joinable()) throw std::logic_error("No thread");
    }

    ~thread_guard() {
        if(thread.joinable()) thread.join();
    }

    thread_guard(const thread_guard& t)=delete;
    thread_guard& operator=(const thread_guard& t)=delete;
};

struct functor {
    unsigned int& i;
    functor(unsigned int& i_): i(i_) {}
    void operator()() {
	    std::cout << "Your're in thread: " << std::this_thread::get_id() << std::endl;
        for(unsigned j = 0; j < i; j++) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Functor thread waited some time to be here..." << std::endl;
        }
    }
};

void f() {
    unsigned int pause = 3;
    thread_guard thread((std::thread(functor(pause))));
    std::cout << "Your're in main thread: " << std::this_thread::get_id() << std::endl;
}
