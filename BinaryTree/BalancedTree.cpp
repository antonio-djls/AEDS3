#include<iostream>


/* A balanced Binary Tree has at most 1 in difference between its left and right subtree heights, for each node in the tree.
 * Implementação para estudos
 *
 *
 */
struct no{
    no *principal;
    no *secundario;
    long long int valor;
};

class tree{
    public:
        no root;


};

int main(){
    tree arvore;

    arvore.root.valor = 11;
    arvore.root.principal->valor = 7;
    // Criando n
    arvore.root.principal->principal->valor = 3;
    arvore.root.principal->secundario->valor = 9;

    arvore.root.secundario->valor = 15;
    arvore.root.secundario->principal->valor = 13;
    arvore.root.secundario->secundario->valor = 19;
    arvore.root.secundario->principal->valor = 18;




    return  0;
}
