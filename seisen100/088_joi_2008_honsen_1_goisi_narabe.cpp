#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  // 0: 白, 1: 黒
  // pair 碁石の種類, 個数
  stack<pair<int,int>> sta;
  
  rep(i,1,N+1) {
    int c;
    cin >> c;
    
    if (i==1) {
      sta.push(make_pair(c, 1));
      continue;
    }
    
    if (i%2==1) {
      if (sta.top().first == c) {
        sta.top().second += 1;
      } else {
        sta.push(make_pair(c,1));
      }
    } else {
      if (sta.top().first == c) {
        sta.top().second += 1;
      } else {
        pair<int,int> prev1 = sta.top();
        sta.pop();
        if (!sta.empty()) {
          sta.top().second += (prev1.second + 1);
        } else {
          sta.push(make_pair(c, prev1.second + 1));
        }
      }
    }
  }
  
  int ans = 0;
  while (!sta.empty()) {
    pair<int,int> prev = sta.top();
    sta.pop();
    if (prev.first == 0) ans += prev.second;
  }
  
  cout << ans << endl;
}
