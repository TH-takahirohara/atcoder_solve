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
  ll N, sum = 0;
  cin >> N;
  vector<ll> A(N);
  map<ll,ll> mp;
  rep(i,0,N) {
    cin >> A.at(i);
    sum += A.at(i);
    mp[A.at(i)]++;
  }
    
  int Q; cin >> Q;
  rep(i,0,Q) {
    ll b,c;
    cin >> b >> c;
    
    ll cntb = mp[b];
    sum = sum - cntb * b + cntb * c;
    cout << sum << endl;
    
    mp[b] -= cntb;
    mp[c] += cntb;
  }
}

