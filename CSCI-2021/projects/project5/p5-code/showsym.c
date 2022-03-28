// Template for parsing an ELF file to print its symbol table
// UPDATED: Tue Dec  8 03:27:18 PM CST 2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <elf.h>

// The below macros help to prevent errors when doing pointer
// arithmetic. Adding an offset to a pointer is the most common
// operation here while the other macros may not be needed.

#define PTR_PLUS_BYTES(ptr,off) ((void *) (((size_t) (ptr)) + ((size_t) (off))))
// macro to add a byte offset to a pointer, arguments are a pointer
// and a # of bytes (usually size_t)

#define PTR_MINUS_BYTES(ptr,off) ((void *) (((size_t) (ptr)) - ((size_t) (off))))
// macro to subtract a byte offset from a pointer, arguments are a pointer
// and a # of bytes (usually size_t)

#define PTR_MINUS_PTR(ptr,ptq) ((long) (((size_t) (ptr)) - ((size_t) (ptq))))
// macro to subtract one pointer from another

int DEBUG = 0;
// Controls whether to print debug messages
// Can be used in conditionals like if(DEBUG){ ... }
// and running 'showsym -d x.o' will set DEBUG=1

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("usage: %s [-d] <file>\n",argv[0]);
    return 0;
  }

  char *objfile_name = argv[1];

  // check for debug mode
  if(argc >=3){
    if(strcmp("-d",argv[1])==0){
      DEBUG = 1;
      objfile_name = argv[2];
    }
    else{
      printf("incorrect usage\n");
      return 1;
    }
  }

  // Open file descriptor and set up memory map for objfile_name
  int fd = open(objfile_name, O_RDONLY);
  struct stat stat_buf;
  fstat(fd, &stat_buf);
  int size = stat_buf.st_size;

  // CREATE A POINTER to the intial bytes of the file which are an ELF64_Ehdr struct
  Elf64_Ehdr *ehdr = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);

  // CHECK e_ident field's bytes 0 to for for the sequence {0x7f,'E','L','F'}.
  if(ehdr->e_ident[0] != 0x7f || ehdr->e_ident[1] != 'E' || ehdr->e_ident[2] != 'L' || ehdr->e_ident[3] != 'F'){
    printf("ERROR: Magic bytes wrong, this is not an ELF file");
    return 1;
  }
  // Exit the program with code 1 if the bytes do not match


  // PROVIDED: check for a 64-bit file
  if(ehdr->e_ident[EI_CLASS] != ELFCLASS64){
    printf("Not a 64-bit file ELF file\n");
    return 1;
  }

  // PROVIDED: check for x86-64 architecture
  if(ehdr->e_machine != EM_X86_64){
    printf("Not an x86-64 file\n");
    return 1;
  }

  // DETERMINE THE OFFSET of the Section Header Array (e_shoff), the
  // number of sections (e_shnum), and the index of the Section Header
  // String table (e_shstrndx). These fields are from the ELF File
  // Header.
  int e_shoff = ehdr->e_shoff;
  int e_shnum = ehdr->e_shnum;
  int e_shstrndx = ehdr->e_shstrndx;

  // Set up a pointer to the array of section headers. Use the section
  // header string table index to find its byte position in the file
  // and set up a pointer to it.

  Elf64_Shdr *sec_hdrs = PTR_PLUS_BYTES(ehdr, e_shoff);;
  uint64_t offset0 = sec_hdrs[e_shstrndx].sh_offset;
  char *sec_names = PTR_PLUS_BYTES(ehdr, offset0);

  // Search the Section Header Array for the secion with name .symtab
  // (symbol table) and .strtab (string table).  Note their positions
  // in the file (sh_offset field).  Also note the size in bytes
  // (sh_size) and and the size of each entry (sh_entsize) for .symtab
  // so its number of entries can be computed.

  //creating variables to save symtable information
  long offset1;
  long size1;
  long entsize1;

  //creating a variable to save the offset of strtable
  long offset2;

  //booleans to determine if the symtable or strtable exist
  int symtab_exists = 0;
  int strtab_exists = 0;

  for(int i=0; i<e_shnum; i++){
    if(strcmp(sec_names + sec_hdrs[i].sh_name, ".symtab") == 0){
      offset1 = sec_hdrs[i].sh_offset;
      size1 = sec_hdrs[i].sh_size;
      entsize1 = sec_hdrs[i].sh_entsize;
      symtab_exists = 1;
    }
    if(strcmp(sec_names + sec_hdrs[i].sh_name, ".strtab") == 0){
      offset2 = sec_hdrs[i].sh_offset;
      strtab_exists = 1;
    }
  }

  if(symtab_exists == 0){
    printf("ERROR: Couldn't find symbol table\n");
    return 1;
  }

  if(strtab_exists == 0){
    printf("ERROR: Couldn't find string table\n");
    return 1;
  }

  // PRINT byte information about where the symbol table was found and
  // its sizes. The number of entries in the symbol table can be
  // determined by dividing its total size in bytes by the size of
  // each entry.
  printf("Symbol Table\n");
  printf("- %ld bytes offset from start of file\n", offset1);
  printf("- %ld bytes total size\n", size1);
  printf("- %ld bytes per entry\n", entsize1);
  printf("- %ld entries\n", (size1 / entsize1));


  // Set up pointers to the Symbol Table and associated String Table
  // using offsets found earlier.
  Elf64_Sym *symtable_entry = PTR_PLUS_BYTES(ehdr, offset1);
  char *strtable_entry = PTR_PLUS_BYTES(ehdr, offset2);


  // Print column IDs for info on each symbol
  printf("[%3s]  %8s %4s %s\n",
         "idx","TYPE","SIZE","NAME");

  // Iterate over the symbol table entries
  for(int i=0; i<(size1 / entsize1); i++){
    // Determine size of symbol and name. Use <NONE> name has zero
    // length.
    long unsigned int size_offset = symtable_entry[i].st_size;
    // long *size_pointer = strtable_entry + size_offset
    int name_offset = symtable_entry[i].st_name;
    char *name_pointer = strtable_entry + name_offset;
    if(strlen(name_pointer) == 0){
      name_pointer = "<NONE>";
    }
    // Determine type of symbol. See assignment specification for
    // fields, macros, and definitions related to this.
    unsigned char typec = ELF64_ST_TYPE(symtable_entry[i].st_info);
    char *type_pointer = "<NONE>";
    if(typec == STT_NOTYPE){
      type_pointer = "NOTYPE";
    }
    else if(typec == STT_OBJECT){
      type_pointer = "OBJECT";
    }
    else if(typec == STT_FUNC){
      type_pointer = "FUNC";
    }
    else if(typec == STT_FILE){
      type_pointer = "FILE";
    }
    else if(typec == STT_SECTION){
      type_pointer = "SECTION";
    }
    // Print symbol information
    printf("[%3d]: %8s %4lu %s\n", i, type_pointer, size_offset, name_pointer);
  }


  // Unmap file from memory and close associated file descriptor
  munmap(ehdr, size);
  close(fd);
  return 0;
}
