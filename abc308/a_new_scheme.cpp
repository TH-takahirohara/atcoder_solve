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
  vector<int> S(8);
  rep(i,0,8) cin >> S.at(i);

  string ans = "Yes";
  rep(i,0,8) {
    if (i != 0) {
      if (S.at(i) < S.at(i-1)) ans = "No";
    }
    if (S.at(i) >= 100 && S.at(i) <= 675 && S.at(i) % 25 == 0) {
      continue;
    } else {
      ans = "No";
    }
  }
  cout << ans << endl;
}
