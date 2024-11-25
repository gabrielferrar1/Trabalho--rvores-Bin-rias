#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Classe Nodo
class NodoArvore {
private:
    int chave;
    NodoArvore* esquerda;
    NodoArvore* direita;
public:
    NodoArvore(int vlr) {
        chave = vlr;
        esquerda = NULL;
        direita = NULL;
    }

    int RetornaChave() {
        return chave;
    }

    NodoArvore* RetornaEsquerda() {
        return esquerda;
    }

    NodoArvore* RetornaDireita() {
        return direita;
    }

    void InsereEsquerda(NodoArvore* nodo) {
        esquerda = nodo;
    }

    void InsereDireita(NodoArvore* nodo) {
        direita = nodo;
    }
};

// Classe Árvore Binária
class ArvoreBinaria {
private:
    NodoArvore* raiz;
public:
    ArvoreBinaria() {
        raiz = NULL;
    }

    bool ArvoreVazia() {
        return raiz == NULL;
    }

    NodoArvore* RetornaRaiz() {
        return raiz;
    }

    void InsereRaiz(NodoArvore* RAIZ) {
        raiz = RAIZ;
    }

    void insere(NodoArvore* RAIZ, NodoArvore* nodo) {
        if (RAIZ == NULL)
            RAIZ = nodo;
        else if (nodo->RetornaChave() > RAIZ->RetornaChave()) {
            if (RAIZ->RetornaDireita() == NULL)
                RAIZ->InsereDireita(nodo);
            else
                insere(RAIZ->RetornaDireita(), nodo);
        }
        else {
            if (RAIZ->RetornaEsquerda() == NULL)
                RAIZ->InsereEsquerda(nodo);
            else
                insere(RAIZ->RetornaEsquerda(), nodo);
        }
    }

    void inordem(NodoArvore* RAIZ, vector<int>& resultado) {
        if (RAIZ == NULL)
            return;
        inordem(RAIZ->RetornaEsquerda(), resultado);
        resultado.push_back(RAIZ->RetornaChave());
        inordem(RAIZ->RetornaDireita(), resultado);
    }
};

int main() {
    int N, Q;
    while (cin >> N >> Q) {
        ArvoreBinaria arvore;
        NodoArvore* raiz = NULL;

        for (int i = 0; i < N; i++) {
            int nota;
            cin >> nota;
            NodoArvore* nodo = new NodoArvore(nota);
            if (arvore.ArvoreVazia()) {
                arvore.InsereRaiz(nodo);
                raiz = arvore.RetornaRaiz();
            } else {
                arvore.insere(raiz, nodo);
            }
        }

        vector<int> notas_ordenadas;
        arvore.inordem(raiz, notas_ordenadas);
        reverse(notas_ordenadas.begin(), notas_ordenadas.end());

        for (int i = 0; i < Q; i++) {
            int posicao;
            cin >> posicao;
            cout << notas_ordenadas[posicao - 1] << endl;
        }
    }
    return 0;
}
