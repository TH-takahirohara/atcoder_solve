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
  string S;
  cin >> S;

  bool can = true;
  if (!(S.at(0) - 'A' >= 0 && S.at(0) - 'A' <= 26)) {
    can = false;
  }
  rep(i,1,S.size()) {
    if (!(S.at(i) - 'a' >= 0 && S.at(i) - 'a' <= 26)) {
      can = false;
    }
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
