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
  int N;
  cin >> N;
  
  vector<ll> S(N), T(N), vec;
  rep(i,0,N) cin >> S.at(i);
  rep(i,0,N) cin >> T.at(i);
  
  vec = T;
  
  rep(ite,0,2) {
    rep(i,0,N) {
      if (i != N-1) vec.at(i+1) = min(vec.at(i+1), vec.at(i)+S.at(i));
      else vec.at(0) = min(vec.at(0), vec.at(i)+S.at(i));
    }
  }
  
  rep(i,0,N) cout << vec.at(i) << endl;
}

