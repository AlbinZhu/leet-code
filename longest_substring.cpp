/*
 * @author:      Swing
 * @create:      2019-12-22 16:32
 * @description: Given a string, find the length of the longest substring without repeating characters.
 */


#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {

    int ans = 0;
    int n = s.length();

    unordered_map<char, int> map;

    for (int i = 0, j = 0; j < n; j++) {

        cout << s[j] << endl;

        if (map.find(s[j]) != map.end()) {
            i = max(i, map[s[j]]);
        }

        map[s[j]] = j + 1;
        ans = max(ans, j - i + 1);
    }

    cout << ans << endl;

    return ans;

}