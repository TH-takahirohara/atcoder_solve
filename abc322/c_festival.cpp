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
  vector<int> A(M);
  rep(i,0,M) cin >> A.at(i);

  rep(i,1,N+1) {
    int hiniti = *lower_bound(A.begin(), A.end(), i);
    cout << hiniti - i << endl;
  }
}
