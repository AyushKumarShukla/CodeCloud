def xcount(seq,key):
    cnt=0
    if isinstance(seq,list):    
        for val in seq:
            if val==key:
                cnt += 1
    elif isinstance(seq,str):
        for i in range(0,len(seq)+1):
            if seq[i:i+2] == key:
                cnt += 1
    return cnt

seq1 = "hi there! hi, how are you? hihihi"
print("For String: ",xcount(seq1,"hi"))

seq2 = [1,2,3,4,1,2,3,4,1,2,3,4]
print("For List: ",xcount(seq2,1))
