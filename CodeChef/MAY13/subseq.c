#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  int nTestCases=0;
  char str1[25001],str2[25001];
  scanf("%d",&nTestCases);
  for(;nTestCases > 0;--nTestCases){
	scanf("%s",str1);
	scanf("%s",str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	char* mStr1,*mStr2;
	if(len1 == len2){
	  if(strcmp(str1,str2) == 0){
		printf("YES\n");
	  }
	  else{
		printf("NO\n");
	  }
	  continue;
	}
	if(len1 > len2){
	  mStr1 = str1;
	  mStr2 = str2;
	}
	else{
	  mStr1=str2;
	  mStr2=str1;
	}
	char c;
	int not_found=0;
	while( (c = *(mStr2++)) != 0 ){
	  mStr1 = strchr(mStr1,c);
	  if(mStr1 == NULL){
		not_found=1;
		break;
	  }
	  mStr1++;
	}
	if(not_found == 1){
	  printf("NO\n");
	}
	else{
	  printf("YES\n");
	}
  }
  return 0;
}
