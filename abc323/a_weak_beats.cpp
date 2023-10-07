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
  string S;
  cin >> S;

  rep(i,0,S.size()) {
    if (i % 2 == 1 && S.at(i) == '1') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
