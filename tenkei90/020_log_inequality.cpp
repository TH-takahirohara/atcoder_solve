#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  
  ll right = 1;
  rep(i,0,b) {
    right *= c;
  }
  
  if (a < right) cout << "Yes" << endl;
  else cout << "No" << endl;
}
