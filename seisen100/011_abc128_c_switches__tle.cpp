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
    vector<int> bit(10000000);
    for (int j=0; j<N; j++) {
      int Div = (1 << j);
      bit.at(j) = (i / Div) % 2;
    }
        
    for (int k=0; k<N; k++) {
      if (bit.at(k) == 1) {
        // lはs_arrのl番目の要素（s_arrの要素は、各電球の対応スイッチ群）
        for (int l=0; l<M; l++) {
          vector<int> tmp_arr = s_arr.at(l);
          if (binary_search(tmp_arr.begin(), tmp_arr.end(), k+1)) s_sum.at(l)++;
        }
      }
    }
    
    bool can_right = true;
    for (int m=0; m<M; m++) {
      if (s_sum.at(m) % 2 != p_arr.at(m)) can_right = false;
    }
    
    if (can_right) cnt++;
  }
  
  cout << cnt << endl;
}
