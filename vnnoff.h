#ifndef __VNNOFF_H
#define __VNNOFF_H

#include <stddef.h>
#include <stdint.h>
//#include "vnnoff_arch.h"

/*static const uint8_t VNNOFF_MAGIC[6] = { 'V', 'N', 'N', 'O', 'F', 'F' };*/

#define VNNOFF_BIG_ENDIAN 0
#define VNNOFF_LITTLE_ENDIAN 1

struct vnnoff_hdr {
    uint8_t magic[6];
    uint8_t arch;
    uint8_t endianness;
    uint8_t os;
    uint8_t address_size;
    size_t starting_address;
    //uint32_t relocation_table_location;
    uint32_t symbol_table_location;
} __attribute((packed));

/*#define symtab_entry(T) struct __attribute__((packed)) { T address; uint8_t visibility; char *symbol; }

typedef symtab_entry(uint8_t) symtab_entryb;
typedef symtab_entry(uint16_t) symtab_entryw;
typedef symtab_entry(uint32_t) symtab_entryl;
typedef symtab_entry(uint64_t) symtab_entryq;*/

struct symtab_entry {
    uint8_t *address;
    uint8_t visibility;
    char *symbol;
};

#define VNNOFF_DATA_REGULAR 0
#define VNNOFF_DATA_ADDRESS 1

struct data_entry {
    uint8_t type;
    size_t size;
    uint8_t *data;
};

void vnnoff_header_init(struct vnnoff_hdr *header, uint8_t arch, uint8_t endianness, uint8_t os, uint8_t address_size, size_t starting_address);

#endif
