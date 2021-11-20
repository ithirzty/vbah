# VBah
A graphic library in Bah, built on [Glut](https://www.opengl.org/resources/libraries/glut/) and [OpenGL](https://www.opengl.org/).

## Usage
Note that this includes libraries that are typically shared.
**You will need to add the `-d` option to compile your program.**

### Step 1 - Dependencies
Make sure you have [OpenGL](https://www.opengl.org/) and [Glut](https://www.opengl.org/resources/libraries/glut/) C libraries installed.

### Step 2 - Writting code
Make a new program `main.bah`.
```bah
#include "include.bah"
#include "vbah.bah"

main(args []cpstring) int {
    // Your Glut/OpenGL code here.
    return 0
}
```

### Step 3 - Compiling
Compile your program, `bah main.bah -d`.


## Examples
- [Particles](./examples/particles.bah), a simple particle system. <br> ![particles sreenshot](./screenshots/particles.png)
- [Textures](./examples/textures.bah), a demonstration of loading textures. <br> ![textures screenshot](./screenshots/textures.png)