#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 0; cin >> t;

    string target,input;
    while(t--){
        cin >> target >> input;
        bool b = true;
        for(int i = 0;i < target.size(); i++){
            if(std::string::npos == input.find(target[i])){
                b = false;
                break;
            }
        }
        if(b ==  true){
            int index = 0;
            sort(input.begin(),input.end());
            for(int k = 0; k < input.size(); k++){
                if((int)target[k] >= (int)input[k]){
                    index = k;
                    break;
                }
            }
            string nova(input.begin(),input.begin()+index);
            nova += target;
            index += target.size();
            for(int i = index-1; i < input.size(); i++){
                nova += input[i];
            }
            cout << nova << endl;
        }else{
            cout << "Impossible" << endl;
        }

    }

    return 0;
}
