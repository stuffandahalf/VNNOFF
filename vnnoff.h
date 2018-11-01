#ifndef __VNNOFF_H
#define __VNNOFF_H

#include <stdint.h>
//#include "vnnoff_arch.h"

#define VNNOFF_BIG_ENDIAN 0
#define VNNOFF_LITTLE_ENDIAN 1

struct __attribute((packed)) vnnoff_hdr {
    uint8_t magic[5];
    uint8_t arch;
    uint8_t endianness;
    uint8_t os;
    uint8_t address_size;
    uint32_t relocation_table_location;
    uint32_t symbol_table_location;
};

#define symtab_entry(T) struct __attribute__((packed)) { T address; uint8_t visibility; char *symbol; }

struct data_entry {
    uint8_t type;
    size_t size;
    uint8_t *data;
};

#endif
