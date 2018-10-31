#ifndef __VNNOFF_H
#define __VNNOFF_H

#include <stdint.h>
#include "vnnoff_arch.h"

#define VNNOFF_BIG_ENDIAN 0
#define VNNOFF_LITTLE_ENDIAN 1

struct vnnoff_hdr {
    uint8_t magic[5];
    uint8_t arch;
    uint8_t endianness;
    uint8_t os;
    uint8_t address_size;
    uint32_t relocation_table_location;
    uint32_t symbol_table_location;
}

struct symtab_entry {
    uint8_t *address;
    uint8_t visibility;
    char *symbol;
}

struct data_entry {

}

#endif
