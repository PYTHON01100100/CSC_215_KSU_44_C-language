#include <stdio.h>
#include <stdlib.h>
#include "prog.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(){
 FileStats* fsp;
 fsp = process_file("wcs.txt");
 char** lines;
 lines = get_lines("wcs.txt");

// read_file("wcs.txt");
//write_file("wcs1.txt");
//textToBinary("wcs1.txt");
//printBinaryFile("wcs1.txt");

  if (fsp){
    printf("File size = %d\n", fsp->total_chars);
    printf("Number of letters = %d\n", fsp->letters_count);
    printf("Number of Words = %d\n", fsp->words_count);
    printf("Number of lines = %d\n", fsp->lines_count);
    printf("Length of longest line = %d\n", fsp->max_line_length);
  }

  write_rev("wcs-rev1.txt", lines, fsp->lines_count);
    
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

  // Allocate memory for a new FileStats struct
  if (!(fs = (FileStats*)calloc(1, sizeof(FileStats)))) return NULL;

  // Open the file for reading
  if (!(fp = fopen(fn, "r"))) return NULL;

  // Loop over each character in the file
  do { 
    c=getc(fp);
    fs->total_chars++;

    // If the character is a letter, increment the letter count and set the inword flag
    if (is_letter(c)){
      fs->letters_count++;
      inword = 1;
    }
    // If the character is not a letter, increment the word count if we're in a word, and clear the inword flag
    else {
      if (inword) fs->words_count++;
      inword = 0;
    }

    // If the character is a newline or end-of-file, increment the line count, update the max line length, and reset the line length counter
    if (c == '\n' || c == EOF){
      fs->lines_count++;
      if (fs->max_line_length < line_length)
        fs->max_line_length = line_length;
      line_length = 0;  
    }
    // Otherwise, increment the line length counter
    else line_length++;
    
  } while (c != EOF);

  // Close the file
  fclose(fp);

  // Return the FileStats struct
  return fs;
}
char** get_lines(char* fn){
  char c;
  int i;
  char **lines, *p;
  
  // Allocate memory for a new FileStats struct and check if the allocation was successful
  FileStats* fs;
  if (!(fs = process_file(fn))) return NULL;
 
  // Allocate memory for the lines array
  lines = (char**)calloc(fs->lines_count, sizeof(char*));
  for (i=0; i < fs->lines_count; i++)
    lines[i] = (char*)calloc(fs->max_line_length+1, 1);

  // Open the file for reading and check if the file was opened successfully
  FILE* fp;
  if (!(fp = fopen(fn, "r"))) return NULL;

  // Loop over each character in the file and copy each line into a separate row of the lines array
  i = 0; 
  p = lines[0];
  do {
    c = getc(fp);
    if (c == '\n' || c == EOF)
      p = lines[++i];
    else
      *p++ = c;
  } while (c != EOF);

  // Close the file
  fclose(fp);

  // Return the lines array
  return lines;
}


void read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}
void write_file(char* filename) {
    FILE* file = fopen(filename, "a"); // open file in append mode
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    fputs("This text was added to the file.\n", file);

    fclose(file);
}
void textToBinary(char* filename) {
    FILE* text_file = fopen(filename, "r");
    if (text_file == NULL) {
        printf("Error: could not open text file %s\n", filename);
        return;
    }

    FILE* binary_file = fopen("output.bin", "wb");
    if (binary_file == NULL) {
        printf("Error: could not create binary file\n");
        fclose(text_file);
        return;
    }

    char buffer[1024];
    size_t read_size;
    while ((read_size = fread(buffer, 1, sizeof(buffer), text_file)) > 0) {
        fwrite(buffer, 1, read_size, binary_file);
    }

    fclose(text_file);
    fclose(binary_file);
}
void printBinaryFile(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open binary file %s\n", filename);
        return;
    }

    char buffer[1024];
    size_t read_size;
    while ((read_size = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < read_size; i++) {
            unsigned char byte = buffer[i];
            for (int j = 7; j >= 0; j--) {
                printf("%d", (byte >> j) & 1);
            }
            printf(" ");
        }
    }
    fclose(file);
}
int isVowel(char c) {
    return c == 'a' || c == 'A' ||
           c == 'e' || c == 'E' ||
           c == 'i' || c == 'I' ||
           c == 'o' || c == 'O' ||
           c == 'u' || c == 'U';
}

void replaceThe(char* filename) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    char buffer[1024];
    char word[1024];
    char prev_word[1024] = "";
    while (fscanf(file, "%1023s", word) == 1) {
        if (strcmp(prev_word, "the") == 0) {
            if (strlen(word) > 0 && isVowel(word[0])) {
                fseek(file, -3, SEEK_CUR);
                fprintf(file, "an");
            } else {
                fseek(file, -3, SEEK_CUR);
                fprintf(file, "a");
            }
        }
        strcpy(prev_word, word);
    }

    fclose(file);
}

void write_rev(char* fn, char** lines, int count){
  int i;  

  // Open the file for writing and check if the file was opened successfully
  FILE* fp = fopen(fn, "w");
  if (!fp) return;

  // Loop over each line in the lines array in reverse order and write it to the file
  for (i=count-1; i >= 0; i--){
    fputs(lines[i], fp);
    if (i) 
    fprintf(fp, "\n");
  }

  // Close the file
  fclose(fp);
}