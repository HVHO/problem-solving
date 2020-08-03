// 125. Valid Palindrome
import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        newstr = re.sub(r'[^A-Za-z0-9]', "", s)
        newstr = newstr.lower()
        return newstr == newstr[::-1]
        