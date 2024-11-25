#include <iostream>
#include <string>
using namespace std;

class NodoArvore {
private:
    char chave;
    NodoArvore* esquerda;
    NodoArvore* direita;

public:
    NodoArvore(char vlr) {
        chave = vlr;
        esquerda = NULL;
        direita = NULL;
    }

    char RetornaChave() {
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

    void Insere(char valor) {
        NodoArvore* novo = new NodoArvore(valor);
        if (ArvoreVazia()) {
            raiz = novo;
        } else {
            insereRecursivo(raiz, novo);
        }
    }

    void insereRecursivo(NodoArvore* atual, NodoArvore* novo) {
        if (novo->RetornaChave() < atual->RetornaChave()) {
            if (atual->RetornaEsquerda() == NULL) {
                atual->InsereEsquerda(novo);
            } else {
                insereRecursivo(atual->RetornaEsquerda(), novo);
            }
        } else {
            if (atual->RetornaDireita() == NULL) {
                atual->InsereDireita(novo);
            } else {
                insereRecursivo(atual->RetornaDireita(), novo);
            }
        }
    }

    void preordem(NodoArvore* nodo, bool& isFirst) {
        if (nodo != NULL) {
            if (!isFirst) cout << " ";
            cout << nodo->RetornaChave();
            isFirst = false;
            preordem(nodo->RetornaEsquerda(), isFirst);
            preordem(nodo->RetornaDireita(), isFirst);
        }
    }

    void inordem(NodoArvore* nodo, bool& isFirst) {
        if (nodo != NULL) {
            inordem(nodo->RetornaEsquerda(), isFirst);
            if (!isFirst) cout << " ";
            cout << nodo->RetornaChave();
            isFirst = false;
            inordem(nodo->RetornaDireita(), isFirst);
        }
    }

    void posordem(NodoArvore* nodo, bool& isFirst) {
        if (nodo != NULL) {
            posordem(nodo->RetornaEsquerda(), isFirst);
            posordem(nodo->RetornaDireita(), isFirst);
            if (!isFirst) cout << " ";
            cout << nodo->RetornaChave();
            isFirst = false;
        }
    }

    bool busca(NodoArvore* nodo, char valor) {
        if (nodo == NULL) return false;
        if (nodo->RetornaChave() == valor) return true;
        if (valor < nodo->RetornaChave()) return busca(nodo->RetornaEsquerda(), valor);
        return busca(nodo->RetornaDireita(), valor);
    }
};

int main() {
    ArvoreBinaria arvore;
    string comando;

    while (cin >> comando) {
        if (comando == "I") {
            char valor;
            cin >> valor;
            arvore.Insere(valor);
        } else if (comando == "PREFIXA") {
            bool isFirst = true;
            arvore.preordem(arvore.RetornaRaiz(), isFirst);
            cout << endl;
        } else if (comando == "INFIXA") {
            bool isFirst = true;
            arvore.inordem(arvore.RetornaRaiz(), isFirst);
            cout << endl;
        } else if (comando == "POSFIXA") {
            bool isFirst = true;
            arvore.posordem(arvore.RetornaRaiz(), isFirst);
            cout << endl;
        } else if (comando == "P") {
            char valor;
            cin >> valor;
            if (arvore.busca(arvore.RetornaRaiz(), valor)) {
                cout << valor << " existe" << endl;
            } else {
                cout << valor << " nao existe" << endl;
            }
        }
    }

    return 0;
}