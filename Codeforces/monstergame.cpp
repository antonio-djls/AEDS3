#include <algorithm>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 0;
  cin >> t;

  while (t--) {

    ll size = 0;
    cin >> size;
    vector<ll> espadas(size);
    vector<ll> levels(size);

    for (int i = 0; i < size; i++)
      cin >> espadas[i];
    for (int i = 0; i < size; i++)
      cin >> levels[i];
    // ordenando
    sort(espadas.begin(), espadas.end());

    // soma dos niveis atrás

    vector<ll> sum(size);
    sum[0] = levels[0];
    for (int i = 1; i < size; i++) {
      sum[i] = sum[i - 1] + levels[i];
    }
    ll res = 0;

    for (int k = 0; k < size; k++) {
      ll x = espadas[k];
      ll qtd = size - k; // pega o intervalo

      ll niveis = upper_bound(sum.begin(), sum.end(), qtd) - sum.begin();
      ll resultado = x * niveis;
      res = max(resultado, res);
    }
    cout << res << endl;
  }
}
