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
  vector<int> H(N);
  rep(i,0,N) cin >> H.at(i);

  int res = -1;
  rep(i,0,N) {
    if (i == 0) continue;
    if (H.at(i) > H.at(0)) {
      res = i+1;
      break;
    }
  }
  cout << res << endl;
}
