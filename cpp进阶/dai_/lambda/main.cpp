// File Path: ~/cpp/cpp进阶/dai_/lambda/main.cpp
// File Name: main.cpp
// Directory: ~/cpp/cpp进阶/dai_/lambda
// Date: 2023-06-23

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{

    int c = 10;
    int d = 20;

    auto test = [&](int a, int b)
    {
        std::cout << "d = " << d << std::endl;
        //    c = d;
        return c;
    };

    d = 10;
    std::cout << test(1, 2) << std::endl;

    return 0;
}