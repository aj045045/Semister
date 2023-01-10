//Defines the entry point for the console application.

#include<stdio.h>
#include<stdlib.h>


int main()
{
	FILE *ifp;
	char text[80];
	int i,c;

	FILE *fp1;
	int ch;

	FILE *fp2;
	char *c1;
	
    //WRITE
    /////////////////////////////////////////////////////////////////////////////
	ifp = fopen("abc.txt", "w+");
	printf("\nEnter text : \n");
	scanf("%[^\n]",text);
//	for (c=1;c<=10;c++) {
		for (i=0;text[i];i++)
        {
            putc(text[i], ifp);
        }
			//putc('\n',fp);
	//}
fclose(ifp);
    
    //READ
//////////////////////////////////////////////////////////////////////////
	fp1=fopen("abc.txt","r");
	if (fp1==NULL)
	{
		printf("Cannot open the file a.txt \n");
	}
	
	ch=getc(fp1);
	while (ch!=EOF)
	{
		putchar(ch);
		ch=getc(fp1);
	}
	fclose(fp1);
//////////////////////////////////////////////////////////////////////
/* 
// Read line at a time
	
	
	
	fp2=fopen("msceg.txt","r");
	printf("\n");
    char *word[60];
	do{
		c1=fgets(word,60,fp2);
		
		if (c1!=NULL)
			printf("%s",word);
	} while(c1!=NULL);
	
	fclose(fp2);
	
	///////////////////////////////////////////////////////////

 */	return 0;
}

