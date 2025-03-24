#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib/peteste.h"

void fatal_err(char* msg){

  fprintf(stderr,"%s\n", msg);

  exit(1);
 
}

void usage(void){

  printf("Uso: readpe <arquivo.exe>\n");

  exit(1);
}


int main(int argc, char *argv[]){

  setlocale(LC_ALL, "pt_BR");
  
  if(argc != 2){

   usage();

  } 
  
  else{ 

  PEFILE pe;

  pe.filepath = argv[1];

  peteste_init(&pe);

  if(peteste_ispe(&pe)){
  
    printf("O arquivo '%s' é um executável PE.\n", pe.filepath);

  }
  else{
  
    fatal_err("O arquivo não é um executável PE.");
      
  }

  printf("File: %s\n\n", pe.filepath);

  printf("DOS Header\n");

  printf("    Magic number:                   0x%x (MZ)\n", pe.hdr_dos->e_magic);

  printf("    Bytes in last page:             %x\n", pe.hdr_dos->e_cblp);

  printf("    Pages in file:                  %x\n", pe.hdr_dos->e_cp);

  printf("    Relocations:                    %x\n", pe.hdr_dos->e_crlc);

  printf("    Size of header in paragraphs:   %x\n", pe.hdr_dos->e_cparhdr);

  printf("    Minimum extra paragraphs:       %x\n", pe.hdr_dos->e_minalloc);

  printf("    Maximum extra paragraphs:       %x\n", pe.hdr_dos->e_maxalloc);

  printf("    Initial (relative) SS value:    %x\n", pe.hdr_dos->e_ss);

  printf("    Initial SP value:               0x%x\n", pe.hdr_dos->e_sp);

  printf("    Initial IP value:               %x\n", pe.hdr_dos->e_ip);

  printf("    Initial (relative) CS value:    %x\n", pe.hdr_dos->e_cs);

  printf("    Address of relocation table:    0x%x\n", pe.hdr_dos->e_lfatlc);

  printf("    Overlay number:                 %x\n", pe.hdr_dos->e_ovno);

  printf("    OEM identifier:                 %x\n", pe.hdr_dos->e_oemid);

  printf("    OEM information:                %x\n", pe.hdr_dos->e_oeminfo);
  
  printf("    PE header offset:               0x%x\n", pe.hdr_dos->e_lfanew);

  printf("COFF/File header\n");
 
  peteste_deinit(&pe);

  }


return 0;
}
