#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;
int colu = 1, linhas=1;

void iniciojogo(string tabuleiro[8][6]) {
    cout << "********** 4 em linha **********";



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

void mostrartabuleiro(string tabuleiro[8][6]) {
    cout << "\nTABELA:" << endl << endl;

    for (int y = 5; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
            if (x > 0) cout << "|";
            if (tabuleiro[x][y] != "") {
                cout << tabuleiro[x][y];
            }else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void pedirjogada(string tabuleiro[8][6]){

int qualaltura;
    string  elemento;
    bool encontroulivre = false;

    cout << "\nQuem e a jogar o X ou O [" << qualaltura << "] : ";
    cin >> elemento;
    cout << "\nEm que coluna quer fazer a jogada(0 / 1 / 2 / 3 / 4 / 5 / 6 / 7)? : ";
    cin >> qualaltura;

    for (int i=0; i<linhas; i++) {
        if (tabuleiro[qualaltura][i] == "") {
            tabuleiro[qualaltura][i] = elemento;
            mostrartabuleiro(tabuleiro);
            encontroulivre = true;
            break;
        }
    }
}


int main() {
    string tabuleiro[8][6] = {
        {"", "", "", "", "", ""},
        {"", "", "", "", "", ""},
        {"", "", "", "", "", ""},
        {"", "", "", "", "", ""},
        {"", "", "", "", "", ""},
        {"", "", "", "", "", ""},
        {"", "", "", "", "", ""},
        {"", "", "", "", "", ""}
    };

    mostrartabuleiro(tabuleiro); // Chama a função para mostrar o tabuleiro
    pedirjogada(tabuleiro);

    bool tabuleiropreenchido = false;
    bool jogoterminou = false;

    do {
        mostrartabuleiro(tabuleiro);
        pedirjogada(tabuleiro);
    } while (!jogoterminou) ;

    return 0;
}
