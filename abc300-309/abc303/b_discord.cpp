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
  vector<vector<int>> vec(M, vector<int>(N));
  rep(i,0,M) {
    rep(j,0,N) {
      int t;
      cin >> t;
      t--;
      vec.at(i).at(j) = t;
    }
  }

  vector<vector<bool>> funaka(N, vector<bool>(N, true));
  rep(i,0,N) funaka.at(i).at(i) = false;

  rep(i,0,M) {
    rep(j,0,N-1) {
      int a = vec.at(i).at(j);
      int b = vec.at(i).at(j+1);
      funaka.at(a).at(b) = false;
      funaka.at(b).at(a) = false;
    }
  }

  int cnt = 0;
  rep(i,0,N) {
    rep(j,0,N) {
      if (funaka.at(i).at(j)) cnt++;
    }
  }
  cout << cnt / 2 << endl;
}
