#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N;
  cin >> N;
  
  vector<ll> A(N);
  vector<ll> B(N);
  
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) cin >> B.at(i);
  
  ll cnt1 = 0LL;
  ll cnt2 = 0LL;
  
  rep(i,0,N) {
    if (A.at(i) == B.at(i)) cnt1++;
  }
  
  rep(i,0,N) {
    ll tmp_a = A.at(i);
    rep(j,0,N) {
      if (tmp_a == B.at(j) && i != j) cnt2++;
    }
  }
  
  cout << cnt1 << endl;
  cout << cnt2 << endl;
}
