import sys
T = int(sys.stdin.readline())
for i in range(0, T):
    s = list(sys.stdin.readline())
    s=s[:len(s)-1]
    n = int(sys.stdin.readline())
    numbers = sys.stdin.readline()
    numbers = numbers[1:len(numbers)-2]
    numbers = numbers.split(',')

    if numbers[0] == '':
        numbers = []

    revers = False
    end = True
    left = 0
    right = len(numbers)
    for command in s:
        if command == 'R':
            if revers:
                revers = False
            else:
                revers = True
        elif command == 'D':
            if left == right:
                end = False
                break
            if revers:
                right-=1
            else:
                left+=1
    
    numbers = numbers[left:right]
    
    if revers:
        numbers.reverse()

    if end:
        if len(numbers) == 0:
            print("[]")
        else:
            print("[", end='')
            for j in range(0,len(numbers)-1):
                print(str(numbers[j]) + ',', end='')
            print(numbers[len(numbers)-1]+']')
    else:
        print("error")
