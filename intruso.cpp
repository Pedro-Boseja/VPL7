#include "intruso.hpp"

#include <string>
#include <vector>
#include <map>
#include <iostream>

void Intruso::set_senha_vazada(std::string vazou) {
    int k = 10;
    char ponte[6];
    for (int j = 0; j < 6; j++) {
        ponte[j] = vazou[k];
        k++;  
    }
    _vazou_senha.push_back(ponte);
    
    std::map<char, std::vector<int>> passarela;
    char c = 'A';
    for (int j = 0; j < 10; j+=2){
        std::vector<int> nums;
        nums.push_back(int(vazou[j]) - 48); nums.push_back(int(vazou[j+1]) - 48);
        passarela[c] = nums;
        c++;
    }
    //std::cout << passarela.at('A')[0] << passarela.at('A')[1] << std::endl;
    _vazou_chave.push_back(passarela);  
    //std::cout << passarela.at('B')[0] << passarela.at('B')[1] <<std::endl;
    // Verificado OK
}

std::string Intruso::crack_senha() {
    std::string senha {};
    std::cout << "ponto0\n";
    std::vector<std::vector<int>> suposta_senha;
    int i = 0;
    for (int t = 0; t < _vazou_senha.size(); t++){
        std::cout << "ponto1\n";
        std::map<char, std::vector<int>> chave;
        chave = _vazou_chave[t];
        char k = 'A';
        for (char j = 'A'; j <= 'E'; j++){
            std::cout << "ponto2\n";
            //std::cout << _vazou_senha[t][i] << std::endl;
            if (_vazou_senha[t][i] == k){
                std::cout << "ponto3\n";
                suposta_senha.push_back(chave.at(j));
                std::cout << suposta_senha[t][0] << suposta_senha[t][1] << std::endl;
                //std::cout << chave.at(j)[0];
                chave = {};
                break;
            }
            else {k += 1; i += 1;}
        }
    }
    std::cout << "ponto4\n";
    // Verificado OK

    for (int t = 0; t < 6; t++){
        std::cout << "ponto5\n";
        int qtde_senhas = suposta_senha.size();
        for (int i = 0; i < 6*(qtde_senhas-1); i++){
            std::cout << "ponto6\n";
            for (int j = 0; j < 2; j++){
                std::cout << "ponto7\n";
                std::cout << suposta_senha[i][j] << " " << suposta_senha[i+6][j] << "\n";
                if (suposta_senha[i][j] == suposta_senha[i+6][j]){
                    senha += char (suposta_senha[i][j]);
                    std::cout << "ponto8\n";
                    break;
                }
                std::cout << "ponto9\n";
            }
            std::cout << "ponto10\n";
        }
        std::cout << "ponto11\n";
    }
    std::cout << "ponto12\n";
    return senha;
}