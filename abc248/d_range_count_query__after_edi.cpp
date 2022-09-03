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
  map<int,vector<int>> mp;
  rep(i,0,N) {
    int tmp; cin >> tmp;
    mp[tmp].push_back(i);
  }

  int Q; cin >> Q;
  rep(i,0,Q) {
    int l,r,x;
    cin >> l >> r >> x;
    l--;r--;
    // r以下の個数 - lより小さい個数
    int rika = (upper_bound(mp[x].begin(), mp[x].end(), r) - mp[x].begin());
    int lika = (lower_bound(mp[x].begin(), mp[x].end(), l) - mp[x].begin());
    cout << rika - lika << endl;
  }
}
