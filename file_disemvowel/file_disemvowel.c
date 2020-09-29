#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) { //Checks the given character if its a vowel or not
  if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u'){
    return true;
  } return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {

}

void disemvowel(FILE* inputFile, FILE* outputFile) {

}

int main(int argc, char *argv[]) {

  disemvowel(inputFile, outputFile);
  
  return 0;
}
