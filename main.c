#include <stdio.h>
#include<stdlib.h>
#include "str_process.h"

void print_menu() {
  const char* menu = "1. split\n2. startswith\n3. endswith\n4. swapcase\n"
                     "5. lstrip\n6. rstrip\n7. strip\n8. replace\n9. format";
  printf("%s\nPlease enter your selection: ", menu);
}

int main(const int argc, const char** argv) {
  // Print the main menu


  // Get user input
  int input = 1;
while(input!=0)
  {
   print_menu();
   scanf_s("%d", &input);
  switch(input)
  {
  	case 1:
	{//int split_s(const char* src, const char* sp, char dst[MAX_STR_COUNT][MAX_STR_LEN])
		char dst[MAX_STR_COUNT][MAX_STR_LEN];
		char src[MAX_STR_LEN];
		char tem;
		int choice = 0;
		int n = 0;
		printf("module:split\n");
		printf("1. split by character\n2. split by string\n");
		printf("Please enter your selection:");
		scanf_s("%d", &choice);
		tem=getchar();
		if (choice == 1)
		{
			char sp;
			int i;
			printf("Please input the string:");
			scanf("%s",&src);
			printf("Please input the splitter:");
			tem=getchar();
			sp=getchar();  
			n=split_c(src, sp, dst);
			printf("Result:\nGet %d substrings.\n", n);
			for (i = 0; i < n; i++)
			{
				printf("%d.%s\n", i + 1, dst[i]);
			}
			printf("\n");
		}
		else if(choice==2)
		{
			char sp[MAX_STR_LEN]; 
			int i;
			printf("Please input the string:");
			scanf_s("%s",src,sizeof(src));
			printf("Please input the splitter:");
            scanf_s("%s",sp,sizeof(sp));
			n=split_s(src, sp, dst);
			printf("Result:\nGet %d substrings.\n", n);
			for (i = 0; i < n; i++)
			{
				printf("%d.%s\n", i + 1, dst[i]);
			}
			printf("\n");
		}
	}break;
	case 2:
		{
			char tem; 
			char str[MAX_STR_LEN];
			char p[MAX_STR_LEN];
			int n=0;
			tem=getchar();
			printf("module:startswith\n");
			printf("Please input the string:");
			gets(str);
			printf("Please input the check pattern:");
			scanf_s("%s",p,sizeof(p));
			n=startswith(str,p);
			if(n==1)
			{
				printf("This string is started with the check pattern\n");
			}
			if(n==0)
			{
				printf("It's wrong!\n");
			}
			printf("\n");
		}break;
	case 3:
		{
			char str[MAX_STR_LEN];
			char p[MAX_STR_LEN];
			int n=0;
			char tem;
			tem=getchar();
			printf("module:endswith\n");
			printf("Please input the string:");
			gets(str);
			printf("Please input the check pattern:");
			scanf_s("%s",p,sizeof(p));
			n=endswith(str,p);
			if(n==1)
			{
				printf("This string is ended with the check pattern\n");
			}
			if(n==0)
			{
				printf("It's wrong!\n");
			}
			printf("\n");
		}break;
	case 4:
		{
			char src[MAX_STR_LEN];
			char dst[MAX_STR_LEN];
			char tem;
			tem=getchar();
			printf("module:swapcase\n");
			printf("Please input the string:");
			gets(src);
			swapcase(src,dst);
			printf("The result is:%s\n",dst);
		}break;
	case 5:
		{
			char src[MAX_STR_LEN];
			char dst[MAX_STR_LEN];
			char tem;
			tem=getchar();
			printf("module:lstrip\n");
			printf("Please input the string:");
			gets(src);
			lstrip(src,dst);
			printf("The result is:%s\n",dst);
		}break;
	case 6:
		{
			char src[MAX_STR_LEN];
			char dst[MAX_STR_LEN];
			char tem;
			tem=getchar();
			printf("module:rstrip\n");
			printf("Please input the string:");
			gets(src);
			rstrip(src,dst);
			printf("The result is:%s\n",dst);
		}break;
	case 7:
		{
			char src[MAX_STR_LEN];
			char dst[MAX_STR_LEN];
			char tem;
			tem=getchar();
			printf("module:strip\n");
			printf("Please input the string:");
			gets(src);
			strip(src,dst);
			printf("The result is:%s\n",dst);
		}break;
	case 8:
		{
			char src[MAX_STR_LEN];
			char old_pat[MAX_STR_LEN];
			char new_pat[MAX_STR_LEN];
			char dst[MAX_STR_LEN];
			int g;
			char tem;
			tem=getchar();
			printf("module:strip\n");
			printf("Please input the string:");
			gets(src);
		//	tem=getchar();
			printf("Please input the old_pat:");
			gets(old_pat);
		//	tem=getchar();
			printf("Please input the new_pat:");
			gets(new_pat);
		//	tem=getchar();
			printf("Please input the mode(1 is full,0 is first time):");
			scanf("%d",&g);
			tem=getchar();
			replace(src,old_pat,new_pat,dst,g);
			printf("The result is:%s\n",dst);
		}break;
	case 9:
		{
			char fmt[MAX_STR_LEN];
			int argc = 0;
			char** args = (char**)malloc(argc * sizeof(char*));
			char dst[MAX_STR_LEN];
			char tem;
			int i = 0;
			tem = getchar();
			printf("module:format\n");
			printf("Pleae input the string:");
			gets(fmt);
			printf("Please input the num of args:");
			scanf_s("%d", &argc);
			tem = getchar();
			for (i = 0; i < argc; i++)
			{
				args[i] = (char*)malloc((MAX_STR_LEN + 1) * sizeof(char));
				printf("Please input  No.%d string:", i + 1);
				scanf_s("%s", args[i],sizeof(args[i]));
				tem = getchar();
			}
			format(fmt, argc, args, dst);
			printf("%s\n", dst);
		}break;
	}
	} 
  return 0;
}
