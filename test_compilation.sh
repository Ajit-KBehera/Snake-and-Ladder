#!/bin/bash

# Test compilation script for Snake & Ladder Game
# This script tests different compilation scenarios

echo "🧪 Testing Snake & Ladder Game Compilation"
echo "=========================================="

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}✅ $2${NC}"
    else
        echo -e "${RED}❌ $2${NC}"
    fi
}

# Test 1: Check if compilers are available
echo -e "\n${YELLOW}Test 1: Checking Compilers${NC}"
echo "------------------------"

# Check GCC
if command -v gcc &> /dev/null; then
    print_status 0 "GCC is available"
    gcc --version | head -1
else
    print_status 1 "GCC is not available"
fi

# Check Clang
if command -v clang &> /dev/null; then
    print_status 0 "Clang is available"
    clang --version | head -1
else
    print_status 1 "Clang is not available"
fi

# Check CC
if command -v cc &> /dev/null; then
    print_status 0 "CC is available"
    cc --version | head -1
else
    print_status 1 "CC is not available"
fi

# Test 2: Check if SDL2 is available
echo -e "\n${YELLOW}Test 2: Checking SDL2 Libraries${NC}"
echo "----------------------------"

# Check pkg-config
if command -v pkg-config &> /dev/null; then
    print_status 0 "pkg-config is available"
    
    # Check SDL2
    if pkg-config --exists sdl2; then
        print_status 0 "SDL2 is available"
        echo "  Version: $(pkg-config --modversion sdl2)"
        echo "  Cflags: $(pkg-config --cflags sdl2)"
        echo "  Libs: $(pkg-config --libs sdl2)"
    else
        print_status 1 "SDL2 is not available"
    fi
    
    # Check SDL2_ttf
    if pkg-config --exists SDL2_ttf; then
        print_status 0 "SDL2_ttf is available"
        echo "  Version: $(pkg-config --modversion SDL2_ttf)"
    else
        print_status 1 "SDL2_ttf is not available"
    fi
else
    print_status 1 "pkg-config is not available"
fi

# Test 3: Check if files exist
echo -e "\n${YELLOW}Test 3: Checking Source Files${NC}"
echo "----------------------------"

if [ -f "snake_ladder_test.c" ]; then
    print_status 0 "Test version (snake_ladder_test.c) exists"
else
    print_status 1 "Test version (snake_ladder_test.c) not found"
fi

if [ -f "snake_ladder_modern.c" ]; then
    print_status 0 "Modern version (snake_ladder_modern.c) exists"
else
    print_status 1 "Modern version (snake_ladder_modern.c) not found"
fi

if [ -f "Makefile" ]; then
    print_status 0 "Makefile exists"
else
    print_status 1 "Makefile not found"
fi

# Test 4: Try to compile test version (no graphics)
echo -e "\n${YELLOW}Test 4: Compiling Test Version${NC}"
echo "--------------------------------"

if [ -f "snake_ladder_test.c" ]; then
    echo "Attempting to compile test version..."
    
    # Try different compilers
    for compiler in cc gcc clang; do
        if command -v $compiler &> /dev/null; then
            echo "Trying $compiler..."
            if $compiler -o snake_ladder_test snake_ladder_test.c 2>/dev/null; then
                print_status 0 "Test version compiled successfully with $compiler"
                
                # Test if executable was created
                if [ -f "snake_ladder_test" ]; then
                    print_status 0 "Executable created successfully"
                    rm -f snake_ladder_test  # Clean up
                else
                    print_status 1 "Executable was not created"
                fi
                break
            else
                print_status 1 "Test version failed to compile with $compiler"
            fi
        fi
    done
else
    print_status 1 "Cannot test compilation - source file not found"
fi

# Test 5: Try to compile modern version (with SDL2)
echo -e "\n${YELLOW}Test 5: Compiling Modern Version${NC}"
echo "-----------------------------------"

if [ -f "snake_ladder_modern.c" ]; then
    echo "Attempting to compile modern version..."
    
    # Check if SDL2 is available
    if pkg-config --exists sdl2 && pkg-config --exists SDL2_ttf; then
        # Try compilation with pkg-config
        echo "Trying with pkg-config..."
        if cc -std=c99 $(pkg-config --cflags --libs sdl2 SDL2_ttf) -o snake_ladder_modern snake_ladder_modern.c 2>/dev/null; then
            print_status 0 "Modern version compiled successfully with pkg-config"
            if [ -f "snake_ladder_modern" ]; then
                print_status 0 "Executable created successfully"
                rm -f snake_ladder_modern  # Clean up
            fi
        else
            print_status 1 "Modern version failed to compile with pkg-config"
        fi
    else
        print_status 1 "Cannot test modern version - SDL2 libraries not available"
        echo "  Install SDL2 and SDL2_ttf to test the full graphics version"
    fi
else
    print_status 1 "Cannot test compilation - source file not found"
fi

# Test 6: Check Makefile
echo -e "\n${YELLOW}Test 6: Testing Makefile${NC}"
echo "----------------------"

if [ -f "Makefile" ]; then
    if command -v make &> /dev/null; then
        print_status 0 "Make is available"
        
        # Test make help
        if make help &> /dev/null; then
            print_status 0 "Makefile is valid"
        else
            print_status 1 "Makefile has issues"
        fi
    else
        print_status 1 "Make is not available"
    fi
else
    print_status 1 "Makefile not found"
fi

# Summary
echo -e "\n${YELLOW}Summary${NC}"
echo "======="

echo "📋 Compilation Test Results:"
echo "  • Test version (console): $(if [ -f "snake_ladder_test.c" ]; then echo "✅ Available"; else echo "❌ Missing"; fi)"
echo "  • Modern version (graphics): $(if [ -f "snake_ladder_modern.c" ]; then echo "✅ Available"; else echo "❌ Missing"; fi)"
echo "  • Makefile: $(if [ -f "Makefile" ]; then echo "✅ Available"; else echo "❌ Missing"; fi)"

echo -e "\n📋 System Requirements:"
echo "  • Compiler: $(if command -v cc &> /dev/null || command -v gcc &> /dev/null || command -v clang &> /dev/null; then echo "✅ Available"; else echo "❌ Missing"; fi)"
echo "  • SDL2: $(if pkg-config --exists sdl2 2>/dev/null; then echo "✅ Available"; else echo "❌ Missing"; fi)"
echo "  • SDL2_ttf: $(if pkg-config --exists SDL2_ttf 2>/dev/null; then echo "✅ Available"; else echo "❌ Missing"; fi)"

echo -e "\n📋 Next Steps:"
if [ -f "snake_ladder_test.c" ]; then
    echo "  1. Try: cc -o snake_ladder_test snake_ladder_test.c"
    echo "  2. Run: ./snake_ladder_test"
fi

if pkg-config --exists sdl2 2>/dev/null && pkg-config --exists SDL2_ttf 2>/dev/null; then
    echo "  3. Try: make run"
    echo "  4. Or: cc -std=c99 \$(pkg-config --cflags --libs sdl2 SDL2_ttf) -o snake_ladder_modern snake_ladder_modern.c"
else
    echo "  3. Install SDL2: brew install sdl2 sdl2_ttf (macOS) or sudo apt-get install libsdl2-dev libsdl2-ttf-dev (Ubuntu)"
    echo "  4. Then try: make run"
fi

echo -e "\n🎮 Happy Gaming!"
