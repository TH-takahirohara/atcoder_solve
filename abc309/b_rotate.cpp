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
  vector<string> A(N);
  rep(i,0,N) cin >> A.at(i);
  vector<string> B = A;

  // B.at(0).at(0) = A.at(0).at(1);
  // B.at()
  // 一番左
  rep(i,0,N-1) {
    B.at(i).at(0) = A.at(i+1).at(0);
  }
  // 上
  rep(j,0,N-1) {
    B.at(0).at(j+1) = A.at(0).at(j);
  }
  // 右
  rep(i,0,N-1) {
    B.at(i+1).at(N-1) = A.at(i).at(N-1);
  }
  // した
  rep(j,0,N-1) {
    B.at(N-1).at(N-2-j) = A.at(N-1).at(N-1-j);
  }

  rep(i,0,N) {
    cout << B.at(i) << endl;
  }
}
