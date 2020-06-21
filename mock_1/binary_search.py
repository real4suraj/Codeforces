def binary_search(arr, target):
	l, r = 0, len(arr) - 1
	while(l <= r):
		mid = int(l + (r - l)/2)
		if arr[mid] == target : return mid
		elif arr[mid] < target : l = mid + 1
		else :  r = mid - 1
	return -1

arr =  input("Enter the elements of the array : ").split(" ")
arr = [int(x) for x in arr]
arr.sort()
x = int(input("Enter the number to be searched for : "))
idx = binary_search(arr, x)
if idx != -1 : print(f'{x} found at index {idx}')
else :  print(f'{x} not found in the array')


'''
OUTPUT
Enter the elements of the array : 1 2 3 4 5
Enter the number to be searched for : 3
3 found at index 2

Enter the elements of the array : 1 2 3 4 5
Enter the number to be searched for : 5
5 found at index 4

Enter the elements of the array : 1 2 3 4 5
Enter the number to be searched for : 7
7 not found in the array

'''