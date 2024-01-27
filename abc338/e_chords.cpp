// セグメントツリー(segtree)を使って解いた。(コンテストが終わる直前にこれを使うことに気づいた)
// ある区間における最大値を求めれば良いということに早く気付いていれば、コンテスト内に解けただろう。
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int op(int a, int b) {
  return max(a,b);
}

int e() {
  return 0;
}

int main() {
  int N;
  cin >> N;
  segtree<int,op,e> seg(2*N);
  vector<pair<int,int>> vec;
  rep(i,0,N) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (a > b) swap(a,b);
    seg.set(a,b);
    vec.push_back(make_pair(a,b));
  }

  rep(i,0,N) {
    auto p = vec.at(i);
    int mx = seg.prod(p.first, p.second);
    if (mx > p.second) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
