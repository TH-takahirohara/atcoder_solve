#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;

int main() {
  string S;
  cin >> S;
  
  vector<bool> vec(10,false);
  
  rep(i,0,S.size()) {
    int num = int(S.at(i) - '0');
    vec.at(num) = true;
  }
  
  rep(i,0,10) {
    if (!vec.at(i)) cout << i << endl;
  }
}
