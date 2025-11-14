#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    std::string out;
    for (int i = 1; i < argc; ++i)
    {
        if (i > 1)
            out += " ";
        std::string s = argv[i];
        for (size_t j = 0; j < s.length(); ++j)
            out += (char)std::toupper(s[j]);
    }
    std::cout << out << std::endl;
    return 0;
}
