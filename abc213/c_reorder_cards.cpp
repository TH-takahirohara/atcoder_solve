#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int H,W,N;
  cin >> H >> W >> N;
  
  vector<int> A(N), B(N);
  rep(i,0,N) cin >> A.at(i) >> B.at(i);
  
  vector<int> AS = A, BS = B;
  sort(AS.begin(), AS.end());
  sort(BS.begin(), BS.end());
  
  AS.erase(unique(AS.begin(), AS.end()), AS.end());
  BS.erase(unique(BS.begin(), BS.end()), BS.end());
  
  rep(i,0,N) {
    int r = A.at(i);
    int c = B.at(i);
    
    int ro = lower_bound(AS.begin(), AS.end(), r) - AS.begin();
    int co = lower_bound(BS.begin(), BS.end(), c) - BS.begin();
    cout << ro+1 << " " << co+1 << endl;
  }
}

