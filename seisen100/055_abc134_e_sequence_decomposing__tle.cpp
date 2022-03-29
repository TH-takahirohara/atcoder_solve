#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int INF = 1000010000;

int main() {
  int N;
  cin >> N;
  vector<int> vec = {};
  rep(i,0,N) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  
  vector<int> dp(N,INF);
  
  vector<int> nexts = {};
  int cnt = 0;
  while (true) {
    int sz = vec.size();
    rep(i,0,sz) {
      auto itr = lower_bound(dp.begin(), dp.end(), vec.at(i));
      int idx = itr - dp.begin();
      if (dp.at(idx) != INF) nexts.push_back(dp.at(idx));
      dp.at(idx) = vec.at(i);
    }
    
    cnt++;
    if (nexts.size() == 0) break;
    dp.assign(N,INF);
    vec = nexts;
    nexts = {};
  }
  
  cout << cnt << endl;
}
