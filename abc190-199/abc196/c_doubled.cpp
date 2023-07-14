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
  ll N;
  cin >> N;

  int cnt = 0;
  for (ll i=1; i < 1000000; i++) {
    string s = to_string(i);
    s = s + s;
    if (stoll(s) > N) {
      break;
    }
    cnt++;
  }
  cout << cnt << endl;
}
