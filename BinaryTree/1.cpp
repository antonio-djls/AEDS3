#include<iostream>
using namespace std;


struct no{
  int data{};
  no* left;
  no* right;
};

class tree{
  public:
    no* root;
  
    tree(int x){
      root->data = x;
      root->right = nullptr; root->left = nullptr;
    }
    void insert(int x){
      no* atual =  root;

      while(true){
        if(x < atual->data){
          if(atual->left == nullptr){
            atual->left = new no;
            atual->left->data = x;
            atual->left->left = nullptr;
            atual->left->right = nullptr;
            return;
          }
          atual = atual->left;
        }else{
          if(atual->right == nullptr){
            atual->right = new no;
            atual->right->data = x;
            atual->right->left = nullptr;
            atual->right->right = nullptr;
            return;
          }
          atual = atual->right;
        }
      }
    }

  void print_pre_order(){
  }
};

int main(){
  tree n1(2);
  int input{}; cout << "Digite algum numero para ser inserido" << endl;
  cin >> input;
  n1.insert(input);
  return 0;
}
