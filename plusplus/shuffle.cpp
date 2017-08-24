#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char ** argv) {
    std::vector<std::string> files(argv+1, argv+2);

    std::random_device rd;
    std::mt19937 rnd(rd());

    std::shuffle(files.begin(), files.end(), rnd);

    for(const auto& s: files)
        std::cout << s << std::endl;

    return 0;
}
