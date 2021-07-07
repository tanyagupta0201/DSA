l = list(map(int, input().split()))
ele = int(input())
flag = False

for i in range(len(l)):
    if l[i] == ele:
        print("Element found at position " + str(i+1))
        flag = True 

if not flag: 
    print("No element found")