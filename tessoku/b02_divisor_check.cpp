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
  int A, B;
  cin >> A >> B;

  bool ans = false;
  rep(i,A,B+1) {
    if (100 % i == 0) ans = true;
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
