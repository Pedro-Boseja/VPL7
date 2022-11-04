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
    
   
    std::map<char, int*> passarela;
    char c = 'A';
    for (int j = 0; j < 10; j+=2){
        int nums[2]; 
        nums[0] =  (int(vazou[j]) - 48); nums[1] = (int(vazou[j+1]) - 48);
        passarela[c] = nums;
        c++;
    }
    _vazou_chave.push_back(passarela);    
    // Verificado OK
}

std::string Intruso::crack_senha() {
    std::cout << _vazou_senha[0][0] << std::endl;
    std::string senha {};
    std::vector<int*> suposta_senha;
    int i = 0;
    //std::cout << "ponto0\n";
    for (int t = 0; t < _vazou_senha.size(); t++){
        std::cout << _vazou_senha[0][0] << std::endl;
        std::map<char, int*> chave;
        chave = _vazou_chave[t];
        //std::cout << "ponto1\n";
        char k = 'A';
        for (char j = 'A'; j <= 'E'; j++){
            //std::cout << "ponto2\n";
            std::cout << _vazou_senha[t][i] << std::endl;
            if (_vazou_senha[t][i] == k){
                std::cout << "ponto3\n";
                suposta_senha.push_back(chave.at(j));
                std::cout << chave.at(j)[0];
                chave = {};
                break;
            }
            else {k += 1; i += 1;}
        }
    }
    //std::cout << "ponto4\n";
    for (int t = 0; t < 6; t++){
        std::cout << "ponto1\n";
        int qtde_senhas = suposta_senha.size();
        for (int i = 0; i < 6*(qtde_senhas-1); i++){
            std::cout << "ponto2\n";
            for (int j = 0; j < 2; j++){
                std::cout << "ponto3\n";
                std::cout << suposta_senha[i][j] << " " << suposta_senha[i+6][j] << "\n";
                if (suposta_senha[i][j] == suposta_senha[i+6][j]){
                    senha += char (suposta_senha[i][j]);
                    std::cout << "ponto4\n";
                    break;
                }
                //std::cout << "ponto4\n";
            }
            //std::cout << "ponto5\n";
        }
        //std::cout << "ponto6\n";
    }
    std::cout << "ponto5\n";
    return senha;
}