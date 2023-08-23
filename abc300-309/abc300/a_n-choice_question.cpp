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
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> C(N);
  rep(i,0,N) cin >> C.at(i);

  rep(i,0,N) {
    if (A + B == C.at(i)) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
