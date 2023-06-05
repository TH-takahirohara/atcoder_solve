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
  vector<int> X(N), Y(N);
  rep(i,0,N) cin >> X.at(i) >> Y.at(i);

  rep(i,0,N) {
    rep(j,0,N) {
      rep(k,0,N) {
        if (i == j || j == k || k == i) continue;
        int x1 = X.at(i), y1 = Y.at(i), x2 = X.at(j), y2 = Y.at(j), x3 = X.at(k), y3 = Y.at(k);
        if ((x2 - x1)*y3 == (y2 - y1)*(x3 - x1) + (x2 - x1)*y1) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
