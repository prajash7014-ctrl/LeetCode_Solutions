from collections import Counter

class Solution(object):
    def lexPalindromicPermutation(self, s, target):
        """
        :type s: str
        :type target: str
        :rtype: str
        """
        n = len(s)
        cnt = Counter(s)
        odd_chars = [c for c in cnt if cnt[c] % 2 == 1]

        # A palindrome permutation must have exactly n%2 odd-count characters
        if len(odd_chars) != (n % 2):
            return ""

        middle_char = odd_chars[0] if n % 2 == 1 else None
        h = n // 2

        first_half_counts = [0] * 26
        for c, v in cnt.items():
            first_half_counts[ord(c) - 97] = v // 2

        # Determine longest feasible tight prefix (target[0:p] usable from the multiset)
        feasible_max = h
        remaining = first_half_counts[:]
        for i in range(h):
            idx = ord(target[i]) - 97
            if remaining[idx] > 0:
                remaining[idx] -= 1
            else:
                feasible_max = i
                break

        def build_palindrome(A):
            if middle_char:
                return A + middle_char + A[::-1]
            return A + A[::-1]

        # Try full tight match first
        if feasible_max == h:
            A = target[:h]
            T = build_palindrome(A)
            if T > target:
                return T

        # Try diverging at position p, from largest feasible p down to 0
        start_p = feasible_max if feasible_max < h else h - 1
        for p in range(start_p, -1, -1):
            rem = first_half_counts[:]
            for i in range(p):
                rem[ord(target[i]) - 97] -= 1

            tidx = ord(target[p]) - 97
            found = -1
            for c in range(tidx + 1, 26):
                if rem[c] > 0:
                    found = c
                    break
            if found == -1:
                continue

            rem[found] -= 1
            rest = []
            for c in range(26):
                if rem[c]:
                    rest.append(chr(c + 97) * rem[c])

            A = target[:p] + chr(found + 97) + ''.join(rest)
            return build_palindrome(A)

        return ""