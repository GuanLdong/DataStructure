#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE		100
#define TRUE		1
#define FALSE		0
#define OK			1
#define OVERFLOW	2
#define ERROR		1
#define RED			"\033[0;32;31m"
#define NONE		"\033[m"
#define YELLOW		"\033[1;33m"
#define GREEN		"\033[0;32;32m"

typedef int ElemType;
typedef int Status;

typedef struct Str{
	char *ch;
	int length;
}Str;

Status Strassign(Str *str,char *ch){

	printf(GREEN"sentence assignment : %s\n"NONE,ch);
	if((*str).ch)
	{
		free((*str).ch);
		(*str).ch = NULL;
	}
	int len = 0;
	char *c;
	c= ch;
	while(*c)
	{
		++len;
		++c;
	}
	if (len == 0)
	{
		(*str).ch = NULL;
		(*str).length = 0;
		return OK;
	}
	else{
		(*str).ch = (char*)malloc(sizeof(char)*(len+1));
		if((*str).ch == NULL)
			return FALSE;
		else
		{
			c = ch;
			for( int i = 0;i<=len;++i,++c)
				(*str).ch[i]=*c;
			(*str).length = len;
			return TRUE;
		}
	}
}

Status InitString(Str *string){
	printf(GREEN"Initing sentence...\n"NONE);
	(*string).length = 0;
	(*string).ch = NULL;
	return OK;
}
Status PrintString(Str string){
	printf(YELLOW"Now sentence is : \n"NONE);
	char *p;
	p = string.ch;
	while(*p!='\0'){
		printf(RED"%c"NONE,*p);
		p++;
	}
	printf("\n");
}
Status OnlyPrint(Str string){
	char *p;
	p = string.ch;
	while(*p!='\0'){
		printf(YELLOW"%c"NONE,*p);
		p++;
	}
	printf("\n");
}
Status Strlength(Str string){
	return string.length;
}
Status Concat(Str *string,Str str2,Str str3){
	if((*string).ch){
		free((*string).ch);
		(*string).ch = NULL;
	}
	(*string).ch = (char *)malloc(sizeof(char)*(str2.length+str3.length+1));
	if((*string).ch == NULL)
		return OVERFLOW;
	int i;
	i = 0;
	while(i<str2.length){
		(*string).ch[i] = str2.ch[i];
		i++;
	}
	i = 0;
	while(i<=str3.length){
		(*string).ch[str2.length+i] = str3.ch[i];
		i++;
	}
	(*string).length = str2.length+str3.length;
	return OK;
}
Status Strcompare(Str str1,Str str2){
	printf(YELLOW"Compare two sentence ,the result is : "NONE);
	for(int i = 0;i<str1.length && i<str2.length;i++)
		if (str1.ch[i]!=str2.ch[i])
			return str1.ch[i]-str2.ch[i];
	return str1.length - str2.length;
}
Status Substring(Str *substr,Str string, int len,int pos){
	printf("sub string ,after %dth and len is %d\n",pos,len);
	if(pos <0 || pos >string.length || len<0 || (len+pos)>string.length)

		return OVERFLOW;
	if((*substr).ch)
	{
		free((*substr).ch);
		(*substr).ch = NULL;
	}
	(*substr).ch = (char *)malloc(sizeof(char)*len);
	if ((*substr).ch==NULL)
		return OVERFLOW;
	int i = 0;
	while(i<len){
		(*substr).ch[i] = string.ch[pos+i];
		i++;
	}
	(*substr).ch[len]= '\0';
}
Status ClearString(Str *string){
	printf(RED"Clear string...\n"NONE);
	if ((*string).ch){
		free((*string).ch);
		(*string).ch = NULL;
	}
	(*string).length = 0;
}
Status IndexFind(Str string,Str substr,int *location){
	printf("Demonstrate the simple matching algorithm:\n");
	int i= 0,j;
	if(string.length<substr.length)
		return OVERFLOW;
	while(i<string.length-substr.length){
		for(j=0;j<substr.length;j++)
			if(string.ch[i+j] != substr.ch[j])
			{
				i++;
				break;
				// in this tip not find ，i++
			}
			else{
				continue;
			}
		// if find ，execute this
		if(j == substr.length){
			*location = ++i;
			return TRUE;
		}
	}
	// not find ，return -1
	*location = -1;
	return FALSE;
}
Status getnext(Str substr,int next[]){
	int i =1 ,j=0;
	next[1] = 0;
	while(i<substr.length){
		if(j==0 || substr.ch[i]==substr.ch[j]){
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
Status KMP(Str str,Str substr,int next[]){
	int i = 1,j = 1;
	while(i<str.length && j<substr.length)
	{
		if(j==0 || str.ch[i]==substr.ch[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if(j=substr.length && i!=str.length){
		printf("KMP find substr in %dth. \n",i-substr.length);
		return i - substr.length;
	}
	else
		printf("KMP Not find substr in string.");
		return 0;
}
Status main(){
	Str string,strcont1,strcont2,substr;
	InitString(&string);
	InitString(&strcont1);
	InitString(&strcont2);
	Strassign(&string,"1234567890");
	PrintString(string);
	printf("String's length is : %d\n",string.length);
	Strassign(&strcont1,"Above part ");
	Strassign(&strcont2,"Below part ");
	Concat(&string,strcont1,strcont2);
	PrintString(string);
	ClearString(&strcont2);
	Strcompare(string,strcont1)?printf("1st is bigger\n"):printf("2rd is bigger\n");
	Strassign(&string,"AAABCIAUUE");
	Substring(&strcont1,string,10,8);
	PrintString(strcont1);
	InitString(&substr);
	Strassign(&substr,"ZZ");
	int location=-1;
	IndexFind(string,substr,&location)?printf("Find substr in %dth. \n",location):printf("Not find substr.\n");
	if(location!=-1){
		OnlyPrint(string);
		for(int i =0;i<location-1;i++)
			printf(" ");
		OnlyPrint(substr);
	}
	int next[substr.length+1];
	getnext(substr,next);
	int Loc;
	Loc = KMP(string,substr,next);

	if(Loc!=0){
		OnlyPrint(string);
		for(int i =0;i<location-1;i++)
			printf(" ");
		OnlyPrint(substr);
	}
}
