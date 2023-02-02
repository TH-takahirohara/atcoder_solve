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
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i,0,N) cin >> vec.at(i);

  map<int,int> mp;
  rep(i,0,N) {
    mp[((i - vec.at(i)) + N) % N]++;
  }
  int ans = 0;
  for (int ite=0; ite < N; ite++) {
    int tmp = 0;
    tmp += mp[((ite-1) + N) % N];
    tmp += mp[ite];
    tmp += mp[(ite+1) % N];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
