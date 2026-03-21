#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll int t{}; cin >> t;
    ll int qtd{};

    while(t--){
        cin >> qtd;
        vector<int> vi(qtd);

        for(int i = 0; i<qtd;i++){cin >>vi[i];}

        sort(vi.begin(),vi.end());
        auto ans = unique(vi.begin(),vi.end());
        vi.erase(ans,vi.end());
        int menor = vi[0]; int count = 1; int me = 1;
        for(int k = 1; k < vi.size(); k++){
            if(vi[k] == vi[k - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
            me = max(count, me);

        }

        cout << me << endl;
    }


    return 0;
}
