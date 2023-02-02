// 最初は末尾から計算していたが、係数に0が出てくるケースに対応できずREを出した。コンテスト中には解けず。
// コンテスト後、twitterを見て、次数の大きい方から計算すると良いことが分かり、それで対応することでACとなった。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N,M;
  cin >> N >> M;
  
  vector<ll> A(N+1), C(N+M+1);
  rep(i,0,N+1) cin >> A.at(i);
  rep(i,0,N+M+1) cin >> C.at(i);
  
  vector<ll> B(M+1,0);
  
  for (ll i=M; i>=0; i--) {
    B.at(i) = C.at(i+N) / A.at(N);
    
    for (ll j=N+i; j>=i; j--) {
      C.at(j) = C.at(j) - A.at(j-i)*B.at(i);
    }    
  }
  
  rep(i,0,M+1) {
    if (i != M) cout << B.at(i) << " ";
    else cout << B.at(i) << endl;
  }
}
