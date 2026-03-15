#include <cstddef>
#include <iostream>
#include <iterator>

using namespace std;

struct no {
  no *left;
  no *right;
  int data{};
};

class tree {
  public:
  no *topo;

  tree(int x) {
    topo->data = x;
    topo->right = nullptr;
    topo->left = nullptr;
  }
};

int main() {
  no  n1;
  return 0; }
