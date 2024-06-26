#include "sdl_func.h"


int isKeyDown(SDL_Event event){
    if(event.type==SDL_KEYDOWN)
        return 1;
    return 0;
}
int isKeyUp(SDL_Event event){
    if(event.type==SDL_KEYUP)
        return 1;
    return 0;
}
int isKeyHeld(SDL_Event event){
    if((isKeyDown(event) || isKeyUp(event))
       && event.key.state == SDL_PRESSED){
       return 1;
    }
    return 0;
}

KEY_CODE getKeyPressed(SDL_Event event){
    return event.key.keysym.sym;
}

void setDelay (int* var, int time){
    *var = SDL_GetTicks() + time;
    return;
}

int delayPassed (int *var){
    if(*var < SDL_GetTicks() )
        return 1;
    return 0; 
}