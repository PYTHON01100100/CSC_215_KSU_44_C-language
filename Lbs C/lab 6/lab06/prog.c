#include <stdio.h>
#include <stdlib.h>
#include "prog.h"

void writeTextFile(FileStats* stats , char* filename){
FILE* file = fopen(filename,"w");
if(file==NULL){
printf("Error opening file!\n");
return;

}
fprintf(file," total_chars = %d\n Number of letters =%d\n Number of Words = %d\n Number of lines = %d\n Length of longest line = %d\n" , stats->total_chars,stats->letters_count,stats->words_count,stats->lines_count ,stats->max_line_length);


fclose(file);

}
void writeBinaryFile(FileStats* stats ,char* filename){
FILE* file = fopen(filename,"w");
printf("%p",file);
if(file!=NULL){
if(fwrite(file,sizeof(FileStats),1,stats))
fclose(file);
}
return;


}
int main(){
FileStats*fsp;
  fsp = process_file("wcs.txt");

writeTextFile(fsp,"wcs-stats.txt");

writeBinaryFile(fsp,"wcs-stats.dat");
return 0;



}

int is_letter(char c){
  return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

FileStats* process_file(char* fn){
  FileStats* fs;
  FILE* fp;
  char c;
  int inword = 0;
  int line_length = 0;

  if (!(fs = (FileStats*)calloc(1, sizeof(FileStats)))) return NULL;

  if (!(fp = fopen(fn, "r"))) return NULL;

  do {
    c=getc(fp);
    fs->total_chars++;

    if (is_letter(c)){
      fs->letters_count++;
      inword = 1;
    }
    else {
      if (inword) fs->words_count++;
      inword = 0;
    }

    if (c == '\n' || c == EOF){
      fs->lines_count++;
      if (fs->max_line_length < line_length)
        fs->max_line_length = line_length;
      line_length = 0;  
    }
    else line_length++;
   
  } while (c != EOF);
  fclose(fp);
  return fs;
}

char** get_lines(char* fn){
  char c;
  int i;
  char **lines, *p;
 
  FileStats* fs;
  FILE* fp;

  if (!(fs = process_file(fn))) return NULL;
 
  lines = (char*)calloc(fs->lines_count, sizeof(char));
  for (i=0; i < fs->lines_count; i++)
    lines[i] = (char*)calloc(fs->max_line_length+1, 1);

  if (!(fp = fopen(fn, "r"))) return NULL;

  i = 0;
  p = lines[0];
  do {
    c = getc(fp);
    if (c == '\n' || c == EOF)
      p = lines[++i];
    else
      *p++ = c;
  } while (c != EOF);
  return lines;
}

void write_rev(char* fn, char** lines, int count){
  int i;  
  FILE* fp = fopen(fn, "w");
  for (i=count-1; i >= 0; i--){
    fputs(lines[i], fp);
    if (i) fprintf(fp, "\n");
  }
  fclose(fp);
}