class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)
        left = 0
        ones = 0
        best = ""
        
        for right in range(n):
            if s[right] == '1':
                ones += 1
            
            # Shrink window from left while it still has exactly k ones
            while ones > k or (ones == k and s[left] == '0'):
                if s[left] == '1':
                    ones -= 1
                left += 1
            
            if ones == k:
                candidate = s[left:right+1]
                if best == "" or len(candidate) < len(best) or \
                   (len(candidate) == len(best) and candidate < best):
                    best = candidate
        
        return best