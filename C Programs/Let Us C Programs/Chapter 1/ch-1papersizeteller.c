/*Write a program to calculate and print paper sizes from A1 to A8*/
/*Author:Ayush Kumar Shukla*//*Date:23rd Nov 2021*/

#include<stdio.h>

int main()
{
	int A1_len,A1_wid;
	int A2_len,A2_wid;
	int A3_len,A3_wid;
	int A4_len,A4_wid;
	int A5_len,A5_wid;
	int A6_len,A6_wid;
	int A7_len,A7_wid;
	int A8_len,A8_wid;
	int A0_len=1189,A0_wid=841;
	
	A1_len = A0_wid;
	A1_wid = (A0_len/2);
	
	A2_len = A1_wid;
	A2_wid = (A1_len/2);
	
	A3_len = A2_wid;
	A3_wid = (A2_len/2);
	
	A4_len = A3_wid;
	A4_wid = (A3_len/2);
	
	A5_len = A4_wid;
	A5_wid = (A4_len/2);
	
	A6_len = A5_wid;
	A6_wid = (A5_len/2);
	
	A7_len = A6_wid;
	A7_wid = (A6_len/2);
	
	A8_len = A7_wid;
	A8_wid = (A7_len/2);
	
	printf("Dimesions Of A1:%dmm x %dmm\n",A1_len,A1_wid);
	printf("Dimesions Of A2:%dmm x %dmm\n",A2_len,A2_wid);
	printf("Dimesions Of A3:%dmm x %dmm\n",A3_len,A3_wid);
	printf("Dimesions Of A4:%dmm x %dmm\n",A4_len,A4_wid);
	printf("Dimesions Of A5:%dmm x %dmm\n",A5_len,A5_wid);
	printf("Dimesions Of A6:%dmm x %dmm\n",A6_len,A6_wid);
	printf("Dimesions Of A7:%dmm x %dmm\n",A7_len,A7_wid);
	printf("Dimesions Of A8:%dmm x %dmm\n",A8_len,A8_wid);
	
	return 0;
		

	
	
	
	
	
}
