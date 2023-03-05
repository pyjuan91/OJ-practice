class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def plus(num1: str, num2: str) -> str:
            i = len(num1) - 1
            j = len(num2) - 1
            res = ""
            carry = 0

            while i >= 0 and j >= 0:
                this = int(num1[i]) + int(num2[j]) + carry
                carry = this // 10
                this = this % 10
                res = str(this) + res
                i -= 1
                j -= 1

            while i >= 0:
                this = int(num1[i]) + carry
                carry = this // 10
                this = this % 10
                res = str(this) + res
                i -= 1

            while j >= 0:
                this = int(num2[j]) + carry
                carry = this // 10
                this = this % 10
                res = str(this) + res
                j -= 1

            if carry > 0:
                res = str(carry) + res

            return res

        def oneDigMul(num1: str, num2: str) -> str:
            if int(num2) == 0:
                return "0"
            carry = 0
            res = ""
            i = len(num1) - 1
            while i >= 0:
                this = int(num1[i]) * int(num2) + carry
                carry = this // 10
                this = this % 10
                res = str(this) + res
                i -= 1

            if carry > 0:
                res = str(carry) + res

            return res

        res = ""
        i = len(num2) - 1
        zero = 0
        while i >= 0:
            this = oneDigMul(num1=num1, num2=num2[i])
            this = this.ljust(zero + len(this), "0")
            res = plus(res, this)
            zero += 1
            i -= 1

        OZ = True
        for d in res:
            if d != "0":
                OZ = False
        if OZ == True:
            return "0"
        return res


s = Solution()
print(s.multiply("123", "456"))
