#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  string S, T;
  cin >> S >> T;
  string sd = "";
  rep(i, S.size()-T.size(), S.size()) {
    sd += S.at(i);
  }

  set<int> damem; // 合っていない文字のindex
  rep(i,0,T.size()) {
    if (sd.at(i) == T.at(i) || sd.at(i) == '?' || T.at(i) == '?') continue;
    damem.insert(i);
  }

  if (damem.size() == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  rep(i,0,T.size()) {
    sd.at(i) = S.at(i);
    if (sd.at(i) == T.at(i) || sd.at(i) == '?' || T.at(i) == '?') {
      if (damem.count(i)) {
        damem.erase(i);
      }
    } else {
      damem.insert(i);
    }
    if (damem.size() == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
