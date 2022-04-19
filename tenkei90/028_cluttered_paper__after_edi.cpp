#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  vector<vector<int>> S(1001, vector<int>(1001, 0));
  
  rep(i,0,N) {
    int lx,ly,rx,ry;
    cin >> lx >> ly >> rx >> ry;
    
    S.at(ly).at(lx) += 1;
    S.at(ly).at(rx) += -1;
    S.at(ry).at(lx) += -1;
    S.at(ry).at(rx) += 1;
  }
    
  rep(i,0,1001) {
    rep(j,1,1001) {
      S.at(i).at(j) += S.at(i).at(j-1);
    }
  }
  
  rep(j,0,1001) {
    rep(i,1,1001) {
      S.at(i).at(j) += S.at(i-1).at(j);
    }
  }
  
  map<int,int> M;
  rep(i,0,1001) {
    rep(j,0,1001) {
      if (S.at(i).at(j) == 0) continue;
      if (M.count(S.at(i).at(j))) {
        M.at(S.at(i).at(j)) += 1;
      } else {
        M[S.at(i).at(j)] = 1;
      }
    }
  }
  
  rep(i,1,N+1) {
    if (!M.count(i)) cout << 0 << endl;
    else cout << M.at(i) << endl;
  }
}
