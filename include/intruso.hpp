#ifndef INTRUSO_HPP
#define INTRUSO_HPP

#include <string>
#include <vector>
#include <map>

class Intruso {
    private:
        std::vector<std::vector<int>> _vazou_num;
        std::vector<char> _vazou_char;

    public:
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};

#endif