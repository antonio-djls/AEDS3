#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll int t{}; cin >> t;
    ll int numero_elementos{},alvo{}, incremento{};

    while(t--){
        cin >> numero_elementos >> alvo >> incremento;
        vector<ll int> vi (numero_elementos);
        ll int somatorio = 0;
        for(int i = 0; i < numero_elementos; i++){
            cin >> vi[i];
            somatorio += vi[i];
        }

        if(somatorio == alvo){
            cout << "YES" << endl;
            continue;
        }else{
            while(somatorio < alvo){
                somatorio += incremento;
            }
            if(somatorio == alvo){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
