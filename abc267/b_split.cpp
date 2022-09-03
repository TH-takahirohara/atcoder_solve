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
  string S;
  cin >> S;

  vector<int> vec(7);
  if (S.at(0)=='1') {
    cout << "No" << endl;
    return 0;
  }

  rep(i,0,10) {
    if (S.at(i) == '0') continue;
    int v = i+1;
    if (v==1 || v==5) {
      vec.at(3)++;
    } else if (v==7) {
      vec.at(0)++;
    } else if (v==4) {
      vec.at(1)++;
    } else if (v==2 || v==8) {
      vec.at(2)++;
    } else if (v==3 || v==9) {
      vec.at(4)++;
    } else if (v==6) {
      vec.at(5)++;
    } else {
      vec.at(6)++;
    }
  }
  // rep(i,0,7) cout << vec.at(i) << endl;

  string ans = "No";
  rep(i,0,7) {
    rep(j,i+1,7) {
      if (vec.at(i) == 0 || vec.at(j) == 0) continue;
      if (abs(j-i) == 1) continue;
      bool can = true;
      rep(k,i+1,j) {
        if (vec.at(k) > 0) can = false;
      }
      if (can) ans = "Yes";
    }
  }
  cout << ans << endl;
}
