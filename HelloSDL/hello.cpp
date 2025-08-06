#include <SDL3/SDL.h>
#include <cstdint>
#include <string>

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
    const std::string window_name = "Hello SDL";
    const int window_width = 640;
    const int window_height = 480;
    const std::uint32_t window_flags = 0u;
    const std::uint32_t program_quit_delay_ms = 2000; // 2000 ms = 2 sec

    // For the rest of this file, any time you see a function call that starts with "SDL_",
    // look up the function on https://wiki.libsdl.org and ask yourself these questions:
    // - What does the function do?
    // - How do the arguments to the function change the function's outcome?
    // - What does the function return and what can I do with that information?
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL2: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Pop Quiz (SDL):
    // 1) If I wanted to use audio and a controller in addition to video, how would I initialize those?

    SDL_Window * window = SDL_CreateWindow(window_name.c_str(),
                                           window_width, window_height,
                                           window_flags);

    // Pop Quiz (SDL):
    // 2) How would you make the window appear centered on the screen?

    if (window == nullptr) {
        SDL_Log("Couldn't create a window in SDL2: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Delay(program_quit_delay_ms);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // Pop Quiz (SDL and C++):
    // 3.a) Why do we need to call SDL_Quit() before we return EXIT_FAILURE if the window wasn't created?
    // 3.b) What happens if we remove the calls to SDL_DestroyWindow and SDL_Quit?

    return EXIT_SUCCESS;
}

// Answer Key:
// 1) SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)
// 2) Use SDL_SetWindowPosition with SDL_WINDOWPOS_CENTERED
//
// 3.a) SDL allocates resources when its subsystems are initialized.
//      These resources always need to be deallocated to prevent a memory leak.
// 3.b) Memory leak!
