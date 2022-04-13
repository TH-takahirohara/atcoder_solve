#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,M;
  cin >> N >> M;
  
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  int sai = A.at(0);
  rep(i,1,N) {
    sai = sai / __gcd(sai, A.at(i)) * A.at(i);
    if (sai > M*2) {
      cout << 0 << endl;
      return 0;
    }
  }
  
  int new_sai = sai / 2;
  
  rep(i,0,N) {
    if ((sai / A.at(i)) % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  
  cout << M/new_sai - M/(new_sai*2) << endl;
}
