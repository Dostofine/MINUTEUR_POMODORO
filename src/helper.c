#include "helper.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL 0
#define SUCC 1
#define TRAN 2
#define EMPTY -1
#define N_DIGIT -2
#define N_ONE_DIGIT -3

#define DEFAULT 1
#define COSTUM 2

// Read a line safely. without intterupting next input functions.
int read_line(char *str, int size) {

  int len;
  int c;

  // `str' should contain at least room for one character
  if (str == NULL || size < 2) {
    return FAIL;
  }

  if (fgets(str, size, stdin) == NULL) {
    return FAIL;
  }

  len = strcspn(str, "\n");

  // - if '\n' is found in str
  if (str[len] == '\n') {
    // terminate '\0' in place of '\n'.
    str[len] = '\0';
    // Success
    return SUCC;
  }

  // - else clean leftover in `stdin`
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  // Success with trancate
  return TRAN;
}

// Read a integer.
int read_int(unsigned int *var) {
  char buffer[20];
  int len;

  if (var == NULL) {
    return FAIL;
  }

  if (read_line(buffer, sizeof(buffer)) == FAIL) {
    return FAIL;
  }

  len = strlen(buffer);
  if (len == 0) {
    return EMPTY;
  }

  for (int i = 0; i < len; i++) {
    // behavior is undefined if buffer[i] a negative char
    if (!isdigit((unsigned char)buffer[i])) {
      return N_DIGIT;
    }
  }

  // TODO
  *var = atoi(buffer);

  return SUCC;
}

int read_digit(int *var) {
  char buffer[20];
  int len;

  if (var == NULL) {
    return FAIL;
  }

  if (read_line(buffer, sizeof(buffer)) == FAIL) {
    return FAIL;
  }

  len = strlen(buffer);
  if (len == 0) {
    return EMPTY;
  }

  if (len != 1)
    return N_ONE_DIGIT;

  if (!isdigit((unsigned char)buffer[0])) {
    return N_DIGIT;
  }

  *var = buffer[0] - '0';

  return SUCC;
}
