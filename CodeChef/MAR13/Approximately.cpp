#include <stdio.h>
#include <stdlib.h>
const int max_len=1000002;

int main()
{
	char arr[max_len];
	int numerator=103993;
	int denominator=33102;
	int int_part=numerator/denominator;
	int remain=numerator % denominator;
	arr[0]='3';
	arr[1]='.';
	for(int i=2;i<max_len;++i)
	{
		arr[i]='0' + ((remain * 10) / denominator);
		remain=(remain * 10) % denominator;
	}
	int nTestCases;
	scanf("%d",&nTestCases);
	for(;nTestCases>0;--nTestCases)
	{
		int p=0;
		scanf("%d",&p);
		if(p==0)
		{
			printf("%d\n",3);
			continue;
		}
		for(int i=0;i<p+2;++i)
		{
			putchar(arr[i]);
		}
		putchar('\n');
	}
	return 0;
}
