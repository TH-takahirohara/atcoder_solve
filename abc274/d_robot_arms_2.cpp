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
  int N,x,y;
  cin >> N >> x >> y;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<int> tate, yoko;
  rep(i,1,N) {
    if (i % 2 == 1) tate.push_back(A.at(i));
    else yoko.push_back(A.at(i));
  }

  x -= A.at(0);

  vector<vector<bool>> vect(tate.size()+1, vector<bool>(20005));
  vector<vector<bool>> vecy(yoko.size()+1, vector<bool>(20005));

  vect.at(0).at(10000) = true;
  rep(i,0,tate.size()) {
    rep(j,0,20004) {
      if (vect.at(i).at(j)) {
        vect.at(i+1).at(j + tate.at(i)) = true;
        vect.at(i+1).at(j - tate.at(i)) = true;
      }
    }
  }

  vecy.at(0).at(10000) = true;
  rep(i,0,yoko.size()) {
    rep(j,0,20004) {
      if (vecy.at(i).at(j)) {
        vecy.at(i+1).at(j + yoko.at(i)) = true;
        vecy.at(i+1).at(j - yoko.at(i)) = true;
      }
    }
  }

  if (vect.at(tate.size()).at(10000+y) && vecy.at(yoko.size()).at(10000+x)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
