
#include "render.h"
#include "world.h"


void renderer_init_opengl() {
  /* Enable smooth shading */
  glShadeModel( GL_SMOOTH );

  /* Set the background black */
  glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

  /* Depth buffer setup */
  glClearDepth( 1.0f );

  /* Enables Depth Testing */
  glEnable( GL_DEPTH_TEST );

  /* The Type Of Depth Test To Do */
  glDepthFunc( GL_LEQUAL );

  /* Really Nice Perspective Calculations */
  glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}


void renderer_set_viewport(int width, int height) {
  /* Height / width ration */
  GLfloat ratio;

  /* Protect against a divide by zero */
  if ( height == 0 ) {
    height = 1;
  }

  ratio = ( GLfloat )width / ( GLfloat )height;

  /* Setup our viewport. */
  glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

  /* change to the projection matrix and set our viewing volume. */
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );

  /* Set our perspective */
  /* gluPerspective( 45.0f, ratio, 0.1f, 100.0f ); */

  /* Make sure we're chaning the model view and not the projection */
  glMatrixMode( GL_MODELVIEW );

  /* Reset The View */
  glLoadIdentity( );

}

void render() {

}

void render_example(SDL_Surface *surface, struct world *world) {
    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    /* Move Left 1.5 Units And Into The Screen 6.0 */
    glLoadIdentity();
    glTranslatef( -1.5f, 0.0f, -6.0f );

    glBegin( GL_TRIANGLES );            /* Drawing Using Triangles */
      glVertex3f(  0.0f,  1.0f, 0.0f ); /* Top */
      glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
      glVertex3f(  1.0f, -1.0f, 0.0f ); /* Bottom Right */
    glEnd( );                           /* Finished Drawing The Triangle */

    /* Move Right 3 Units */
    glTranslatef( 3.0f, 0.0f, 0.0f );

    glBegin( GL_QUADS );                /* Draw A Quad */
      glVertex3f( -1.0f,  1.0f, 0.0f ); /* Top Left */
      glVertex3f(  1.0f,  1.0f, 0.0f ); /* Top Right */
      glVertex3f(  1.0f, -1.0f, 0.0f ); /* Bottom Right */
      glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
    glEnd( );                           /* Done Drawing The Quad */
}
