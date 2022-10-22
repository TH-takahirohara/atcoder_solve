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
  int R, C;
  cin >> R >> C;

  vector<string> vec(R);

  rep(i,0,R) cin >> vec.at(i);

  vector<int> X(C);

  rep(j,0,C) {
    int tmp = 0;
    rep(i,0,R) {
      if (vec.at(i).at(j) == '#') tmp++;
    }
    X.at(j) = tmp;
  }

  rep(i,0,C) cout << X.at(i) << " ";
  cout << endl;
}
