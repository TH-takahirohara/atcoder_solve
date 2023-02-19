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
  int N, K;
  cin >> N >> K;
  vector<bool> exist(300005, false);
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  rep(i,0,N) {
    if (A.at(i) < 300005) {
      exist.at(A.at(i)) = true;
    }
  }

  int ans = 0;
  rep(i,0,K) {
    if (!exist.at(i)) break;
    ans++;
  }

  cout << ans << endl;
}
