#include <iostream>
#include <string>

using namespace std;

const int LINHAS = 6;
const int COLUNAS = 8;

void iniciojogo() {
    cout << "********** 4 em linha **********" << endl;
    cout << "Jogador 1: X" << endl;
    cout << "Jogador 2: O" << endl;
    cout << "Cada jogador insere o numero da coluna onde quer colocar a peca." << endl;
}

bool tabuleirocheio(const string tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            if (tabuleiro[i][j] == "") {
                return false;
            }
        }
    }
    return true;
}

bool verificar_vitoria(const string tabuleiro[LINHAS][COLUNAS], const string &jogador) {
    // Verificar linhas
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j <= COLUNAS - 4; ++j) {
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
    for (int j = 0; j < COLUNAS; ++j) {
        for (int i = 0; i <= LINHAS - 4; ++i) {
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
    for (int i = 0; i <= LINHAS - 4; ++i) {
        for (int j = 0; j <= COLUNAS - 4; ++j) {
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

    // Verificar diagonais secundárias
    for (int i = 0; i <= LINHAS - 4; ++i) {
        for (int j = COLUNAS - 1; j >= 3; --j) {
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

void mostrartabuleiro(const string tabuleiro[LINHAS][COLUNAS]) {
    cout << "---------------------------" << endl;
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            cout << "|" << (tabuleiro[i][j] == "" ? " " : tabuleiro[i][j]) << " ";
        }
        cout << "|" << endl;
    }
    cout << "---------------------------" << endl;
    cout << " 1  2  3  4  5  6  7  8" << endl; // Numeração das colunas
}

int main() {
    string tabuleiro[LINHAS][COLUNAS] = {
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""}
    };

    int coluna;
    bool jogoterminou = false;
    string jogador_atual = "X"; // Começa com o jogador 1 (X)

    iniciojogo();

    do {
        mostrartabuleiro(tabuleiro);

        cout << "Jogador " << jogador_atual << ", insira o numero da coluna (1-" << COLUNAS << "): ";
        cin >> coluna;

        if (coluna < 1 || coluna > COLUNAS) {
            cout << "Coluna invalida! Insira novamente." << endl;
            continue;
        }

        coluna--; // Ajuste para índice do array

        // Procura a primeira linha vazia na coluna escolhida
        int linha = LINHAS - 1;
        while (linha >= 0 && tabuleiro[linha][coluna] != "") {
            linha--;
        }

        if (linha >= 0) {
            tabuleiro[linha][coluna] = jogador_atual;

            if (verificar_vitoria(tabuleiro, jogador_atual)) {
                cout << "Jogador " << jogador_atual << " ganhou!" << endl;
                jogoterminou = true;
            } else if (tabuleirocheio(tabuleiro)) {
                cout << "Empate!" << endl;
                jogoterminou = true;
            }

            // Troca para o próximo jogador
            jogador_atual = (jogador_atual == "X") ? "O" : "X";
        } else {
            cout << "Coluna cheia! Escolha outra coluna." << endl;
            continue;
        }

    } while (!jogoterminou);

    mostrartabuleiro(tabuleiro);

    return 0;
}

