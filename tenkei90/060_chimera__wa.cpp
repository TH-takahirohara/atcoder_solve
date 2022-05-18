// 060 両側から考える/最長増加部分列
// 両側から考えるということと最長増加部分列に着目したところは良かったが、ほとんどWAだった。
// 最長増加部分列を考えるアルゴリズムでは、部分列自体を作れない？っぽい
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int INF = 1000000000;

int main() {
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  vector<int> rev_A = A;
  reverse(rev_A.begin(), rev_A.end());
  
  vector<int> dp(N, INF);
  vector<int> ids(N, INF);
  
  int maxval = 0;
  int maxidx = 0;
  rep(i,0,N) {
    int idx = lower_bound(dp.begin(), dp.end(), A.at(i)) - dp.begin();
    //cout << idx << " " << A.at(i) << endl;
    
    if (dp.at(idx) > A.at(i)) ids.at(idx) = i;
    dp.at(idx) = A.at(i);
  }
  
  vector<int> dp_rev(N, INF), ids_rev(N, INF);
  
  rep(i,0,N) {
    int idx = lower_bound(dp_rev.begin(), dp_rev.end(), rev_A.at(i)) - dp_rev.begin();
    if (dp_rev.at(idx) > rev_A.at(i)) ids_rev.at(idx) = i;
    dp_rev.at(idx) = rev_A.at(i);
  }
  
  int ans = 0;
  rep(i,0,N) {
    if (dp.at(i) >= INF) break;
    int idx = ids.at(i);
    int val = dp.at(i);
    
    int nokori = N - idx - 1;
    int idx_back = lower_bound(ids_rev.begin(), ids_rev.end(), nokori) - ids_rev.begin();
    int cnt_max = lower_bound(dp_rev.begin(), dp_rev.begin()+idx_back, val) - dp_rev.begin();
    
    ans = max(ans, i + 1 + cnt_max);
  }
  cout << ans << endl;
}

