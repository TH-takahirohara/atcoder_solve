#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  
  vector<vector<int>> vec(N, vector<int>(N));
  vec.at(0).at(0) = 1;
  // vec.at((N+1)/2).at((N+1)/2) = -1;
  // vector<vector<bool>> seen(N, vector<int>(N, false));

  int idx = 0;
  int x = 0;
  int y = 0;
  int cnt = 1;
  rep(i,0,N*N-2) {
    cnt++;
    if (x+dx.at(idx) >= N || y+dy.at(idx) >= N || x+dx.at(idx) < 0 || y+dy.at(idx) < 0) {
      idx = (idx+1) % 4;
    }
    int karix = x+dx.at(idx);
    int kariy = y+dy.at(idx);
    // cout << "karix,y: "<< karix << " " << kariy << endl;
    
    if (vec.at(karix).at(kariy) > 0) {
      idx = (idx+1) % 4;
    }

    karix = x+dx.at(idx);
    kariy = y+dy.at(idx);

    // cout << "karix,y: "<< karix << " " << kariy << endl;
    // cout << "cnt: " << cnt << endl;
    vec.at(karix).at(kariy) = cnt;
    x = karix;
    y = kariy;
    // cout << x << " " << y << endl;
  }

  rep(i,0,N) {
    rep(j,0,N) {
      if (i == (N)/2 && j == (N)/2) {
        cout << "T";
      } else {
        cout << vec.at(i).at(j);
      }
      cout << " ";
    }
    cout << endl;
  }
}
