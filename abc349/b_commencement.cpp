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

  vector<int> cnt(30);
  rep(i,0,S.size()) {
    int n = int(S.at(i) - 'a');
    cnt.at(n)++;
  }

  vector<int> num_sums(105);
  rep(i,0,30) {
    if (cnt.at(i) == 0) continue;
    num_sums.at(cnt.at(i))++;
  }

  rep(i,1,101) {
    if (num_sums.at(i) == 0 || num_sums.at(i) == 2) {
      continue;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
