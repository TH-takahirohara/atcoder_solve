#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int INF = 1000000000;
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, 1, -1};

int main() {
  int N;
  int ax, ay, bx, by;
  cin >> N >> ax >> ay >> bx >> by;
  ax--;ay--;bx--;by--;
  
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);
  
  queue<pair<int,int>> que;
  
  vector<vector<bool>> seen(N, vector<bool>(N, false));
  vector<vector<int>> masu(N, vector<int>(N, INF));
  
  que.push(make_pair(ax,ay));
  masu.at(ax).at(ay) = 0;
  seen.at(ax).at(ay) = true;
  
  while (!que.empty()) {
    pair<int,int> p = que.front();
    que.pop();
    
    rep(i,0,4) {
      rep(j,1,N) {
        int x = p.first + dx.at(i) * j;
        int y = p.second + dy.at(i) * j;
        
        if (x < 0 || x >= N || y < 0 || y >= N) break;
        if (S.at(x).at(y) == '#') break;
        if (seen.at(x).at(y)) continue;
        if (!seen.at(x).at(y)) {
          seen.at(x).at(y) = true;
          masu.at(x).at(y) = min(masu.at(x).at(y), masu.at(p.first).at(p.second)+1);
          que.push(make_pair(x,y));
        }
      }
    }

    if (masu.at(bx).at(by) != INF) break;
  }
  
  if (masu.at(bx).at(by) >= INF/2) cout << -1 << endl;
  else cout << masu.at(bx).at(by) << endl;
}
