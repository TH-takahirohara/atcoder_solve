#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll MOD = 998244353LL;

ull calc_sum(ull num) {
  if (num % 2 == 0) {
    return ((num / 2) % MOD) * ((num+1) % MOD);
  } else {
    return (((num+1) / 2) % MOD) * (num % MOD);
  }
}

int main() {
  ull N;
  cin>>N;
  
  string S = to_string(N);
  int siz = S.size()-1;
  
  ull sum = 0;
  rep(i,0,siz) {
    ull kake = 9;
    rep(j,0,i) {
      kake *= 10;
    }
    
    sum += calc_sum(kake);
    sum %= MOD;
  }
  
  ull minus = 1;
  ull tmpN = N;
  while (tmpN > 0) {
    tmpN /= 10;
    if (tmpN == 0) break;
    minus *= 10;
  }
  minus -= 1;
  
  sum += calc_sum(N - minus);
  sum %= MOD;
  cout << sum << endl;
}

