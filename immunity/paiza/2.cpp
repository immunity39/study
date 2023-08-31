#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> matrix(H);
  for (int i = 0; i < H; i++) {
    cin >> matrix[i];
  }

  vector<int> heights(W, 0);  // 各列の高さを保持する配列
  int maxArea = 0;

  for (int i = 0; i < H; i++) {
    // 各列の高さを更新
    for (int j = 0; j < W; j++) {
      if (matrix[i][j] == '#') {
        heights[j] = 0;  // '#'がある場合は高さを0にリセット
      } else {
        heights[j]++;  // '#'がない場合は高さを加算
      }
    }

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cout << matrix[i][j] << ' ' << heights[j] << '\n';
      }
      cout << '\n';
    }

    // スタックを使って最大長方形の面積を計算
    stack<int> st;
    for (int j = 0; j <= W; j++) {
      while (!st.empty() && (j == W || heights[st.top()] >= heights[j])) {
        int heightIndex = st.top();
        st.pop();

        int widthIndex = st.empty() ? -1 : st.top();
        int area = (j - widthIndex - 1) * heights[heightIndex];
        maxArea = max(maxArea, area);
      }
      st.push(j);
    }
  }

  cout << maxArea << "\n";
  return 0;
}