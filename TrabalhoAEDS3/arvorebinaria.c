#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef  struct no{
  int valor;
  struct no *direita;
  struct no *esquerda;
}no;


void inserir(no *raiz, int x){
  if(raiz->valor == -1){
    raiz->valor = x;
    printf("Valor adicionado %d \n", raiz->valor);
  }else{
    bool b = true;
    no *temp  = malloc(sizeof(no));
    temp = raiz;
    while (true) {
      if(x > temp->valor){
        if(temp->direita != NULL){
            if(temp->direita->valor){
            temp = temp->direita;
          }
        }else{
          temp->direita = malloc(sizeof(no));
          printf(" Valor adicionado \n");
          temp->direita->valor  = x; break;
        }
      }else{
        if(temp->esquerda != NULL){
          if(temp->esquerda->valor){
            temp = temp->esquerda;
          }
        }else{
          temp->esquerda = malloc(sizeof(no));
          printf(" Valor adicionado \n");
          temp->esquerda->valor = x; break;
        }
      }

    }
  }
}

int altura(no *raiz){
    if(raiz == NULL){
        return -1;
    }
    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
    if(alturaEsquerda > alturaDireita){
        return alturaEsquerda + 1;
    }else{
        return alturaDireita + 1;
    }
}

void buscar(no *raiz, int objetivo){
  no *aux=  malloc(sizeof(no));
  aux = raiz;

  while (true) {
    if(objetivo == aux->valor){
      printf("Valor encontrado\n");
      free(aux);
      break;
    }
    if(objetivo > aux->valor){
      if(aux->direita != NULL){
        aux = aux->direita;
      }else{
        printf("Valor n encontrado \n");
        free(aux);
        break;
      }
    }else{
      if(aux->esquerda != NULL){
        aux = aux->esquerda;
      }else{
        printf("Valor n encontrado\n");
        free(aux);
        break;
      }
    }
  
  }
  
}


void preOrdem(no *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(no *raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(no *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void liberarArvore(no *raiz){
    if(raiz != NULL){
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}


int main(){

  int opcao = 0;
  int valor = 0;
  no *raiz = malloc(sizeof(no));
  raiz->valor = -1;

  while (opcao != 7) {
    printf("0- Liberar memoria 1- Inserir 2- Pre-ordem 3- Em-ordem 4- Pos-ordem 5- Altura 6- Buscar 7- Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 0:
        liberarArvore(raiz);
        raiz = NULL;
        printf("Memoria liberada\n");
        break;
      case 1:
        printf("Digite algum valor \n");
        scanf("%d",&valor);
        if(raiz == NULL){
          raiz = malloc(sizeof(no));
          raiz->valor = -1;
        }
        inserir(raiz, valor);
        break;
      case 2:
        printf("Pre-ordem: ");
        preOrdem(raiz);
        printf("\n");
        break;
      case 3:
        printf("Em-ordem: ");
        emOrdem(raiz);
        printf("\n");
        break;
      case 4:
        printf("Pos-ordem: ");
        posOrdem(raiz);
        printf("\n");
        break;
      case 5:
        printf("Altura: %d\n", altura(raiz));
        break;
      case 6:
        printf("Digite o valor que vai ser buscado \n");
        scanf("%d", &valor);
        buscar(raiz, valor);
        break;
      case 7:
        return 0;
    }
  } 
  return 0;
}
