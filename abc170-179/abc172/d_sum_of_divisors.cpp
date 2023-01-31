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

  vector<int> vec(10000005, 1);

  rep(i,2,10000001) {
    for (int j=i; j<=10000000; j+=i) {
      vec.at(j)++;
    }
  }

  ll ans = 0;
  rep(i,1,N+1) {
    ans += (ll)i * vec.at(i);
  }
  cout << ans << endl;
}
