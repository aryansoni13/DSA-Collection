#include <iostream>
#include <vector>
using namespace std;

int checkPalindrome(vector<int>& num) {
    int n = num.size();
    for (int i = 0; i < n / 2; ++i) {
        if (num[i] != num[n - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

vector<int> nextPalindrome(vector<int>& num) {
    int n = num.size();

    // Increase the number by 1 and check for palindrome
    while (!checkPalindrome(num)) {
        
        // Add 1 to the number
        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            num[i] += carry;
            if (num[i] == 10) {
                num[i] = 0;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }

        // If there's still a carry, insert 1 at the beginning
        if (carry == 1) {
            num.insert(num.begin(), 1);
            n++;
        }
    }

    return num;
}

int main() {
    vector<int> num = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
    
    vector<int> res = nextPalindrome(num);
    
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
