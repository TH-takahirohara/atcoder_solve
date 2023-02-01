#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef pair<int,int> P;

int main() {
  int N,M,Q;
  cin >> N >> M >> Q;
  vector<P> nimotu(N);
  rep(i,0,N) {
    int w,v;
    cin >> w >> v;
    nimotu.at(i) = make_pair(w,v);
  }

  vector<P> hako(M);
  rep(i,0,M) {
    int x; cin >> x;
    hako.at(i) = make_pair(x,i);
  }
  // 箱は大きさの小さい順にソートする
  sort(hako.begin(), hako.end());

  rep(ite,0,Q) {
    int l,r; cin >> l >> r;
    l--; r--;
    int ans = 0;
    vector<bool> canpick(N, true);
    // 各箱についてチェック
    rep(i,0,M) {
      int x = hako.at(i).first;
      int num = hako.at(i).second;
      // 使えない箱はスキップする
      if (l<=num && num<=r) continue;
      int nimotu_n = -1;
      int kati = 0;
      // 全ての荷物についてチェックし、この箱に入れることができる最も価値の高い荷物を保持する
      rep(j,0,N) {
        if (canpick.at(j) && nimotu.at(j).first <= x && nimotu.at(j).second > kati) {
          nimotu_n = j;
          kati = nimotu.at(j).second;
        }
      }
      if (nimotu_n != -1) {
        canpick.at(nimotu_n) = false;
        ans += kati;
      }
    }
    cout << ans << endl;
  }
}
