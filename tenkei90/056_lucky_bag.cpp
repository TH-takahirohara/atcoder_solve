// dpの要素をpair<int,string>みたいにしてsecond要素にその時点までの購入計画文字列を格納しようとすると、
// MLE(メモリ制限超過)になってしまうので、dpのsecond要素には { 1つ前の時点での金額, 1つ前の福袋の種類の文字列 } を格納し、
// 最後から辿るようにしていくといける。
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

int main() {
  int N,S;
  cin>>N>>S;
  
  vector<int> A(N), B(N);
  rep(i,0,N) cin >> A.at(i) >> B.at(i);
  
  vector<vector<pair<bool,pair<int,string>>>> dp(N+1, vector<pair<bool,pair<int,string>>>(S+1, make_pair(false,make_pair(-1,""))));
  dp.at(0).at(0) = make_pair(true,make_pair(0,""));
  
  rep(i,0,N) {
    rep(j,0,S+1) {
      if (!dp.at(i).at(j).first) continue;
      if (j+A.at(i) <= S) dp.at(i+1).at(j+A.at(i)) = make_pair(true, make_pair(j,"A"));
      if (j+B.at(i) <= S) dp.at(i+1).at(j+B.at(i)) = make_pair(true, make_pair(j,"B"));
    }
  }
  
  if (!dp.at(N).at(S).first) {
    cout << "Impossible" << endl;
  } else {
    vector<string> vec;
    int ind = dp.at(N).at(S).second.first;
    vec.push_back(dp.at(N).at(S).second.second);
    for (int i=N-1; i>=0; i--) {
      string bef_str = dp.at(i).at(ind).second.second;
      vec.push_back(bef_str);
      ind = dp.at(i).at(ind).second.first;
    }
    
    for (int i=N; i>=0; i--) {
      cout << vec.at(i);
    }
  }
}

