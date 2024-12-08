#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc != 2) { puts("give me 1 arg"); return 0; }

  char *s = argv[1];
  
  char ch;
  int sum = 0;

  while (sscanf(s, "%c", &ch) != EOF) {
    s++;
    switch (ch) {
      case 'I':
        sum += 1;
        if (sscanf(s, "%c", &ch) != EOF) {
          if (ch == 'V') { s++; sum += 3; }
          if (ch == 'X') { s++; sum += 8; }
        }
        break;
      case 'V': sum += 5   ; break;
      case 'X':
        sum += 10;
        if (sscanf(s, "%c", &ch) != EOF) {
          if (ch == 'L') { s++; sum += 30; }
          if (ch == 'C') { s++; sum += 80; }
        }
        break;
      case 'L': sum += 50  ; break;
      case 'C':
        sum += 100;
        if (sscanf(s, "%c", &ch) != EOF) {
          if (ch == 'D') { s++; sum += 300; }
          if (ch == 'M') { s++; sum += 800; }
        }
        break;
      case 'D': sum += 500 ; break;
      case 'M': sum += 1000; break;
      default: break;
    }
  }
  printf("%d\n", sum);
  return 0;
}
