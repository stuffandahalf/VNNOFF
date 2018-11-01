#include "vnnoff.h"
#include <string.h>

void vnnoff_header_init(struct vnnoff_hdr *header, uint8_t arch, uint8_t endianness, uint8_t os, uint8_t address_size, size_t starting_address) {
    const char *magic = "VNNOFF";
    for (int i = 0; i < strlen(magic); i++) {
        header->magic[i] = magic[i];
    }
    
    header->arch = arch;
    header->endianness = endianness;
    header->os = os;
    header->address_size = address_size;
    header->starting_address = starting_address;
}
