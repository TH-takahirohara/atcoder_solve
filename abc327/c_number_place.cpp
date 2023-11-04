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
  vector<vector<int>> A(9, vector<int>(9));
  rep(i,0,9) {
    rep(j,0,9) {
      cin >> A.at(i).at(j);
    }
  }

  bool can = true;
  rep(j,0,9) {
    vector<int> cnt(10);
    rep(i,0,9) {
      cnt.at(A.at(i).at(j))++;
    }
    rep(k,1,10) {
      if (cnt.at(k) != 1) can = false;
    }
  }

  rep(i,0,9) {
    vector<int> cnt(10);
    rep(j,0,9) {
      cnt.at(A.at(i).at(j))++;
    }
    rep(k,1,10) {
      if (cnt.at(k) != 1) can = false;
    }
  }

  for (int i=0; i <= 6; i+=3) {
    for (int j=0; j <= 6; j+=3) {
      vector<int> cnt(10);
      rep(k,0,3) {
        rep(l,0,3) {
          cnt.at(A.at(i+k).at(j+l))++;
        }
      }
      rep(m,1,10) {
        if (cnt.at(m) != 1) can = false;
      }
    }
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
