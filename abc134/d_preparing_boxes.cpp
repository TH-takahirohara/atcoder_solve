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
  vector<int> A(N+1);
  rep(i,1,N+1) cin >> A.at(i);

  bool can = true;
  vector<int> bai(N+1);
  vector<bool> ans(N+1);
  for (int i=N; i>=1; i--) {
    if (bai.at(i) % 2 == A.at(i)) continue;
    ans.at(i) = true;
    for (int w=1; w*w<=i; w++) {
      if (i % w != 0) continue; // 割り切れない場合は次へ
      if (w * w == i) {
        bai.at(w) += 1;
      } else {
        bai.at(w) += 1;
        bai.at(i/w) += 1;
      }
    }
  }
  int num = 0;
  rep(i,1,N+1) if (ans.at(i)) num++;
  cout << num << endl;
  rep(i,1,N+1) if (ans.at(i)) cout << i << " ";
  cout << endl;
}
