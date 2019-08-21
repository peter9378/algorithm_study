#	Codeforces
#	#581		A. BowWow and the Timetable
#	@author	peter9378
#	@date		2019.08.21

s = input()
number = 0
index = 0

for i in range(len(s) - 1, -1, -1) :
	if s[i] == '1' :
		number += pow(2, index)
		index += 1

		answer = 0
		count = 1
		while count < number:
count *= 4
answer += 1

print(answer)