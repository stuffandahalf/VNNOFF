#include "vnnoff.h"
#include <stdlib.h>
#include <string.h>

void vnnoff_header_init(struct vnnoff_hdr *header) {
    if (header != NULL) {
        const char *magic = "VNNOFF";
        for (int i = 0; i < strlen(magic); i++) {
            header->magic[i] = magic[i];
        }
    }
}

int vnnoff_symtab_init(struct vnnoff_symtab *symtab) {
    if (symtab == NULL) {
        return 0;
    }
    symtab->entries = 0;
    symtab->max_size = 10;
    if ((symtab->symbols = calloc(symtab->max_size, sizeof(struct vnnoff_symtab_entry))) == NULL) {
        return 0;
    }
    return 1;
}

int vnnoff_symtab_add_entry(struct vnnoff_symtab *symtab, struct vnnoff_symtab_entry *symbol) {
    if (symtab == NULL || symbol == NULL) {
        return 0;
    }
    
    if (symtab->max_size == symtab->entries) {
        symtab->max_size += 10;
        if ((symtab->symbols = realloc(symtab->symbols, symtab->max_size)) == NULL) {
            return 0;
        }
    }
    symtab->symbols[symtab->entries++] = symbol;
    return symtab->entries;
}

int vnnoff_datatab_init(struct vnnoff_datatab *datatab) {
    if (datatab == NULL) {
        return 0;
    }
    datatab->entries = 0;
    datatab->max_size = 10;
    if ((datatab->data = calloc(datatab->max_size, sizeof(struct vnnoff_data_entry))) == NULL) {
        return 0;
    }
    return 1;
}

int vnnoff_datatab_add_entry(struct vnnoff_datatab *datatab, struct vnnoff_data_entry *data) {
    if (datatab == NULL || data == NULL) {
        return 0;
    }
    
    if (datatab->max_size == datatab->entries) {
        datatab->max_size += 10;
        if ((datatab->data = realloc(datatab->data, datatab->max_size)) == NULL) {
            return 0;
        }
    }
    datatab->data[datatab->entries++] = data;
    return datatab->entries;
}

void write_vnnoff(FILE *out_file, struct vnnoff_hdr *header, struct vnnoff_symtab *symtab, struct vnnoff_datatab *datatab) {
    fwrite((uint8_t *)header, sizeof(struct vnnoff_hdr), 1, out_file);
}
