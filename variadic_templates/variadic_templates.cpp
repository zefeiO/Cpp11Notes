#include <sstream>
#include <iostream>
#include <vector>

template <typename T>
std::string to_string_impl(const T& t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <typename... Params>
std::vector<std::string> to_string(const Params&... params) {
    return {to_string_impl(params)...};
}

int main() {
    const auto vec = to_string("abc", 1, 1.3f, 5.3, 'r');
    for (const auto& v:vec) {
        std::cout << v << std::endl;
    }
    return 0;
}