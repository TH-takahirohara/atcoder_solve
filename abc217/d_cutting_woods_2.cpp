// あらかじめsetに0とLを追加しておくと、条件分岐を減らせる。
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
  int L,Q;
  cin >> L >> Q;

  set<int> st;
  st.insert(0);
  st.insert(L);

  rep(i,0,Q) {
    int c,x;
    cin >> c >> x;
    if (c==1) {
      st.insert(x);
    } else {
      auto it = st.upper_bound(x);
      cout << *it - *(--it) << endl;
    }
  }
}
