#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 0; cin >> t;
    ll size = 0;
    string input;
    while(t--){
        cin >> size;
        cin >> input;
        ll count = 0;
        for(int i = 2; i < size; i+=2){
            if(input[i] == '0')count++;
        }
        cout << count << endl;
    }

    return 0;
}
