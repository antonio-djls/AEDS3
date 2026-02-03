#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 0; cin >> t;
    while(t--){
        ll int size =0;
        cin >> size;
        vector<ll int> vi(size);
        vector<ll int> ans;
        for(int i =0; i < size; i++) cin >> vi[i];
        ll int previo = vi[0];
        ll int count = 0;
        ll int dif = 0;
        for(int i =1; i < size; i++){
            if(previo > vi[i]){
                dif = abs(previo -vi[i]);
                ans.push_back(dif);
                previo = max(previo,vi[i]);
            }else{
                previo = vi[i];
            }
        }

        for(int i = 0; i < ans.size(); i++){
            count += ans[i];
        }
        if(!ans.empty()){
            auto maximo = max_element(ans.begin(),ans.end());
            count += *maximo;
        }
        cout << count << endl;
        ans.clear();
    }

    return 0;
}
