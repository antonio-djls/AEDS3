#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef  struct no{
  int valor;
  struct no *direita;
  struct no *esquerda;
}no;


void inserir(no *root, int x){
  if(root->valor == -1){
    root->valor = x;
    printf("Valor adicionado %d \n", root->valor);
  }else{
    bool b = true;
    no *temp  = malloc(sizeof(no));
    temp = root;
    while (true) {
      if(x > temp->valor){
        // Anteriormente ele calcula se um valor é maior que o outro para encontrar a posicao correta
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

void buscar(no *root, int objetivo){
  no *aux=  malloc(sizeof(no));
  aux = root;

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

void mostrar(no *root){
  no *aux = malloc(sizeof(no));
  int a_mostrar = 0;

  while(true && aux->valor != root->valor){
    aux->esquerda->valor = a_mostrar;
  }
}


int main(){

  int opcao = 0;
  int valor = 0;
  no *root = malloc(sizeof(no));
  root->valor = -1;

  while (opcao != 5) {
    printf("1- inserir 2 - Mostrar 3-Buscar 5-Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Digite algum valor \n");
        scanf("%d",&valor);
        inserir(root, valor);
      case 3:
        printf("Digite o valor que vai ser buscado \n");
        scanf("%d", &valor);
        buscar(root, valor);
      case 5:
        return 0;
    }
  } 
  return 0;
}
