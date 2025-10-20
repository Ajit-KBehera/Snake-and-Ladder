#!/usr/bin/env python3
"""
Snake & Ladder Game - Console Version (No Graphics)
Replicated from the original C program with all features

Features:
- Two-player gameplay
- Menu system
- Game instructions
- Snake and ladder effects
- Winner detection
- Console-based interface
"""

import random
import time
import sys
from typing import Dict, Tuple

class SnakeLadderConsole:
    def __init__(self):
        # Game state
        self.player_a_pos = 0
        self.player_b_pos = 0
        self.current_player = 1  # 1 for A, 2 for B
        self.game_running = True
        self.menu_active = True
        
        # Snake and ladder positions (from original C code)
        self.snakes = {
            60: 30,   # Snake: 60 -> 30
            94: 1,    # Snake: 94 -> 1
            82: 17,   # Snake: 82 -> 17
            36: 7,    # Snake: 36 -> 7
            99: 3,    # Snake: 99 -> 3
            97: 32    # Snake: 97 -> 32
        }
        
        self.ladders = {
            27: 98,   # Ladder: 27 -> 98
            43: 66,   # Ladder: 43 -> 66
            7: 77,    # Ladder: 7 -> 77
            33: 85,   # Ladder: 33 -> 85
            49: 93,   # Ladder: 49 -> 93
            14: 61    # Ladder: 14 -> 61
        }
        
        # Board layout (10x10 grid)
        self.board = self.create_board()
    
    def create_board(self):
        """Create the 10x10 board with numbers 1-100"""
        board = []
        num = 100
        for row in range(10):
            board_row = []
            for col in range(10):
                board_row.append(num)
                num -= 1
            board.append(board_row)
        return board
    
    def print_board(self):
        """Print the game board"""
        print("\n" + "="*60)
        print("🎲 SNAKE & LADDER BOARD")
        print("="*60)
        
        for row in range(10):
            for col in range(10):
                number = self.board[row][col]
                # Highlight current positions
                if number == self.player_a_pos:
                    print(f"[A{number:2d}]", end=" ")
                elif number == self.player_b_pos:
                    print(f"[B{number:2d}]", end=" ")
                else:
                    print(f" {number:2d} ", end=" ")
            print()
        
        print("="*60)
        print(f"Player A (🟡): Position {self.player_a_pos}")
        print(f"Player B (🟠): Position {self.player_b_pos}")
        print("="*60)
    
    def handle_snake_ladder(self, position: int) -> int:
        """Handle snake and ladder effects"""
        if position in self.snakes:
            new_pos = self.snakes[position]
            print(f"🐍 Snake! Moved from {position} to {new_pos}")
            return new_pos
        elif position in self.ladders:
            new_pos = self.ladders[position]
            print(f"🪜 Ladder! Moved from {position} to {new_pos}")
            return new_pos
        return position
    
    def play_sound(self):
        """Play sound effect (console version)"""
        print("🔊 Beep!")
        # You can add actual sound here if needed
    
    def show_welcome(self):
        """Show welcome screen"""
        print("\n" + "🎮" * 20)
        print("🎮 WELCOME TO SNAKE & LADDER GAME 🎮")
        print("🎮" * 20)
        print("\nPresented by: AJIT KUMAR BEHERA (CLASS-IX)")
        print("=" * 50)
        
        # Animated title
        title = "SNAKE & LADDERS"
        for i in range(len(title)):
            print(f"\r{' ' * i}{title[i]}", end="", flush=True)
            time.sleep(0.1)
        print()
        
        time.sleep(1)
    
    def show_menu(self):
        """Show main menu"""
        print("\n" + "="*40)
        print("🎮 MAIN MENU")
        print("="*40)
        print("1. 🎲 PLAY GAME")
        print("2. 📖 GAME INSTRUCTIONS")
        print("3. 🚪 QUIT")
        print("="*40)
    
    def show_instructions(self):
        """Show game instructions"""
        print("\n" + "📖" * 20)
        print("📖 GAME INSTRUCTIONS 📖")
        print("📖" * 20)
        print("""
1. 2 PLAYERS MUST PLAY.
2. PLAYER SHOULD PUT HIS WILLING NUMBER WITH THE KEYBOARD.
3. THAT NUMBER SHOULD BELONG >=1 AND <=6.
4. IF THE PLAYER WILL PUT NUMBER IGNORING
   THE INSTRUCTION THE HE WILL LOSS HIS CHANCE.
5. YOU SHOULD PRESS THE ENTER KEY AFTER YOU
   ENTERED THE NUMBER.
6. THE SNAKES AND LADDERS ARE NOT SEEN TO THE
   PLAYERS.

🐍 SNAKES (Move Down):
   • 60 → 30
   • 94 → 1
   • 82 → 17
   • 36 → 7
   • 99 → 3
   • 97 → 32

🪜 LADDERS (Move Up):
   • 27 → 98
   • 43 → 66
   • 7 → 77
   • 33 → 85
   • 49 → 93
   • 14 → 61

READ PROPERLY!
        """)
        input("Press Enter to continue...")
    
    def show_credits(self):
        """Show credits"""
        print("\n" + "🎭" * 20)
        print("🎭 CREDITS 🎭")
        print("🎭" * 20)
        print("SNAKE & LADDERS")
        print("presented by :-")
        print("AJIT KUMAR BEHERA")
        print("CLASS-IX")
        print("🎭" * 20)
        time.sleep(2)
    
    def play_game(self):
        """Main game loop"""
        print("\n🎲 BEST OF LUCK!")
        time.sleep(1)
        
        self.show_credits()
        self.print_board()
        
        while self.game_running:
            if self.current_player == 1:
                print(f"\n🎯 Player A's turn (Current position: {self.player_a_pos})")
                try:
                    dice_roll = int(input("Enter dice roll (1-6): "))
                    if 1 <= dice_roll <= 6:
                        self.player_a_pos += dice_roll
                        print(f"Player A rolled {dice_roll}, moved to position {self.player_a_pos}")
                        
                        # Check for snake/ladder
                        new_pos = self.handle_snake_ladder(self.player_a_pos)
                        if new_pos != self.player_a_pos:
                            self.player_a_pos = new_pos
                        
                        self.print_board()
                        
                        if self.player_a_pos >= 100:
                            self.show_winner("PLAYER A")
                            return
                        
                        self.current_player = 2
                    else:
                        print("Invalid dice roll! Please enter 1-6.")
                except ValueError:
                    print("Invalid input! Please enter a number.")
            
            else:
                print(f"\n🎯 Player B's turn (Current position: {self.player_b_pos})")
                try:
                    dice_roll = int(input("Enter dice roll (1-6): "))
                    if 1 <= dice_roll <= 6:
                        self.player_b_pos += dice_roll
                        print(f"Player B rolled {dice_roll}, moved to position {self.player_b_pos}")
                        
                        # Check for snake/ladder
                        new_pos = self.handle_snake_ladder(self.player_b_pos)
                        if new_pos != self.player_b_pos:
                            self.player_b_pos = new_pos
                        
                        self.print_board()
                        
                        if self.player_b_pos >= 100:
                            self.show_winner("PLAYER B")
                            return
                        
                        self.current_player = 1
                    else:
                        print("Invalid dice roll! Please enter 1-6.")
                except ValueError:
                    print("Invalid input! Please enter a number.")
    
    def show_winner(self, player: str):
        """Show winner screen"""
        print("\n" + "🎉" * 30)
        print(f"🎉 {player} WINS! 🎉")
        print("🎉 CONGRATULATION! 🎉")
        print("🎉" * 30)
        time.sleep(3)
    
    def run(self):
        """Main game loop"""
        self.show_welcome()
        
        # Main menu loop
        while self.menu_active:
            self.show_menu()
            
            try:
                choice = int(input("Enter your choice (1-3): "))
                
                if choice == 1:  # Play game
                    self.play_game()
                    self.menu_active = False
                    
                elif choice == 2:  # Instructions
                    self.show_instructions()
                    
                elif choice == 3:  # Quit
                    print("\n👋 THANK YOU FOR PLAYING!")
                    print("👋" * 20)
                    time.sleep(2)
                    self.menu_active = False
                    
                else:
                    print("Invalid choice! Please enter 1, 2, or 3.")
                    
            except ValueError:
                print("Invalid input! Please enter a number.")
            except KeyboardInterrupt:
                print("\n\nGame interrupted by user.")
                self.menu_active = False

def main():
    """Main function"""
    try:
        game = SnakeLadderConsole()
        game.run()
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
