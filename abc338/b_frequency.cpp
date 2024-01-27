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

  map<char,int> mp;
  rep(i,0,S.size()) {
    mp[S.at(i)]++;
  }

  char ans;
  int cnt = 0;
  for (auto p : mp) {
    if (p.second > cnt) {
      ans = p.first;
      cnt = p.second;
    }
  }
  cout << ans << endl;
}
