// 520. Detect Capital
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.islower():
            return True;
        if word.isupper():
            return True;
        return word[:1].isupper() and word[1:].islower();
        