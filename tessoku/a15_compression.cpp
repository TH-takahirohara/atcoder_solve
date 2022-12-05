// 座標圧縮
// 参考: https://qiita.com/ysk24ok/items/30ae72f4f1060b088588
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
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<int> SA = A;
  sort(SA.begin(), SA.end());
  SA.erase(unique(SA.begin(), SA.end()), SA.end());

  vector<int> ans(N);
  rep(i,0,N) {
    ans.at(i) = lower_bound(SA.begin(), SA.end(), A.at(i)) - SA.begin() + 1;
  }
  rep(i,0,N) cout << ans.at(i) << " ";
}
