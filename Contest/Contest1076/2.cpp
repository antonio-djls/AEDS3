#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll int t{};
  cin >> t;
  while (t--) {
    int size{};
    cin >> size;
    vector<int> vi(size);
    for (int i = 0; i < size; i++) {
      cin >> vi[i];
    }

    int maior = 0, direita = 0;

    for (int i = 0; i < size; i++) {
      maior = vi[i];
      direita = i;
      for (int j = i; j < size; j++) {
        if (vi[j] >= maior) {
          maior = vi[j];
          direita = j;
        }
      }
      if (direita != i) {
        reverse(vi.begin() + i, vi.begin() + direita + 1);
        break;
      }
    }
    for (int num : vi) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
