import math
import sys
def gaussAdd(nums):
    total = start = 0
    end = math.ceil(len(nums)/2)
    for i in range(start,end):
        part_sum = nums[i] + nums[-1-i]
        print(f"Partial Sum {i+1}: {part_sum}")
        total += part_sum
    return total
args = sys.argv[1:]
numlist = [float(value) for value in args]
print("Given List = ",numlist)
res = gaussAdd(numlist)
print(f"RESULT OF ADDITION:{res}")
