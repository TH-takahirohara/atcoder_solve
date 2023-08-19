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
  int M;
  cin >> M;
  vector<int> D(M);
  rep(i,0,M) cin >> D.at(i);

  int sum = 0;
  rep(i,0,M) {
    sum += D.at(i);
  }
  int naka = (sum + 1) / 2;

  rep(i,0,M) {
    if (naka <= D.at(i)) {
      cout << i+1 << " " << naka << endl;
      return 0;
    }
    naka -= D.at(i);
  }
}
