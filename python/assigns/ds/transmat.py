def getmatrix(row,col):
    if col is None:
        col=row
    mat=[]
    for i in range(row):
        arr=[]
        for j in range(col):
            temp=int(input(f"Enter the {i},{j} element: "))
            arr.append(temp)
        mat.append(arr)
    return mat

def showmatrix(mat):
    row=len(mat)
    col=len(mat[0])
    for i in range(row):
        for j in range(col):
            print(mat[i][j],end="\t")
        print()

def pad(mat,row,col):
    diff=abs(row-col)
    if row < col:
        for i in range(diff):
            mat.append([0]*col)
    else:
        for val in mat:
            for i in range(diff):
                val.append(0)
    return mat

def transposemat(mat):
    row=len(mat)
    col=len(mat[0])
    if row != col:
        mat=pad(mat,row,col)
    for i in range(row):
        for j in range(col):
            if j>i:
                mat[i][j],mat[j][i]=mat[j][i],mat[i][j]
    return mat
    
row,col=int(input("Enter number of rows: ")),int(input("Enter number of columns: "))
print(f"Input Dimensions= {row}x{col}")

mat=getmatrix(row,col)
print("State of the matrix: ")
showmatrix(mat)
mat=transposemat(mat)
print("Transpose:")
showmatrix(mat)
