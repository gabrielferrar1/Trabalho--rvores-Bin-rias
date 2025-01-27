#include <stdio.h>
#include <stdlib.h>
#define limpatela system("cls")
#define parar system("pause")
// classe nodo
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

	void MostraNodo()
	{
	  if(esquerda != NULL) 	
        printf("%d <- ",esquerda->chave);
      else
      	printf("NULL <- ");
      printf("%d -> ",chave);
	  if(direita != NULL) 	
        printf("%d\n",direita->chave);
      else
      	printf("NULL\n");   
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


// classe Arvore
class ArvoreBinaria
{
private:
	NodoArvore* raiz; // raiz da �rvore
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
			
	virtual ~ArvoreBinaria() // destrutor
	{
		delete raiz;
	}
	
    void insere(NodoArvore* RAIZ,NodoArvore* nodo)
	{
        //Insere um nodo em uma �rvore bin�ria de pesquisa
        if (RAIZ == NULL)
 		    RAIZ = nodo;
		//Nodo deve ser inserido na sub�rvore direita.
        else if (nodo->RetornaChave() > RAIZ->RetornaChave())
		{
			printf("%d -> %d\n",RAIZ->RetornaChave(),nodo->RetornaChave());
            printf("Inseriu a direita.\n");
            if (RAIZ->RetornaDireita() == NULL)
                RAIZ->InsereDireita(nodo);
            else
                insere(RAIZ->RetornaDireita(), nodo);
		}
        //Nodo deve ser inserido na sub�rvore esquerda
        else
		{
            printf("%d <- %d\n",nodo->RetornaChave(),RAIZ->RetornaChave());
            printf("Inseriu a esquerda.\n");
            if (RAIZ->RetornaEsquerda() == NULL)
                RAIZ->InsereEsquerda(nodo);
            else
                insere(RAIZ->RetornaEsquerda(), nodo);
		}
	}
		
	void preordem (NodoArvore* RAIZ)
	{
		if (RAIZ == NULL)
            return;
        RAIZ->MostraNodo();
        //Visita filho da esquerda.
        preordem(RAIZ->RetornaEsquerda());
        //Visita filho da direita.
        preordem(RAIZ->RetornaDireita());		
	}

	void posordem(NodoArvore* RAIZ)
	{
		if (RAIZ == NULL)
            return;		
	}

	void inordem (NodoArvore* RAIZ)
	{
		if (RAIZ == NULL)
            return;		
	}	
};

int main()
{
	int op, valor;	
	ArvoreBinaria Arvore;
	NodoArvore* raiz = NULL;
	while(1)
	{
		limpatela;
		printf("1 - Insere valores na arvore.\n");
		printf("2 - Exibe PRE-FIXADO.\n");
		printf("3 - Exibe INFIXADO.\n");
		printf("4 - Exibe POS-FIXADO.\n");
		printf("5 - Sair.\n\n\n");
		printf("Entre com a opcao desejada..........: ");
		scanf("%d", &op);
		if ((op < 1) || (op > 5))
			printf("OPCAO INVALIDA!!!!!!!!!!!\n");
		else if (op == 1)
		{
			printf("Entre com o valor: ");
			scanf("%d", &valor);
			NodoArvore* nodo = new NodoArvore(valor);
			if (Arvore.ArvoreVazia())
			{
              printf("Nodo Raiz.\n");
			  Arvore.InsereRaiz(nodo);
			  raiz = Arvore.RetornaRaiz();			  
			}
			else
			  Arvore.insere(raiz,nodo);
		}
		else if (op == 2)
			Arvore.preordem(raiz);
		else if (op == 3)
			Arvore.inordem(raiz);
		else if (op == 4)
			Arvore.posordem(raiz);
		else
			break;
		parar;
	}
	return 0;
}
