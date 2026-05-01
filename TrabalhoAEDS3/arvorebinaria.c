#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct no {
    int valor;
    int fb;
    struct no *direita;
    struct no *esquerda;
} no;

int altura(no *raiz) {
    if (raiz == NULL) {
        return -1;
    }
    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
    if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda + 1;
    } else {
        return alturaDireita + 1;
    }
}

void atualizarFB(no *noAtual) {
    if (noAtual == NULL) return;
    noAtual->fb = altura(noAtual->esquerda) - altura(noAtual->direita);
}

no* rotacaoDireita(no *p) {
    no *u = p->esquerda;
    p->esquerda = u->direita;
    u->direita = p;
    atualizarFB(p);
    atualizarFB(u);
    return u;
}

no* rotacaoEsquerda(no *p) {
    no *u = p->direita;
    p->direita = u->esquerda;
    u->esquerda = p;
    atualizarFB(p);
    atualizarFB(u);
    return u;
}

no* rotacaoDuplaDireita(no *p) {
    p->esquerda = rotacaoEsquerda(p->esquerda);
    return rotacaoDireita(p);
}

no* rotacaoDuplaEsquerda(no *p) {
    p->direita = rotacaoDireita(p->direita);
    return rotacaoEsquerda(p);
}

no* balancear(no *raiz) {
    atualizarFB(raiz);
    if (raiz->fb == 2 && raiz->esquerda != NULL) {
        if (raiz->esquerda->fb >= 0) {
            return rotacaoDireita(raiz);
        } else {
            return rotacaoDuplaDireita(raiz);
        }
    } else if (raiz->fb == -2 && raiz->direita != NULL) {
        if (raiz->direita->fb <= 0) {
            return rotacaoEsquerda(raiz);
        } else {
            return rotacaoDuplaEsquerda(raiz);
        }
    }
    return raiz;
}

no* criarNo(int x) {
    no *novo = (no*)malloc(sizeof(no));
    novo->valor = x;
    novo->fb = 0;
    novo->direita = NULL;
    novo->esquerda = NULL;
    return novo;
}

no* inserirAVL(no *raiz, int x) {
    if (raiz == NULL) {
        return criarNo(x);
    }
    if (x > raiz->valor) {
        raiz->direita = inserirAVL(raiz->direita, x);
    } else if (x < raiz->valor) {
        raiz->esquerda = inserirAVL(raiz->esquerda, x);
    } else {
        return raiz;
    }
    atualizarFB(raiz);
    if (raiz->fb > 1 || raiz->fb < -1) {
        raiz = balancear(raiz);
    }
    return raiz;
}

void preOrdem(no *raiz) {
    if (raiz != NULL) {
        printf("%d(FB:%d) ", raiz->valor, raiz->fb);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(no *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d(FB:%d) ", raiz->valor, raiz->fb);
        emOrdem(raiz->direita);
    }
}

void posOrdem(no *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d(FB:%d) ", raiz->valor, raiz->fb);
    }
}

bool buscar(no *raiz, int objetivo) {
    if (raiz == NULL) {
        printf("Valor %d nao encontrado\n", objetivo);
        return false;
    }
    if (objetivo == raiz->valor) {
        printf("Valor %d encontrado\n", objetivo);
        return true;
    }
    if (objetivo > raiz->valor) {
        return buscar(raiz->direita, objetivo);
    } else {
        return buscar(raiz->esquerda, objetivo);
    }
}

void liberarArvore(no *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

void atualizarFBTodos(no *raiz) {
    if (raiz == NULL) return;
    atualizarFB(raiz);
    atualizarFBTodos(raiz->esquerda);
    atualizarFBTodos(raiz->direita);
}

int main() {
    int opcao = 0;
    int valor = 0;
    no *raiz = NULL;

    while (opcao != 8) {
        printf("\n0- Liberar memoria 1- Inserir 2- Pre-ordem 3- Em-ordem 4- Pos-ordem 5- Altura 6- Buscar 7- Recalcular FB 8- Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                liberarArvore(raiz);
                raiz = NULL;
                printf("Memoria liberada\n");
                break;
            case 1:
                printf("Digite algum valor: ");
                scanf("%d", &valor);
                raiz = inserirAVL(raiz, valor);
                printf("Valor %d inserido\n", valor);
                break;
            case 2:
                if (raiz != NULL) {
                    printf("Pre-ordem: ");
                    preOrdem(raiz);
                    printf("\n");
                } else {
                    printf("Arvore vazia\n");
                }
                break;
            case 3:
                if (raiz != NULL) {
                    printf("Em-ordem: ");
                    emOrdem(raiz);
                    printf("\n");
                } else {
                    printf("Arvore vazia\n");
                }
                break;
            case 4:
                if (raiz != NULL) {
                    printf("Pos-ordem: ");
                    posOrdem(raiz);
                    printf("\n");
                } else {
                    printf("Arvore vazia\n");
                }
                break;
            case 5:
                printf("Altura: %d\n", altura(raiz));
                break;
            case 6:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                buscar(raiz, valor);
                break;
            case 7:
                atualizarFBTodos(raiz);
                printf("FB recalculado para todos os nos\n");
                break;
            case 8:
                liberarArvore(raiz);
                return 0;
            default:
                printf("Opcao invalida\n");
        }
    }
    return 0;
}
