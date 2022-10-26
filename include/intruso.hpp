#ifndef INTRUSO_HPP
#define INTRUSO_HPP

#include <string>
#include <vector>
#include <map>

class Intruso {
    private:
        std::map<char, std::vector<int>> *_conjunto_numeros;
        std::string *_senha_vazada;

    public:
        void set_senha_vazada(std::map<char, std::vector<int>> conjunto_numeros,
                                                std::string senha_vazada);
        std::vector<int> crack_senha();
};

#endif