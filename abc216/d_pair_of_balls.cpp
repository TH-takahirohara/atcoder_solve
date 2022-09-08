// 実装問題だと思う。途中のrep回数をNにすると1WA残ったが、2NにするとACとなった。理由は不明
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
  int N,M;
  cin >> N >> M;
  vector<queue<int>> tutu(M);
  vector<set<int>> tops(N);

  rep(i,0,M) {
    int k; cin >> k;
    rep(j,0,k) {
      int a; cin >> a;
      a--;
      if (j==0) tops.at(a).insert(i); // 筒の番号をtopsに入れる
      tutu.at(i).push(a);
    }
  }

  rep(i,0,2*N) {
    int num_t = i % M;
    if (tutu.at(num_t).size() == 0) continue;
    int _top_v = tutu.at(num_t).front(); // その筒の一番上のボールの色

    queue<int> que;
    que.push(_top_v);
    while (!que.empty()) {
      int top_v = que.front(); que.pop();
      if (tops.at(top_v).size() == 2) {
        rep(iter,0,2) {
          int tutu_n = *begin(tops.at(top_v)); tops.at(top_v).erase(tutu_n);
          tutu.at(tutu_n).pop();
          // cout << "top: " << tops.at(top_v).size() << endl;

          if (tutu.at(tutu_n).size() == 0) continue;
          int nw_top_n = tutu.at(tutu_n).front();
          tops.at(nw_top_n).insert(tutu_n);
          que.push(nw_top_n);
        }
      }
    }
  }

  string ans = "Yes";
  rep(i,0,M) {
    if (tutu.at(i).size() > 0) ans = "No";
  }
  cout << ans << endl;
}
