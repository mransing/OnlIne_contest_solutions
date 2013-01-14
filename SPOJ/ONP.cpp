#include <iostream>
#include <map>
 
char arrOperand[7]={'(',')','+','-','*','/','^'};
std::map <char, int> priMap;
 
class stack_node
{
  char p;
  stack_node *next;
 
public:
  stack_node(char _p):p(_p),next(NULL){};
  void insert(stack_node* next_node)
  {
    next = next_node;
  }
  stack_node* GetNext()
  {
    return next;
  }
  char GetData()
  {
    return p;
  }
};
 
class stack
{
  stack_node *mtop;
  int len;
public:
  stack():mtop(NULL),len(0){};
  void push(char c)
  {
    if(mtop == NULL)
      {
	mtop = new stack_node(c);
      }
    else
      {
	stack_node *new_node= new stack_node(c);
	new_node->insert(mtop);
	mtop = new_node;
      }
    len++;
  };
  char pop()
  {
    if(isEmpty())
      {
	return -1;
      }
    char c = mtop->GetData();
    stack_node *temp = mtop;
    mtop = mtop->GetNext();
    delete temp;
    len--;
    return c;
  };
 
  bool isEmpty()
  {
    return (mtop==NULL);
  };
 
  char top()
  {
    return mtop->GetData();
  };
};
 
 
 
bool IsOperand(char c)
{
  for(int i=0;i<7;i++)
    {
      if(c == arrOperand[i])
	return true;
    }
  return false;
};
 
int main()
{
 
  for(int i=0;i<7;i++)
    {
      priMap.insert(std::make_pair<char,int>(arrOperand[i],i));
    };
  char buf[410*100];
  char *poBuf = buf;
  char OutBuf[410*100];
  char *OrigOutBuf = OutBuf;
  int iTestCases =0;
  char outbuf[410*100];
  read(0,buf,410*100);
  int bytes = sscanf(poBuf,"%d\n",&iTestCases);
  if(iTestCases < 9)
    {
      poBuf = poBuf + bytes + 1;
    }
  else if(iTestCases < 99)
    {
      poBuf = poBuf + bytes + 2;
    }
  else
    {
      poBuf = poBuf + bytes + 3;
    }
  int OutWriteBytes=0;
  for(int i=0;i<iTestCases;i++)
    {
      stack c;
      char iLine[400];
      int iiline = 0;
      char outLine[400];
      while(*poBuf!='\n')
	{
	  iLine[iiline++]=*(poBuf++);
	}
      iLine[iiline++]='\0';
      poBuf++;
      int len=iiline;
      int olen =0;
      for(int j=0;j<len-1;j++)
	{
	  const char curChar = iLine[j];
	  if (curChar == ' ')
	    {
	      continue;
	    }
	  if(!IsOperand(curChar))
	    {
	      outLine[olen++] = curChar;
	      continue;
	    }
	  if(curChar == '(')
	    {
	      c.push(curChar);
	      continue;
	    }
	  if(curChar == ')')
	    {
	      char p = c.pop();
	      while(p != '(')
		{
		  outLine[olen++] = p;
		  p = c.pop();
		}
	      continue;
	    }
	  bool done =false;
	  do
	    {
	      if(c.isEmpty() || (priMap[c.top()] < priMap[curChar]))
		{
		  c.push(curChar);
		  done = true;
		}
	      else
		{
		  outLine[olen++] = c.pop();
		}
	    }while(!done);
	}
      while(!c.isEmpty())
	{
	  outLine[olen++] = c.pop();
	}
      outLine[olen++] = '\0';
      bytes = sprintf(OrigOutBuf,"%s\n",outLine);
      OrigOutBuf = OrigOutBuf + bytes;
      OutWriteBytes += bytes;
    }
  write(1,OutBuf,OutWriteBytes);
  return 0;
}
