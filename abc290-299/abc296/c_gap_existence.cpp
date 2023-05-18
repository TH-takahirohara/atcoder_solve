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
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  sort(A.begin(), A.end());

  string ans = "No";
  rep(i,0,N) {
    int tar = A.at(i);
    auto idx = lower_bound(A.begin(), A.end(), tar + X);
    if (idx == A.end()) continue;
    if (tar + X - *idx == 0) ans = "Yes";
  }

  cout << ans << endl;
}
