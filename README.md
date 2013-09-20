magicarray
==========

Macro and macro generator for array size inside an array in C.

Only works for __C99__.

Using the macro
---------------

    #include <stdio.h>
    #include "magicarray.h"
    int main() {
      const int abcd[] = MAGIC_ARRAY(1, 2, 3, 4, 5, 666, 777, 888, 999);
      printf("%li\n", sizeof(abcd) / sizeof(*abcd) - 1);
      printf("%li\n", (long) *abcd);
      return 0;
    }

Should print the same if the MAGIC\_ARRAY has a large enough max\_size.


Generating a macro
------------------

Compile `arraywizard.c` to `arraywizard` for instance.

The following will generate the standard header with max supported size of 255.

    ./arraywizard > magicarray.h

To generate a header with a larger size:

    ./arraywizard 1024 > magicarray.h


License
-------

None: public domain. Do what you want, go to [unlicense.org](http://unlicense.org/)
for more info.
