arr = [72, 31, 11, 78, 65, 111, 54, 8, 99]
for i in range(1, len(arr)):
    key = arr[i]
    j = i-1
    while j >= 0 and key < arr[j]:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = key
print("Sorted array is:")
for i in range(len(arr)):
    print(arr[i], end=" ")
