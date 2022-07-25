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
  int N, Q;
  cin >> N >> Q;
  
  vector<int> mae(N,-1), usiro(N,-1);
  
  rep(i,0,Q) {
    int c;
    cin >> c;
    
    if (c == 1) {
      int x,y;
      cin >> x >> y;
      x--; y--;
      usiro.at(x) = y;
      mae.at(y) = x;
    } else if (c == 2) {
      int x,y;
      cin >> x >> y;
      x--; y--;
      usiro.at(x) = -1;
      mae.at(y) = -1;
    } else {
      int x;
      cin >> x;
      x--;
      int now = x;
      while (true) {
        if (mae.at(now) != -1) {
          now = mae.at(now);
        } else {
          break;
        }
      }
      
      vector<int> vec;
      vec.push_back(now);
      while (true) {
        if (usiro.at(now) != -1) {
          vec.push_back(usiro.at(now));
          now = usiro.at(now);
        } else {
          break;
        }
      }
      
      cout << vec.size() << " ";
      rep(i,0,vec.size()) {
        if (i != vec.size() - 1) cout << vec.at(i)+1 << " ";
        else cout << vec.at(i)+1 << endl;
      }
    }
  }
}

