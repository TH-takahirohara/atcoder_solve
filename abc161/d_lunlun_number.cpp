#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int K;
string ans;
int cnt = 0;
bool flag = false;

void rec(int keta, string s) {
  if (flag) return;

  int _min = 1; int _max = 9;
  if (s != "") {
    int matubi = int(s.at(s.size() - 1) - '0');
    _min = max(matubi - 1, 0);
    _max = min(matubi + 1, 9);
  }

  for (int n = _min; n <= _max; n++) {
    string nx = s + to_string(n);
    if (nx.size() == keta) {
      cnt++;
      if (cnt == K) {
        ans = nx;
        flag = true;
        return;
      }
    } else if (nx.size() < keta) {
      rec(keta, nx);
    }
  }
}

int main() {
  cin >> K;

  for (int i=1; i<=10; i++) {
    rec(i, "");
  }
  cout << ans << endl;
}
