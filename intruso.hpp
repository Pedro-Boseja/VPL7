#ifndef INTRUSO_HPP
#define INTRUSO_HPP

#include <string>
#include <vector>
#include <map>

class Intruso {
    private:
        std::vector<std::map<char, std::vector<int>>> _vazou_chave;
        std::vector<std::string> _vazou_senha;

    public:
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};

#endif