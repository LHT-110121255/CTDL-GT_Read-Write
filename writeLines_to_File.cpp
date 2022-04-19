/**
 * C program to append data to a file
 * Source: codeforwin.org
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000


/**
 * Reads a file character by character 
 * and prints on console.
 * 
 * @fPtr    Pointer to FILE to read.
 */
FILE* openFile() 
{
	FILE* fPtr;
	char filePath[100];
	/* Input file path to remove empty lines from user */
    printf("Enter file path: ");
    scanf("%s", filePath);
    /*  Open all file in mode. */
    fPtr = fopen(filePath, "r");


    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL)
	{
        /* Unable to open file hence exit */
        printf("\nUnable to open '%s' file.\n", filePath);
        printf("Please check whether file exists and you have write privilege.\n");
        exit(EXIT_FAILURE);
    }
    return fPtr;
}

void readFile(FILE * fPtr) 
{
    char ch;

    do 
    {
        ch = fgetc(fPtr);

        putchar(ch);

    } while (ch != EOF);
}

int countLetters(FILE * fPtr)
{
	char ch;
	int count = 0;
    do 
    {
        ch = fgetc(fPtr);

        putchar(ch);
        
		if ((ch >=65)&&(ch<=90) || (ch>=97)&& (ch<=122))
        	count++;

    } while (ch != EOF);

    return count;
}

void inputFile()
{
    /* File pointer to hold reference of input file */
    FILE *fPtr;
    char filePath[100];
    char stop[] ="Exit";

    char dataToAppend[BUFFER_SIZE];


    /* Input file path to remove empty lines from user */
    printf("Enter file path: ");
    scanf("%s", filePath);

    /*  Open all file in append mode. */
    fPtr = fopen(filePath, "a");


    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL)
	{
        /* Unable to open file hence exit */
        printf("\nUnable to open '%s' file.\n", filePath);
        printf("Please check whether file exists and you have write privilege.\n");
        exit(EXIT_FAILURE);
    }
	

	    /* Input data to append from user */
	printf("\nEnter data to append: ");
	while(1)
	{
		
	    fflush(stdin);          // To clear extra white space characters in stdin
	    gets(dataToAppend);
		if (strcmp(dataToAppend, stop)==0)
		{
			printf("Break!");
			break;			
		}
	
	    /* Append data to file */
	    fputs(dataToAppend, fPtr);
	    fputc('\n', fPtr);
	}


    /* Reopen file in read mode to print file contents */
    fPtr = freopen(filePath, "r", fPtr);

    /* Print file contents after appending string */
    printf("\nSuccessfully appended data to file. \n");
    printf("Changed file contents:\n\n");
    readFile(fPtr);


    /* Done with file, hence close file. */
    fclose(fPtr);

    
}

int main()
{
	FILE* myFile = openFile();
	int c = countLetters(myFile);
	printf("Number of letters in the file is: %d ", c);
	return 0;
}




