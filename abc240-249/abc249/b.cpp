#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  string S;
  cin >> S;

  string oomoji = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string komoji = "abcdefghijklmnopqrstuvwxyz";

  bool is_oomoji = false;
  bool is_komoji = false;

  rep(i,0,S.size()) {
    rep(j,0,oomoji.size()) {
      if (oomoji.at(j) == S.at(i)) is_oomoji = true;
      if (komoji.at(j) == S.at(i)) is_komoji = true;
    }
  }

  bool kotonaru = true;
  rep(i,0,S.size()) {
    rep(j,0,S.size()) {
      if (i==j) continue;
      if (S.at(i) == S.at(j)) kotonaru = false;
    }
  }

  if (is_oomoji && is_komoji && kotonaru) cout << "Yes" << endl;
  else cout << "No" << endl;
}
