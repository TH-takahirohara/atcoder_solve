#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll mod = 1000000007LL;

void kake(ll &a, ll b) {
  a = a*b;
  a %= mod;
}

int main() {
  int N;
  cin >> N;
  
  vector<ll> d_now(6, 1);
  for (int j=0; j<6; j++) {
    cin >> d_now.at(j);
  }
  
  for (int i=1; i<N; i++) {
    vector<ll> d_tmp(6);
    for (int j=0; j<6; j++) {
      cin >> d_tmp.at(j);
    }
    
    // d_nowの総和計算
    ll sum = 0LL;
    for (int j=0; j<6; j++) {
      sum += d_now.at(j);
      sum %= mod;
    }
    
    for (int j=0; j<6; j++) {
      d_now.at(j) = sum * d_tmp.at(j) % mod;
    }
  }
  
  ll output = 0LL;
  for (int i=0; i<6; i++) {
    output += d_now.at(i);
    output %= mod;
  }
  cout << output << endl;
}

