#include "generator.h"

#include <iostream>
// promise_type interface

generator::promise_type::coro_handle generator::promise_type::from_promise() {
  return coro_handle::from_promise(*this);
}

generator::promise_type::coro_handle
generator::promise_type::get_return_object() {
  return coro_handle::from_promise(*this);
}

std::suspend_always generator::promise_type::initial_suspend() {
  return std::suspend_always{};
}

std::suspend_always generator::promise_type::final_suspend() {
  return std::suspend_always{};
}

#if 0
void generator::promise_type::return_void() { return; }
#endif

std::suspend_always generator::promise_type::yield_value(int value) {
#if 0
  std::cout << "val: " << value << '\n';
#endif

  current_value = value;
  return std::suspend_always{};
}

void generator::promise_type::unhandled_exception() { std::terminate(); }

// coroutine interface
generator::generator(coro_handle handle) : handle_(handle) {}

generator::generator(generator &&other) : handle_(std::move(other.handle_)) {
  other.handle_ = nullptr;
}

int generator::current_value() { return handle_.promise().current_value; }

bool generator::next() {
  // return handle_ ? (handle_.resume(), !handle_.done()) : false;
  if (!handle_.done())
    handle_.resume();
  return !handle_.done();
}

generator::~generator() {
  if (handle_)
    handle_.destroy();
}
