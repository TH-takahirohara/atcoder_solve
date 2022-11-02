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
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  bool ans = false;
  rep(i,0,N) {
    rep(j,i+1,N) {
      rep(k,j+1,N) {
        if (A.at(i) + A.at(j) + A.at(k) == 1000) ans = true;
      }
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
