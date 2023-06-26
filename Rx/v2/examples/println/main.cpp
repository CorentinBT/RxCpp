#include "rxcpp/rx.hpp"
// create alias' to simplify code
// these are owned by the user so that
// conflicts can be managed by the user.
namespace rx=rxcpp;
namespace rxu=rxcpp::util;

#include<string>

struct Foo{};

auto my_long_obs = rx::observable<>::from(Foo{}, Foo{})
        .map([](auto&& f) { return f; })
        .map([](auto&& f) { return f; });

auto my_second_obs = rx::observable<>::from(Foo{}, Foo{})
        .map([](auto&& f) { return f; })
        .map([](auto&& f) { return f; })
        .map([](auto&& f) { return f; })
        .map([](auto&& f) { return f; });

int main()
{
    auto obs = rx::observable<>::from(Foo{}, Foo{})
        .map([](auto&& f) { return f; })
        .subscribe([](auto&&) { std::cout << "Reception\n"; });

    return 0;
}
