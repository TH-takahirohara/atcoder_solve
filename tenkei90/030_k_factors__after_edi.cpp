#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,K;
  cin >> N >> K;
  
  vector<int> vec(10000010, 0);
  
  rep(i,2,10000010) {
    if (vec.at(i) != 0) continue;
    for (int j=i; j<10000010; j+=i) vec.at(j) += 1;
  }
  
  int ans = 0;
  rep(i,2,N+1) {
    if (vec.at(i) >= K) ans++;
  }
  cout << ans << endl;
}
