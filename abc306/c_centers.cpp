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
  vector<int> A(3*N);
  rep(i,0,3*N) cin >> A.at(i);

  vector<int> cnt(N+1);
  vector<int> soeji(3*N, -1);
  rep(i,0,3*N) {
    cnt.at(A.at(i))++;
    if (cnt.at(A.at(i)) == 2) soeji.at(i) = A.at(i);
  }

  rep(i,0,3*N) {
    if (soeji.at(i) >= 0) cout << soeji.at(i) << " ";
  }
  cout << endl;
}
