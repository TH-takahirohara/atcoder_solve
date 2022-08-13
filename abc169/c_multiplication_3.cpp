#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll A;
  string B;
  cin >> A >> B;
  
  string b100 = "";
  rep(i,0,B.size()) {
    if (B.at(i) == '.') continue;
    b100 += B.at(i);
  }
  
  ll nb = stoll(b100);
    
  cout << (ll)(A * nb / 100) << endl;
}

