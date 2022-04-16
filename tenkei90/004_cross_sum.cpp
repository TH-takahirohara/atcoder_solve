#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int H,W;
  cin >> H >> W;
  
  vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
  
  rep(i,0,H) {
    rep(j,0,W) {
      cin >> A.at(i).at(j);
    }
  }
  
  vector<int> tate(W), yoko(H);
  
  rep(j,0,W) {
    int sum = 0;
    rep(i,0,H) {
      sum += A.at(i).at(j);
    }
    tate.at(j) = sum;
  }
  
  rep(i,0,H) {
    int sum = 0;
    rep(j,0,W) {
      sum += A.at(i).at(j);
    }
    yoko.at(i) = sum;
  }
  
  rep(i,0,H) {
    rep(j,0,W) {
      if (j!=W-1) cout << yoko.at(i) + tate.at(j) - A.at(i).at(j) << " ";
      else cout << yoko.at(i) + tate.at(j) - A.at(i).at(j);
    }
    cout << endl;
  }
}
