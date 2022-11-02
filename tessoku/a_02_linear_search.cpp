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
  int N, X;
  cin >> N >> X;

  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  string ans = "No";
  rep(i,0,N) {
    if (A.at(i) == X) ans = "Yes";
  }
  cout << ans << endl;
}
