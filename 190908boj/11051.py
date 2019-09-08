n, k = map(int, input().split())
if k == 0:
    print(1)
else:
    answer = 1
    for i in range(k):
        answer *= (n-i)
    while k != 0:
        answer //= k
        k -= 1
    print(answer%10007)