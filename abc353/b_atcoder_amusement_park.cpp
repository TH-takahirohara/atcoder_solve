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
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  int cnt = 0;
  int emp = K;
  rep(i,0,N) {
    int tugi = A.at(i);
    if (emp < tugi) {
      cnt += 1;
      emp = K - tugi;
    } else {
      emp -= tugi;
    }
  }
  if (emp < K) cnt++;
  cout << cnt << endl;
}
