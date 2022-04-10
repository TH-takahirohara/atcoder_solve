#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

double INF = 1100000000;
typedef pair<pair<int,int>, double> Circle;

int main() {
  int N,M;
  cin >> N >> M;
  vector<Circle> vec;
  
  double ans = INF;
  rep(i,0,N) {
    int x,y;
    double r;
    cin >> x >> y >> r;
    ans = min(ans, r);
    vec.push_back(make_pair(make_pair(x,y), r));
  }
  
  rep(i,0,M) {
    int x,y;
    cin >> x >> y;
    vec.push_back(make_pair(make_pair(x,y), 0.0));
  }
  
  rep(i,N,N+M) {
    double tmp_r = INF;
    int nx = vec.at(i).first.first;
    int ny = vec.at(i).first.second;
    
    rep(j,0,N) {
      double tr = sqrt((nx-vec.at(j).first.first)*(nx-vec.at(j).first.first) + (ny-vec.at(j).first.second)*(ny-vec.at(j).first.second)) - vec.at(j).second;
      vec.at(i).second = tr;
      tmp_r = min(tmp_r, tr);
    }
    
    rep(j,N,N+M) {
      if (i==j) continue;
      
      int nxx = vec.at(j).first.first;
      int nxy = vec.at(j).first.second;
      double nxr = vec.at(j).second;
      double dis = sqrt((nx-nxx)*(nx-nxx) + (ny-nxy)*(ny-nxy));
      if (nxr == 0.0) {
        tmp_r = min(tmp_r, dis / 2);
      } else if (nxr > dis / 2) {
        if (tmp_r > dis / 2) {
          vec.at(j).second = dis/2;
          tmp_r = dis / 2;
        } else {
          tmp_r = min(tmp_r, dis-nxr);
        }
      } else {
        tmp_r = min(tmp_r, dis-nxr);
      }
    }
    
    vec.at(i).second = tmp_r;
    ans = min(ans, tmp_r);
  }
  
  cout << fixed << setprecision(7) << ans;
}
