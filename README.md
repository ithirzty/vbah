# VBah
A graphic library in Bah, built on [Glut](https://www.opengl.org/resources/libraries/glut/) and [OpenGL](https://www.opengl.org/).

## Usage
Note that this includes libraries that are typically shared.
**You will need to add the `-d` option to compile your program.**

### Step 1
Make sure you have [OpenGL](https://www.opengl.org/) and [Glut](https://www.opengl.org/resources/libraries/glut/) C libraries installed.

### Step 2
Make a new program.
```bah
#include "include.bah"
#include "vbah.bah"

main(args []cpstring) int {
    // Your Glut/OpenGL code here.
    return 0
}
```

### Step 3
Compile your program, `bah main.bah -d`.


## Examples
- [particles](./examples/particles.bah) (simple particle system)