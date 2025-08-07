#include <SDL2/SDL.h>
#include <cstdint>
#include <string>

// In this tutorial series, I mostly won't be explaining the code line by line. Instead, I'll assume
// that you've looked up the functions I use on https://wiki.libsdl.org to understand what they do, or have
// done other research to find more context about how a library feature or technology is meant to be used.
// Then to test you're understanding, I'll ask questions that review the bits I think are important,
// confusing or often overlooked.
//
// To help with your understanding, I'd recommend asking yourself these questions when you're reading the
// documentation:
// - What does the function do?
// - How do the arguments to the function change the function's outcome?
// - What does the function return and what can I do with that information?

// We'll just do a few simple things in this first example:
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

    if (SDL_Init(SDL_INIT_VIDEO) != SDL_INIT_SUCCESS) {
        SDL_Log("Couldn't initialize SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Pop Quiz (SDL):
    // 1.a) If you wanted to use audio and a controller in addition to video, how would you initialize those
    //      systems? How do you combine the system flags passed to the init function?
    // 1.b) If we hadn't defined the macro SDL_INIT_SUCCESS earlier, the conditional expression would have been
    //      SDL_Init(SDL_INIT_VIDEO) != 0. Is it clear what role 0 plays? How might that expression be misread?

    SDL_Window * window = SDL_CreateWindow(window_name.c_str(),
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                           window_width, window_height,
                                           window_flags);

    // Pop Quiz (SDL):
    // 2) How would you make the window appear centered on the screen?

    if (window == nullptr) {
        SDL_Log("Couldn't create a window in SDL: %s\n", SDL_GetError());
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
