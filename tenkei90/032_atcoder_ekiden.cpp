#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int INF = 1000000000;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N, 0));
  rep(i,0,N) rep(j,0,N) cin >> A.at(i).at(j);
  
  int M;
  cin >> M;
  // 仲が悪いかどうかの判定用配列
  vector<vector<bool>> warui(N, vector<bool>(N, false));
  rep(i,0,M) {
    int x,y;
    cin >> x >> y;
    x--;y--;
    warui.at(x).at(y) = true;
    warui.at(y).at(x) = true;
  }
  
  // next_permutation用配列の初期化
  vector<int> vec(N);
  rep(i,0,N) vec.at(i) = i;
  
  int ans = INF;
  do {
    int tmp = 0;
    rep(i,0,N) {
      if (i==N-1) {
        tmp += A.at(vec.at(i)).at(i);
        break;
      }
      
      if (warui.at(vec.at(i)).at(vec.at(i+1))) {
        tmp = INF;
        break;
      }
      tmp += A.at(vec.at(i)).at(i);
    }
    
    ans = min(ans, tmp);
  } while (next_permutation(vec.begin(), vec.end()));
  
  if (ans >= INF) cout << -1 << endl;
  else cout << ans << endl;
}
