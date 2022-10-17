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
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  int D; cin >> D;
  vector<int> L(D), R(D);
  rep(i,0,D) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    L.at(i) = l;
    R.at(i) = r;
  }

  vector<int> max_front(N), max_back(N);
  int tmp_mf = -1, tmp_mb = -1;
  rep(i,0,N) {
    if (tmp_mf < A.at(i)) {
      max_front.at(i) = max(tmp_mf, A.at(i));
      tmp_mf = A.at(i);
    } else {
      max_front.at(i) = tmp_mf;
    }
  }
  rep(i,0,N) {
    if (tmp_mb < A.at(N-i-1)) {
      max_back.at(N-i-1) = max(tmp_mb, A.at(N-i-1));
      tmp_mb = A.at(N-i-1);
    } else {
      max_back.at(N-i-1) = tmp_mb;
    }
  }

  rep(i,0,D) {
    int ans = max(max_front.at(L.at(i)-1), max_back.at(R.at(i)+1));
    cout << ans << endl;
  }
}
