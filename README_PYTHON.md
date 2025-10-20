# Snake & Ladder Game - Python Versions

This directory contains Python implementations of the classic Snake & Ladder game, replicated from the original C program with all features preserved and enhanced.

## 🎮 Available Versions

### 1. **Graphics Version** (`snake_ladder_python.py`)
- **Full pygame graphics** with animations
- **Colorful game board** and visual effects
- **Animated welcome screen** and transitions
- **Sound effects** (placeholder)
- **Professional UI** with menus and instructions

### 2. **Console Version** (`snake_ladder_console.py`)
- **Text-based interface** (no graphics dependencies)
- **Same game mechanics** as graphics version
- **Cross-platform compatibility**
- **Lightweight and fast**

## 🚀 Quick Start

### Graphics Version (Recommended)
```bash
# Install pygame
pip install pygame

# Run the game
python3 snake_ladder_python.py
```

### Console Version (No Dependencies)
```bash
# Run directly (no installation needed)
python3 snake_ladder_console.py
```

## 📋 Features Replicated from Original C Program

### ✅ **Core Game Features**
- **Two-player gameplay** (Player A and Player B)
- **Dice rolling** (1-6 input validation)
- **Snake and ladder effects** with exact same positions
- **Winner detection** at position 100
- **Menu system** with 3 options
- **Game instructions** screen
- **Credits** with author information

### ✅ **Snake & Ladder Positions (Exact Match)**
**Snakes (Move Down):**
- 60 → 30
- 94 → 1
- 82 → 17
- 36 → 7
- 99 → 3
- 97 → 32

**Ladders (Move Up):**
- 27 → 98
- 43 → 66
- 7 → 77
- 33 → 85
- 49 → 93
- 14 → 61

### ✅ **Visual Features (Graphics Version)**
- **Animated welcome screen** with color cycling
- **Menu animations** with background effects
- **Game board** with 10×10 grid (1-100)
- **Player pieces** with different colors
- **Snake/ladder visual effects**
- **Winner celebration** screen
- **Smooth transitions** and delays

### ✅ **Enhanced Features (Python Improvements)**
- **Better error handling** and input validation
- **Cross-platform compatibility**
- **Modular code structure**
- **Type hints** for better code quality
- **Exception handling** for robustness
- **Clean console output** with emojis and formatting

## 🎯 Game Mechanics

### **How to Play:**
1. **Start the game** - Choose option 1 from menu
2. **Take turns** - Players alternate rolling dice
3. **Enter dice roll** (1-6) when prompted
4. **Move forward** by the dice roll amount
5. **Snakes** move you down to lower positions
6. **Ladders** move you up to higher positions
7. **First to reach 100** wins!

### **Input Validation:**
- ✅ Dice rolls must be 1-6
- ✅ Menu choices must be 1-3
- ✅ Invalid inputs show error messages
- ✅ Game continues after invalid input

## 🛠️ Technical Details

### **Dependencies:**
- **Graphics Version**: `pygame>=2.0.0`
- **Console Version**: No dependencies (pure Python)

### **File Structure:**
```
Snake-and-Ladder/
├── snake_ladder_python.py      # 🎨 Graphics version
├── snake_ladder_console.py     # 📝 Console version
├── requirements.txt            # 📦 Dependencies
├── README_PYTHON.md            # 📖 This file
├── snake_ladder_modern.c       # 🔧 C graphics version
├── snake_ladder_test.c         # 🔧 C console version
└── snake&ladder.c              # 📜 Original C program
```

### **Code Quality:**
- ✅ **Type hints** for better code documentation
- ✅ **Error handling** for robust operation
- ✅ **Modular design** with separate classes
- ✅ **Clean code** with proper documentation
- ✅ **Cross-platform** compatibility

## 🎨 Graphics Version Features

### **Visual Elements:**
- **640×480 window** (same as original)
- **Colorful backgrounds** with animations
- **Game board** with grid lines and numbers
- **Player pieces** (yellow for A, orange for B)
- **Snake/ladder effects** with visual feedback
- **Menu system** with animated backgrounds

### **Animations:**
- **Welcome screen** with moving title
- **Color cycling** backgrounds
- **Smooth transitions** between screens
- **Player movement** visualization
- **Winner celebration** effects

## 📝 Console Version Features

### **Text Interface:**
- **ASCII art** and emojis for visual appeal
- **Colored output** (if terminal supports it)
- **Board visualization** with player positions
- **Clear instructions** and prompts
- **Error messages** and validation

### **Advantages:**
- **No dependencies** - runs anywhere Python is installed
- **Fast startup** - no graphics initialization
- **Terminal friendly** - works in any terminal
- **Lightweight** - minimal resource usage

## 🔧 Installation & Setup

### **Option 1: Graphics Version**
```bash
# Install pygame
pip install pygame

# Or use requirements file
pip install -r requirements.txt

# Run the game
python3 snake_ladder_python.py
```

### **Option 2: Console Version**
```bash
# No installation needed!
python3 snake_ladder_console.py
```

### **Option 3: Virtual Environment (Recommended)**
```bash
# Create virtual environment
python3 -m venv snake_ladder_env

# Activate it
source snake_ladder_env/bin/activate  # Linux/Mac
# or
snake_ladder_env\Scripts\activate     # Windows

# Install dependencies
pip install -r requirements.txt

# Run the game
python3 snake_ladder_python.py
```

## 🎮 Game Screenshots

### **Graphics Version:**
- Welcome screen with animated title
- Main menu with colorful background
- Game board with player pieces
- Snake/ladder effects with animations
- Winner screen with celebration

### **Console Version:**
- ASCII art welcome screen
- Text-based menu system
- Board visualization with player positions
- Clear game instructions
- Winner announcement

## 🐛 Troubleshooting

### **Common Issues:**

#### **Graphics Version:**
- **"pygame not found"**: Install pygame with `pip install pygame`
- **"Display not available"**: Run on system with display (not SSH)
- **"Window not responding"**: Close and restart the game

#### **Console Version:**
- **"Python not found"**: Install Python 3.6+ from python.org
- **"Permission denied"**: Make executable with `chmod +x snake_ladder_console.py`
- **"Encoding errors"**: Ensure terminal supports UTF-8

### **Performance:**
- **Graphics version**: Requires display and pygame
- **Console version**: Works on any system with Python
- **Memory usage**: Both versions are lightweight
- **Startup time**: Console version starts faster

## 🏆 Comparison with Original C Program

| Feature | Original C | Python Graphics | Python Console |
|---------|------------|-----------------|----------------|
| **Graphics** | DOS BGI | Pygame | Text/ASCII |
| **Platform** | DOS only | Cross-platform | Cross-platform |
| **Dependencies** | Turbo C | pygame | None |
| **Code Size** | 1150 lines | 400 lines | 300 lines |
| **Maintainability** | Low | High | High |
| **Features** | All | All + Enhanced | All + Enhanced |

## 🎯 Future Enhancements

### **Possible Improvements:**
- **Sound effects** with pygame.mixer
- **AI opponent** for single-player mode
- **Network multiplayer** over internet
- **Save/load game** state
- **Statistics tracking** (games won, etc.)
- **Custom board layouts**
- **Themes and skins**

### **Advanced Features:**
- **3D graphics** with OpenGL
- **Mobile version** with Kivy
- **Web version** with JavaScript
- **Database integration** for high scores
- **Tournament mode** with multiple games

## 📞 Support

If you encounter any issues:
1. **Check Python version** (3.6+ required)
2. **Verify dependencies** are installed
3. **Check terminal/display** compatibility
4. **Review error messages** carefully

## 🎉 Conclusion

The Python versions successfully replicate all features of the original C program while adding modern improvements:

- ✅ **All original features** preserved
- ✅ **Enhanced user experience** with better UI
- ✅ **Cross-platform compatibility** 
- ✅ **Modern code structure** and maintainability
- ✅ **No compilation required** - just run!

**Enjoy playing the modernized Snake & Ladder game!** 🎲🪜🐍
