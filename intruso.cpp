#include "intruso.hpp"

#include <string>
#include <vector>
#include <map>
#include <iostream>

void Intruso::set_senha_vazada(std::string vazou) 
{
    
    //std::cout<<"lugar1"<<std::endl;
    
    int k = 10;
    std::string ponte;
    for(int j = 0; j < 6; j++)
    {
        ponte[j] = vazou[k];
        k++;  
    }
    _vazou_senha.push_back(ponte);
    
    //std::cout<<"lugar2"<<std::endl;
    
    std::map<char, int*> passarela;
    char c = 'A';
    for(int j = 0; j < 10; j+=2)
    {
        int nums[2] = {j, j+1};
        passarela[c] = nums;
        c++;
    }
    _vazou_chave.push_back(passarela);
    
    //std::cout<<"lugar3"<<std::endl;
    
}

std::string Intruso::crack_senha() {
    std::string senha {};
    std::vector<int*> suposta_senha;
    int i = 0;
    for (int t = 0; t < 6; t++){
        for (auto it = _vazou_chave[t].begin(); it != _vazou_chave[t].end(); it++){
            if (_vazou_senha[t][i] == it->first){
                if (suposta_senha.empty()) 
                    suposta_senha[t] = it->second;
                break;
            }
            i += 1;
        }
    }
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