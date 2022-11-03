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
        //std::cout << ponte[j] << std::endl;
        //std::cout << vazou[k] << std::endl;
        k++;  
    }
    
    _vazou_senha.push_back(ponte);
    //std::cout << "ponto0\n";
    //for(auto it = _vazou_senha.begin(); it < _vazou_senha.end(); it++){
    //    std::cout << "ponto1\n";
    //    std::cout << (*it)[0] << std::endl;
    //    std::cout << "ponto3\n";
    //}
    //std::cout << "ponto4\n";
    
    // Verificado OK
   
    std::map<char, int*> passarela;
    char c = 'A';
    //std::cout << "ponto0\n";
    for (int j = 0; j < 10; j+=2){
        //std::cout << "ponto1\n";
        int nums[2]; 
        nums[0] =  (int(vazou[j]) - 48); nums[1] = (int(vazou[j+1]) - 48);
        passarela[c] = nums;
        //std::cout << passarela[c][0] << " " << nums[0] << std::endl;
        //std::cout << "ponto2\n";
        c++;
    }
    _vazou_chave.push_back(passarela);
    //std::cout << "ponto3\n";
    
    // Verificado OK
}

td::string Intruso::crack_senha() {
    //std::cout << "ponto0\n";
    //for(auto it = _vazou_senha.begin(); it < _vazou_senha.end(); it++){
    //    std::cout << "ponto1\n";
    //    for (int i = 0; i < 6; i++){
    //        std::cout << (*it)[i];
    //    }
    //    std::cout << "/n";
    //    std::cout << "ponto3\n";
    //}2
    std::string senha {};
    std::vector<int*> suposta_senha;
    int i = 0;
    std::cout << "ponto0\n";
    for (int t = 0; t < 6; t++){
        std::map<char, int*> chave;
        chave = _vazou_chave[t];
        std::cout << "ponto1\n";
        char k = 'A';
        for (auto it = chave.begin(); it != chave.end(); it++){
            std::cout << "ponto2\n";
            std::cout << _vazou_senha[t][i] << std::endl;
            if (_vazou_senha[t][i] == k){
                std::cout << "ponto3\n";
                if (suposta_senha.empty()) 
                    suposta_senha[t] = it->second;
                break;
            }
            else {k+=1; i += 1;}
        }
    }
    std::cout << "ponto4\n";
    for (int t = 0; t < 6; t++){
        int qtde_senhas = suposta_senha.size();
        for (int i = 0; i < 6*(qtde_senhas-1); i++){
            for (int j = 0; j < 2; j++){
                if (suposta_senha[i][j] == suposta_senha[i+6][j]){
                    senha += char (suposta_senha[i][j]);
                    break;
                }
            }
        }
    }
    return senha;
}