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
  int Q;
  cin >> Q;

  rep(i,0,Q) {
    int c;
    cin >> c;
    if (c == 1) {
      int k,x;
      cin >> k >> x;
      A.at(k-1) = x;
    } else {
      int k;
      cin >> k;
      cout << A.at(k-1) << endl;
    }
  }
}
