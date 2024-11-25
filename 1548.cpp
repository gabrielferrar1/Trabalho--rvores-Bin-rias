#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

class NodoArvore
{
private:
    int chave;
    NodoArvore* esquerda;
    NodoArvore* direita;
public:
    NodoArvore(int vlr)
    {
        chave = vlr;
        esquerda = NULL;
        direita = NULL;
    }

    int RetornaChave()
    {
        return chave;
    }

    NodoArvore* RetornaEsquerda()
    {
        return esquerda;
    }

    NodoArvore* RetornaDireita()
    {
        return direita;
    }

    void InsereEsquerda(NodoArvore* nodo)
    {
        esquerda = nodo;
    }

    void InsereDireita(NodoArvore* nodo)
    {
        direita = nodo;
    }
};

class ArvoreBinaria
{
private:
    NodoArvore* raiz;
public:
    ArvoreBinaria()
    {
        raiz = NULL;
    }

    bool ArvoreVazia()
    {
        return raiz == NULL;
    }

    NodoArvore* RetornaRaiz()
    {
        return raiz;
    }

    void InsereRaiz(NodoArvore* RAIZ)
    {
        raiz = RAIZ;
    }

    void insere(NodoArvore* RAIZ, NodoArvore* nodo)
    {
        if (RAIZ == NULL)
            RAIZ = nodo;
        else if (nodo->RetornaChave() > RAIZ->RetornaChave())
        {
            if (RAIZ->RetornaDireita() == NULL)
                RAIZ->InsereDireita(nodo);
            else
                insere(RAIZ->RetornaDireita(), nodo);
        }
        else
        {
            if (RAIZ->RetornaEsquerda() == NULL)
                RAIZ->InsereEsquerda(nodo);
            else
                insere(RAIZ->RetornaEsquerda(), nodo);
        }
    }

    void coletaInOrder(NodoArvore* RAIZ, std::vector<int>& notasOrdenadas)
    {
        if (RAIZ == NULL)
            return;
        coletaInOrder(RAIZ->RetornaEsquerda(), notasOrdenadas);
        notasOrdenadas.push_back(RAIZ->RetornaChave());
        coletaInOrder(RAIZ->RetornaDireita(), notasOrdenadas);
    }
};

int main()
{
    int N;
    scanf("%d", &N);

    for (int t = 0; t < N; t++)
    {
        int M;
        scanf("%d", &M);

        ArvoreBinaria arvore;
        NodoArvore* raiz = NULL;

        std::vector<int> notasOriginais(M);
        for (int i = 0; i < M; i++)
        {
            int nota;
            scanf("%d", &nota);
            notasOriginais[i] = nota;

            NodoArvore* nodo = new NodoArvore(nota);
            if (arvore.ArvoreVazia())
            {
                arvore.InsereRaiz(nodo);
                raiz = arvore.RetornaRaiz();
            }
            else
            {
                arvore.insere(raiz, nodo);
            }
        }

        std::vector<int> notasOrdenadas;
        arvore.coletaInOrder(raiz, notasOrdenadas);

        std::reverse(notasOrdenadas.begin(), notasOrdenadas.end());

        int naoTrocados = 0;
        for (int i = 0; i < M; i++)
        {
            if (notasOriginais[i] == notasOrdenadas[i])
                naoTrocados++;
        }

        printf("%d\n", naoTrocados);
    }

    return 0;
}
