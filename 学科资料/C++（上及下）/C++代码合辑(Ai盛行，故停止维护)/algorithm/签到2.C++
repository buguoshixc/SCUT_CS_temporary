#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    vector<pair<long long, long long>> intervals(t);
    
    // 读入所有区间
    for (int i = 0; i < t; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    // 按右端点排序
    sort(intervals.begin(), intervals.end(), 
        [](const pair<long long, long long>& a, const pair<long long, long long>& b) {
            return a.second < b.second;
        });
    
    // 贪心选择
    int count = 0;
    long long lastEnd = -1e18;
    
    for (const auto& interval : intervals) {
        if (interval.first >= lastEnd) {
            count++;
            lastEnd = interval.second;
        }
    }
    
    cout << count << endl;
    return 0;
}
