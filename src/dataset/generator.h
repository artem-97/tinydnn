#pragma once

#include <coroutine>
#include <exception>

class generator {
public:
  struct promise_type {
    int current_value;
    using coro_handle = std::coroutine_handle<promise_type>;

    coro_handle from_promise();
    coro_handle get_return_object();

    std::suspend_always initial_suspend();
    std::suspend_always final_suspend();

    // void return_void();
    std::suspend_always yield_value(int value);

    void unhandled_exception();
  };

  using coro_handle = std::coroutine_handle<promise_type>;
  generator(coro_handle handle);

  generator(const generator &) = delete;
  generator(generator &&);

  int current_value();

  bool next();
  ~generator();

private:
  coro_handle handle_;
};
