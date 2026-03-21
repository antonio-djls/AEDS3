#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){
        ll qtd, operacoes, limite;
        cin >> qtd >> operacoes >> limite;

        vector<ll> vi(qtd), copia(qtd);
        for(int i = 0; i < qtd; i++){
            cin >> vi[i];
            copia[i] = vi[i];
        }

        vector<ll> ultima(qtd, 0);
        ll versao = 1;

        for(ll i = 0; i < operacoes; i++){
            ll indice, somar;
            cin >> indice >> somar;
            indice--;

            if(ultima[indice] != versao){
                vi[indice] = copia[indice];
                ultima[indice] = versao;
            }

            vi[indice] += somar;

            if(vi[indice] > limite){
                versao++;
            }
        }
        for(int i = 0; i < qtd; i++){
            if(ultima[i] != versao){
                vi[i] = copia[i];
            }
            cout << vi[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
