#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  // vector<int> data;
  deque<int> data_d;
  
  for (int i=0; i<N; i++) {
    int now_num;
    cin >> now_num;
    data_d.push_back(now_num);
    
    int data_size = data_d.size();
    int count = 0;
    for (int j=data_size-1; j >= (data_size-now_num); j--) {
      if (j < 0) {
        break;
      }
      if (data_d.at(j) != now_num) {
        break;
      } else {
        count++;
      }
    }
    
    if (count == now_num) {
      for (int k=0; k < now_num; k++) {
        data_d.pop_back();
      }
    }
    
    cout << data_d.size() << endl;
  }
}
