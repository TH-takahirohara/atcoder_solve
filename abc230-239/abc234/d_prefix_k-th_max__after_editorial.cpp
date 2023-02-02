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
  int N,K;
  cin >> N >> K;
  
  queue<int> que;
  rep(i,0,N) {
    int tmp;
    cin >> tmp;
    que.push(tmp);
  }
  
  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i,0,K) {
    int fro = que.front();
    pq.push(fro);
    que.pop();
  }
  
  cout << pq.top() << endl;
  
  rep(i,0,N-K) {
    int p = que.front();
    que.pop();
    
    if (p > pq.top()) {
      pq.pop();
      pq.push(p);
      cout << pq.top() << endl;
    } else {
      cout << pq.top() << endl;
    }
  }
}

