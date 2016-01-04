
#include "event.h"
#include "graphics.h"
#include "render.h"
#include "world.h"

#include <assert.h>
#include <time.h>
#include <stdlib.h>


int main(void) {
  SDL_Surface *surface;
  int start_time, end_time;
  struct world world;

  world_init(&world, 800, 480);

  srand(time(NULL));

  // TODO (jb55): configurable window size
  SDL_Window *window = SDL_CreateWindow(
    "sandbox-tile-game", 0, 0, 800, 480,
    SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

  SDL_GLContext *context =
    SDL_GL_CreateContext(window);

  while (1) {
    process_events(window, &world);

    start_time = SDL_GetTicks();

    render(&world);

    end_time = SDL_GetTicks();

    SDL_GL_SwapWindow(window);

    SDL_Delay(6);
  }

  SDL_GL_DeleteContext(window);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

