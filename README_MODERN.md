# Snake & Ladder Game - Modernized Version

This is a modernized version of the classic Snake & Ladder game, updated to work on current operating systems using SDL2 graphics library.

## Features

- **Cross-platform compatibility** - Works on Windows, macOS, and Linux
- **Modern graphics** - Uses SDL2 instead of obsolete DOS graphics
- **Improved user interface** - Better text rendering and colors
- **All original game mechanics** - Same snakes, ladders, and gameplay
- **Input validation** - Proper error handling for invalid inputs

## Prerequisites

### macOS
```bash
brew install sdl2 sdl2_ttf
```

### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install libsdl2-dev libsdl2_ttf-dev
```

### CentOS/RHEL
```bash
sudo yum install SDL2-devel SDL2_ttf-devel
```

### Windows
- Download SDL2 development libraries from https://www.libsdl.org/
- Install Visual Studio or MinGW

## Building and Running

### Quick Start
```bash
# Install dependencies (choose your OS)
make install-deps-mac        # macOS
make install-deps-ubuntu     # Ubuntu/Debian
make install-deps-centos     # CentOS/RHEL

# Build and run
make run
```

### Manual Build
```bash
# Build the game
make

# Run the game
./snake_ladder_modern
```

## Game Instructions

1. **Two players** take turns rolling dice
2. **Enter dice roll** (1-6) when prompted
3. **Snakes** will move you down to lower positions
4. **Ladders** will move you up to higher positions
5. **First player to reach 100** wins!

### Snake and Ladder Positions

**Snakes (move down):**
- 60 → 30
- 94 → 1
- 82 → 17
- 36 → 7
- 99 → 3
- 97 → 32

**Ladders (move up):**
- 27 → 98
- 43 → 66
- 7 → 77
- 33 → 85
- 49 → 93
- 14 → 61

## Files

- `snake_ladder_modern.c` - Modernized version using SDL2
- `snake&ladder.c` - Original version (requires DOS/Turbo C)
- `snake&ladder_original_backup.c` - Backup of original
- `Makefile` - Build configuration
- `README_MODERN.md` - This file

## Differences from Original

### Fixed Issues
- ✅ Fixed coordinate bugs in drawing functions
- ✅ Fixed text positioning outside screen bounds
- ✅ Added proper input validation
- ✅ Changed `void main()` to `int main()`
- ✅ Added return statement

### Modernizations
- 🔄 Replaced `graphics.h` with SDL2
- 🔄 Replaced `conio.h` with standard I/O
- 🔄 Replaced `dos.h` with cross-platform alternatives
- 🔄 Added proper font rendering with TTF
- 🔄 Improved color system
- 🔄 Better error handling

### Removed Dependencies
- ❌ `graphics.h` (DOS graphics)
- ❌ `conio.h` (console I/O)
- ❌ `dos.h` (DOS system calls)
- ❌ `process.h` (process control)
- ❌ Hardcoded DOS paths

## Troubleshooting

### Font Issues
If text doesn't display properly, the game will try to find system fonts automatically. You can also:
1. Download Arial.ttf and place it in the game directory
2. Install system fonts: `sudo apt-get install ttf-mscorefonts-installer` (Ubuntu)

### Compilation Errors
- Make sure SDL2 and SDL2_ttf are installed
- Check that your compiler supports C99 standard
- On Windows, ensure SDL2 libraries are in your PATH

### Runtime Errors
- Ensure SDL2 runtime libraries are available
- Check that you have proper graphics drivers
- Try running with `sudo` if permission issues occur

## Original vs Modern

| Feature | Original | Modern |
|---------|----------|--------|
| Platform | DOS only | Cross-platform |
| Graphics | BGI library | SDL2 |
| Fonts | Built-in | TTF fonts |
| Colors | 16 colors | Full RGB |
| Input | `getch()` | Standard I/O |
| Sound | PC speaker | SDL audio |
| Compilation | Turbo C | GCC/Clang |

## Contributing

Feel free to improve the game by:
- Adding sound effects
- Improving graphics
- Adding animations
- Creating better AI opponents
- Adding network multiplayer

## License

This is an educational project. The original game was created by Ajit Kumar Behera (Class IX).
