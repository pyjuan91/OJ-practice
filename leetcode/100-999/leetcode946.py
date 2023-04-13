from typing import List


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        st = []
        while popped:
            if not pushed and not st:
                return False
            if st and st[-1] == popped[0]:
                st.pop()
                popped.pop(0)
            else:
                if not pushed:
                    return False
                else:
                    st.append(pushed.pop(0))
        return True


s = Solution()
print(s.validateStackSequences(pushed=[1, 2, 3, 4, 5], popped=[4, 5, 3, 2, 1]))
