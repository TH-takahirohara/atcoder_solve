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
  int Q;
  cin >> Q;
  
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  
  ll add = 0LL;
  rep(i,0,Q) {
    int c;
    cin >> c;
    
    if (c==1) {
      ll x;
      cin >> x;
      
      x -= add;
      pq.push(x);
    } else if (c==2) {
      ll x;
      cin >> x;
      add += x;
    } else {
      cout << pq.top() + add << endl;
      pq.pop();
    }
  }
}


