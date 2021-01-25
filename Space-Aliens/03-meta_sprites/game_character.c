#include <gb/gb.h>

typedef struct GameCharacter {
    UBYTE spriteids[4];  // all character uses 4 sprites
    UINT8 x;
    UINT8 y;
    UINT8 width;
    UINT8 height;
} GameCharacter;
