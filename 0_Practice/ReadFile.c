#include <stdio.h>
#include <string.h>
int main()
{
   FILE *fp = NULL;
   fp = fopen("test.txt", "r"); //第一个逗号前是文件位置。逗号之后是打开文件方式
   char buf[100];
   char *p_buf,*retptr;
   p_buf = buf;
   if (fgets(p_buf,100,fp)!=NULL)
	   printf(p_buf);
   while ((retptr=strtok(p_buf, " ")) != NULL) {
       printf("\nsubstr:%s", retptr);
	   p_buf =NULL;
   }
   return 0;
}
