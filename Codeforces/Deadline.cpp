#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(double n, double d) {

  for (int i = 1; i < n; i++) {
    double sum = ceil(d / (i + 1));
    // cout << sum+i << endl;
    if ((sum + i) <= n) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t = 0;
  cin >> t;
  while (t--) {
    double n, d;
    cin >> n >> d;
    if (d <= n) {
      cout << "YES" << endl;
    } else {
      bool b = true;
      b = solve(n, d);
      if (b == true) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
