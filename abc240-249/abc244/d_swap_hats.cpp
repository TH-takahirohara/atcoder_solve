#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  vector<char> S(3), T(3);
  rep(i,0,3) cin >> S.at(i);
  rep(i,0,3) cin >> T.at(i);
  
  bool flag = true;
  int eq_num = 0;
  rep(i,0,3) {
    if (S.at(i) == T.at(i)) eq_num++;
  }
  
  if (eq_num == 1) cout << "No" << endl;
  else cout << "Yes" << endl;
}
