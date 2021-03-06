def max_subarray(A):
    max_ending_here = max_so_far = 0
    for x in A:
        max_ending_here = max(0, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

if __name__ == '__main__':
    A = raw_input()
    A = A.split(' ')
    for x in range(len(A)):
        A[x] = int(A[x])
    print max_subarray(A)
