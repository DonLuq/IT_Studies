#if __cplusplus < 201412L
#endif

#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

namespace fs = std::filesystem;

auto f = []() {
    static int x = 0;
    return x++;
};

int main()
{

    // std::cout<< f()<< std::endl;
    // std::cout<< f()<< std::endl;
    // std::cout<< f()<< std::endl;
    // std::cout<< f()<< std::endl;
    // std::cout<< f()<< std::endl;

    fs::current_path("/tmp");

    for (auto& p: fs::recursive_directory_iterator(fs::current_path()))
        std::cout << p.path() << '\n';

    return 0;
}
