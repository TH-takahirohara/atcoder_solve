#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> k_arr(M, 0);
  vector<vector<int>> s_arr(M, vector<int>(10, 0));
  
  // 入力
  for (int i=0; i<M; i++) {
    int tmpk;
    cin >> tmpk;
    k_arr.at(0) = tmpk;
    for (int j=0; j<tmpk; j++) {
      cin >> s_arr.at(i).at(j);
    }
    sort(s_arr.at(i).begin(), s_arr.at(i).end());
  }
  
  vector<int> p_arr(M);
  for (int i=0; i<M; i++) {
    cin >> p_arr.at(i);
  }
  // 入力終わり
  
  int cnt = 0;
  for (int i=0; i<(1<<N); i++) {
    vector<int> s_sum(M, 0);
    
    // bitを配列に入れる
    //vector<int> bit(10000000);
    //for (int j=0; j<N; j++) {
    //  int Div = (1 << j);
    //  bit.at(j) = (i / Div) % 2;
    //}
    
    // 上記のbitを配列に入れる箇所に非常に時間がかかっていた
    
    for (int l=0; l<M; l++) {
      int cnt = 0;
      for (auto s : s_arr.at(l)) {
        if (i & (1 << s)) cnt++;
      }
      s_sum.at(l) = cnt;
    }
    
    bool can_right = true;
    for (int m=0; m<M; m++) {
      if (s_sum.at(m) % 2 != p_arr.at(m)) can_right = false;
    }
    
    if (can_right) cnt++;
  }
  
  cout << cnt << endl;
}
