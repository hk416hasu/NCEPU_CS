#include <stdio.h>
#include <stdlib.h>

int main() {
  char ch;
  char *p = &ch;
  scanf("%c", &ch);
  scanf("%c", &ch);

  int octal = 0;
  while (scanf("%c", &ch) && ch != '\n') {
    switch(ch) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        octal = octal * 16 + atoi(p);
        break;
      case 'A':
        octal = octal * 16 + 10;
        break;
      case 'B':
        octal = octal * 16 + 11;
        break;
      case 'C':
        octal = octal * 16 + 12;
        break;
      case 'D':
        octal = octal * 16 + 13;
        break;
      case 'E':
        octal = octal * 16 + 14;
        break;
      case 'F':
        octal = octal * 16 + 15;
        break;
    default: 
        break;
    }
  }

  printf("%d\n", octal);
  return 0;
}
