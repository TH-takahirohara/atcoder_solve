// 解説放送を見てから実装してAC
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
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> B(N); // 休日と休日の間がw日だった場合の、間に挟まれている平日の生産量を保持する配列
  for (int w=1; w <= N-1; w++) {
    for (int i=1; i <= w; i++) {
      B.at(w) += A.at(min(i-1, w-i));
    }
  }

   // 0とNは最初から休日とみなす
  vector<ll> dp(N+1);
  for (int i=1; i <= N; i++) {
    for (int j=0; j < i; j++) {
      dp.at(i) = max(dp.at(i), dp.at(j) + B.at(i - j - 1));
    }
  }
  cout << dp.at(N) << endl;
}
