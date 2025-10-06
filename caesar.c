#include <stdio.h>
#include <stdlib.h>
#include "caesar.h"

/* Shift a single uppercase letter by shift (can be negative).*/
static char shift_char(char c, int shift) {
  if (c >= 'A' && c <= 'Z') {
    int base = 'A';
    int pos = c - base;
    int newpos = (pos + shift) % 26;
    if (newpos < 0) newpos += 26;
    return (char)(base + newpos);
  }
  return c;
}

/* Allocate and return a new nul-terminated string with transformed chars.
   Caller must free the returned pointer. */
static char *transform(const char *input, int shift) {
  if (!input) return NULL;
  size_t len = 0;
  while (input[len]) ++len;
  char *out = malloc(len + 1);
  if (!out) return NULL;
  for (size_t i = 0; i < len; ++i)
    out[i] = shift_char(input[i], shift);
  out[len] = '\0';
  return out;
}

char *caesar_encrypt(char *plaintext) {
  return transform(plaintext, 3);
}

char *caesar_decrypt(char *ciphertext) {
  return transform(ciphertext, -3);
}
