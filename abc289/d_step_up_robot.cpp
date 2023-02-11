#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, M;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  cin >> M;
  vector<ll> B(M);
  rep(i,0,M) cin >> B.at(i);

  ll X;
  cin >> X;

  vector<bool> moti(100005, false);
  rep(i,0,M) {
    moti.at(B.at(i)) = true;
  }

  vector<bool> dp(200100, false);
  dp.at(0) = true;

  rep(i,0,X+1) {
    if (!dp.at(i)) continue;
    if (moti.at(i)) continue;
    rep(j,0,N) {
      if (i + A.at(j) <= 200000) dp.at(i + A.at(j)) = true;
    }
  }

  if (dp.at(X)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
