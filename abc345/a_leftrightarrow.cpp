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
  if (S.at(0) != '<' || S.at(S.size()-1) != '>') {
    cout << "No" << endl;
    return 0;
  }

  bool ok = true;
  for (int i=1; i<S.size()-1; i++) {
    if (S.at(i) != '=') {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
