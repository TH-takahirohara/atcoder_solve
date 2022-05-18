// 060 両側から考える/最長増加部分列
// 解法を見てから書き直した。
// A.at(i) を部分列の最大値とする最長増加部分列の長さを、配列の両側（A_1 ~ A_i と A_N ~ A_i）から計算して、
// 両者を足した値の最大値が答えになる。（A.at(i) を「最大値」とする最長増加部分列というところがポイント？）
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int INF = 1000000000;

int main() {
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  vector<int> rev_A = A;
  reverse(rev_A.begin(), rev_A.end());
  
  vector<int> dp(N, INF), dp_rev(N, INF);
  vector<int> P(N), Q(N);
  
  rep(i,0,N) {
    int idx = lower_bound(dp.begin(), dp.end(), A.at(i)) - dp.begin();
    dp.at(idx) = A.at(i);
    P.at(i) = idx+1;
  }
  
  rep(i,0,N) {
    int idx = lower_bound(dp_rev.begin(), dp_rev.end(), rev_A.at(i)) - dp_rev.begin();
    dp_rev.at(idx) = rev_A.at(i);
    Q.at(i) = idx+1;
  }
  
  int ans = 0;
  rep(i,0,N) {
    ans = max(ans, P.at(i) + Q.at(N-i-1) - 1);
  }
  cout << ans << endl;  
}

