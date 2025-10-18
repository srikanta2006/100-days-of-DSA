#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& l, int value, int n, int m) {
    int painter = 1;
    int length = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] > value) return false;
        if (length + l[i] <= value) {
            length += l[i];
        } else {
            painter++;
            length = l[i];
        }
    }
    return painter <= m;
}

int sum(vector<int>& l) {
    int total = 0;
    for (int ele : l) total += ele;
    return total;
}

int minTimeToPaint(vector<int>& l, int n, int m) {
    int start = 0;
    int end = sum(l);
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isValid(l, mid, n, m)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> lengths = {40, 30, 10, 20};
    int n = 4;
    int m = 2;
    cout << "The minimum time required to paint all the boards is: "
         << minTimeToPaint(lengths, n, m) << endl;
    return 0;
}
