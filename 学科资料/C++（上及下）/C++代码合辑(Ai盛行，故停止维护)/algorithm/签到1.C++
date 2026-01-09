#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        int count = 0;
        while (x != y) {
            if (x < y) {
                x++;
                count++;
            } else {
                y += 2;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
