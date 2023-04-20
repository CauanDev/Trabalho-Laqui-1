#include <stdlib.h> 		
#include <time.h>


#include "conio_v3.2.4.h"   
#include "console_v1.5.4.h"
#include "graphics_v1.1.h"  
#include "arquivo_header_v1.h"


/*
gcc arquivo.c conio_v3.2.4.c console_v1.5.4.c  arquivo_codigos.c -o arquivo.exe -Wall -Werror -Wextra -pedantic -lgdi32 -lwinmm
*/


int main(int argc, char *argv[])
{

    
    
    
    /* Artifício para silenciar warning */
    argc = argc;
	argv = argv;
    /* Artifício para silenciar warning */

    Start();
 
    return 0;
}

