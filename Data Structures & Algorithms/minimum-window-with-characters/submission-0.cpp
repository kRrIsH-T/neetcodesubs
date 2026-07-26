class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }

        int requiredChars = tCount.size();
        int formedChars = 0;

        int windowStart = 0;
        int minLen = INT_MAX;
        string minWindow;

        unordered_map<char, int> windowCounts;

        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            char rightChar = s[windowEnd];
            windowCounts[rightChar]++;

            if (tCount.find(rightChar) != tCount.end() && 
                windowCounts[rightChar] == tCount[rightChar]) {
                formedChars++;
            }

            while (windowStart <= windowEnd && 
                   formedChars == requiredChars) {
                if (windowEnd - windowStart + 1 < minLen) {
                    minLen = windowEnd - windowStart + 1;
                    minWindow = s.substr(windowStart, minLen);
                }

                char leftChar = s[windowStart];
                windowCounts[leftChar]--;

                if (tCount.find(leftChar) != tCount.end() && 
                    windowCounts[leftChar] < tCount[leftChar]) {
                    formedChars--;
                }

                windowStart++;
            }
        }

        return minWindow;
    }
};
