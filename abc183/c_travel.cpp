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
  int N, K;
  cin >> N >> K;

  vector<vector<int>> T(N, vector<int>(N));
  rep(i,0,N) {
    rep(j,0,N) {
      int t;
      cin >> t;
      T.at(i).at(j) = t;
    }
  }

  vector<int> vec(N-1);
  rep(i,0,N-1) vec.at(i) = i+1;

  int ans = 0;
  do {
    int tmp = 0;
    rep(i,0,N) {
      if (i == 0) {
        tmp += T.at(0).at(vec.at(0));
      } else if (i == N-1) {
        tmp += T.at(vec.at(N-2)).at(0);
      } else {
        tmp += T.at(vec.at(i-1)).at(vec.at(i));
      }
    }
    if (tmp == K) ans++;
  } while (next_permutation(vec.begin(), vec.end()));

  cout << ans << endl;
}
