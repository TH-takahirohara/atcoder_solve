#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N; cin >> N;
  int l = 1, r = N;
  rep(i,0,10) {
    int mid = (l+r)/2;
    cout << "? " << l << " " << mid << " " << 1 << " " << N << endl;
    int t; cin >> t;
    if (t == (mid-l+1)) l=mid+1;
    else r=mid;
  }

  int l2 = 1, r2 = N;
  rep(i,0,10) {
    int mid = (l2+r2)/2;
    cout << "? " << 1 << " " << N << " " << l2 << " " << mid << endl;
    int t; cin >> t;
    if (t==(mid-l2+1)) l2 = mid+1;
    else r2 = mid;
  }
  cout << "! " << l << " " << l2 << endl;
  return 0;
}
