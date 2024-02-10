#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

map<ull,ull> mp;
// ull ans;

ull rec(ull n) {
  if (mp.count(n)) {
    return mp.at(n);
  }

  ull nx1, nx2;
  if (n % 2 == 0) {
    nx1 = n / 2;
    nx2 = n / 2;
  } else {
    nx1 = n / 2;
    nx2 = n / 2 + 1;
  }
  // ull nx1 = floor(n / 2.0);
  // ull nx2 = ceil(n / 2.0);
  // cout << "n: " << n << " " << nx1 << " " << nx2 << endl;
  ull out1 = rec(nx1);
  if (!mp.count(nx1)) mp[nx1] = out1;
  ull out2 = rec(nx2);
  if (!mp.count(nx2)) mp[nx2] = out2;

  return mp[n] = n + out1 + out2;
}

int main() {
  ull N;
  cin >> N;

  // ans = 0;
  mp[0] = 0;
  mp[1] = 0;
  // mp[2] = 2;
  
  cout << rec(N) << endl;
}
