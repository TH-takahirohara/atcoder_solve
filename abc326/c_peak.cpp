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
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  sort(A.begin(), A.end());

  int ans = 0;

  for (int i=0; i < N; i++) {
    int za = A.at(i);
    int less_za = lower_bound(A.begin(), A.end(), za) - A.begin();
    int less_m = lower_bound(A.begin(), A.end(), za+M) - A.begin();
    ans = max(ans, less_m - less_za);
  }
  cout << ans << endl;
}
