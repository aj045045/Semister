/*Write a program to copy the contents of one file to another
 and also print the no. of lines in the first file.*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp,*fpc;
    int line=1,word=0,space=0;
    char text[80];
    char ch,i;

    // Creating a File,Input and Print in File
    /////////////////////////////////////////////////////////////////////////////////////////////
    if((fp=fopen("2ass.txt","w+"))==NULL)
    {
        printf("File Not created");
        exit(1);
    }
    printf("Enter text to store");
    gets(text);
    for(i=0;text[i];i++)
    {
        fputc(text[i],fp);
        
    }
    fclose(fp);

    //Copy to 2ass_copy.txt file
    /////////////////////////////////////////////////////////////////////////////////////////////
    if((fp=fopen("2ass.txt","r"))==NULL)
            printf("Destination file and source file not created");

    if((fpc=fopen("2ass_copy.txt","w+"))==NULL)
            printf("Destination file and source file not created");


    ch=getc(fp);
    while(ch!=EOF)
    {
       // calculating no of lines
        ////////////////////////////////////////////////////////////////////////////////////
       if(ch==' ')
         space++;
        if(ch=='\n')
        line++;
        word++;
        fputc(ch,fpc);

        ch=getc(fp);
    }
    word-=space;
    printf("In the program no of line %d , no of word %d, no of space %d",line,word,space);
    fclose(fp);
    fclose(fpc);
  return 0;
}