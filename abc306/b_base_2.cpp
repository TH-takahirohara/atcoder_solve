#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  vector<ull> A(64);
  rep(i,0,64) cin >> A.at(i);

  ull kake = 1;
  ull ans = 0;
  rep(i,0,64) {
    ans += kake * A.at(i);
    kake *= 2;
  }

  cout << ans << endl;
}
