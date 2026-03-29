#include <complex.h>
#include <stdio.h>
#include<stdlib.h>

typedef struct treenode{
  int data;
  struct treenode *left;
  struct treenode *right;
} treenode;

void mostrar_arvore(treenode *root){
  if(root == NULL){
    printf("Vazio \n");
    return;
  }
  printf("Valor = %d \n",root->data);
  printf("Esquerda \n");
  mostrar_arvore(root->left);
  printf("Direita \n");
  mostrar_arvore(root->right);
  printf("Feito");
  

}
treenode *criar_node(int valor){
    treenode * resultado =  malloc(sizeof(treenode));
    if(resultado != NULL){
    resultado->left = NULL;
    resultado->right = NULL;
    resultado->data = valor;
  }
  printf("Node criado");
  return resultado;
}

int main(){
  treenode *n1 = criar_node(10);

  for(int i = 10; i < 15; i++){
    criar_node(i);
  }

  mostrar_arvore(treenode *root);
  return 0;
}
