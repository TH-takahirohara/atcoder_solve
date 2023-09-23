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

  string ans = "Yes";
  char zen = S.at(0);
  rep(i,1,S.size()) {
    if ((int)(S.at(i) - '0') >= (int)(zen - '0'))  {
      cout << "No" << endl;
      return 0;
    } else {
      zen = S.at(i);
    }
  }
  cout << "Yes" << endl;
}
