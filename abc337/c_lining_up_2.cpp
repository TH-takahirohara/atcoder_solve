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

  vector<int> next(N+1);
  int st = -1;
  rep(i,0,N) {
    if (A.at(i) != -1) {
      next.at(A.at(i)) = i+1;
    } else {
      st = i+1;
    }
  }

  cout << st << " ";
  int now = st;
  int cnt = 1;
  if (N == 1) {
    cout << endl;
    return 0;
  }
  while (true) {
    int nx = next.at(now);
    now = nx;
    cout << now << " ";
    cnt++;
    if (cnt == N) break;
  }
  cout << endl;
}
