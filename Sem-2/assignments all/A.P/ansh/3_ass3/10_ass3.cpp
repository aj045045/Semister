/* Write a program that will generate a data file containing the
list of customers and their corresponding telephone numbers.
Use a structure variable to store the name and telephone
number of each customer.
 */

#include <stdio.h>
#include <stdlib.h>

struct client
{
    char name[20];
    int tel;
} cv[20];

int main()
{
    int i, v = 0;
    struct client c[20];
    FILE *fp;

    if ((fp = fopen("3_ass3.txt", "w+")) == NULL)
        printf("File Not created\n");

     for(i=0;i<5;i++)
     {
      printf("=========Enter %d data:=============\n",i+1);
    printf("Name :");
    scanf("%s", c[i].name);
    printf("Number :");
    scanf("%d", &c[i].tel);
    }
    fwrite(c, sizeof(struct client), 5, fp);
    fprintf(fp, "%d", v);
    fclose(fp);

    if((fp=fopen("3_ass3.txt","r"))==NULL)
         printf("File Not created\n");

     fread(cv,sizeof(struct client),5,fp);

     for(i=0;i<5;i++)
     {
             printf("=========print %d data:=============\n",i+1);
             printf("Name is %s",cv[i].name);
             printf("\tContact is %d",cv[i].tel);
             printf("\n");
     }
 return 0;
}
