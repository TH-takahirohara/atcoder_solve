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

  int idx = -1;
  rep(i,0,S.size()) {
    if (S.at(i) != T.at(i)) {
      idx = i+1;
      break;
    }
  }
  if (idx == -1) idx = T.size();
  cout << idx << endl;
}
