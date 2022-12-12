#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  string S, T;
  cin >> S >> T;
  map<char,set<char>> mp, mpr;

  rep(i,0,S.size()) {
    mp[T.at(i)].insert(S.at(i));
    mpr[S.at(i)].insert(T.at(i));
  }

  bool can = true;
  rep(i,0,26) {
    if (mp.count('a' + i) && mp.at('a' + i).size() >= 2) can = false;
  }
  rep(i,0,26) {
    if (mpr.count('a' + i) && mpr.at('a' + i).size() >= 2) can = false;
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
