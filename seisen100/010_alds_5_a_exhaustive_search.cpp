#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  
  int arr[N];
  int sum = 0;
  for (int i=0; i<N; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  
  int Q;
  cin >> Q;
  
  int q_arr[Q];
  for (int i=0; i<Q; i++) {
    cin >> q_arr[i];
  }
    
  for (int i=0; i<Q; i++) {
    int m = q_arr[i];
    
    // m_iが配列の合計値より大きい場合はnoを出力し、次のループに飛ぶ（これをしないとTLEになる）
    if (m > sum) {
      cout << "no" << endl;
      continue;
    }
    
    bool can = false;
    for (int j=0; j<(1 << N); j++) {
      int sum = 0;
      // 二進数の位が1の時に、対応する配列の要素を加算する
      for (int k=0; k<N; k++) {
        if (j & (1 << k)) {
          sum += arr[k];
        }
      }
      
      if (m == sum) {
        can = true;
        break;
      }
    }
    
    if (can) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
