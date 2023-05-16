def sort_by_date(L: list):
    # your code here
    L.sort(key=lambda x: (x[4:], x[:2], x[2:4]))


# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    date_list = input().split()
    sort_by_date(date_list)
    print(date_list)
