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

  if (S.size() != 8) {
    cout << "No" << endl;
    return 0;
  }

  if (S.at(0) - 'A' < 0 || S.at(0) - 'A' >= 26 || S.at(S.size()-1) - 'A' < 0 || S.at(S.size()-1) - 'A' >= 26) {
    cout << "No" << endl;
    return 0;
  }
  // cout << 'Z' - 'A';

  rep(i,1,7) {
    if (S.at(i) - 'A' >= 0 && S.at(i) - 'A' < 26) {
      cout << "No" << endl;
      return 0;
    }
  }

  string s = "";
  rep(i,1,7) {
    s += S.at(i);
  }

  // cout << s << endl;
  int num = stoi(s);
  
  if (num >= 100000 && num <= 999999) cout << "Yes" << endl;
  else cout << "No" << endl;
}
