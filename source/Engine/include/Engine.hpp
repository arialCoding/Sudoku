#pragma once

#include <SDL2/SDL.h>

struct Key{
    bool pressed = false;
    bool released = false;
};

struct Mouse{
    bool RMBpressed = false, RMBreleased = false;
    bool LMBpressed = false, LMBreleased = false;
    bool MMBpressed = false, MMBreleased = false;

    int x, y;
};

class Engine
{
public:

    static Engine& Get(){
        return instance;
    }

    bool Init(int w, int h, const char* title);
    void HandleEvents();
    void ClearScreen();
    void Draw(SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dest);
    void Present();

    bool isRunning() { return running; }
    void Quit() { running = false; }

    Key* getInput() { return input; }
    Mouse& getMouseState() { return mouse; }

    SDL_Texture* loadTexture(const char* path);

private:
    Engine() {}

    static Engine instance;

    SDL_Renderer* renderer;
    SDL_Window* window;

    SDL_Event event;

    bool running = false;

    Key input[256];
    Mouse mouse;
};
