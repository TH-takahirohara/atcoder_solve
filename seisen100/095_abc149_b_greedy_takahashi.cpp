#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)


int main() {
  ll taka,aoki,K;
  cin >> taka >> aoki >> K;
  
  if (taka > K) {
    taka -= K;
  } else {
    aoki -= (K - taka);
    taka = 0;
  }
  
  if (aoki < 0) aoki = 0;
  
  cout << taka << " " << aoki;
}

