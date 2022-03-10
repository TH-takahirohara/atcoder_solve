#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int N, K;
vector<ll> arr;

int main() {
  cin >> N >> K;
  arr.assign(N, 0LL);
  
  rep(i, 0, N) {
    cin >> arr.at(i);
  }
  
  ll ans = 100000000000;
  rep(i, 0, (1 << N)) {
    // bit全探索した上で、1の数がKと同じ場合だけを対象にする
    if (__builtin_popcount(i) != K) continue;
    
    ll tmp_cost = 0LL;
    ll tmp_hei = 0LL;
    rep(j, 0, N) {
      // 一つ前の建物の高さとtmp_heiを比較し、高い方をtmp_heiとする
      if (j != 0) tmp_hei = max(tmp_hei, arr.at(j-1));
      if (i & (1 << j)) {
        if (tmp_hei == 0LL) {
          // 初回だったら、単にtmp_heiにjの位置の建物高さを代入する
          tmp_hei = arr.at(j);
        } else {
          // 2件目以降の建物の場合
          if (arr.at(j) > tmp_hei) {
            // 一つ前の建物より高い場合は何もしない
            continue;
          } else {
            // 一つ前の建物より低い場合、一つ前より高くなるようにコストをかけた上で、tmp_heiを更新する
            tmp_cost += tmp_hei - arr.at(j) + 1;
            tmp_hei++;
          }
        }
      }
    }
    
    ans = min(ans, tmp_cost);
  }
  
  cout << ans << endl;
}
