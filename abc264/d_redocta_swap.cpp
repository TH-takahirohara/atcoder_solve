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
  string str;
  cin >> str;

  vector<char> S(7);
  rep(i,0,7) S.at(i) = str.at(i);

  vector<char> tar = {'a', 't', 'c', 'o' ,'d', 'e', 'r'};
  int ans = 0;
  rep(i,0,7) {
    if (S.at(i) == tar.at(i)) continue;
    int idx = -1;
    rep(j,0,7) if (S.at(j) == tar.at(i)) idx = j;
    ans += idx - i;
    for (int k=idx; k>i; k--) {
      swap(S.at(k-1), S.at(k));
    }
  }
  cout << ans << endl;
}
