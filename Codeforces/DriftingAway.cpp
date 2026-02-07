#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 0;
    cin >> t;
    string input;
    while (t--) {
        cin >> input;
        ll n = input.size();
        if (n == 1 && input[0] == '*') {
            cout << 1 << "\n";
            continue;
        }
        bool infinito = false;
        for (char c : input) {
            if (c == '*') {
                infinito = true;
                break;
            }
        }
        for (int i = 0; i + 1< n; i++) {
            if (input[i] == '>' && input[i + 1] == '<') {
                infinito = true;
                break;
            }
        }
        if (infinito == true) {
            cout << -1 << "\n";
            continue;
        }
        ll max_time = 0;
        ll count = 0;
        for (int i = 0; i < n; i++) {
            if (input[i] == '>') count++;
            else break;
        }
        max_time = max(max_time, count);
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (input[i] == '<') count++;
            else break;
        }
        max_time = max(max_time, count);
        cout << max_time << "\n";
    }

    return 0;
}
