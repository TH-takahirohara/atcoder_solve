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
  int N;
  cin >> N;
  
  stack<pair<int,int>> st;
  int cnt = 0;
  
  rep(i,0,N) {
    int a;
    cin >> a;
    
    cnt++;
    if (st.empty() || st.top().first != a) {
      st.push(make_pair(a,1));
    } else {
      st.top().second += 1;
      if (st.top().second == st.top().first) {
        cnt -= st.top().second;
        st.pop();
      }
    }
    cout << cnt << endl;
  }
}

