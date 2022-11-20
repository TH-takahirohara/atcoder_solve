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
  sort(A.begin(), A.end());

  int Q;
  cin >> Q;
  rep(i,0,Q) {
    int X;
    cin >> X;

    int ng = -1;
    int ok = N;
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      if (A.at(mid) >= X) ok = mid;
      else ng = mid;
    }
    cout << ok << endl;
  }
}
