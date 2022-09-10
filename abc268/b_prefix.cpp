#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  string S,T;
  cin >> S >> T;
  if (S.size() > T.size()) {
    cout << "No" << endl;
    return 0;
  }
  string ans = "Yes";
  rep(i,0,S.size()) {
    if (S.at(i) != T.at(i)) ans = "No";
  }
  cout << ans << endl;
}
