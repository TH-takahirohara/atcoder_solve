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
  int N;
  cin >> N;
  vector<string> vec(N);
  rep(i,0,N) cin >> vec.at(i);

  bool ans = true;
  rep(i,0,N) {
    rep(j,0,N) {
      if (i==j) continue;
      if (vec.at(i).at(j) == 'W') {
        if (vec.at(j).at(i) != 'L') ans = false;
      } else if (vec.at(i).at(j) == 'L') {
        if (vec.at(j).at(i) != 'W') ans = false;
      } else if (vec.at(i).at(j) == 'D') {
        if (vec.at(j).at(i) != 'D') ans = false;
      }
    }
  }

  if (ans) cout << "correct" << endl;
  else cout << "incorrect" << endl;
}
