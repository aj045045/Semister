/* Write a program to read a line from file and print alternate characters in the output file. 
Display appropriate message for file i/o errors. */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char text[80],word[60],opt[20];
	int i;
	char ch,*c1;

	printf("Enter File Name to Store Data");
	gets(opt);

	// Create a FILE
	/////////////////////////////////////////////////////////////////////////////////////////////////
	if((fp=fopen(opt,"w+"))==NULL)
	{
		printf("\nFile not Created :");
		exit(1);
	}

	// Write in FILE
	/////////////////////////////////////////////////////////////////////////////////////////////////
	printf("Enter text to be instered :");
	scanf("%[^\n]",text);

	for(i=0;text[i];i++)
	{
		fputc(text[i],fp);
	}
 	fclose(fp);
	
	//Print Char from FILE
	/////////////////////////////////////////////////////////////////////////////////////////////////
	if ((fp=fopen(opt,"r"))==NULL)
	{
		printf("Cannot open the file a.txt :\n");
	}
	ch=getc(fp);
	while (ch!=EOF)
	{
		putchar(ch);
		ch=getc(fp);
	}
	fclose(fp);
	
	// Read line at a time
	//////////////////////////////////////////////////////////////////////
	fp=fopen(opt,"r");
	printf("\n");
	do{
		c1=fgets(word,sizeof(word),fp);
		if (c1!=NULL)
		printf("%s",word);
		
	} while(c1!=NULL);
	
	fclose(fp);
	
	//////////////////////////////////////////////////////////

 return 0;
}
