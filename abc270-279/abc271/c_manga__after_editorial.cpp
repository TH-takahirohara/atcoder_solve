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
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<bool> vec(N+2, false);

  int amari = 0;
  rep(i,0,N) {
    if (A.at(i) > N+1) amari++;
    else if (vec.at(A.at(i))) amari++;
    else vec.at(A.at(i)) = true;
  }

  int plus = amari / 2;
  amari = amari % 2;
  rep(i,1,N+1) {
    if (vec.at(i)) continue;
    if (plus == 0) break;
    vec.at(i) = true;
    plus--;
  }

  int r = N+1;
  rep(i,1,N+1) {
    if (r <= i) break;
    if (vec.at(i)) continue;
    while (i < r && amari < 2) {
      if (vec.at(r)) {
        amari++;
        vec.at(r) = false;
      }
      r--;
    }
    if (amari < 2) break;
    vec.at(i) = true;
    amari = 0;
  }

  int ans = N;
  rep(i,1,N+1) {
    if (!vec.at(i)) {
      ans = i-1;
      break;
    }
  }
  cout << ans << endl;
}
