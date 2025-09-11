/*SNAKE & LADDER GAME - TEST VERSION (No Graphics)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Game board representation
int board[10][10];
int player_a_pos = 0, player_b_pos = 0;

// Initialize the board with numbers
void init_board() {
    int num = 100;
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            board[row][col] = num--;
        }
    }
}

// Print the board
void print_board() {
    printf("\n=== SNAKE & LADDER BOARD ===\n");
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            printf("%3d ", board[row][col]);
        }
        printf("\n");
    }
    printf("============================\n\n");
}

// Get position from board coordinates
int get_position(int row, int col) {
    return board[row][col];
}

// Get board coordinates from position
void get_coordinates(int position, int* row, int* col) {
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            if (board[r][c] == position) {
                *row = r;
                *col = c;
                return;
            }
        }
    }
}

// Handle snake and ladder effects
int handle_snake_ladder(int position) {
    switch (position) {
        case 60: // Snake
            printf("🐍 Snake! Moved from 60 to 30\n");
            return 30;
        case 94: // Snake
            printf("🐍 Snake! Moved from 94 to 1\n");
            return 1;
        case 82: // Snake
            printf("🐍 Snake! Moved from 82 to 17\n");
            return 17;
        case 36: // Snake
            printf("🐍 Snake! Moved from 36 to 7\n");
            return 7;
        case 99: // Snake
            printf("🐍 Snake! Moved from 99 to 3\n");
            return 3;
        case 97: // Snake
            printf("🐍 Snake! Moved from 97 to 32\n");
            return 32;
        case 27: // Ladder
            printf("🪜 Ladder! Moved from 27 to 98\n");
            return 98;
        case 43: // Ladder
            printf("🪜 Ladder! Moved from 43 to 66\n");
            return 66;
        case 7: // Ladder
            printf("🪜 Ladder! Moved from 7 to 77\n");
            return 77;
        case 33: // Ladder
            printf("🪜 Ladder! Moved from 33 to 85\n");
            return 85;
        case 49: // Ladder
            printf("🪜 Ladder! Moved from 49 to 93\n");
            return 93;
        case 14: // Ladder
            printf("🪜 Ladder! Moved from 14 to 61\n");
            return 61;
        default:
            return position;
    }
}

// Show menu
void show_menu() {
    printf("\n=== SNAKE & LADDER GAME ===\n");
    printf("1. PLAY GAME\n");
    printf("2. GAME INSTRUCTIONS\n");
    printf("3. QUIT\n");
    printf("Enter your choice (1-3): ");
}

// Show instructions
void show_instructions() {
    printf("\n=== GAME INSTRUCTIONS ===\n");
    printf("1. 2 PLAYERS MUST PLAY.\n");
    printf("2. PLAYER SHOULD PUT HIS WILLING NUMBER WITH THE KEYBOARD.\n");
    printf("3. THAT NUMBER SHOULD BELONG >=1 AND <=6.\n");
    printf("4. IF THE PLAYER WILL PUT NUMBER IGNORING\n");
    printf("   THE INSTRUCTION THE HE WILL LOSS HIS CHANCE.\n");
    printf("5. YOU SHOULD PRESS THE ENTER KEY AFTER YOU\n");
    printf("   ENTERED THE NUMBER.\n");
    printf("6. THE SNAKES AND LADDERS ARE NOT SEEN TO THE\n");
    printf("   PLAYERS.\n");
    printf("==========================\n");
}

// Play the game
void play_game() {
    int dice_roll;
    int current_player = 1; // 1 for A, 2 for B
    
    printf("\n🎮 Starting the game!\n");
    print_board();
    
    while (1) {
        if (current_player == 1) {
            printf("\n🎯 Player A's turn (Current position: %d)\n", player_a_pos);
            printf("Enter dice roll (1-6): ");
            scanf("%d", &dice_roll);
            
            if (dice_roll >= 1 && dice_roll <= 6) {
                player_a_pos += dice_roll;
                printf("Player A rolled %d, moved to position %d\n", dice_roll, player_a_pos);
                
                // Check for snake/ladder
                int new_pos = handle_snake_ladder(player_a_pos);
                if (new_pos != player_a_pos) {
                    player_a_pos = new_pos;
                }
                
                if (player_a_pos >= 100) {
                    printf("\n🎉 PLAYER A WINS! CONGRATULATIONS!\n");
                    return;
                }
                
                current_player = 2;
            } else {
                printf("Invalid dice roll! Please enter 1-6.\n");
            }
        } else {
            printf("\n🎯 Player B's turn (Current position: %d)\n", player_b_pos);
            printf("Enter dice roll (1-6): ");
            scanf("%d", &dice_roll);
            
            if (dice_roll >= 1 && dice_roll <= 6) {
                player_b_pos += dice_roll;
                printf("Player B rolled %d, moved to position %d\n", dice_roll, player_b_pos);
                
                // Check for snake/ladder
                int new_pos = handle_snake_ladder(player_b_pos);
                if (new_pos != player_b_pos) {
                    player_b_pos = new_pos;
                }
                
                if (player_b_pos >= 100) {
                    printf("\n🎉 PLAYER B WINS! CONGRATULATIONS!\n");
                    return;
                }
                
                current_player = 1;
            } else {
                printf("Invalid dice roll! Please enter 1-6.\n");
            }
        }
    }
}

// Main function
int main() {
    int choice;
    
    printf("🎮 Welcome to Snake & Ladder Game!\n");
    printf("Presented by: AJIT KUMAR BEHERA (CLASS-IX)\n");
    
    init_board();
    
    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 3) {
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
            continue;
        }
        
        switch (choice) {
            case 1: // Play game
                printf("\n🎲 BEST OF LUCK!\n");
                player_a_pos = 0;
                player_b_pos = 0;
                play_game();
                break;
                
            case 2: // Instructions
                show_instructions();
                break;
                
            case 3: // Quit
                printf("\n👋 THANK YOU FOR PLAYING!\n");
                return 0;
        }
    }
    
    return 0;
}
