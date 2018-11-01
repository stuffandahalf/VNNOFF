#ifndef __VNNOFF_H
#define __VNNOFF_H

#include <stdio.h>
#include <stdint.h>

struct __attribute__((packed)) vnnoff_hdr {
    uint8_t magic[6];
    uint8_t arch;
    uint8_t endianness;
    uint8_t os;
    uint8_t file_type;
    uint8_t address_size;
    size_t starting_address;
    size_t symbol_table_location;
};

/*#define symtab_entry(T) struct __attribute__((packed)) { T address; uint8_t visibility; char *symbol; }

typedef symtab_entry(uint8_t) symtab_entryb;
typedef symtab_entry(uint16_t) symtab_entryw;
typedef symtab_entry(uint32_t) symtab_entryl;
typedef symtab_entry(uint64_t) symtab_entryq;*/

struct __attribute__((packed)) vnnoff_symtab_entry {
    uint8_t *address;
    uint8_t visibility;
    char *symbol;
};

struct __attribute__((packed)) vnnoff_symtab {
    struct vnnoff_symtab_entry **symbols;
    size_t entries;
    size_t max_size;
};

struct __attribute__((packed)) vnnoff_data_entry {
    uint8_t type;
    size_t size;
    uint8_t *data;
};

struct __attribute__((packed)) vnnoff_datatab {
    struct vnnoff_data_entry **data;
    size_t entries;
    size_t max_size;
};

void vnnoff_header_init(struct vnnoff_hdr *header);
int vnnoff_symtab_init(struct vnnoff_symtab *symtab);
int vnnoff_symtab_add_entry(struct vnnoff_symtab *symtab, struct vnnoff_symtab_entry *symbol);
int vnnoff_datatab_init(struct vnnoff_datatab *datatab);
int vnnoff_datatab_add_entry(struct vnnoff_datatab *datatab, struct vnnoff_data_entry *data);

void write_vnnoff(FILE *out_file, struct vnnoff_hdr *header, struct vnnoff_symtab *symtab, struct vnnoff_datatab *datatab);


/* Endianness definitions */
#define VNNOFF_BIG_ENDIAN 0
#define VNNOFF_LITTLE_ENDIAN 1

/* Architectures */
#define VNNOFF_ARCH_NONE    0
#define VNNOFF_ARCH_I386    1
#define VNNOFF_ARCH_AMD64   2
#define VNNOFF_ARCH_PPC     3
#define VNNOFF_ARCH_PPC64   4
#define VNNOFF_ARCH_M68k    5
#define VNNOFF_ARCH_MC6809  6
#define VNNOFF_ARCH_HD6309  7
#define VNNOFF_ARCH_6502    8
#define VNNOFF_ARCH_Z80     9

/* Operating Systems */
#define VNNOFF_OS_NONE      0
#define VNNOFF_OS_LINUX     1
#define VNNOFF_OS_MACOS     2
#define VNNOFF_OS_FREEBSD   3
#define VNNOFF_OS_WINDOWS   4

#define VNNOFF_VISIBILITY_LOCAL     0
#define VNNOFF_VISIBILITY_PUBLIC    1
#define VNNOFF_VISIBILITY_EXTERN    2

/* File type */
#define VNNOFF_FILE_UNKNOWN 0
#define VNNOFF_FILE_REL     1
#define VNNOFF_FILE_EXE     2
#define VNNOFF_FILE_LIB     3

/* Data type */
#define VNNOFF_DATA_REGULAR 0
#define VNNOFF_DATA_ADDRESS 1
#define VNNOFF_DATA_SYMBOL  2

#endif
