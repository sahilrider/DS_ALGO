'''
Time Complexity
Best : O(n)
Average : O(n^2)
Worst : O(n^2)
'''

def INSERTION_SORT(A):
	for j in range(2, len(A)):
		key = A[j]
		#Insert A[j] into the sorted sequence A[1....j-1]
		i = j - 1

		while i > 0 and A[i] > key:
			A[i + 1] = A[j]
			i -= 1

		A[i + 1] = key

	return A


print(INSERTION_SORT([1, 4, 2, 7, 4, 9]))
