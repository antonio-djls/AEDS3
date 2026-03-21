#include <algorithm>
#include <bits/stdc++.h>

#include <utility>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll int t{}; cin >> t;
    vector<int> vi;


    while(t--){
        int qtd{}; cin >> qtd;
        vector<int> vi(qtd);
        for(int k = 0; k < qtd; k++){
            cin >> vi[k];
        }
        auto ans =  max_element(vi.begin(),vi.end());
        if(*ans != vi[0]){
            int pos = ans - vi.begin();
           swap(vi[0],vi[pos]);
           int sum = 0;
           for(int i =  0; i < vi.size(); i++){
               sum += *max_element(vi.begin(),vi.begin()+i);
           }
           cout << sum << endl;
           vi.clear();
         }else{
             int sum = 0;
             for(int i =  0; i < vi.size(); i++){
                 sum += *max_element(vi.begin(),vi.begin()+i);
             }
             cout << sum << endl;
             vi.clear();
        }

    }



    return 0;
}
