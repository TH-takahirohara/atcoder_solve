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
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  map<int,int> ato, mae;
  rep(i,0,N) {
    if (i == 0) {
      if (N > 1) ato[A.at(i)] = A.at(i+1);
      else ato[A.at(i)] = 2e9;
      mae[A.at(i)] = -1;
    } else if (i != N-1){
      ato[A.at(i)] = A.at(i+1);
      mae[A.at(i+1)] = A.at(i);
      mae[A.at(i)] = A.at(i-1);
    } else {
      ato[A.at(i)] = 2e9;
      mae[A.at(i)] = A.at(i-1);
      mae[2e9] = A.at(i);
    }
  }

  int Q;
  cin >> Q;
  rep(i,0,Q) {
    int n; cin >> n;
    if (n == 1) { // 挿入
      int x, y;
      cin >> x >> y;
      int n_tsugi = ato.at(x);
      ato[x] = y;
      ato[y] = n_tsugi;
      mae[n_tsugi] = y;
      mae[y] = x;
    } else { // n == 2 削除
      int x;
      cin >> x;
      int x_tsugi = ato.at(x);
      int x_mae = mae.at(x);
      ato[x_mae] = x_tsugi;
      mae[x_tsugi] = x_mae;
      ato.erase(x);
      mae.erase(x);
    }
  }

  vector<int> ans;
  int st = 2e9;
  while (true) {
    int tmp = mae.at(st);
    if (tmp == -1) break;
    ans.push_back(tmp);
    st = tmp;
  }
  reverse(ans.begin(), ans.end());
  rep(i,0,ans.size()) {
    cout << ans.at(i) << " ";
  }
  cout << endl;
}
