#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,K,R,S,P;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  
  vector<bool> canwin(N, true);
  
  ll ans = 0;
  rep(i,0,N) {
    if (!canwin.at(i)) continue;
    if (i+K < N && T.at(i) == T.at(i+K)) canwin.at(i+K) = false;
    if (T.at(i) == 'r') ans += P;
    else if (T.at(i) == 's') ans += R;
    else ans += S;
  }
  cout << ans << endl;
}

