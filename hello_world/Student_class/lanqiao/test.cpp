#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // 统计 ? 的数量
    int cnt_q = 0, cnt_l = 0, cnt_ques = 0;
    for (char c : s) {
        if (c == 'Q') cnt_q++;
        else if (c == 'L') cnt_l++;
        else cnt_ques++;
    }

    // 贪心：将所有 ? 替换为 L，最大化 L 的数量
    // 这样每个 L 后面所有的 Q 都能形成一对
    // 计算每个位置为 L，后面 Q 的数量 
    int total_q = 0;
    for (char c : s) if (c == 'Q') total_q++;
    int max_lq = 0, cur_q = total_q;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L' || s[i] == '?') {
            max_lq += cur_q;
        }
        if (s[i] == 'Q') cur_q--;
    }
    cout << max_lq << endl;
    return 0;
}