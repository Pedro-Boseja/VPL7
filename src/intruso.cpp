#include "intruso.hpp"

#include <string>
#include <vector>
#include <map>

std::string Intruso::crack_senha() {
    std::string senha {};
    std::map<char, int> chave;
    int i = 0, j = 0;
    bool s = 0;
    //Compara os números de dois a dois e coloca o número que for igual
    //no map associado a uma letra;
    for (int i = 0; i<(_vazou_num.size() - 1); i += 2){
        for (int j = 0; j<2; j++){
            for (int k = 0; k<2; k++){
                if (_vazou_num[i][j] == _vazou_num[i+1][k]){ chave['A'] = _vazou_num[i][j]; s=1;}
                if (s == 1) {break;}
            }
            if (s == 1) {break;}
        }
        s = 0;
        for (int j = 2; j<4; j++){
            for (int k = 2; k<4; k++){
                if (_vazou_num[i][j] == _vazou_num[i+1][k]){ chave['B'] = _vazou_num[i][j]; s=1;}
                if (s == 1) {break;}
            }
            if (s == 1) {break;}
        }
        s = 0;
        for (int j = 4; j<6; j++){
            for (int k = 4; k<6; k++){
                if (_vazou_num[i][j] == _vazou_num[i+1][k]){ chave['C'] = _vazou_num[i][j]; s=1;}
                if (s == 1) {break;}
            }
            if (s == 1) {break;}
        }
        s = 0;
        for (int j = 6; j<8; j++){
            for (int k = 6; k<8; k++){
                if (_vazou_num[i][j] == _vazou_num[i+1][k]){ chave['D'] = _vazou_num[i][j]; s=1;}
                if (s == 1) {break;}
            }
            if (s == 1) {break;}
        }
        s = 0;
        for (int j = 8; j<10; j++){
            for (int k = 8; k<10; k++){
                if (_vazou_num[i][j] == _vazou_num[i+1][k]){ chave['E'] = _vazou_num[i][j]; s=1;}
                if (s == 1) {break;}
            }
            if (s == 1) {break;}
        }
    }
    for (int i = 0; i<6; i++){        //Percorre o map para formar a senha numérica
        for (auto it = chave.begin(); it != chave.end(); it++){
            if (_vazou_char[i] == it->first){
                senha += it->second;
                break;
            }
        }
    }
    return senha;
}