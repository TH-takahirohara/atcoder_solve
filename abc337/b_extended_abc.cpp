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
  string S;
  cin >> S;

  string ans = "";
  char zen;
  rep(i,0,S.size()) {
    if (i==0) {
      zen = S.at(i);
      ans += zen;
    } else {
      if (zen != S.at(i)) {
        zen = S.at(i);
        ans += zen;
      }
    }
  }

  if (ans == "ABC" || ans == "A" || ans == "B" || ans == "C" || ans == "AB" || ans == "BC" || ans == "AC") {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
