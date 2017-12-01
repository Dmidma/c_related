/**
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 * The purpose in life of this program is to convert the data from the file into a CSV.
 */



#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{

	// checking the arguments
	if (argc != 2)
	{
		printf("Must enter the path for the input file and the name of outputfile\n");
		printf("./prof inputFile outputFile\n");
		return 1;
	}

	// remember filenames
    char* infile = argv[1];


	// open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen("prof.output", "a");
    if (outptr == NULL)
    {
    	printf("Could not open/create output file %s\n", "prof.output");
    	return 3;
    }


    // starting the process
    printf("Reading and writing data...\n");

 
    char tmp = fgetc(inptr);
    /*
    	The main idea of this loop if to find the key value and store the text between "*****"
    	This loop will run till it reaches the EOF
     */
    while (tmp != '*')
    {		

    	if (tmp == 'v')
    	{
    		tmp = fgetc(inptr);
    		if (tmp == 'a')
    		{
    			tmp = fgetc(inptr);
    			if (tmp == 'l')
    			{
    				tmp = fgetc(inptr);
    				if (tmp == 'u')
    				{
    					tmp = fgetc(inptr);
    					if (tmp == 'e')
    					{
    						fgetc(inptr);
    						fgetc(inptr);
    						tmp = fgetc(inptr);
    						while (tmp != '"')
    						{	/*
    							// replace all '\n' with ''
    							if (tmp == '\n')
    							{
    								tmp = '';
				    			}
							*/
				    			// write into the output file
				    			fputc(tmp, outptr);
				    			// reading the next char
				    			tmp = fgetc(inptr);
				    		}

				    		// return to line for new data
				    		fputc('\n', outptr);
				    	}
				    }
    			}
    		}
    	}
    	
    	tmp = fgetc(inptr);
    }

    // done
    printf("DONE!\n");


    // closing files
    fclose(inptr);
    fclose(outptr);
    return 0;
}
