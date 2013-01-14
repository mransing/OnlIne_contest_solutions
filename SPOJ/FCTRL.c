#include<stdio.h>
#include<stdlib.h>
 
#define MAX (262144 * 4)
#define BUFMAX 65536
int main()
{
  const long FivePowers[12] = {5, 25, 125, 625, 625 * 5, 625 * 25, 625 * 125, 625* 625, 625 * 625 * 5, 625 * 625 * 25, 625 * 625 * 125, 625 * 625 * 625};
  long iTestCases=0;
  long curNumber =0, i=0;
  char arrOutNumber[MAX];
  long index = 0;
  scanf("%d",&iTestCases);
  char * tempBuffer = arrOutNumber;
  int n;
  for(i=0;i <iTestCases; i++)
    {
      scanf("%d",&curNumber);
      long outNumber = curNumber/FivePowers[0] + curNumber/FivePowers[1] + curNumber/FivePowers[2] + curNumber/FivePowers[3] +
	curNumber/FivePowers[4] + curNumber/FivePowers[5] + curNumber/FivePowers[6] + curNumber/FivePowers[7] +
	curNumber/FivePowers[8] + curNumber/FivePowers[9] + curNumber/FivePowers[10] + curNumber/FivePowers[11];
      index++;
      n = sprintf(tempBuffer, "%lu", outNumber);
      tempBuffer += n;
      sprintf(tempBuffer,"\n");
      tempBuffer++;
      if(index == BUFMAX)
	{
	  //Output this buffer
	  write(1,arrOutNumber, tempBuffer-arrOutNumber);
	  index =0;
	  tempBuffer = arrOutNumber;
	}
    }
  write(1,arrOutNumber, tempBuffer-arrOutNumber);
  return 0;
}
