/*
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
 *
 */

#include <stdlib.h>
#include <stdio.h>
// Array Wizard: the MAGIC_ARRAY generator!
int main(int argc, char *argv[]) {
  int max_size = 256, i;
  if (argc == 2) max_size = atoi(argv[1]);
  printf("#define _COUNT_ARGS(...) _COUNT_ARGS_(,##__VA_ARGS__");
  for (i = max_size; i >= 0; --i) printf(",%i", i);
  printf(")\n#define _COUNT_ARGS_(");
  for (i = 0; i <= max_size; ++i) printf("_%i,", i);
  printf("cnt,...) cnt\n#define MAGIC_ARRAY(...) {_COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__}\n");
  return 0;
}
