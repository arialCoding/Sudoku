#include "Game.hpp"
#include "Sudoku.hpp"

#define SCR_WIDTH 80*8
#define SCR_HEIGHT 80*8

int Run()
{
    
    init();

    while(Engine::Get().isRunning())
    {
        Engine::Get().HandleEvents();

        update(0.f);

        Engine::Get().ClearScreen();

        render();

        Engine::Get().Present();

    }

    return 0;
}

SDL_Texture* boardTex;
SDL_Texture* numbers;

int board[9][9];

void reset()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = 0;
        }
    }
    generateBoard(board);
}

void init()
{
    if(!Engine::Get().Init(SCR_WIDTH, SCR_HEIGHT, "Sudoku"))
    {
        printf("Failed to initialize engine!\n");
        Engine::Get().Quit();
    }

    boardTex = Engine::Get().loadTexture("resource/board.png");
    numbers = Engine::Get().loadTexture("resource/Numbers.png");

    reset();
}

void update(float dt)
{
    if(Engine::Get().getMouseState().LMBreleased)
    {
        int row = Engine::Get().getMouseState().y / 72;
        int col = Engine::Get().getMouseState().x / 72;

        if(row >= 0 && row < 9 && col >= 0 && col < 9)
            board[row][col] = (board[row][col] + 1) % 10;
        
    }
    if(Engine::Get().getMouseState().RMBreleased)
    {
        int row = Engine::Get().getMouseState().y / 72;
        int col = Engine::Get().getMouseState().x / 72;

        if(row >= 0 && row < 9 && col >= 0 && col < 9)
            board[row][col] = (board[row][col] + 9) % 10;
        
    }

    if(boardFull(board) && validateBoard(board))
        printf("WON!\n");
    
}

void render()
{
    Engine::Get().Draw(boardTex, NULL, NULL);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] != 0)
            {
                SDL_Rect src = { (board[i][j]) * 16, 0, 16, 16 };
                SDL_Rect dest = { j * 72, i * 72, 64, 64 };
                Engine::Get().Draw(numbers, &src, &dest);
            }
        }
    }

}