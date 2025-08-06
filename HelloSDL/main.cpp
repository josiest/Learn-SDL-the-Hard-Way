#include <SDL2/SDL.h>
#include <cstdint>

// We'll just do a few simple things in this example:
// - boot up SDL
// - create a window with a custom name
// - wait for a couple seconds then quit the program

// We'll need to initialize the SDL library to use it, but it's possible something may go wrong.
// This definition will clarify the logic of what to do when something does go wrong.
#define SDL_INIT_SUCCESS 0

int main(int argc, char * argv[])
{
    // These are arbitrary values we'll use to configure our program. Feel free to change them to your liking.
    // We've hard-coded them for the sake of simplicity, but in the future we may want to read them from a file.
    constexpr char window_name[] = "Hello SDL2";
    constexpr int window_width = 640;
    constexpr int window_height = 480;
    constexpr std::uint32_t program_quit_delay_ms = 2000; // 2000 ms = 2 sec

    // Pop Quiz (Advanced C++):
    // 1.a) How does the keyword constexpr change how we use these variables?
    // 1.b) What are some reasons why I might want to declare window_name as char[] instead of string?
    // 1.c) If we read these values from a file, can they still be constexpr?

    // For the rest of this file, any time you see a function call that starts with "SDL_",
    // look up the function on https://wiki.libsdl.org and ask yourself these questions:
    // - What does the function do?
    // - How do the arguments to the function change the function's outcome?
    // - What does the function return and what can I do with that information?
    if (SDL_Init(SDL_INIT_VIDEO) != SDL_INIT_SUCCESS) {
        SDL_Log("Couldn't initialize SDL2: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Pop Quiz (SDL):
    // 2.a) Why do we need to initialize SDL?
    // 2.b) If I wanted to use audio and a controller in addition to video, how would I initialize those?
    // 2.c) If we hadn't defined the macro SDL_INIT_SUCCESS earlier, the conditional expression would have been
    //      SDL_Init(SDL_INIT_VIDEO) != 0. Is it clear what role 0 plays? How might that expression be misread?

    SDL_Window * window = SDL_CreateWindow(window_name,
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                           window_width, window_height,
                                           SDL_WINDOW_SHOWN);

    // Pop Quiz (SDL):
    // 3.a) How does SDL_WINDOWPOS_UNDEFINED affect the position of the window on the screen?
    // 3.b) How would you make the window appear centered on the screen?
    // 3.c) Why might I have chosen to put SDL_WINDOW_SHOWN in the last argument - does it need to be there?
    //      If you add other window flags, why would you keep or remove SDL_WINDOW_SHOWN?

    if (window == nullptr) {
        SDL_Log("Couldn't create a window in SDL2: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Delay(program_quit_delay_ms);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // Pop Quiz (SDL and C++):
    // 4.a) Why do we need to call SDL_Quit() before we return EXIT_FAILURE if the window wasn't created?
    // 4.b) What happens if we remove the calls to SDL_DestroyWindow and SDL_Quit?

    return EXIT_SUCCESS;
}