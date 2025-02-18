#include <fmt/core.h>
#include <type_traits>
#include <iostream>


template <typename T>
auto value_of(const T v) {
    if constexpr (std::is_pointer_v<T>) {
        return *v;
    } else {
        return v;
    }
}

int main() {

    int x{50};
    int* y{&x};

    std::cout << fmt::format("value is {}", value_of(x));
    std::cout << fmt::format("value is {}", value_of(y));

    return EXIT_SUCCESS;
}
