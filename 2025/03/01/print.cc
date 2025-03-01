#include <stdio.h>

struct myclass {
   long long a;
   char str[11];
   myclass(): a(60) {
      str[0] = 'h';
      str[1] = 'e';
      str[2] = 'l';
      str[3] = 'l';
      str[4] = 'o';
      str[5] = 'w';
      str[6] = 'o';
      str[7] = 'r';
      str[8] = 'l';
      str[9] = 'd';
      str[10] = '\0';
   }
};

int main() {
   myclass a;
   unsigned char *p = (unsigned char *)&a;
   for (int i = 0; i < sizeof(a); i++) {
      printf("%02x ", p[i]);
   }
   printf("\n");
   return 0;
}
