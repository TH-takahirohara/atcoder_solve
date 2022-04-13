#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll M;
  cin >> M;
  
  vector<ll> C(M), D(M);
  rep(i,0,M) cin >> D.at(i) >> C.at(i);
  
  ll num_keta = 0LL;
  rep(i,0,M) num_keta += C.at(i);
  
  ll sum_keta = 0LL;
  rep(i,0,M) sum_keta += C.at(i) * D.at(i);
  
  cout << num_keta - 1 + (sum_keta - 1) / 9 << endl;
}
