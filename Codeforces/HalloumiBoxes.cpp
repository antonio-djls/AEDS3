#include <bits/stdc++.h>
#include<algorithm>
#include <vector>
#define ll long long
#define f first
#define s second
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t = 0; cin >> t;
  ll size{}, maximo{};
  
  cin >> size;
  
  while(t--){

    cin >> size >> maximo;

    int input = 0;
    vector<int> vi;
    for(int i = 0; i < size; i++){
      cin >> input;
      vi.push_back(input);
    }
    if(is_sorted(vi.begin(),vi.end()) or maximo >= 2){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
    vi.clear();
  }
  return 0;
}
