typedef struct {
  int total_chars;
  int letters_count;
  int words_count;
  int lines_count;
  int max_line_length;
} FileStats;
/*Return 1 if param is a letter and 0 otherwise*/
int is_letter(char);
/*takes a file name as a string parm
and returns a pointer to filestats strct or NULL on fail.
*/
FileStats* process_file(char*);
/*
takes a file name as a string parm
and returns an array contains all the lines of the file, or null on fail.
*/
char** get_lines(char*);
/*assiment: 
Which takes a filename as a string parameter, an array of strings and the number of strings as an integer, and
stores the strings in a text file called filename in a reversed order (i.e the first string should be the last line of
the file, … ).
*/
void write_rev(char*, char**, int);