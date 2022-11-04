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
    std::string senha {};
    std::vector<int*> suposta_senha;
    int i = 0;
    for (int t = 0; t < _vazou_senha.size(); t++){
        std::map<char, int*> chave;
        chave = _vazou_chave[t];
        char k = 'A';
        for (auto it = chave.begin(); it != chave.end(); it++){
            if (_vazou_senha[t][i] == k){
                suposta_senha.push_back(it->second);
            }
            else {k+=1; i+=1;}
        }
    }
    // Verificado OK

    for (int t = 0; t < 6; t++)
    {
        //std::cout << "ponto0\n";
        int qtde_senhas = suposta_senha.size();
        for (int i = 0; i < 6*(qtde_senhas-1); i++)
        {
            //std::cout << "ponto1\n";
            for (int j = 0; j < 2; j++)
            {
                //std::cout << "ponto2\n";
                if (suposta_senha[i][j] == suposta_senha[i+6][j])
                {
                    //std::cout << "ponto3\n";
                    senha += char (suposta_senha[i][j]);
                    break;
                }
                //std::cout << "ponto4\n";
            }
            //std::cout << "ponto5\n";
        }
        //std::cout << "ponto6\n";
    }
    //std::cout << "ponto7\n";
    return senha;
}