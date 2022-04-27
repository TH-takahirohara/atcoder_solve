#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N;
  cin >> N;
  
  ll ans = 0;
  rep(i,1,100000000) {
    if (i > N) break;
    double a = (double)N/(double)i - (double)i/2.0 + 0.5;
    
    if (floor(a) == a && a > 0) {
      ans++;
    }
  }
  cout << ans*2 << endl;
}

