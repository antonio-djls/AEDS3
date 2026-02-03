#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define f first
#define s second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 0;

    vector<ll> vi(2*t);
    ll dp[2*t+1][3];
    dp[0][0] =0;
    for(int i = 0; i < 2*t; i++){
        cin >> vi[i];
    }
    sort(vi.begin(),vi.end());

    for(int i  = 0; i < vi.size(); i++){
        for(int j = i+1; j < vi.size(); j++){

        }
    }

    return 0;
}
