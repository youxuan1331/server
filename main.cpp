#include <chrono>
#include <coroutine>
#include <exception>
#include "debug.hpp"

struct Promise {
    auto initial_suspend() noexcept {
        return std::suspend_always();
    }

    auto final_suspend() noexcept {
        return std::suspend_always();
    }

    void return_void() {}

    void unhandled_exception() {
        std::terminate();
    }

    std::coroutine_handle<Promise> get_return_object() {
        return std::coroutine_handle<Promise>::from_promise(*this);
    }
};

struct Task {
    using promise_type = Promise;
    std::coroutine_handle<Promise> handle;

    Task(std::coroutine_handle<Promise> coroutine) : handle(coroutine) {}
    ~Task() { if (handle) handle.destroy(); }
};

Task hello() {
    std::cout << "Hello from coroutine!\n";
    co_return;
}

int main() {
    Task t = hello();
    t.handle.resume(); // 启动协程
    return 0;
}