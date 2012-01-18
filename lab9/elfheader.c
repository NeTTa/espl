#include <stdio.h>
#include <elf.h>

int main(int argc, char** argv) {
  Elf32_Ehdr header; //Header
  FILE *fin;
  int sFlag = 0;
  int opt;
  char *optstring = "S";
  for (opt=getopt(argc, argv, optstring); opt != -1; opt = getopt(argc, argv, optstring)) {
    switch (opt) {
      case 'S':
    sFlag = 1;
    break;
      default:
    //do nothing;
    break;
    }
  }
 
  if (sFlag == 1)
      fin = fopen(argv[2],"r");
  else
      fin = fopen(argv[1],"r");
 
  //If only the program name was entered.
  if (argc < 2) {
    printf("Syntax: elfheader FILE\n");
    return 0;
  }
 
  //When problem loading page:
  if (fin == NULL) {
    printf("Problem read file.\n");
    return 0;
  }
 
  fread(&header,sizeof(header),1,fin);
 
  //Class:
  if (sFlag == 1) {
      Elf32_Shdr sheader; //Section header
      
      
      //shtrndx points to names list
      char names[1000];
      //Seek for the position where the names start:
      fseek(fin,header.e_shoff + (header.e_shentsize*header.e_shstrndx),SEEK_SET);
      //read the position of that value:
      fread(&sheader,sizeof(sheader),1,fin);
      
      //get the offset between the names.
      int names_offset = sheader.sh_offset;
      fseek(fin,names_offset,SEEK_SET); //move to the place of the names
      //Read the names from the file to names array:
      fread(&names,sizeof(names),1,fin);
      
      //Extract the names:
      
      
      int j;
      for (j=0; j < header.e_shnum; j++) {
    fseek(fin,header.e_shoff + (header.e_shentsize * j),SEEK_SET);
    fread(&sheader,sizeof(sheader),1,fin);
    printf("[%02i] %s\t%i\n",j,names+sheader.sh_name,sheader.sh_type);
      }
      fseek(fin,header.e_shoff + (header.e_shentsize * j),SEEK_SET);
    
  } else {
 
    //Magic:
    int i = 0;
    char str_ident[48];
    for (i=0; i<EI_NIDENT; ++i) {
    sprintf(str_ident + (i*3), "%02x ", header.e_ident[i]);
    }
    
    printf("ELF Header:\n");
    printf("Magic:   %s\n", str_ident);    

    printf("\n");    
    printf("Class:\t%u\n",header.e_ident[4]);
  }
 
  return 0;
}