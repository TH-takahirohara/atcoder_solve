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
  vector<int> A(N-1);
  rep(i,0,N-1) cin >> A.at(i);

  for (int i=0; i<=100; i++) {
    vector<int> NA = A;
    NA.push_back(i);
    sort(NA.begin(), NA.end());
    int ans = 0;
    for (int j=1; j<=N-2; j++) {
      ans += NA.at(j);
    }
    if (ans >= X) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
