#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int linhas = 6;
const int colunas = 8;

void iniciojogo() {
    cout << "********** 4 em linha **********" << endl;
    cout << "Jogador 1: X" << endl;
    cout << "Jogador 2: O" << endl;
    cout << "Cada jogador insere o numero da coluna onde quer colocar a peca." << endl;
}

bool tabuleirocheio(const string tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (tabuleiro[i][j] == "") {
                return false;
            }
        }
    }
    return true;
}

bool alguemganhou(const string tabuleiro[linhas][colunas], const string &jogador) {
    // Verificar linhas
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j <= colunas - 4; ++j) {
            bool vitoria = true;
            for (int k = 0; k < 4; ++k) {
                if (tabuleiro[i][j + k] != jogador) {
                    vitoria = false;
                    break;
                }
            }
            if (vitoria) {
                return true;
            }
        }
    }

    // Verificar colunas
    for (int j = 0; j < colunas; ++j) {
        for (int i = 0; i <= linhas - 4; ++i) {
            bool vitoria = true;
            for (int k = 0; k < 4; ++k) {
                if (tabuleiro[i + k][j] != jogador) {
                    vitoria = false;
                    break;
                }
            }
            if (vitoria) {
                return true;
            }
        }
    }

    // Verificar diagonais principais
    for (int i = 0; i <= linhas - 4; ++i) {
        for (int j = 0; j <= colunas - 4; ++j) {
            bool vitoria = true;
            for (int k = 0; k < 4; ++k) {
                if (tabuleiro[i + k][j + k] != jogador) {
                    vitoria = false;
                    break;
                }
            }
            if (vitoria) {
                return true;
            }
        }
    }

    // Verificar diagonais secund�rias
    for (int i = 0; i <= linhas - 4; ++i) {
        for (int j = colunas - 1; j >= 3; --j) {
            bool vitoria = true;
            for (int k = 0; k < 4; ++k) {
                if (tabuleiro[i + k][j - k] != jogador) {
                    vitoria = false;
                    break;
                }
            }
            if (vitoria) {
                return true;
            }
        }
    }

    return false;
}

void mostrartabuleiro(const string tabuleiro[linhas][colunas]) {
    cout << "---------------------------" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << "|" << (tabuleiro[i][j] == "" ? " " : tabuleiro[i][j]) << " ";
        }
        cout << "|" << endl;
    }
    cout << "---------------------------" << endl;
    cout << " 1  2  3  4  5  6  7  8" << endl; // Numera��o das colunas
}

void reiniciar_jogo(string tabuleiro[linhas][colunas]) {
    // Limpa o tabuleiro para reiniciar o jogo
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            tabuleiro[i][j] = "";
        }
    }
}


int main() {
    string tabuleiro[linhas][colunas] = {
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""}
    };

    int coluna;
    bool jogoterminou = false;
    string jogador_atual = "X"; // Come�a com o jogador 1 (X)

    iniciojogo();

    do {
        jogoterminou = false;
        reiniciar_jogo(tabuleiro);

    do {
        mostrartabuleiro(tabuleiro);

        cout << "Jogador " << jogador_atual << ", insira o numero da coluna (1-8) : ";
        cin >> coluna;

        if (coluna < 1 || coluna > colunas) {
            cout << "Coluna invalida! Insira novamente." << endl;
            continue;
        }

        coluna--; // Ajuste para �ndice do array

        // Procura a primeira linha vazia na coluna escolhida
        int linha = linhas - 1;
        while (linha >= 0 && tabuleiro[linha][coluna] != "") {
            linha--;
        }

        if (linha >= 0) {
            tabuleiro[linha][coluna] = jogador_atual;

            if (alguemganhou(tabuleiro, jogador_atual)) {
                cout << "Jogador " << jogador_atual << " ganhou!" << endl;
                jogoterminou = true;
            } else if (tabuleirocheio(tabuleiro)) {
                cout << "Empate!" << endl;
                jogoterminou = true;
            }

            // Troca para o pr�ximo jogador
            jogador_atual = (jogador_atual == "X") ? "O" : "X";
        } else {
            cout << "Coluna cheia! Escolha outra coluna." << endl;
            continue;
        }



    } while (!jogoterminou);

        mostrartabuleiro(tabuleiro);

     cout << "Deseja jogar novamente? (s/n): ";
        char resposta;
        cin >> resposta;

        if (resposta != 's' && resposta != 'S') {
            break;
        }

         system("cls");

    } while (true);

    cout << "Obrigado por jogar!" << endl;

    cout << "Feito por Filipe e Rodrigo" << endl;

    return 0;
}

