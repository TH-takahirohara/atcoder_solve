#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  double Kd = (1+sqrt(1+8*N))/2;
  if (floor(Kd) != Kd) {
    cout << "No" << endl;
    return 0;
  }
  
  int K = (int)Kd;
  int X = K - 1;
  
  cout << "Yes" << endl;
  cout << K << endl;
  
  int ite = 1;
  vector<vector<int>> vec(K);
  rep(i,0,K-1) {
    rep(j,0,X-i) {
      vec.at(i).push_back(ite+j);
    }
    rep(l,i+1,K) {
      vec.at(l).push_back(ite + (l-i-1));
    }
    ite += (X-i);
  }
  
  rep(i,0,K) {
    cout << X << " ";
    rep(j,0,X) {
      if (j!=X-1) cout << vec.at(i).at(j) << " ";
      else cout << vec.at(i).at(j);
    }
    cout << endl;
  }
}
