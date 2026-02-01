#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t{}; cin >> t;
    while(t--){
        int size{}; cin >> size;
        vector<ll>vi(size);
        for(int i = 0; i < size; i++) cin >> vi[i];
        bool b = true;
        for(int i = 1; i < size-1; i++){
            if(gcd(lcm(vi[i-1],vi[i]), lcm(vi[i],vi[i+1])) != vi[i]){
                b = false; break;
            }
        }
        if(b == true){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }



    }

    return 0;
}
