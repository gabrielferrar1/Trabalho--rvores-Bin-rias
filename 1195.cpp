#include <iostream>
#include <vector>
using namespace std;

class NodoArvore {
private:
    int chave;
    NodoArvore* esquerda;
    NodoArvore* direita;

public:
    NodoArvore(int vlr) {
        chave = vlr;
        esquerda = nullptr;
        direita = nullptr;
    }

    int RetornaChave() { return chave; }

    NodoArvore*& RetornaEsquerda() { return esquerda; }
    NodoArvore*& RetornaDireita() { return direita; }

    void InsereEsquerda(NodoArvore* nodo) { esquerda = nodo; }

    void InsereDireita(NodoArvore* nodo) { direita = nodo; }
};

class ArvoreBinaria {
private:
    NodoArvore* raiz;

public:
    ArvoreBinaria() { raiz = nullptr; }

    bool ArvoreVazia() { return raiz == nullptr; }

    NodoArvore*& RetornaRaiz() { return raiz; }

    void insere(NodoArvore*& RAIZ, NodoArvore* nodo) {
        if (RAIZ == nullptr) {
            RAIZ = nodo;
        } else if (nodo->RetornaChave() < RAIZ->RetornaChave()) {
            insere(RAIZ->RetornaEsquerda(), nodo);
        } else {
            insere(RAIZ->RetornaDireita(), nodo);
        }
    }

    void preordem(NodoArvore* RAIZ, vector<int>& result) {
        if (RAIZ == nullptr) return;
        result.push_back(RAIZ->RetornaChave());
        preordem(RAIZ->RetornaEsquerda(), result);
        preordem(RAIZ->RetornaDireita(), result);
    }

    void inordem(NodoArvore* RAIZ, vector<int>& result) {
        if (RAIZ == nullptr) return;
        inordem(RAIZ->RetornaEsquerda(), result);
        result.push_back(RAIZ->RetornaChave());
        inordem(RAIZ->RetornaDireita(), result);
    }

    void posordem(NodoArvore* RAIZ, vector<int>& result) {
        if (RAIZ == nullptr) return;
        posordem(RAIZ->RetornaEsquerda(), result);
        posordem(RAIZ->RetornaDireita(), result);
        result.push_back(RAIZ->RetornaChave());
    }
};

void imprime(const string& label, const vector<int>& vec) {
    cout << label;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) cout << " ";
        cout << vec[i];
    }
    cout << endl;
}

int main() {
    int C;
    cin >> C;

    for (int caso = 1; caso <= C; ++caso) {
        int N;
        cin >> N;

        ArvoreBinaria arvore;
        for (int i = 0; i < N; ++i) {
            int valor;
            cin >> valor;
            NodoArvore* nodo = new NodoArvore(valor);
            arvore.insere(arvore.RetornaRaiz(), nodo);
        }

        vector<int> pre, in, pos;
        arvore.preordem(arvore.RetornaRaiz(), pre);
        arvore.inordem(arvore.RetornaRaiz(), in);
        arvore.posordem(arvore.RetornaRaiz(), pos);

        cout << "Case " << caso << ":\n";
        imprime("Pre.: ", pre);
        imprime("In..: ", in);
        imprime("Post: ", pos);
        cout << endl;
    }

    return 0;
}
