#!/usr/bin/env python3
"""
Snake & Ladder Game - Python Version
Replicated from the original C program with all features

Features:
- Two-player gameplay
- Graphics with pygame
- Animated welcome screen
- Menu system
- Game instructions
- Snake and ladder effects
- Winner detection
- Sound effects
- Colorful graphics
"""

import pygame
import sys
import random
import time
import math
from typing import Tuple, List, Optional

# Initialize Pygame
pygame.init()

# Constants
SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480
BOARD_WIDTH = 620
BOARD_HEIGHT = 420
CELL_SIZE = 64
CELL_HEIGHT = 42

# Colors (RGB)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
YELLOW = (255, 255, 0)
CYAN = (0, 255, 255)
MAGENTA = (255, 0, 255)
ORANGE = (255, 165, 0)
PINK = (255, 192, 203)
GRAY = (128, 128, 128)
DARK_GRAY = (64, 64, 64)
LIGHT_BLUE = (173, 216, 230)
BROWN = (139, 69, 19)
PURPLE = (128, 0, 128)

class SnakeLadderGame:
    def __init__(self):
        self.screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        pygame.display.set_caption("Snake & Ladder Game")
        self.clock = pygame.time.Clock()
        self.font = pygame.font.Font(None, 24)
        self.big_font = pygame.font.Font(None, 36)
        self.title_font = pygame.font.Font(None, 48)
        
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
        
    def create_board(self) -> List[List[int]]:
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
    
    def get_position_coords(self, position: int) -> Tuple[int, int]:
        """Convert board position to screen coordinates"""
        if position < 1 or position > 100:
            return (0, 0)
        
        # Find position in board
        for row in range(10):
            for col in range(10):
                if self.board[row][col] == position:
                    # Convert to screen coordinates
                    x = 25 + col * CELL_SIZE
                    y = 15 + row * CELL_HEIGHT
                    return (x, y)
        return (0, 0)
    
    def draw_welcome_screen(self):
        """Animated welcome screen like the original"""
        colors = [RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, ORANGE, PINK, GRAY, DARK_GRAY, LIGHT_BLUE, BROWN, PURPLE]
        
        for frame in range(50):
            self.screen.fill(colors[frame % len(colors)])
            
            # Animated title
            title_text = self.title_font.render("SNAKE & LADDERS", True, WHITE)
            title_rect = title_text.get_rect(center=(300 - frame * 2, 200 - frame * 2))
            self.screen.blit(title_text, title_rect)
            
            # Welcome text
            welcome_text = self.big_font.render("WELCOME", True, WHITE)
            welcome_rect = welcome_text.get_rect(center=(230, 210))
            self.screen.blit(welcome_text, welcome_rect)
            
            pygame.display.flip()
            pygame.time.delay(100)
            
            # Check for quit
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
    
    def draw_menu(self):
        """Draw the main menu"""
        self.screen.fill(BLUE)
        
        # Animated background
        for i in range(13):
            color = [RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, ORANGE, PINK, GRAY, DARK_GRAY, LIGHT_BLUE, BROWN, PURPLE][i % 13]
            self.screen.fill(color)
            
            # Menu options
            option1 = self.font.render("1.WANT TO PLAY", True, WHITE)
            option2 = self.font.render("2.GAME INSTRUCTION", True, WHITE)
            option3 = self.font.render("3.QUIT", True, WHITE)
            prompt = self.font.render("press the option", True, WHITE)
            
            self.screen.blit(option1, (320, 230))
            self.screen.blit(option2, (320, 250))
            self.screen.blit(option3, (320, 270))
            self.screen.blit(prompt, (320, 290))
            
            pygame.display.flip()
            pygame.time.delay(100)
            
            # Check for quit
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
    
    def draw_instructions(self):
        """Draw game instructions"""
        self.screen.fill(RED)
        
        instructions = [
            "GAME INSTRUCTIONS:",
            "1. 2 PLAYERS MUST PLAY.",
            "2. PLAYER SHOULD PUT HIS WILLING NUMBER WITH THE KEYBOARD.",
            "3. THAT NUMBER SHOULD BELONG >=1 AND <=6.",
            "4. IF THE PLAYER WILL PUT NUMBER IGNORING",
            "   THE INSTRUCTION THE HE WILL LOSS HIS CHANCE.",
            "5. YOU SHOULD PRESS THE ENTER KEY AFTER YOU",
            "   ENTERED THE NUMBER.",
            "6. THE SNAKES AND LADDERS ARE NOT SEEN TO THE",
            "   PLAYERS.",
            "READ PROPERLY"
        ]
        
        y_offset = 50
        for instruction in instructions:
            text = self.font.render(instruction, True, WHITE)
            self.screen.blit(text, (50, y_offset))
            y_offset += 20
        
        pygame.display.flip()
        pygame.time.delay(15000)  # 15 second delay like original
    
    def draw_credits(self):
        """Draw credits screen"""
        self.screen.fill(GREEN)
        
        title = self.title_font.render("SNAKE & LADDERS", True, WHITE)
        presented = self.font.render("presented by :-", True, WHITE)
        author = self.font.render("AJIT KUMAR BEHERA", True, WHITE)
        class_info = self.font.render("CLASS-IX", True, WHITE)
        
        self.screen.blit(title, (200, 20))
        self.screen.blit(presented, (270, 280))
        self.screen.blit(author, (390, 340))
        self.screen.blit(class_info, (390, 360))
        
        pygame.display.flip()
        pygame.time.delay(5000)  # 5 second delay like original
    
    def draw_board(self):
        """Draw the game board"""
        self.screen.fill(BLUE)
        
        # Draw board outline
        pygame.draw.rect(self.screen, WHITE, (20, 0, BOARD_WIDTH, BOARD_HEIGHT), 2)
        
        # Draw grid lines
        for i in range(1, 10):
            pygame.draw.line(self.screen, WHITE, (20, i * CELL_HEIGHT), (640, i * CELL_HEIGHT))
            pygame.time.delay(100)
        
        for i in range(1, 10):
            pygame.draw.line(self.screen, WHITE, (20 + i * CELL_SIZE, 0), (20 + i * CELL_SIZE, BOARD_HEIGHT))
            pygame.time.delay(100)
        
        # Draw numbers on board
        for row in range(10):
            for col in range(10):
                number = self.board[row][col]
                x = 25 + col * CELL_SIZE
                y = 15 + row * CELL_HEIGHT
                number_text = self.font.render(str(number), True, WHITE)
                self.screen.blit(number_text, (x, y))
            pygame.time.delay(200)
        
        # Draw player indicators
        pygame.draw.rect(self.screen, YELLOW, (5, 440, 48, 15))
        pygame.draw.rect(self.screen, BLACK, (5, 440, 48, 15), 2)
        pygame.draw.rect(self.screen, ORANGE, (53, 440, 53, 15))
        pygame.draw.rect(self.screen, BLACK, (53, 440, 53, 15), 2)
        
        player_a_text = self.font.render("A", True, BLACK)
        player_b_text = self.font.render("B", True, BLACK)
        self.screen.blit(player_a_text, (30, 435))
        self.screen.blit(player_b_text, (70, 435))
        
        pygame.display.flip()
    
    def draw_player(self, position: int, color: Tuple[int, int, int]):
        """Draw player piece on board"""
        x, y = self.get_position_coords(position)
        if x > 0 and y > 0:
            pygame.draw.rect(self.screen, color, (x, y, 14, 10))
            pygame.draw.rect(self.screen, BLACK, (x, y, 14, 10), 2)
    
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
        """Play sound effect (placeholder)"""
        print("🔊 Beep!")
    
    def show_winner(self, player: str):
        """Show winner screen"""
        self.screen.fill(PURPLE)
        
        winner_text = self.title_font.render(f"{player} WINS!", True, WHITE)
        congrats_text = self.big_font.render("CONGRATULATION!", True, WHITE)
        
        winner_rect = winner_text.get_rect(center=(320, 230))
        congrats_rect = congrats_text.get_rect(center=(320, 270))
        
        self.screen.blit(winner_text, winner_rect)
        self.screen.blit(congrats_text, congrats_rect)
        
        pygame.display.flip()
        pygame.time.delay(5000)
    
    def play_game(self):
        """Main game loop"""
        self.draw_board()
        
        while self.game_running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.game_running = False
                    return
            
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
                        
                        # Draw player
                        self.draw_player(self.player_a_pos, YELLOW)
                        pygame.display.flip()
                        
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
                        
                        # Draw player
                        self.draw_player(self.player_b_pos, ORANGE)
                        pygame.display.flip()
                        
                        if self.player_b_pos >= 100:
                            self.show_winner("PLAYER B")
                            return
                        
                        self.current_player = 1
                    else:
                        print("Invalid dice roll! Please enter 1-6.")
                except ValueError:
                    print("Invalid input! Please enter a number.")
    
    def run(self):
        """Main game loop"""
        # Welcome screen
        self.draw_welcome_screen()
        
        # Credits
        self.draw_credits()
        
        # Animated transition
        colors = [RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, ORANGE, PINK, GRAY, DARK_GRAY, LIGHT_BLUE, BROWN, PURPLE]
        for i in range(640):
            color = colors[i // 50 % len(colors)]
            self.screen.fill(color)
            pygame.draw.rect(self.screen, WHITE, (i, 200, 100, 80))
            pygame.draw.rect(self.screen, BLACK, (i, 200, 100, 80), 2)
            pygame.display.flip()
            pygame.time.delay(5)
        
        # Main menu loop
        while self.menu_active:
            self.draw_menu()
            
            try:
                choice = int(input("Enter your choice (1-3): "))
                
                if choice == 1:  # Play game
                    self.screen.fill(MAGENTA)
                    best_luck = self.big_font.render("BEST OF LUCK!", True, WHITE)
                    best_luck_rect = best_luck.get_rect(center=(250, 200))
                    self.screen.blit(best_luck, best_luck_rect)
                    pygame.display.flip()
                    pygame.time.delay(2000)
                    
                    self.play_game()
                    self.menu_active = False
                    
                elif choice == 2:  # Instructions
                    self.draw_instructions()
                    
                elif choice == 3:  # Quit
                    self.screen.fill(GREEN)
                    thank_you = self.title_font.render("THANK YOU", True, WHITE)
                    thank_you_rect = thank_you.get_rect(center=(320, 230))
                    self.screen.blit(thank_you, thank_you_rect)
                    pygame.display.flip()
                    pygame.time.delay(3000)
                    
                    # Animated exit
                    for i in range(640):
                        color = colors[i // 50 % len(colors)]
                        self.screen.fill(color)
                        pygame.draw.rect(self.screen, WHITE, (i, 200, 100, 80))
                        pygame.draw.rect(self.screen, BLACK, (i, 200, 100, 80), 2)
                        pygame.display.flip()
                        pygame.time.delay(5)
                    
                    self.menu_active = False
                    
                else:
                    print("Invalid choice! Please enter 1, 2, or 3.")
                    
            except ValueError:
                print("Invalid input! Please enter a number.")
            except KeyboardInterrupt:
                print("\nGame interrupted by user.")
                self.menu_active = False
        
        pygame.quit()

def main():
    """Main function"""
    print("🎮 Snake & Ladder Game - Python Version")
    print("Presented by: AJIT KUMAR BEHERA (CLASS-IX)")
    print("=" * 50)
    
    try:
        game = SnakeLadderGame()
        game.run()
    except Exception as e:
        print(f"Error: {e}")
        pygame.quit()
        sys.exit(1)

if __name__ == "__main__":
    main()
