#include <bits/stdc++.h>
#include <atcoder/segtree>
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
  
  vector<bool> en(361, false);
  en.at(360) = true;
  
  int sum = 0;
  rep(i,0,N) {
    sum += A.at(i);
    sum %= 360;
    en.at(sum) = true;
  }
  
  int ans = 0;
  int now = 0;
  rep(i,0,361) {
    if (en.at(i)) {
      int ns = i - now;
      ans = max(ans, ns);
      now = i;
    }
  }
  cout << ans << endl;
}

