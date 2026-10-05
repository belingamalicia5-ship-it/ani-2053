#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    if (!(std::cin >> N)) return 0;

    std::string line;
    for (int i = 0; i < N; ++i) {
        std::cin >> line;
        std::cout << line << "\n";
    }

    return 0;
}
