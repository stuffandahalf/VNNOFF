#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vnnoff.h"

#define FAIL(fmt, ...) { \
    fprintf(stderr, fmt, ##__VA_ARGS__); \
    exit(1); \
}

char *strclone(const char *);
void free_header(struct vnnoff_hdr *header);
void free_symbol_table(struct vnnoff_symtab *symtab);
void free_symbol(struct vnnoff_symtab_entry *symbol);
void free_data_table(struct vnnoff_datatab *data_table);
void free_data_entry(struct vnnoff_data_entry *data_entry);

int main(int argc, char **argv)
{
    struct vnnoff_hdr *header;
    if ((header = malloc(sizeof(struct vnnoff_hdr))) == NULL) {
        FAIL("Failed to allocate vnnoff header");
    }
    vnnoff_header_init(header);
    
    header->arch = VNNOFF_ARCH_MC6809;
    header->endianness = VNNOFF_BIG_ENDIAN;
    header->os = VNNOFF_OS_NONE;
    header->file_type = VNNOFF_FILE_REL;
    header->address_size = 2;
    header->starting_address = 0;
    
    struct vnnoff_symtab *symtab;
    if ((symtab = malloc(sizeof(struct vnnoff_symtab))) == NULL) {
        free_header(header);
        FAIL("Failed to allocate vnnoff symbol table");
    }
    vnnoff_symtab_init(symtab);
    
    char str[] = "A";
    struct vnnoff_symtab_entry *symtab_entry;
    for (int i = 0; i < 5; i++) {
        if ((symtab_entry = malloc(sizeof(struct vnnoff_symtab_entry))) == NULL) {
            free_symbol_table(symtab);
            free_header(header);
            FAIL("Failed to allocate new symbol");
        }
        if ((symtab_entry->address = calloc(header->address_size, sizeof(uint8_t))) == NULL) {
            free_symbol(symtab_entry);
            free_symbol_table(symtab);
            free_header(header);
            FAIL("Failed to allocate new symbol nae");
        }
        symtab_entry->address[0] = i;
        symtab_entry->address[1] = 0;
        symtab_entry->visibility = VNNOFF_VISIBILITY_LOCAL;
        symtab_entry->symbol = strclone(str);
        printf("%s\n", str);
        
        vnnoff_symtab_add_entry(symtab, symtab_entry);
        
        str[0]++;
    }
    
    /*struct vnnoff_datatab *data_table;
    if ((data_table = malloc(sizeof(struct vnnoff_datatab))) == NULL) {
        free_symbol_table(symtab);
        free_header(header);
        FAIL("Failed to allocate data table");
    }
    vnnoff_datatab_init(data_table);
    
    struct vnnoff_data_entry *data;
    if ((data = malloc(sizeof(struct vnnoff_data_entry))) == NULL) {
        free_data_table(data_table);
        free_symbol_table(symtab);
        free_header(header);
    }
    data->type = VNNOFF_DATA_ADDRESS;
    data->size = header->address_size;
    data->data = calloc(data->size, sizeof(uint8_t));
    //header->symbol_table_location = sizeof(*header) + symtab->size;
    //data->
    
    FILE *ofile = fopen("a.out", "w+");
    
    write_vnnoff(ofile, header, symtab, data_table);
    
    fclose(ofile);
    
    free_data_table(data_table);*/
    free_symbol_table(symtab);
    free_header(header);
    
	return 0;
}


char *strclone(const char *src) {
    size_t str_size = strlen(src) + 1;
    
    char *dest;
    if ((dest = malloc(str_size * sizeof(char))) == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < str_size; i++) {
        dest[i] = src[i];
    }
    return dest;
}

void free_header(struct vnnoff_hdr *header) {
    free(header);
}

void free_symbol_table(struct vnnoff_symtab *symtab) {
    for (size_t i = 0; i < symtab->entries; i++) {
        free_symbol(symtab->symbols[i]);
    }
    free(symtab->symbols);
    free(symtab);
}

void free_symbol(struct vnnoff_symtab_entry *symbol) {
    free(symbol->symbol);
    free(symbol->address);
    free(symbol);
}

void free_data_table(struct vnnoff_datatab *data_table) {
    for (size_t i = 0; i < data_table->entries; i++) {
        free_data_entry(data_table->data[i]);
    }
    free(data_table);
}

void free_data_entry(struct vnnoff_data_entry *data_entry) {
    free(data_entry->data);
    free(data_entry);
}
