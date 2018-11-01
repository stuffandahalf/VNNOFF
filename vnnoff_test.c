#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vnnoff.h"

int main(int argc, char **argv)
{
    struct vnnoff_hdr *header = malloc(sizeof(struct vnnoff_hdr));
    header->magic[0] = 'V';
    header->magic[1] = 'N';
    header->magic[2] = 'N';
    header->magic[3] = 'O';
    header->magic[4] = 'F';
    header->magic[5] = 'F';
    //memcpy(&(header->magic), VNNOFF_MAGIC, sizeof(VNNOFF_MAGIC));
    for (int i = 0; i < 6; i++) {
        printf("%c", header->magic[i]);
    }
    puts("");
    
    
    free(header);
    
	return 0;
}

