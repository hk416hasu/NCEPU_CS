#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(void) {
  FILE *tty = popen("tty", "r");
  char ttyBuffer[16];
  assert(fgets(ttyBuffer, sizeof(ttyBuffer), tty) != NULL);

  ttyBuffer[strcspn(ttyBuffer, "\n")] = '\0';

  char helloBuffer[64];
  snprintf(helloBuffer, sizeof(helloBuffer), "echo Hello World from popen > %s", ttyBuffer);

  popen(helloBuffer, "r");

  return 0;
}
