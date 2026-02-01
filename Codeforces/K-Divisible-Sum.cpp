#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t{}; cin >>t;
    while(t--){
        ll qtd = 0, div = 0;
        cin >> qtd >> div;

        ll sum = ((qtd + div - 1) / div) * div;

        ll ans = (sum + qtd - 1) / qtd;

        cout << ans << endl;
    }
    return 0;
}
