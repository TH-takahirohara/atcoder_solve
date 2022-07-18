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
  int N,X,Y,Z;
  cin >> N >> X >> Y >> Z;
  
  vector<int> A(N), B(N), S(N);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) cin >> B.at(i);
  rep(i,0,N) S.at(i) = A.at(i) + B.at(i);
  
  vector<bool> goukaku(N, false);
  
  rep(ite,0,X) {
    int pos = -1;
    rep(i,0,N) {
      if (goukaku.at(i)) continue;
      if (pos == -1 || A.at(i) > A.at(pos)) pos = i;
    }
    goukaku.at(pos) = true;
  }
  
  rep(ite,0,Y) {
    int pos = -1;
    rep(i,0,N) {
      if (goukaku.at(i)) continue;
      if (pos == -1 || B.at(i) > B.at(pos)) pos = i;
    }
    goukaku.at(pos) = true;
  }
  
  rep(ite,0,Z) {
    int pos = -1;
    rep(i,0,N) {
      if (goukaku.at(i)) continue;
      if (pos == -1 || S.at(i) > S.at(pos)) pos = i;
    }
    goukaku.at(pos) = true;
  }
  
  rep(i,0,N) {
    if (goukaku.at(i)) cout << i+1 << endl;
  }
}
