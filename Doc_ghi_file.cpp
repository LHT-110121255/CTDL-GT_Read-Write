
/** 
* C prgram to append data to a file
* Source: codeforwin.org
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void readFile(FILE * fPtr);
void dem(FILE * fPtr);
int main() 
{
	/* File pointer to hold reference of input file */
	FILE *fPtr;
	char STOP[] = "exit";
	char filePath[100];
	
	char dataToAppend[BUFFER_SIZE];
	
	/* Input file path to remove empty lines from user */
	printf("EMter file path: ");
	scanf("%s", filePath);
	
	/* Open all file in append mode. */
	fPtr = fopen(filePath, "a");
	
	/* fpoen() return NULL if unable to open file in given
mode. */
	if (fPtr == NULL) 
	{
		/* Unable to open file hence exit. */
		printf("\nUnable to open '%s' file. \n", filePath);
		printf("Please check whether file exists and you have write privilege.\n");
		exit(EXIT_FAILURE);
	}
	
	
	/*Input data to append from user*/
	printf("\nEnter date too append: ");
	fflush(stdin);		// To clear extra white space charaters in stdin
//	fgets(dataToAppend, BUFFER_SIZE, stdin);

	/*UPDATE INPUT LINES*/
	while (1) {
		gets(dataToAppend);
		fputs("\n", fPtr);
		if(strcmp(dataToAppend, STOP) == 0) {	
			break;
		}
		/*Append data too file*/
		fputs(dataToAppend, fPtr);
	}
	
	


	
	
	/*Reopen file in read mode to print file contents*/ 
	fPtr = freopen(filePath, "r", fPtr);
	
	
	/*Print file contents after appending string*/
	printf("\nSuccerfully appended data to file. \n");
	printf("Changed file contents: \n\n");
	readFile(fPtr);
	/*Done with file, hence close file.*/
	fPtr = freopen(filePath, "r", fPtr);
	
	
	/*Print file contents after appending string*/
	printf("\nSuccerfully appended data to file. \n");
	printf("Sum letter of data: \n\n");
	dem(fPtr);
	/*Done with file, hence close file.*/
	fclose(fPtr);
	return 0;
	
}



/*
*Reads a file chareter by charater 
*and prints on console.
*
*@fPtr	Pointer to FILE to read.
*/
void readFile(FILE * fPtr)
{
	char ch;
	                                      
	do
	{
		ch = fgetc(fPtr);
		putchar(ch);	
	} while (ch != EOF);
}
void dem(FILE * fPtr)
{
	char ch;
	int  dem = 0;                                  
	do
	{
		ch = fgetc(fPtr);
		if(ch > 65 && ch < 122) {
			dem++;
		}
	} while (ch != EOF);
	printf("%d", dem);
}

