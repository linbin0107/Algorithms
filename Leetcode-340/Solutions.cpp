
#include "../common.h"

class Solution {
public:
  int lengthOfLongestSubstringWithTwoDistinctChar(string s, int k) {
    int res = 0, left = 0;
    // <character, count>
    unordered_map<char, int> mapping;

    for (int i = 0; i < s.length(); ++i) {
      mapping[s[i]]++;

      while (mapping.size() > k) {
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

  cout << solu->lengthOfLongestSubstringWithTwoDistinctChar("", 2) << endl;
  cout << solu->lengthOfLongestSubstringWithTwoDistinctChar("eceba", 2) << endl;
  cout << solu->lengthOfLongestSubstringWithTwoDistinctChar("aaaaaaaaaaaaaaaa \
       aaaaaaaaaaaaaabcccccccccccccccccccccccccccccccccccccccccccccc", 2) << endl;

  return 0;
}
