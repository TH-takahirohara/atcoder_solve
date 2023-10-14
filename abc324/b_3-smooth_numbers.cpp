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

  while (true) {
    if (N % 2 != 0) {
      break;
    }
    N = N / 2;
  }

  while (true) {
    if (N % 3 != 0) {
      break;
    }
    N = N / 3;
  }

  if (N == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
