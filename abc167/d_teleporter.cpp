#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,0,N) {
    ll tmp;
    cin >> tmp;
    tmp--;
    A.at(i) = tmp;
  }
  
  vector<ll> nums(N, -1);
  nums.at(0) = 0;
  
  ll nowp = 0;
  ll nxp = -1;
  ll cnt = 0;
  ll loop_len = -1;
  ll loop_sta_cnt = -1;
  ll loop_sta_ind = -1;
  rep(i,0,N) {
    nxp = A.at(nowp);
    if (nums.at(nxp) >= 0) {
      loop_sta_cnt = nums.at(nxp);
      loop_sta_ind = nxp;
      loop_len = nums.at(nowp) - nums.at(nxp) + 1;
      break;
    }
    cnt++;
    nums.at(nxp) = cnt;
    nowp = nxp;
  }
  
  if (K < loop_sta_cnt) {
    ll np = 0;
    ll nx = 01;
    rep(i,0,K) {
      nx = A.at(np);
      np = nx;
    }
    cout << np+1 << endl;
    return 0;
  } else {
    ll ban = (K-loop_sta_cnt) % loop_len;
    ll np = loop_sta_ind;
    ll nx = 0;
    rep(i,0,ban) {
      nx = A.at(np);
      np = nx;
    }
    cout << np+1 << endl;
    return 0;
  }
}
