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
  int N, M;
  cin >> N >> M;
  vector<set<int>> G(N+1);
  vector<bool> seen(N+1, false);
  stack<int> sta;
  sta.push(1);
  while (true) {
    int k;
    cin >> k;
    if (k == -1) return 0; // 異常ケース
    vector<int> vec(k);
    seen.at(sta.top()) = true;

    rep(i,0,k) cin >> vec.at(i);
    int tmp = -1;
    rep(i,0,k) {
      if (seen.at(vec.at(i))) continue;
      tmp = vec.at(i);
      break;
    }
    if (tmp == N) {
      cout << tmp << endl;
      string ans;
      cin >> ans;
      return 0;
    }
    if (tmp != -1) {
      sta.push(tmp);
      cout << tmp << endl;
    } else {
      sta.pop();
      cout << sta.top() << endl;
    }
  }
}
