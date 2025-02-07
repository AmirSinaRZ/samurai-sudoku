#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <fstream>
#include <vector>

constexpr int CELL_SIZE = 30;
constexpr int GRID_SIZE = 21;
constexpr int WINDOW_SIZE = CELL_SIZE * GRID_SIZE;

struct Cell {
    int value = 0;
    bool isFixed = false;
};

class SamuraiSudoku {
public:
    Cell grid[GRID_SIZE][GRID_SIZE];

    SamuraiSudoku() {
        for (auto &i: grid) {
            for (auto &j: i) {
                j = Cell();
            }
        }
        setDefaultNumbers();
    }

    // any better idea?
    void setDefaultNumbers() { // crime ;)
        grid[1][0].value = 3;
        grid[1][0].isFixed = true;
        grid[2][0].value = 1;
        grid[2][0].isFixed = true;
        grid[1][1].value = 2;
        grid[1][1].isFixed = true;
        grid[2][2].value = 5;
        grid[2][2].isFixed = true;
        grid[3][1].value = 5;
        grid[3][1].isFixed = true;
        grid[6][2].value = 1;
        grid[6][2].isFixed = true;
        grid[7][2].value = 8;
        grid[7][2].isFixed = true;
        grid[7][1].value = 3;
        grid[7][1].isFixed = true;
        grid[8][0].value = 4;
        grid[8][0].isFixed = true;
        grid[0][4].value = 8;
        grid[0][4].isFixed = true;
        grid[3][3].value = 2;
        grid[3][3].isFixed = true;
        grid[4][4].value = 6;
        grid[4][4].isFixed = true;
        grid[5][4].value = 4;
        grid[5][4].isFixed = true;
        grid[4][5].value = 1;
        grid[4][5].isFixed = true;
        grid[6][4].value = 2;
        grid[6][4].isFixed = true;
        grid[6][3].value = 3;
        grid[6][3].isFixed = true;
        grid[7][3].value = 7;
        grid[7][3].isFixed = true;
        grid[0][7].value = 6;
        grid[0][7].isFixed = true;
        grid[0][8].value = 1;
        grid[0][8].isFixed = true;
        grid[1][7].value = 9;
        grid[1][7].isFixed = true;
        grid[3][8].value = 9;
        grid[3][8].isFixed = true;
        grid[4][8].value = 7;
        grid[4][8].isFixed = true;
        grid[5][8].value = 2;
        grid[5][8].isFixed = true;
        grid[4][6].value = 5;
        grid[4][6].isFixed = true;
        grid[7][6].value = 2;
        grid[7][6].isFixed = true;
        grid[8][6].value = 9;
        grid[8][6].isFixed = true;
        grid[8][8].value = 3;
        grid[8][8].isFixed = true;
        grid[9][8].value = 1;
        grid[9][8].isFixed = true;
        grid[10][7].value = 4;
        grid[10][7].isFixed = true;
        grid[12][5].value = 4;
        grid[12][5].isFixed = true;
        grid[12][1].value = 1;
        grid[12][1].isFixed = true;
        grid[14][1].value = 7;
        grid[14][1].isFixed = true;
        grid[15][1].value = 4;
        grid[15][1].isFixed = true;
        grid[17][0].value = 3;
        grid[17][0].isFixed = true;
        grid[19][0].value = 1;
        grid[19][0].isFixed = true;
        grid[20][0].value = 7;
        grid[20][0].isFixed = true;
        grid[20][2].value = 5;
        grid[20][2].isFixed = true;
        grid[18][2].value = 4;
        grid[18][2].isFixed = true;
        grid[18][1].value = 9;
        grid[18][1].isFixed = true;
        grid[18][1].value = 6;
        grid[18][1].isFixed = true;
        grid[18][3].value = 5;
        grid[18][3].isFixed = true;
        grid[18][4].value = 9;
        grid[18][4].isFixed = true;
        grid[17][3].value = 1;
        grid[17][3].isFixed = true;
        grid[15][3].value = 8;
        grid[15][3].isFixed = true;
        grid[16][4].value = 5;
        grid[16][4].isFixed = true;
        grid[14][3].value = 3;
        grid[14][3].isFixed = true;
        grid[14][5].value = 6;
        grid[14][5].isFixed = true;
        grid[13][6].value = 8;
        grid[13][6].isFixed = true;
        grid[12][7].value = 6;
        grid[12][7].isFixed = true;
        grid[12][8].value = 2;
        grid[12][8].isFixed = true;
        grid[15][7].value = 7;
        grid[15][7].isFixed = true;
        grid[16][6].value = 6;
        grid[16][6].isFixed = true;
        grid[17][8].value = 9;
        grid[17][8].isFixed = true;
        grid[18][7].value = 1;
        grid[18][7].isFixed = true;
        grid[20][6].value = 4;
        grid[20][6].isFixed = true;
        grid[13][9].value = 9;
        grid[13][9].isFixed = true;
        grid[9][9].value = 4;
        grid[9][9].isFixed = true;
        grid[10][11].value = 5;
        grid[10][11].isFixed = true;
        grid[6][9].value = 7;
        grid[6][9].isFixed = true;
        grid[6][10].value = 3;
        grid[6][10].isFixed = true;
        grid[6][11].value = 2;
        grid[6][11].isFixed = true;
        grid[8][10].value = 6;
        grid[8][10].isFixed = true;
        grid[7][10].value = 9;
        grid[7][10].isFixed = true;
        grid[0][12].value = 4;
        grid[0][12].isFixed = true;
        grid[0][13].value = 8;
        grid[0][13].isFixed = true;
        grid[2][12].value = 6;
        grid[2][12].isFixed = true;
        grid[3][13].value = 7;
        grid[3][13].isFixed = true;
        grid[4][12].value = 2;
        grid[4][12].isFixed = true;
        grid[5][12].value = 8;
        grid[5][12].isFixed = true;
        grid[7][12].value = 7;
        grid[7][12].isFixed = true;
        grid[7][14].value = 8;
        grid[7][14].isFixed = true;
        grid[9][12].value = 2;
        grid[9][12].isFixed = true;
        grid[10][12].value = 1;
        grid[10][12].isFixed = true;
        grid[11][14].value = 9;
        grid[11][14].isFixed = true;
        grid[12][14].value = 1;
        grid[12][14].isFixed = true;
        grid[13][13].value = 5;
        grid[13][13].isFixed = true;
        grid[14][12].value = 8;
        grid[14][12].isFixed = true;
        grid[14][14].value = 3;
        grid[14][14].isFixed = true;
        grid[17][14].value = 4;
        grid[17][14].isFixed = true;
        grid[18][14].value = 7;
        grid[18][14].isFixed = true;
        grid[19][13].value = 4;
        grid[19][13].isFixed = true;
        grid[12][15].value = 6;
        grid[12][15].isFixed = true;
        grid[13][15].value = 1;
        grid[13][15].isFixed = true;
        grid[12][16].value = 7;
        grid[12][16].isFixed = true;
        grid[16][15].value = 8;
        grid[16][15].isFixed = true;
        grid[16][17].value = 5;
        grid[16][17].isFixed = true;
        grid[18][16].value = 3;
        grid[18][16].isFixed = true;
        grid[19][16].value = 1;
        grid[19][16].isFixed = true;
        grid[19][17].value = 2;
        grid[19][17].isFixed = true;
        grid[20][17].value = 8;
        grid[20][17].isFixed = true;
        grid[19][18].value = 3;
        grid[19][18].isFixed = true;
        grid[18][19].value = 4;
        grid[18][19].isFixed = true;
        grid[20][20].value = 2;
        grid[20][20].isFixed = true;
        grid[16][20].value = 7;
        grid[16][20].isFixed = true;
        grid[16][19].value = 6;
        grid[16][19].isFixed = true;
        grid[13][18].value = 7;
        grid[13][18].isFixed = true;
        grid[14][18].value = 4;
        grid[14][18].isFixed = true;
        grid[12][19].value = 8;
        grid[12][19].isFixed = true;
        grid[13][19].value = 3;
        grid[13][19].isFixed = true;
        grid[0][16].value = 5;
        grid[0][16].isFixed = true;
        grid[0][17].value = 7;
        grid[0][17].isFixed = true;
        grid[1][16].value = 9;
        grid[1][16].isFixed = true;
        grid[1][17].value = 3;
        grid[1][17].isFixed = true;
        grid[3][15].value = 9;
        grid[3][15].isFixed = true;
        grid[5][16].value = 1;
        grid[5][16].isFixed = true;
        grid[6][16].value = 8;
        grid[6][16].isFixed = true;
        grid[6][17].value = 5;
        grid[6][17].isFixed = true;
        grid[8][15].value = 3;
        grid[8][15].isFixed = true;
        grid[8][16].value = 7;
        grid[8][16].isFixed = true;
        grid[0][20].value = 9;
        grid[0][20].isFixed = true;
        grid[2][19].value = 2;
        grid[2][19].isFixed = true;
        grid[2][18].value = 7;
        grid[2][18].isFixed = true;
        grid[4][19].value = 1;
        grid[4][19].isFixed = true;
        grid[5][18].value = 4;
        grid[5][18].isFixed = true;
        grid[6][18].value = 3;
        grid[6][18].isFixed = true;
        grid[7][19].value = 4;
        grid[7][19].isFixed = true;
        grid[6][20].value = 2;
        grid[6][20].isFixed = true;
        grid[7][20].value = 6;
        grid[7][20].isFixed = true;
    }

    static bool isCellInGrid(const int gridIdx, const int x, const int y, int &local_r, int &local_c) {
        switch (gridIdx) {
            case 0:
                if (x >= 6 && x <= 14 && y >= 6 && y <= 14) {
                    local_r = x - 6;
                    local_c = y - 6;
                    return true;
                }
                break;
            case 1:
                if (x >= 0 && x <= 8 && y >= 0 && y <= 8) {
                    local_r = x;
                    local_c = y;
                    return true;
                }
                break;
            case 2:
                if (x >= 0 && x <= 8 && y >= 12 && y <= 20) {
                    local_r = x;
                    local_c = y - 12;
                    return true;
                }
                break;
            case 3:
                if (x >= 12 && x <= 20 && y >= 0 && y <= 8) {
                    local_r = x - 12;
                    local_c = y;
                    return true;
                }
                break;
            case 4:
                if (x >= 12 && x <= 20 && y >= 12 && y <= 20) {
                    local_r = x - 12;
                    local_c = y - 12;
                    return true;
                }
                break;
            default: ;
        }
        return false;
    }

    [[nodiscard]] bool checkLoseCondition(const int x, const int y, const int new_value) const {
        for (int gridIdx = 0; gridIdx < 5; ++gridIdx) {
            int local_r, local_c;
            if (!isCellInGrid(gridIdx, x, y, local_r, local_c)) continue;


            int row_count = 0;
            for (int c = 0; c < 9; ++c) {
                int gx, gy;
                getGlobalCoords(gridIdx, local_r, c, gx, gy);
                const int val = (gx == x && gy == y) ? new_value : grid[gx][gy].value;
                if (val == new_value) row_count++;
            }
            if (row_count >= 3) return true;


            int col_count = 0;
            for (int r = 0; r < 9; ++r) {
                int gx, gy;
                getGlobalCoords(gridIdx, r, local_c, gx, gy);
                int val = (gx == x && gy == y) ? new_value : grid[gx][gy].value;
                if (val == new_value) col_count++;
            }
            if (col_count >= 3) return true;


            const int subgrid_r = 3 * (local_r / 3);
            const int subgrid_c = 3 * (local_c / 3);
            int sub_count = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int r = subgrid_r + i;
                    int c = subgrid_c + j;
                    int gx, gy;
                    getGlobalCoords(gridIdx, r, c, gx, gy);
                    int val = (gx == x && gy == y) ? new_value : grid[gx][gy].value;
                    if (val == new_value) sub_count++;
                }
            }
            if (sub_count >= 3) return true;
        }
        return false;
    }

    [[nodiscard]] bool checkWinCondition() const {
        for (const auto &i: grid)
            for (const auto j: i)
                if (j.value == 0) return false;
        return true;
    }

private:
    static void getGlobalCoords(const int gridIdx, int r, int c, int &gx, int &gy) {
        switch (gridIdx) {
            case 0: gx = 6 + r;
                gy = 6 + c;
                break;
            case 1: gx = r;
                gy = c;
                break;
            case 2: gx = r;
                gy = 12 + c;
                break;
            case 3: gx = 12 + r;
                gy = c;
                break;
            case 4: gx = 12 + r;
                gy = 12 + c;
                break;
            default: ;
        }
    }
};

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window *window = SDL_CreateWindow("Samurai Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE,
                                          WINDOW_SIZE, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font *font = TTF_OpenFont("C:/Users/LOQ/Downloads/samurai-sudoku/font/arial.ttf", 20);
    if (!font) {
        // printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        return 1;
    }

    SamuraiSudoku game;
    int selectedX = -1, selectedY = -1;
    bool quit = false, gameOver = false, won = false;

    std::vector<std::string> movesLog;

    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                const int cellX = x / CELL_SIZE;
                if (const int cellY = y / CELL_SIZE;
                    cellX >= 0 && cellX < GRID_SIZE && cellY >= 0 && cellY < GRID_SIZE) {
                    if (!game.grid[cellX][cellY].isFixed) {
                        selectedX = cellX;
                        selectedY = cellY;
                    } else {
                        selectedX = selectedY = -1;
                    }
                }
            } else if (e.type == SDL_KEYDOWN && !gameOver) {
                if (selectedX != -1 && selectedY != -1) {
                    if (e.key.keysym.sym >= SDLK_1 && e.key.keysym.sym <= SDLK_9) {
                        int num = e.key.keysym.sym - SDLK_0;
                        if (!game.checkLoseCondition(selectedX, selectedY, num)) {
                            game.grid[selectedX][selectedY].value = num;
                            movesLog.push_back(
                                "grid[" + std::to_string(selectedX) + "][" + std::to_string(selectedY) +
                                "].value = " + std::to_string(num) + "; " +
                                "grid[" + std::to_string(selectedX) + "][" + std::to_string(selectedY) +
                                "].isFixed = true;"
                            );
                            if (game.checkWinCondition()) {
                                gameOver = true;
                                won = true;
                            }
                        } else {
                            gameOver = true;
                            won = false;
                        }
                    } else if (e.key.keysym.sym == SDLK_BACKSPACE) {
                        game.grid[selectedX][selectedY].value = 0;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        for (int gridIdx = 0; gridIdx < 5; ++gridIdx) {
            int startX = 0, startY = 0, endX = 0, endY = 0;
            switch (gridIdx) {
                case 0: startX = 6 * CELL_SIZE;
                    startY = 6 * CELL_SIZE;
                    endX = 15 * CELL_SIZE;
                    endY = 15 * CELL_SIZE;
                    break;
                case 1: startX = 0;
                    startY = 0;
                    endX = 9 * CELL_SIZE;
                    endY = 9 * CELL_SIZE;
                    break;
                case 2: startX = 0;
                    startY = 12 * CELL_SIZE;
                    endX = 9 * CELL_SIZE;
                    endY = 21 * CELL_SIZE;
                    break;
                case 3: startX = 12 * CELL_SIZE;
                    startY = 0;
                    endX = 21 * CELL_SIZE;
                    endY = 9 * CELL_SIZE;
                    break;
                case 4: startX = 12 * CELL_SIZE;
                    startY = 12 * CELL_SIZE;
                    endX = 21 * CELL_SIZE;
                    endY = 21 * CELL_SIZE;
                    break;
                default: ;
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            for (int i = 0; i <= 9; ++i) {
                const int x = startX + i * CELL_SIZE;
                SDL_RenderDrawLine(renderer, x, startY, x, endY);
                const int y = startY + i * CELL_SIZE;
                SDL_RenderDrawLine(renderer, startX, y, endX, y);
                if (i % 3 == 0) {
                    SDL_RenderDrawLine(renderer, x - 1, startY, x - 1, endY);
                    SDL_RenderDrawLine(renderer, x + 1, startY, x + 1, endY);
                    SDL_RenderDrawLine(renderer, startX, y - 1, endX, y - 1);
                    SDL_RenderDrawLine(renderer, startX, y + 1, endX, y + 1);
                }
            }
        }

        // Draw numbers
        // SDL_Color black = {0, 0, 0, 255};
        // SDL_Color blue = {0, 0, 255, 255};
        // for (int i = 0; i < GRID_SIZE; ++i) {
        //     for (int j = 0; j < GRID_SIZE; ++j) {
        //         if (game.grid[i][j].value == 0) continue;
        //         const SDL_Color color = game.grid[i][j].isFixed ? black : blue;
        //         SDL_Surface* surface = TTF_RenderText_Solid(font, std::to_string(game.grid[i][j].value).c_str(), color);
        //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        //         SDL_Rect rect = {i * CELL_SIZE + 10, j * CELL_SIZE + 10, 20, 20};
        //         SDL_RenderCopy(renderer, texture, nullptr, &rect);
        //         SDL_FreeSurface(surface);
        //         SDL_DestroyTexture(texture);
        //     }
        // }
        SDL_Color black = {0, 0, 0, 255};
        SDL_Color blue = {0, 0, 255, 255};
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (game.grid[i][j].value == 0) continue;
                const SDL_Color color = game.grid[i][j].isFixed ? black : blue;
                SDL_Surface *surface = TTF_RenderText_Solid(font, std::to_string(game.grid[i][j].value).c_str(), color);
                SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);


                SDL_Rect rect = {
                    i * CELL_SIZE + (CELL_SIZE - surface->w) / 2,
                    j * CELL_SIZE + (CELL_SIZE - surface->h) / 2,
                    surface->w,
                    surface->h
                };

                SDL_RenderCopy(renderer, texture, nullptr, &rect);
                SDL_FreeSurface(surface);
                SDL_DestroyTexture(texture);
            }
        }
        if (selectedX != -1 && selectedY != -1) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_Rect rect = {selectedX * CELL_SIZE, selectedY * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            SDL_RenderDrawRect(renderer, &rect);
        }

        if (gameOver) {
            const SDL_Color color = won ? SDL_Color{0, 255, 0, 255} : SDL_Color{255, 0, 0, 255};
            const char *text = won ? "You Win!" : "You Lose!";
            SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect rect = {WINDOW_SIZE / 2 - 50, WINDOW_SIZE / 2 - 25, 100, 50};
            SDL_RenderCopy(renderer, texture, nullptr, &rect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
        SDL_RenderPresent(renderer);
    }

    std::ofstream outFile("saved_game.txt"); //a better idea
    if (outFile.is_open()) {
        for (const auto &line: movesLog) {
            outFile << line << "\n";
        }
        outFile.close();
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
