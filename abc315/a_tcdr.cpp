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

  vector<char> vec = {'a', 'e', 'i', 'o', 'u'};
  string ans = "";
  rep(i,0,S.size()) {
    char c = S.at(i);
    bool fl = true;
    rep(j,0,5) {
      if (vec.at(j) == c) fl = false;
    }
    if (fl) ans += c;
  }
  cout << ans << endl;
}
