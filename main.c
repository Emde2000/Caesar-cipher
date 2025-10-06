#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  for (size_t i = 0; i < argc; ++i)
    puts(argv[i]);

  /* Demonstration of encryption/decryption using the provided functions. */
  /* This part uses caesar.h functions; you can modify or remove it as needed. */
  extern char *caesar_encrypt(char *plaintext);
  extern char *caesar_decrypt(char *ciphertext);

  char sample[] = "COFFEE, IS LIFE! 123"; // Example input
  char *enc = caesar_encrypt(sample);
  if (!enc) {
    fprintf(stderr, "Encryption failed\n");
    return 1;
  }
  printf("Plain : %s\n", sample);
  printf("Encrypt: %s\n", enc);

  char *dec = caesar_decrypt(enc);
  if (!dec) {
    fprintf(stderr, "Decryption failed\n");
    free(enc);
    return 1;
  }
  printf("Decrypt: %s\n", dec);

  free(enc);
  free(dec);
  return 0;
}
