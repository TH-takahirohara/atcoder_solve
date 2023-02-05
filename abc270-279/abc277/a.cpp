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
  int N, K;
  cin >> N >> K;
  vector<int> vec(N);
  rep(i,0,N) cin >> vec.at(i);

  int ans = -1;
  rep(i,0,N) {
    if (vec.at(i) == K) ans = i+1;
  }
  cout << ans << endl;
}
