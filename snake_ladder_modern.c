/*SNAKE & LADDER GAME - MODERNIZED VERSION*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Screen dimensions
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define BOARD_WIDTH 620
#define BOARD_HEIGHT 420

// Color definitions (RGB)
#define COLOR_BLACK (SDL_Color){0, 0, 0, 255}
#define COLOR_WHITE (SDL_Color){255, 255, 255, 255}
#define COLOR_BLUE (SDL_Color){0, 0, 255, 255}
#define COLOR_RED (SDL_Color){255, 0, 0, 255}
#define COLOR_GREEN (SDL_Color){0, 255, 0, 255}
#define COLOR_YELLOW (SDL_Color){255, 255, 0, 255}
#define COLOR_CYAN (SDL_Color){0, 255, 255, 255}
#define COLOR_MAGENTA (SDL_Color){255, 0, 255, 255}
#define COLOR_ORANGE (SDL_Color){255, 165, 0, 255}
#define COLOR_PINK (SDL_Color){255, 192, 203, 255}
#define COLOR_GRAY (SDL_Color){128, 128, 128, 255}
#define COLOR_DARK_GRAY (SDL_Color){64, 64, 64, 255}
#define COLOR_LIGHT_BLUE (SDL_Color){173, 216, 230, 255}
#define COLOR_BROWN (SDL_Color){139, 69, 19, 255}

// Global variables
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;
TTF_Font* small_font = NULL;

// Function prototypes
int init_graphics();
void cleanup_graphics();
void set_background_color(SDL_Color color);
void clear_screen();
void draw_text(int x, int y, const char* text, SDL_Color color);
void draw_rectangle(int x, int y, int width, int height, SDL_Color color);
void draw_filled_rectangle(int x, int y, int width, int height, SDL_Color color);
void draw_line(int x1, int y1, int x2, int y2, SDL_Color color);
void delay_ms(int milliseconds);
void play_sound();
void draw_board();
void draw_player(int x, int y, SDL_Color color);
void show_menu();
void show_instructions();
void show_credits();
void play_game();
void handle_snake_ladder(int position, int* new_position, SDL_Color* effect_color);
void show_winner(const char* player);

// Initialize graphics system
int init_graphics() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    
    if (TTF_Init() == -1) {
        printf("TTF could not initialize! TTF_Error: %s\n", TTF_GetError());
        return 0;
    }
    
    window = SDL_CreateWindow("Snake & Ladder Game",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    
    // Load fonts (using system fonts as fallback)
    font = TTF_OpenFont("/System/Library/Fonts/Arial.ttf", 24);
    if (font == NULL) {
        font = TTF_OpenFont("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf", 24);
    }
    if (font == NULL) {
        font = TTF_OpenFont("arial.ttf", 24);
    }
    
    small_font = TTF_OpenFont("/System/Library/Fonts/Arial.ttf", 16);
    if (small_font == NULL) {
        small_font = TTF_OpenFont("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf", 16);
    }
    if (small_font == NULL) {
        small_font = TTF_OpenFont("arial.ttf", 16);
    }
    
    if (font == NULL || small_font == NULL) {
        printf("Warning: Could not load fonts, text may not display properly\n");
    }
    
    return 1;
}

// Cleanup graphics system
void cleanup_graphics() {
    if (font) TTF_CloseFont(font);
    if (small_font) TTF_CloseFont(small_font);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

// Set background color
void set_background_color(SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
}

// Clear screen
void clear_screen() {
    SDL_RenderClear(renderer);
}

// Draw text
void draw_text(int x, int y, const char* text, SDL_Color color) {
    if (!font) return;
    
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, text, color);
    if (text_surface == NULL) return;
    
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (text_texture == NULL) {
        SDL_FreeSurface(text_surface);
        return;
    }
    
    SDL_Rect text_rect = {x, y, text_surface->w, text_surface->h};
    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
    
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
}

// Draw small text
void draw_small_text(int x, int y, const char* text, SDL_Color color) {
    if (!small_font) return;
    
    SDL_Surface* text_surface = TTF_RenderText_Solid(small_font, text, color);
    if (text_surface == NULL) return;
    
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (text_texture == NULL) {
        SDL_FreeSurface(text_surface);
        return;
    }
    
    SDL_Rect text_rect = {x, y, text_surface->w, text_surface->h};
    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
    
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
}

// Draw rectangle outline
void draw_rectangle(int x, int y, int width, int height, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderDrawRect(renderer, &rect);
}

// Draw filled rectangle
void draw_filled_rectangle(int x, int y, int width, int height, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}

// Draw line
void draw_line(int x1, int y1, int x2, int y2, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

// Delay function with event processing
void delay_ms(int milliseconds) {
    Uint32 start = SDL_GetTicks();
    while (SDL_GetTicks() - start < milliseconds) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                exit(0);
            }
        }
        SDL_Delay(10);
    }
}

// Play sound (placeholder - would need SDL_mixer for actual sound)
void play_sound() {
    // Sound implementation would go here
    printf("Beep!\n");
}

// Draw the game board
void draw_board() {
    SDL_Color white = COLOR_WHITE;
    SDL_Color black = COLOR_BLACK;
    
    // Clear screen with blue background
    SDL_Color blue = COLOR_BLUE;
    set_background_color(blue);
    clear_screen();
    
    // Draw board outline
    draw_rectangle(20, 0, BOARD_WIDTH, BOARD_HEIGHT, white);
    
    // Draw grid lines
    for (int i = 1; i <= 9; i++) {
        draw_line(20, 42 * i, 640, 42 * i, white);
        delay_ms(100);
    }
    
    for (int i = 1; i <= 9; i++) {
        draw_line(64 * i, 0, 64 * i, BOARD_HEIGHT, white);
        delay_ms(100);
    }
    
    // Draw numbers on the board
    int numbers[10][10] = {
        {100, 99, 98, 97, 96, 95, 94, 93, 92, 91},
        {90, 89, 88, 87, 86, 85, 84, 83, 82, 81},
        {80, 79, 78, 77, 76, 75, 74, 73, 72, 71},
        {70, 69, 68, 67, 66, 65, 64, 63, 62, 61},
        {60, 59, 58, 57, 56, 55, 54, 53, 52, 51},
        {50, 49, 48, 47, 46, 45, 44, 43, 42, 41},
        {40, 39, 38, 37, 36, 35, 34, 33, 32, 31},
        {30, 29, 28, 27, 26, 25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16, 15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    };
    
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            int x = 25 + col * 64;
            int y = 15 + row * 42;
            char num_str[4];
            sprintf(num_str, "%d", numbers[row][col]);
            draw_small_text(x, y, num_str, white);
        }
        delay_ms(200);
    }
    
    // Draw player indicators
    SDL_Color yellow = COLOR_YELLOW;
    SDL_Color orange = COLOR_ORANGE;
    draw_filled_rectangle(5, 440, 48, 15, yellow);
    draw_rectangle(5, 440, 48, 15, black);
    draw_filled_rectangle(53, 440, 53, 15, orange);
    draw_rectangle(53, 440, 53, 15, black);
    draw_small_text(30, 435, "A", black);
    draw_small_text(70, 435, "B", black);
    
    SDL_RenderPresent(renderer);
}

// Draw player piece
void draw_player(int x, int y, SDL_Color color) {
    draw_filled_rectangle(x, y, 14, 10, color);
    draw_rectangle(x, y, 14, 10, COLOR_BLACK);
}

// Show main menu
void show_menu() {
    SDL_Color colors[] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_CYAN, 
                         COLOR_MAGENTA, COLOR_ORANGE, COLOR_PINK, COLOR_GRAY, COLOR_DARK_GRAY,
                         COLOR_LIGHT_BLUE, COLOR_BROWN, COLOR_WHITE};
    
    for (int i = 0; i < 13; i++) {
        set_background_color(colors[i]);
        clear_screen();
        draw_text(320, 230, "1.WANT TO PLAY", COLOR_WHITE);
        draw_text(320, 250, "2.GAME INSTRUCTION", COLOR_WHITE);
        draw_text(320, 270, "3.QUIT", COLOR_WHITE);
        draw_text(320, 290, "press the option", COLOR_WHITE);
        SDL_RenderPresent(renderer);
        delay_ms(500);
    }
}

// Show game instructions
void show_instructions() {
    SDL_Color red = COLOR_RED;
    set_background_color(red);
    clear_screen();
    
    draw_text(50, 50, "GAME INSTRUCTIONS:", COLOR_WHITE);
    draw_text(50, 80, "1. 2 PLAYERS MUST PLAY.", COLOR_WHITE);
    draw_text(50, 100, "2. PLAYER SHOULD PUT HIS WILLING NUMBER WITH THE KEYBOARD.", COLOR_WHITE);
    draw_text(50, 120, "3. THAT NUMBER SHOULD BELONG >=1 AND <=6.", COLOR_WHITE);
    draw_text(50, 140, "4. IF THE PLAYER WILL PUT NUMBER IGNORING", COLOR_WHITE);
    draw_text(50, 160, "   THE INSTRUCTION THE HE WILL LOSS HIS CHANCE.", COLOR_WHITE);
    draw_text(50, 180, "5. YOU SHOULD PRESS THE ENTER KEY AFTER YOU", COLOR_WHITE);
    draw_text(50, 200, "   ENTERED THE NUMBER.", COLOR_WHITE);
    draw_text(50, 220, "6. THE SNAKES AND LADDERS ARE NOT SEEN TO THE", COLOR_WHITE);
    draw_text(50, 240, "   PLAYERS.", COLOR_WHITE);
    draw_text(320, 300, "READ PROPERLY", COLOR_WHITE);
    
    SDL_RenderPresent(renderer);
    delay_ms(15000);
}

// Show credits
void show_credits() {
    SDL_Color green = COLOR_GREEN;
    set_background_color(green);
    clear_screen();
    
    draw_text(200, 20, "SNAKE & LADDERS", COLOR_WHITE);
    draw_text(270, 280, "presented by :-", COLOR_WHITE);
    draw_text(390, 340, " AJIT KUMAR BEHERA", COLOR_WHITE);
    draw_text(390, 360, "CLASS-IX", COLOR_WHITE);
    
    SDL_RenderPresent(renderer);
    delay_ms(5000);
}

// Handle snake and ladder effects
void handle_snake_ladder(int position, int* new_position, SDL_Color* effect_color) {
    *new_position = position;
    *effect_color = COLOR_RED; // Default to red for snakes
    
    switch (position) {
        case 60: // Snake
            *new_position = 30;
            *effect_color = COLOR_RED;
            break;
        case 94: // Snake
            *new_position = 1;
            *effect_color = COLOR_RED;
            break;
        case 82: // Snake
            *new_position = 17;
            *effect_color = COLOR_RED;
            break;
        case 36: // Snake
            *new_position = 7;
            *effect_color = COLOR_RED;
            break;
        case 99: // Snake
            *new_position = 3;
            *effect_color = COLOR_RED;
            break;
        case 97: // Snake
            *new_position = 32;
            *effect_color = COLOR_RED;
            break;
        case 27: // Ladder
            *new_position = 98;
            *effect_color = COLOR_GREEN;
            break;
        case 43: // Ladder
            *new_position = 66;
            *effect_color = COLOR_GREEN;
            break;
        case 7: // Ladder
            *new_position = 77;
            *effect_color = COLOR_GREEN;
            break;
        case 33: // Ladder
            *new_position = 85;
            *effect_color = COLOR_GREEN;
            break;
        case 49: // Ladder
            *new_position = 93;
            *effect_color = COLOR_GREEN;
            break;
        case 14: // Ladder
            *new_position = 61;
            *effect_color = COLOR_GREEN;
            break;
    }
}

// Show winner message
void show_winner(const char* player) {
    SDL_Color purple = {128, 0, 128, 255};
    set_background_color(purple);
    clear_screen();
    
    char win_msg[50];
    sprintf(win_msg, "%s WINS!", player);
    draw_text(320, 230, win_msg, COLOR_WHITE);
    draw_text(320, 270, "CONGRATULATION!", COLOR_WHITE);
    
    SDL_RenderPresent(renderer);
    delay_ms(5000);
}

// Main game loop
void play_game() {
    int player_a_pos = 0, player_b_pos = 0;
    int dice_roll;
    SDL_Color yellow = COLOR_YELLOW;
    SDL_Color orange = COLOR_ORANGE;
    SDL_Color black = COLOR_BLACK;
    
    draw_board();
    
    while (1) {
        // Process SDL events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            }
        }
        
        // Player A's turn
        printf("Player A's turn. Enter dice roll (1-6): ");
        scanf("%d", &dice_roll);
        
        if (dice_roll >= 1 && dice_roll <= 6) {
            player_a_pos += dice_roll;
            
            // Calculate board position
            int row_a = 9 - (player_a_pos - 1) / 10;
            int col_a = (player_a_pos - 1) % 10;
            if (row_a % 2 == 1) col_a = 9 - col_a; // Zigzag pattern
            
            int x_a = 50 + col_a * 64;
            int y_a = 10 + row_a * 42;
            
            // Draw player A
            draw_player(x_a, y_a, yellow);
            SDL_RenderPresent(renderer);
            
            // Check for snake/ladder
            int new_pos_a;
            SDL_Color effect_color_a;
            handle_snake_ladder(player_a_pos, &new_pos_a, &effect_color_a);
            
            if (new_pos_a != player_a_pos) {
                player_a_pos = new_pos_a;
                // Redraw at new position
                int new_row_a = 9 - (player_a_pos - 1) / 10;
                int new_col_a = (player_a_pos - 1) % 10;
                if (new_row_a % 2 == 1) new_col_a = 9 - new_col_a;
                int new_x_a = 50 + new_col_a * 64;
                int new_y_a = 10 + new_row_a * 42;
                draw_player(new_x_a, new_y_a, yellow);
                SDL_RenderPresent(renderer);
            }
            
            if (player_a_pos >= 100) {
                show_winner("PLAYER A");
                return;
            }
        }
        
        // Player B's turn
        printf("Player B's turn. Enter dice roll (1-6): ");
        scanf("%d", &dice_roll);
        
        if (dice_roll >= 1 && dice_roll <= 6) {
            player_b_pos += dice_roll;
            
            // Calculate board position
            int row_b = 9 - (player_b_pos - 1) / 10;
            int col_b = (player_b_pos - 1) % 10;
            if (row_b % 2 == 1) col_b = 9 - col_b; // Zigzag pattern
            
            int x_b = 50 + col_b * 64;
            int y_b = 10 + row_b * 42;
            
            // Draw player B
            draw_player(x_b, y_b, orange);
            SDL_RenderPresent(renderer);
            
            // Check for snake/ladder
            int new_pos_b;
            SDL_Color effect_color_b;
            handle_snake_ladder(player_b_pos, &new_pos_b, &effect_color_b);
            
            if (new_pos_b != player_b_pos) {
                player_b_pos = new_pos_b;
                // Redraw at new position
                int new_row_b = 9 - (player_b_pos - 1) / 10;
                int new_col_b = (player_b_pos - 1) % 10;
                if (new_row_b % 2 == 1) new_col_b = 9 - new_col_b;
                int new_x_b = 50 + new_col_b * 64;
                int new_y_b = 10 + new_row_b * 42;
                draw_player(new_x_b, new_y_b, orange);
                SDL_RenderPresent(renderer);
            }
            
            if (player_b_pos >= 100) {
                show_winner("PLAYER B");
                return;
            }
        }
    }
}

// Main function
int main() {
    if (!init_graphics()) {
        printf("Failed to initialize graphics!\n");
        return 1;
    }
    
    int choice;
    
    // Welcome screen
    SDL_Color blue = COLOR_BLUE;
    set_background_color(blue);
    clear_screen();
    draw_text(230, 210, "WELCOME", COLOR_WHITE);
    SDL_RenderPresent(renderer);
    delay_ms(2000);
    
    // Animated title
    SDL_Color colors[] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_CYAN, 
                         COLOR_MAGENTA, COLOR_ORANGE, COLOR_PINK, COLOR_GRAY, COLOR_DARK_GRAY,
                         COLOR_LIGHT_BLUE, COLOR_BROWN, COLOR_WHITE};
    
    for (int i = 0; i < 13; i++) {
        set_background_color(colors[i]);
        clear_screen();
        draw_text(300 - i * 10, 200 - i * 10, "SNAKE & LADDERS", COLOR_WHITE);
        SDL_RenderPresent(renderer);
        delay_ms(500);
    }
    
    play_sound();
    delay_ms(1000);
    
    // Main menu loop
    while (1) {
        // Process SDL events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                cleanup_graphics();
                return 0;
            }
        }
        
        show_menu();
        
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 3) {
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
            continue;
        }
        
        switch (choice) {
            case 1: // Play game
                set_background_color(COLOR_MAGENTA);
                clear_screen();
                draw_text(250, 200, "BEST OF LUCK!", COLOR_WHITE);
                SDL_RenderPresent(renderer);
                delay_ms(2000);
                
                show_credits();
                play_game();
                break;
                
            case 2: // Instructions
                show_instructions();
                break;
                
            case 3: // Quit
                set_background_color(COLOR_GREEN);
                clear_screen();
                draw_text(320, 230, "THANK YOU", COLOR_WHITE);
                SDL_RenderPresent(renderer);
                delay_ms(3000);
                
                // Animated exit
                for (int i = 0; i <= 640; i += 10) {
                    set_background_color(colors[i / 10 % 13]);
                    clear_screen();
                    draw_filled_rectangle(i, 200, 100, 80, COLOR_WHITE);
                    draw_rectangle(i, 200, 100, 80, COLOR_BLACK);
                    SDL_RenderPresent(renderer);
                    delay_ms(5);
                }
                
                cleanup_graphics();
                return 0;
        }
    }
    
    cleanup_graphics();
    return 0;
}
