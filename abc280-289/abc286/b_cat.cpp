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
  string S;
  cin >> S;

  string ans = "";
  rep(i,0,N) {
    if (S.at(i) == 'n' && i != N-1 && S.at(i+1) == 'a') {
      ans += "ny";
    } else {
      ans += S.at(i);
    }
  }
  cout << ans << endl;
}
