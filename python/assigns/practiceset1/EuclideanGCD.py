def gcd(a,b):
    while a % b != 0:
        temp=b
        b=a%b
        a=temp
    return b

def gcd_list(nums):
    if len(nums) != 1:
        newlist=[]
        for i in range(0,len(nums),2):
            ret=gcd(nums[i],nums[i] if i==len(nums)-1 else nums[i+1])
            newlist.append(ret)
        return gcd_list(newlist)
    return nums[0]
        
        
#driver code
nums=[16,20,14,40,50,12]
res=gcd_list(nums)
print(res)
