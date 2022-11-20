// 二分探索（一番基本的な形式）
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
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  int ng = -1;
  int ok = N+1;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    if (A.at(mid) >= X) ok = mid;
    else ng = mid;
  }
  cout << ok + 1 << endl;
}
