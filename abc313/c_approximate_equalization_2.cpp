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

  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  ll sum = 0;
  rep(i,0,N) sum += A.at(i);

  ll hei = sum / N;
  ll amari = sum % N;

  ll dai_n = 0;
  ll shou_n = 0;
  if (amari == 0) {
    dai_n = N;
  } else {
    rep(i,0,N) {
      if (sum % (hei + 1) == 0) break;
      shou_n++;
      sum -= hei;
    }
    dai_n = N - shou_n;
  }

  ll ans = 0;
  rep(i,0,N) {
    if (dai_n > 0) {
      if (A.at(i) <= (hei + 1)) break;
      dai_n--;
      ans += A.at(i) - (hei + 1);
    } else {
      if (A.at(i) <= hei) break;
      ans += A.at(i) - hei;
    }
  }
  cout << ans << endl;
}
