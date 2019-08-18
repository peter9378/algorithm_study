# -*- encoding: utf-8 -*-
# BOJ
# No.1914   하노이 탑 이동 순서
# author    peter9378
# date      2019.08.18

N = int(input())

def hanoi(N, fromm, through, to):
    if N == 1:
        print(fromm, to)
    else:
        hanoi(N-1, fromm, to, through)
        print(fromm, to)
        hanoi(N-1, through, fromm, to)

print(pow(2, N)-1)
if N<21:
    hanoi(N, 1, 2, 3)