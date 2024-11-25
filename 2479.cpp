#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class NodoArvore {
private:
    string nome;
    NodoArvore* esquerda;
    NodoArvore* direita;

public:
    NodoArvore(string vlr) {
        nome = vlr;
        esquerda = NULL;
        direita = NULL;
    }

    void MostraNodo() {
        cout << nome << endl;
    }

    string RetornaNome() {
        return nome;
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
        else if (nodo->RetornaNome() > RAIZ->RetornaNome()) {
            if (RAIZ->RetornaDireita() == NULL)
                RAIZ->InsereDireita(nodo);
            else
                insere(RAIZ->RetornaDireita(), nodo);
        } else {
            if (RAIZ->RetornaEsquerda() == NULL)
                RAIZ->InsereEsquerda(nodo);
            else
                insere(RAIZ->RetornaEsquerda(), nodo);
        }
    }

    void inordem(NodoArvore* RAIZ) {
        if (RAIZ == NULL)
            return;
        inordem(RAIZ->RetornaEsquerda());
        RAIZ->MostraNodo();
        inordem(RAIZ->RetornaDireita());
    }
};

int main() {
    int n;
    char comportamento;
    char nome[21];
    ArvoreBinaria arvore;
    NodoArvore* raiz = NULL;
    int comportaramBem = 0, comportaramMal = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> comportamento >> nome;
        NodoArvore* nodo = new NodoArvore(nome);

        if (arvore.ArvoreVazia()) {
            arvore.InsereRaiz(nodo);
            raiz = arvore.RetornaRaiz();
        } else {
            arvore.insere(raiz, nodo);
        }

        if (comportamento == '+')
            comportaramBem++;
        else
            comportaramMal++;
    }

    arvore.inordem(raiz);

    cout << "Se comportaram: " << comportaramBem << " | Nao se comportaram: " << comportaramMal << endl;

    return 0;
}
