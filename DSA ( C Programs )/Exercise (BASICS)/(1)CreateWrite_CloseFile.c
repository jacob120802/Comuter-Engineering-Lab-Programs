/*C program to write a string to a file*/
#include <stdio.h>
int main()
{
 FILE *fp;
 char filename[100];
 char writestr[100];
  // Read filename
  printf("Enter a filename :");
  gets(filename);
  // Read string to write
  printf("Enter the string to write :");
  gets(writestr);
   // Open file in write mode/ Create file
   fp = fopen(filename,"w+");
   // If file opened successfully, then write the string to file
   if ( fp )
   {
	   fputs(writestr,fp);
    }
   else
    {
         printf("Failed to open the file\n");
    }
//Close the file
   fclose(fp);
return 0;
}