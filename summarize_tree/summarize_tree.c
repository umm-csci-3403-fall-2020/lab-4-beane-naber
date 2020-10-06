#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

static int num_dirs, num_regular;

bool is_dir(const char* path) {
  struct stat *bstat = malloc(sizeof(struct stat)); // allocates memory

  if (stat(path, bstat)) {
    free(bstat);
    return false;
  } else {
    bool is_dir = S_ISDIR(bstat -> st_mode);
    free(bstat);
    return is_dir;
  }
  
}

/* 
 * I needed this because the multiple recursion means there's no way to
 * order them so that the definitions all precede the cause.
 */
void process_path(const char*);

void process_directory(const char* path) {

  chdir(path); //moves us to the path that we are suppose to be searching
  struct dirent *dt;
  DIR *dir = opendir("."); //opens our current directory

  if (!dir) { // this just checks to see if the given directory doesnt exist.
    return;
  }

  num_dirs++; //increments the number of directories by one.

  while ((dt = readdir(dir)) != NULL){ //reads everything in the given directory until nothing is left to read.
    if (strcmp(dt -> d_name,".") != 0 && strcmp(dt -> d_name,"..") != 0){ //checks if the two are the same
      process_path(dt -> d_name);
    }
  }

  closedir(dir); //closes the directory that we called
  chdir(".."); //backs out of the directory
  free(dt);
}

void process_file(const char* path) {
  num_regular++;
}

void process_path(const char* path) {
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]); //prints if the script was called but no arguments were given
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
