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
  int N;
  cin >> N;

  vector<int> yaku;
  rep(i,1,10) {
    if (N % i == 0) {
      yaku.push_back(i);
    }
  }

  // rep(i,0,yaku.size()) {
  //   cout << yaku.at(i) << " ";
  // }
  // cout << endl;

  string ans = "";
  rep(i,0,N+1) {
    // cout << i << endl;
    char c = '-';
    rep(j,0,yaku.size()) {
      if (i % (N / yaku.at(j)) != 0) continue;
      c = char(yaku.at(j) + '0');
      break;
    }
    ans = ans + c;
  }
  cout << ans << endl;
}
