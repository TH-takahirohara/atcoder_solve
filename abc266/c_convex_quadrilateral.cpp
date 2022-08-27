#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

double PI = 3.14159265359;

int main() {
  vector<pair<int,int>> vec(4);
  rep(i,0,4) {
    int x,y;
    cin >> x >> y;
    vec.at(i) = make_pair(x,y);
  }

  // string ans = "Yes";
  double kaku = 0.0;
  rep(i,0,4) {
    int nx = (i+1) % 4;
    int bx;
    if (i==0) bx = 3;
    else bx = i-1;
    pair<int,int> vecab = make_pair(vec.at(nx).first - vec.at(i).first, vec.at(nx).second - vec.at(i).second);
    pair<int,int> vecad = make_pair(vec.at(bx).first - vec.at(i).first, vec.at(bx).second - vec.at(i).second);
    double co = (double)(vecab.first * vecad.first + vecab.second * vecad.second) / (sqrt(vecab.first * vecab.first + vecab.second * vecab.second)*sqrt(vecad.first * vecad.first + vecad.second * vecad.second));
    kaku += acos(co) * 180 / PI;
    //if (acos(co) * 180 / PI >= 180) ans = "No";
  }
  if (kaku >= 359.9999) cout << "Yes" << endl;
  else cout << "No";
}
