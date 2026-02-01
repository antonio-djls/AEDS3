#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t {}; cin >> t;

    while(t--){
        int size = 0; cin >> size; vector<ll> vi(size);
        for(int i = 0; i < size; i++){
            cin >> vi[i];
        }
        vector<ll> ans;
        ll count = 0;
        ll esperado  = 0;
        for(int i = 0; i < size; i++){
             esperado += ans.size() + 1;
            if(vi[i] == esperado){
                count++;
                ans.push_back(count);
            }else{
                int dif = esperado - vi[i];
                ans.push_back(ans[dif-1]);
            }
            esperado = vi[i];
        }
        for(ll n : ans){
            cout << n << " ";
        }
        cout << endl;

    }

    return 0;
}
