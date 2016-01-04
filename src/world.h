#ifndef GAMENAMEPLACEHOLDER_WORLD_H
#define GAMENAMEPLACEHOLDER_WORLD_H

#include "common.h"

struct world {
  int w;
  int h;
};

void world_init(struct world *world, int w, int h);
void world_update(struct world *world);
void world_free(struct world *world);


#endif /* GAMENAMEPLACEHOLDER_WORLD_H */
