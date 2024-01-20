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
  int N;
  cin >> N;
  int n = N - 1;
  int cnt = 0;
  while (n > 0) {
    cnt++;
    n /= 2;
  }

  cout << cnt << endl;

  rep(ite,0,cnt) {
    vector<int> nums;
    rep(i,0,N) {
      if (i & (1 << ite)) {
        nums.push_back(i+1);
      }
    }
    cout << nums.size() << " ";
    rep(i,0,nums.size()) {
      cout << nums.at(i) << " ";
    }
    cout << endl;
  }

  string S;
  cin >> S;

  int ans = 0;
  int num = 1;
  rep(i,0,S.size()) {
    if (S.at(i) == '1') ans += num;
    num *= 2;
  }
  cout << ans + 1 << endl;
  return 0;
}
