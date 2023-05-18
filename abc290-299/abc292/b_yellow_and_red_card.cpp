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
  int N, Q;
  cin >> N >> Q;
  vector<int> card(N);
  rep(i,0,Q) {
    int t, x;
    cin >> t >> x;
    x--;
    if (t == 1) {
      card.at(x) += 1;
    } else if (t == 2) {
      card.at(x) += 2;
    } else {
      if (card.at(x) >= 2) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}
