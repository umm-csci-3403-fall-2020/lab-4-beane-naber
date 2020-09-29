#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) { //Checks the given character if its a vowel or not
  if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u'){
    return true;
  } return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
  int index = 0;
  for (int i=0; i < num_chars - 1; i++) { //go through all charcters given
    if (is_vowel(in_buf[i]) == false){ //checks if those characters are vowels or not in the given in_buf
      out_buf[index] = in_buf[i]; //sets the out_buf to the items we found that are not vowels
      index++;
    }
  }
  return index;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {

}

int main(int argc, char *argv[]) {

  FILE *inputFile;
  FILE *outputFile;

  if (argc == 1) { // if we arent given an actual files, we take in what ever the user puts in the terminal
    inputFile = stdin;
    outputFile = stdout;
  }
  else if (argc == 2) { //if we are only given 1 file, we take that as the input and read it.
    inputFile = fopen(argv[1], "r");
    outputFile = stdout;
  }
  else if (argc == 3){ //if given two arguments, we take and read the first and take and write the second
    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");
  } else {
    printf("You have given me too many arguments! Please only give me at most two arguments."); //if we get two many, lets user know what they need to do instead and exits
    exit(0);
  }
  
  disemvowel(inputFile, outputFile);
  
  return 0;
}
