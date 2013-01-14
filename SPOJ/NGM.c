#include <stdio.h>
#include <string.h>
 
int main()
{
  char input[11];
  scanf("%s",input);
  int len = strlen(input);
  if (input[len -1] == '0')
    {
      printf("2\n");
    }
  else
    {
      printf("1\n%d\n",input[len -1] - '0');
    }
  return 0;
}
