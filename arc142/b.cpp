#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  
  vector<vector<int>> vec(N, vector<int>(N,0));
  int cnt = 1;
  rep(i,0,N) {
    rep(j,0,N) {
      vec.at(i).at(j) = cnt;
      cnt++;
    }
  }
  
  rep(i,0,N) {
    rep(j,0,N) {
      if (j % 2 == 0 && j != N-1) swap(vec.at(i).at(j), vec.at(i).at(j+1));
    }
  }
  
  rep(i,0,N) {
    rep(j,0,N) {
      if (j != N-1) cout << vec.at(i).at(j) << " ";
      else cout << vec.at(i).at(j);
    }
    cout << endl;
  }
}

