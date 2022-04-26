#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll gojou(ll x) {
  return x*x*x*x*x;
}

int main() {
  ll X;
  cin >> X;
  
  for (ll i=0; i<1001; i++) {
    for (ll j=i; ; j--) {
      if ((gojou(i) - gojou(j)) == X) {
        cout << i << " " << j << endl;
        return 0;
      }
      if ((gojou(i) - gojou(j)) > X) break;
    }
  }
}

