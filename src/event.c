
#include "event.h"
#include "common.h"
#include "world.h"

void process_events(const SDL_Window *window,
                    struct world *world) {
  SDL_Event event;
  u16 x, y;
  static bool left_down = false;
  static bool right_down = false;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_WINDOWEVENT_RESIZED:
      /* SDL_SetWindowSize(window, event.window.data1, event.window.data2); */
      break;
    case SDL_MOUSEMOTION:
      break;
    case SDL_MOUSEBUTTONDOWN:
      x = event.button.x;
      y = event.button.y;

      switch (event.button.button) {
      case SDL_BUTTON_LEFT: left_down = true; break;
      case SDL_BUTTON_RIGHT: right_down = true; break;
      }
      break;
    case SDL_MOUSEBUTTONUP:
      switch (event.button.button) {
      case SDL_BUTTON_LEFT: left_down = false; break;
      case SDL_BUTTON_RIGHT: right_down = false; break;
      }
      break;
    case SDL_KEYUP:
      printf("key %d\n", event.key.keysym.sym);
      char key = event.key.keysym.sym;
      switch (key) {
      case 'c':
        break;
      default:
        if (key >= '0' && key <= '9')
          ;
        break;
      }
      break;
    case SDL_QUIT:
      SDL_Quit();
      exit(0);
    }
  }
}
