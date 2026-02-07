#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 0;
    cin >> t;

    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        set<char> set1(s1.begin(), s1.end());
        set<char> set2(s2.begin(), s2.end());

        bool b = false;
        for(char c : set1) {
            if(set2.count(c) > 0) {
                b = true;
                break;
            }
        }

        if(b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
