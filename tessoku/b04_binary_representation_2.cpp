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
  string N;
  cin >> N;

  reverse(N.begin(), N.end());

  int ans = 0;
  rep(i,0,N.size()) {
    if (N.at(i) == '1') ans += (1 << i);
  }
  cout << ans << endl;
}
