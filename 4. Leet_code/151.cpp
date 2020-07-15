class Solution:
    def reverseWords(self, s: str) -> str:
        _list = s.split()
        _list.reverse()
        return  .join(_list)
