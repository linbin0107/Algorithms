
#include "../common.h"

class Solution {
public:
  int lengthOfLongestSubstringWithTwoDistinctChar(string s) {
    int res = 0, left = 0;
    unordered_map<char, int> mapping;

    for (int i = 0; i < s.length(); ++i) {
      mapping[s[i]]++;

      while (mapping.size() > 2) {
        mapping[s[left]]--;
        if (mapping[s[left]] == 0) {
          mapping.erase(s[left]);
        }

        ++left;
      }

      res = max(res, i - left + 1);
    }

    return res;
  }
};


int main() {
  Solution *solu = new Solution();

  cout << solu->lengthOfLongestSubstringWithTwoDistinctChar("") << endl;
  cout << solu->lengthOfLongestSubstringWithTwoDistinctChar("eceba") << endl;
  cout << solu->lengthOfLongestSubstringWithTwoDistinctChar("aaaaaaaaaaaaaaaa \
       aaaaaaaaaaaaaabcccccccccccccccccccccccccccccccccccccccccccccc") << endl;

  return 0;
}
