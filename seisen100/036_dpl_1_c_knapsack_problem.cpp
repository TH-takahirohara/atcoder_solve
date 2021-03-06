#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int N, W;

int main() {
  cin >> N >> W;
  
  vector<int> value1(N);
  vector<int> weight1(N);
  
  rep(i,0,N) cin >> value1.at(i) >> weight1.at(i);

  // 重さが重複する場合、最も価値が高い品物のみを含むような配列に置き換える。
  // （重さが1で価値が異なるような品物が大量にある場合、今回のアルゴリズムではTLEになる。）
  map<int, int> nimotu;
  rep(i,0,N) {
    if (!nimotu.count(weight1.at(i))) {
      nimotu[weight1.at(i)] = value1.at(i);
    } else {
      if (nimotu.at(weight1.at(i)) < value1.at(i)) nimotu.at(weight1.at(i)) = value1.at(i);
    }
  }
  
  vector<int> weight;
  vector<int> value;
    
  for (map<int,int>::iterator i = nimotu.begin(); i != nimotu.end() ; ++i) {
    int key = i->first;
    int val = i->second;
    weight.push_back(key);
    value.push_back(val);
  }
    
  vector<vector<int> > dp(N+1, vector<int>(W+1, 0));
  
  rep(i,0,value.size()) {
    rep(j,0,W+1) {
      rep(k,0,20000) {
        if (j-k*weight.at(i) < 0) break;
        int tmp = max(dp.at(i).at(j-k*weight.at(i)) + k*value.at(i), dp.at(i).at(j));
        dp.at(i+1).at(j) = max(dp.at(i+1).at(j), tmp);
      }
    }
  }
  
  cout << dp.at(value.size()).at(W) << endl;
}
