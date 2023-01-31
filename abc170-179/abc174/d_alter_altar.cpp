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
  string S;
  cin >> N >> S;
  
  int cnt_r = 0;
  rep(i,0,N) if (S.at(i) == 'R') cnt_r++;
  
  int ans = 0;
  rep(i,0,cnt_r) if (S.at(i) == 'W') ans++;
  
  cout << ans << endl;
}

