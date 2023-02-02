#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;

int main() {
  ll A,B,K;
  cin >> A >> B >> K;
  
  
  if (A>=B) {
    cout << 0 << endl;
    return 0;
  }
  
  ll ans = 1;
  
  while (true) {
    A = A*K;
    if (A>=B) break;
    ans++;
  }
  
  cout << ans << endl;
}
