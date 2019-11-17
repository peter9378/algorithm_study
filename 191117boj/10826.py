li = [0 for i in range(10001)]

li[0] = 0
li[1] = 1

for i in range(2, 10001):
	li[i] = li[i-1] + li[i-2]

print(li[int(input())])