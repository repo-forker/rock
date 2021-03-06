#ifndef ELF_H_
#define ELF_H_

#include <mm/vmm.h>

#define ELF_SIGNATURE 0x464C457F
#define ELF64 2

#define	EI_CLASS 4
#define EI_DATA 5
#define	EI_VERSION 6
#define	EI_OSABI 7

#define ABI_SYSTEM_V 0
#define ABI_LINUX 3

#define LITTLE_ENDIAN 1
#define MACH_X86_64 0x3e

struct elf_hdr {
    uint8_t ident[16];
    uint16_t type;
    uint16_t machine;
    uint32_t version;
    uint64_t entry;
    uint64_t phoff;
    uint64_t shoff;
    uint32_t flags;
    uint16_t hdr_size;
    uint16_t phdr_size;
    uint16_t ph_num;
    uint16_t shdr_size;
    uint16_t sh_num;
    uint16_t shstrndx;
} __attribute__((packed));

#define PT_NULL 0
#define PT_LOAD 1
#define PT_DYNAMIC 2
#define PT_INTERP 3
#define PT_NOTE 4
#define PT_SHLIB 5
#define PT_PHDR 6
#define PT_LTS 7
#define PT_LOOS 0x60000000
#define PT_HIOS 0x6FFFFFFF
#define PT_LOPROC 0x70000000
#define PT_HIPROC 0x7FFFFFFF


#define AT_ENTRY 10
#define AT_PHDR 20
#define AT_PHENT 21
#define AT_PHNUM 22

struct aux {
    uint64_t at_entry;
    uint64_t at_phdr;
    uint64_t at_phent;
    uint64_t at_phnum;
};

struct elf64_phdr {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
};

struct elf64_shdr {
    uint32_t sh_name;
    uint32_t sh_type;
    uint64_t sh_flags;
    uint64_t sh_addr;
    uint64_t sh_offset;
    uint64_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint64_t sh_addr_align;
    uint64_t sh_entsize;
};

int elf64_load(struct page_map *page_map, struct aux *aux, int fd, uint64_t base, char **ld_path);

#endif
