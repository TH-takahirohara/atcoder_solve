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
  int N, L, R;
  cin >> N >> L >> R;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  rep(i,0,N) {
    int a = A.at(i);
    int ans = -1;
    if (a < L) {
      ans = L;
    } else if (a > R) {
      ans = R;
    } else {
      ans = a;
    }
    cout << ans << " ";
  }
  cout << endl;
}
