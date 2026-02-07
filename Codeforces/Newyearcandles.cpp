#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a{},b{}; cin >> a >> b;
    ll sum = a;
    ll queimadas = a;

    while(queimadas >= b){
        ll novas = queimadas/b;
        sum += novas;
        queimadas = queimadas % b +novas;
    }

    cout << sum << endl;
    return 0;
}
