#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;

void iniciojogo() {
    cout << "********** 4 em linha **********"
    // mensagens e in/out de msgs
    // captacao de decisoes do utilizador
}

void terminoujogo() {
    // verificar se terminou o jogo
    //alguem ganhou ? // tabuleiro cheio ?
}

bool tabuleirocheio() {
}

bool alguemganhou() {
}

void mostrartabuleiro() {

}

int main() {
    string tabuleiro[8][6] = {
    { "", "", "", "", "", "",},
    { "", "", "", "", "", "",},
    { "", "", "", "", "", "",},
    { "", "", "", "", "", "",},
    { "", "", "", "", "", "",},
    { "", "", "", "", "", "",},
    { "", "", "", "", "", "",},
    { "", "", "", "", "", "",}

};

    bool tabuleiropreenchido = false;
    bool jogoterminou = false;

    do {
        iniciojogo();
    } while (!jogoterminou) ;

    return 0;
}
