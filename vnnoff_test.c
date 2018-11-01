#include <stdio.h>
#include <stdlib.h>
#include "vnnoff.h"

typedef symtab_entry(uint8_t) symtab_entryb;
typedef symtab_entry(uint16_t) symtab_entryw;

int main(int argc, char **argv)
{
	//symtab_entry(uint8_t) *symtab = malloc(sizeof(symtab_entry(uint8_t)));
    /*symtab_entryb *symtab = malloc(sizeof(symtab_entryb));
    
    symtab->address = 0x5A;
    printf("%ld\t%X\n", sizeof(*symtab), symtab->address);
    printf("%ld\n", sizeof(char *));
    
    free(symtab);*/
    
	return 0;
}

