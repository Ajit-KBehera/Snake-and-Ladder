# Installation and Testing Guide

## System Requirements

The modernized Snake & Ladder game requires:
- **Operating System**: macOS 10.12+, Ubuntu 18.04+, Windows 10+
- **Compiler**: GCC 7+ or Clang 5+
- **Graphics Libraries**: SDL2 and SDL2_ttf
- **Development Tools**: Make, pkg-config (optional)

## Installation Steps

### macOS

#### 1. Install Xcode Command Line Tools
```bash
xcode-select --install
```

#### 2. Install Homebrew (if not already installed)
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

#### 3. Install SDL2 Libraries
```bash
brew install sdl2 sdl2_ttf
```

#### 4. Verify Installation
```bash
pkg-config --cflags --libs sdl2
pkg-config --cflags --libs SDL2_ttf
```

### Ubuntu/Debian

#### 1. Update Package List
```bash
sudo apt-get update
```

#### 2. Install Development Tools
```bash
sudo apt-get install build-essential pkg-config
```

#### 3. Install SDL2 Libraries
```bash
sudo apt-get install libsdl2-dev libsdl2-ttf-dev
```

#### 4. Verify Installation
```bash
pkg-config --cflags --libs sdl2
pkg-config --cflags --libs SDL2_ttf
```

### Windows

#### 1. Install Visual Studio Community
- Download from: https://visualstudio.microsoft.com/vs/community/
- Install with "Desktop development with C++" workload

#### 2. Install SDL2
- Download SDL2 development libraries from: https://www.libsdl.org/download-2.0.php
- Extract to `C:\SDL2`
- Add `C:\SDL2\include` to Include Directories
- Add `C:\SDL2\lib\x64` to Library Directories
- Add `SDL2.lib` and `SDL2_ttf.lib` to Additional Dependencies

## Testing Compilation

### Test 1: Simple Console Version
```bash
# Compile the test version (no graphics)
cc -o snake_ladder_test snake_ladder_test.c

# Run the test
./snake_ladder_test
```

### Test 2: Full Graphics Version
```bash
# Compile with SDL2
cc -std=c99 -o snake_ladder_modern snake_ladder_modern.c -lSDL2 -lSDL2_ttf

# Or use the Makefile
make

# Run the game
./snake_ladder_modern
```

### Test 3: Using Makefile
```bash
# Install dependencies (choose your OS)
make install-deps-mac        # macOS
make install-deps-ubuntu     # Ubuntu/Debian

# Build and run
make run
```

## Troubleshooting

### Common Issues

#### 1. "stdio.h not found"
**Problem**: Missing SDK or development tools
**Solution**: 
- macOS: `xcode-select --install`
- Ubuntu: `sudo apt-get install build-essential`
- Windows: Install Visual Studio

#### 2. "SDL2/SDL.h not found"
**Problem**: SDL2 not installed
**Solution**: Install SDL2 libraries (see installation steps above)

#### 3. "undefined reference to SDL_*"
**Problem**: SDL2 libraries not linked
**Solution**: Add `-lSDL2 -lSDL2_ttf` to compilation flags

#### 4. Font rendering issues
**Problem**: TTF fonts not available
**Solution**: 
- Install system fonts
- Download Arial.ttf and place in game directory
- Check font paths in code

### Alternative Compilation Methods

#### Method 1: Direct Compilation
```bash
cc -std=c99 -I/usr/local/include -L/usr/local/lib \
   -o snake_ladder_modern snake_ladder_modern.c \
   -lSDL2 -lSDL2_ttf
```

#### Method 2: Using pkg-config
```bash
cc -std=c99 $(pkg-config --cflags --libs sdl2 SDL2_ttf) \
   -o snake_ladder_modern snake_ladder_modern.c
```

#### Method 3: Custom Makefile
```makefile
CC = cc
CFLAGS = -std=c99 -Wall -Wextra
LIBS = -lSDL2 -lSDL2_ttf
TARGET = snake_ladder_modern
SRC = snake_ladder_modern.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)

.PHONY: clean
```

## Verification Steps

### 1. Check Compiler
```bash
cc --version
gcc --version
clang --version
```

### 2. Check SDL2 Installation
```bash
# macOS
brew list | grep sdl

# Ubuntu
dpkg -l | grep sdl

# Check library paths
find /usr -name "SDL.h" 2>/dev/null
find /usr -name "SDL_ttf.h" 2>/dev/null
```

### 3. Test Simple SDL2 Program
Create `test_sdl.c`:
```c
#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    
    printf("SDL2 initialized successfully!\n");
    SDL_Quit();
    return 0;
}
```

Compile and run:
```bash
cc -o test_sdl test_sdl.c -lSDL2
./test_sdl
```

## Expected Output

### Successful Compilation
```
cc -std=c99 -o snake_ladder_modern snake_ladder_modern.c -lSDL2 -lSDL2_ttf
# No errors - compilation successful
```

### Successful Execution
```
./snake_ladder_modern
# Game window opens with welcome screen
# Menu appears with options 1, 2, 3
```

### Test Version Output
```
./snake_ladder_test
🎮 Welcome to Snake & Ladder Game!
Presented by: AJIT KUMAR BEHERA (CLASS-IX)

=== SNAKE & LADDER BOARD ===
100  99  98  97  96  95  94  93  92  91
 90  89  88  87  86  85  84  83  82  81
...
```

## Next Steps

1. **If compilation succeeds**: Run the game and test all features
2. **If compilation fails**: Check error messages and follow troubleshooting steps
3. **If runtime errors occur**: Check SDL2 installation and font availability
4. **For performance issues**: Consider using hardware acceleration flags

## Support

If you encounter issues not covered in this guide:
1. Check the error messages carefully
2. Verify all dependencies are installed
3. Try the test version first (no graphics)
4. Check system compatibility
5. Consider using a different compiler or version
