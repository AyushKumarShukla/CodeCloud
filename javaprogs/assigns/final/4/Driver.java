import java.util.Scanner;
import java.lang.Exception;
class MatrixOrderMismatchException extends Exception
{
	MatrixOrderMismatchException(String message)
	{
		super(message);
	}	
}
class Matrix
{
	double mat[][];
	int row,col;
	Matrix(int row,int col)
	{
		mat = new double[row][col];
		this.row=row;
		this.col=col;
	}
	
	int row()
	{
		return this.row;
	}
	
	int col()
	{
		return this.col;
	}
	
	void insertAt(double value,int row,int col)
	{
		this.mat[row][col] = value;	
	}
	
	double valueAt(int row,int col)
	{
		return mat[row][col];
	}
}

class MatrixOp
{
	static Matrix add(Matrix mat1,Matrix mat2) throws MatrixOrderMismatchException
	{	
		Matrix sum;
		if((mat1.row() != mat2.row()) && (mat1.col() != mat2.col()))
			throw new MatrixOrderMismatchException("Matrices not compatible for addition");

		sum = new Matrix(mat1.row(),mat1.col());
		for(int i=0;i<mat1.row();i++)
		{
			for(int j=0;j<mat1.col();j++)
			{
				double add = mat1.valueAt(i,j)+mat2.valueAt(i,j);
				sum.insertAt(add,i,j);
			}
		}
	
		return sum;
	}

	static Matrix sub(Matrix mat1,Matrix mat2) throws MatrixOrderMismatchException
	{	
		Matrix diff;
		if((mat1.row() != mat2.row()) && (mat1.col() != mat2.col()))
			throw new MatrixOrderMismatchException("Matrices not compatible for subtraction");

		diff = new Matrix(mat1.row(),mat1.col());
		for(int i=0;i<mat1.row();i++)
		{
			for(int j=0;j<mat1.col();j++)
			{
				double sub = mat1.valueAt(i,j)-mat2.valueAt(i,j);
				diff.insertAt(sub,i,j);
			}
		}
	
		return diff;
	}

	static Matrix multiply(Matrix mat1,Matrix mat2) throws MatrixOrderMismatchException
	{	
		Matrix diff;
		if((mat1.col() != mat2.row()))
			throw new MatrixOrderMismatchException("Matrices not compatible for multiplication");

		diff = new Matrix(mat1.row(),mat2.col());
		int sum;
		for(int i=0;i<mat1.row();i++)
			for(int j=0;j<mat2.col();j++)
			{
				sum=0;	
				for(int k=0;k<mat1.col();k++)
					sum += mat1.valueAt(i,k)*mat2.valueAt(k,j);
				diff.insertAt(sum,i,j);
			}
		return diff;
	}
	
}
class Driver
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int row1=Integer.parseInt(args[0]);
		int col1=Integer.parseInt(args[1]);
		int row2=Integer.parseInt(args[2]);
		int col2=Integer.parseInt(args[3]);
		
		System.out.println("\nEnter the first Matrix: ");
		Matrix mat1 = new Matrix(row1,col1);
		inputMat(mat1);
		outputMat(mat1);
		System.out.println("\nEnter the second Matrix: ");
		Matrix mat2 = new Matrix(row2,col2);			
		inputMat(mat2);
		outputMat(mat2);
		
	while(true)
	{
		System.out.format("MENU:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit\n");
		System.out.print("Select an option: ");
		int ch = sc.nextInt(); 			
		switch(ch)
		{
				
			case 1:
				try
				{
					Matrix result = MatrixOp.add(mat1,mat2); //hit
					System.out.println("\nSum of the matrices: ");
					outputMat(result);
				}
				catch(MatrixOrderMismatchException e1)
				{
					System.out.println("Exception Caught: " + e1.getMessage());
					System.out.println("Please Ensure that the order of the matrices is same");
				}
				break;
			case 2:
				try
				{
					Matrix result = MatrixOp.sub(mat1,mat2); //hit
					System.out.println("\nDifference of the matrices: ");
					outputMat(result);
				}
				catch(MatrixOrderMismatchException e1)
				{
					System.out.println("Exception Caught: " + e1.getMessage());
					System.out.println("Please Ensure that the order of the matrices is same");

				}
				break;
			case 3:	
				try
				{
					Matrix result = MatrixOp.multiply(mat1,mat2); //hit
					System.out.println("\nProduct of the matrices: ");
					outputMat(result);
				}
				catch(MatrixOrderMismatchException e1)
				{
					System.out.println("Exception Caught: " + e1.getMessage());
					System.out.println("Please Ensure that the matrices are conformable for multiplication");
				}
				break;
			case 4:
				System.out.println("Exit");
		}
	}
	}

	static void inputMat(Matrix mat1)
	{
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<mat1.row;i++)
			for(int j=0;j<mat1.col;j++)
			{
				System.out.format("Enter value at %d %d: ",i,j);
				double inp = sc.nextDouble();
				mat1.insertAt(inp,i,j);
			}
	}

	static void outputMat(Matrix mat1)
	{
		System.out.format("r\\c\t");
		for(int i=0;i<mat1.col;i++)
		{
			System.out.format("%d\t",i);
		}
		System.out.println();
		for(int i=0;i<mat1.row;i++)
		{
			System.out.format("%d\t",i);
			for(int j=0;j<mat1.col;j++)
			{
				System.out.format("%.2f\t",mat1.valueAt(i,j));
			}
			System.out.println();
		}	
	}
}