#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  priority_queue<int> pq;
  for (int i=0; i<N; i++) {
    int tmp;
    cin >> tmp;
    pq.push(tmp);
  }
  
  for (int i=0; i<M; i++) {
    int max_val;
    max_val = pq.top();
    pq.pop();
    max_val /= 2;
    pq.push(max_val);
  }
  
  int64_t sum = 0;
  while (!pq.empty()) {
    sum += pq.top();
    pq.pop();
  }
  
  cout << sum << endl;
}
