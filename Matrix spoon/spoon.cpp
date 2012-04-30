#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
typedef struct _node
{
  int row;
  int col;
  struct _node* next;
}node;
 
long long readIntFromBufferAndAdvance(char *&InBuf)
{
  long long noRead=0;
  bool sign=false;
  for(;*InBuf==' ' || *InBuf=='\n' || *InBuf == '\0' || *InBuf == '\r';++InBuf);
  if(*InBuf == '-')
    {
      sign=true;
      InBuf++;
    }
  for(;*InBuf!=' ' && *InBuf!='\n' && *InBuf != '\0' && *InBuf != '\r';++InBuf)
    {
      noRead = noRead * 10 + (*InBuf - '0');
    }
  if(sign)
    {
      noRead*=-1;
    }
  InBuf++;
  return noRead;
};
 
char readTheMatricCharacter(char *buf, int nCols, int row, int col)
{
  return buf[(nCols + 1)* row + col];
}
 
int main()
{
 
  long lInputBufferLength=100*100*110;
  char *InOrigBuf = new char[lInputBufferLength];
  char *InBuf=InOrigBuf;
  char *OutBuf = new char[40*100];
  char *tempOutBuf=OutBuf;
  int outBufLen=0;
  read(0,InBuf,lInputBufferLength);
  int nTestCases = readIntFromBufferAndAdvance(InBuf);
  const char spoon_small[]="spoon";
  const char spoon_high[]="SPOON";
  const char yes[]="There is a spoon!";
  const char no[]="There is indeed no spoon!";
 
  for(int i=0;i<nTestCases;i++)
    {
      node* HorizList=NULL;
      node* VertList=NULL;
      int nCols=0,nRows=0;
      nRows = readIntFromBufferAndAdvance(InBuf);
      nCols= readIntFromBufferAndAdvance(InBuf);
      //Check for an s
      for(int i=0;i<nRows;++i)
	{
	  for(int j=0;j<nCols;++j)
	    {
	      char ch=readTheMatricCharacter(InBuf,nCols,i,j);
	      if(ch == spoon_small[0] || ch == spoon_high[0])
		{
		  node *tempHoriz=new node;
		  tempHoriz->row=i;
		  tempHoriz->col=j;
		  tempHoriz->next=NULL;
		  node *tempVert = new node;
		  memcpy(tempVert,tempHoriz,sizeof(node));
		  if(j<=nCols-5)
		    {
		      tempHoriz->next=HorizList;
		      HorizList=tempHoriz;
		    }
		  if(i<=nRows-5)
		    {
		      tempVert->next=VertList;
		      VertList=tempVert;
		    }
		}
	    }
	}
      int tempLen=0;
      if(HorizList == NULL && VertList == NULL)
	{
	  tempLen=sprintf(tempOutBuf,"%s\n",no);
	  tempOutBuf+=tempLen;
	  outBufLen+=tempLen;
	  int incrInBuf=nRows * (nCols +1);
	  InBuf+=incrInBuf;
	  continue;
	}
 
      node *root=HorizList;
      int topfound=0;
      while(root!=NULL)
	{
	  int found=1;
	  int curSpoonPos=1;
	  for(curSpoonPos =1;curSpoonPos<5;++curSpoonPos)
	    {
	      char curChar=readTheMatricCharacter(InBuf,nCols,root->row,root->col + curSpoonPos);
	      if (curChar == spoon_high[curSpoonPos] || curChar == spoon_small[curSpoonPos])
		{
		  continue;
		}
	      else
		{
		  found = 0;
		  node *temp=root;
		  HorizList=HorizList->next;
		  root=HorizList;
		  delete temp;
		  temp =NULL;
		  break;
		}
	    }//for end
	  if(found)
	    {
	      topfound=1;
	      break;
	    }
	}//while end
      if(topfound == 1)
	{
	  tempLen=sprintf(tempOutBuf,"%s\n",yes);
	  tempOutBuf+=tempLen;
	  outBufLen+=tempLen;
	  int incrInBuf=nRows * (nCols +1);
	  InBuf+=incrInBuf;
	  continue;
	}
      root=VertList;
      topfound=0;
      while(root!=NULL)
	{
	  int found=1;
	  int curSpoonPos=1;
	  for(curSpoonPos =1;curSpoonPos<5;++curSpoonPos)
	    {
	      char curChar=readTheMatricCharacter(InBuf,nCols,root->row+curSpoonPos,root->col);
	      if (curChar == spoon_high[curSpoonPos] || curChar == spoon_small[curSpoonPos])
		{
		  continue;
		}
	      else
		{
		  found = 0;
		  node *temp=root;
		  VertList=VertList->next;
		  root=VertList;
		  delete temp;
		  temp = NULL;
		  break;
		}
	    }//for end
	  if(found)
	    {
	      topfound=1;
	      break;
	    }
	}//while end
      if(topfound == 1)
	{
	  tempLen=sprintf(tempOutBuf,"%s\n",yes);
	  tempOutBuf+=tempLen;
	  outBufLen+=tempLen;
	}
      else
	{
	  tempLen=sprintf(tempOutBuf,"%s\n",no);
	  tempOutBuf+=tempLen;
	  outBufLen+=tempLen;
	}
      int incrInBuf=nRows * (nCols +1);
      InBuf+=incrInBuf;
    }//for test case end
  write(1,OutBuf,outBufLen);
  delete [] InOrigBuf;
  delete [] OutBuf;
  return 0;
}
