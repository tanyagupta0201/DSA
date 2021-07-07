l = list(map(int, input().split()))
max = l[0]

for i in range(len(l)):
    if l[i] > max:
        max = l[i] 

print("Max element in list is: " + str(max))