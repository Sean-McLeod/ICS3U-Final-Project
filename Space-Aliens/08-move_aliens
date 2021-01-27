// Copyright (c) 2021 Sean McLeod All rights reserved.
//
// Created by: Sean McLeod
// Created on: January 2021
// This is the "Space Aliens" program on the GameBoy

#include <stdio.h>
#include <gb/gb.h>
#include <rand.h>

#include "main_background_tiles.c"
#include "main_background_map.c"
#include <game_character.c>
#include <game_sprites.c>

#include <gb/drawing.h>
#include <gb/font.h>

GameCharacter ship;
GameCharacter alien;
GameCharacter laser;
GameCharacter alien1;
GameCharacter alien2;
GameCharacter alien3;
GameCharacter alien4;
const UBYTE spriteSize = 8;
const UINT8 offScreenX = 200;
const UINT8 offScreenY = 200;


void performantDelay(UINT8 loops) {
    UINT8 counter;

    for (counter = 0; counter < loops; counter++) {
        wait_vbl_done();
    }
}


void moveGameCharacter(GameCharacter* sprite, UINT8 coordinateX, UINT8 coordinateY) {
    move_sprite(sprite->spriteids[0], coordinateX, coordinateY);
    move_sprite(sprite->spriteids[1], coordinateX + spriteSize, coordinateY);
    move_sprite(sprite->spriteids[2], coordinateX, coordinateY + spriteSize);
    move_sprite(sprite->spriteids[3], coordinateX + spriteSize, coordinateY + spriteSize);
}


void setUpShip() {
    ship.x = 82;
    ship.y = 120;
    ship.width = 16;
    ship.height = 16;

    // load sprites for ship
    set_sprite_tile(0, 0);
    ship.spriteids[0] = 0;
    set_sprite_tile(1, 1);
    ship.spriteids[1] = 1;
    set_sprite_tile(2, 2);
    ship.spriteids[2] = 2;
    set_sprite_tile(3, 3);
    ship.spriteids[3] = 3;

    moveGameCharacter(&ship, ship.x, ship.y);
}


void setUpAlien() {
    alien.x = offScreenX;
    alien.y = offScreenY;
    alien.width = 16;
    alien.height = 16;

    // load sprites for ship
    set_sprite_tile(4, 4);
    alien.spriteids[0] = 4;
    set_sprite_tile(5, 5);
    alien.spriteids[1] = 5;
    set_sprite_tile(6, 6);
    alien.spriteids[2] = 6;
    set_sprite_tile(7, 7);
    alien.spriteids[3] = 7;
    
    moveGameCharacter(&alien, alien.x, alien.y);
}


void setUpLaser() {
    laser.x = offScreenX;
    laser.y = offScreenY;
    laser.width = 16;
    laser.height = 16;

    // load sprites for laser
    set_sprite_tile(8, 8);
    laser.spriteids[0] = 8;
    set_sprite_tile(9, 9);
    laser.spriteids[1] = 9;
    set_sprite_tile(10, 10);
    laser.spriteids[2] = 10;
    set_sprite_tile(11, 11);
    laser.spriteids[3] = 11;

    moveGameCharacter(&laser, laser.x, laser.y);
}


void setUpAlien1() {
    alien1.x = offScreenX;
    alien1.y = offScreenY;
    alien1.width = 16;
    alien1.height = 16;

    // load sprites for alien1
    set_sprite_tile(12, 12);
    alien1.spriteids[0] = 12;
    set_sprite_tile(13, 13);
    alien1.spriteids[1] = 13;
    set_sprite_tile(14, 14);
    alien1.spriteids[2] = 14;
    set_sprite_tile(15, 15);
    alien1.spriteids[3] = 15;

    moveGameCharacter(&alien1, alien1.x, alien1.y);
}


void setUpAlien2() {
    alien2.x = offScreenX;
    alien2.y = offScreenY;
    alien2.width = 16;
    alien2.height = 16;

    // load sprites for alien2
    set_sprite_tile(16, 16);
    alien2.spriteids[0] = 16;
    set_sprite_tile(17, 17);
    alien2.spriteids[1] = 17;
    set_sprite_tile(18, 18);
    alien2.spriteids[2] = 18;
    set_sprite_tile(19, 19);
    alien2.spriteids[3] = 19;

    moveGameCharacter(&alien2, alien2.x, alien2.y);
}


void setUpAlien3() {
    alien3.x = offScreenX;
    alien3.y = offScreenY;
    alien3.width = 16;
    alien3.height = 16;

    // load sprites for alien3
    set_sprite_tile(20, 20);
    alien3.spriteids[0] = 20;
    set_sprite_tile(21, 21);
    alien3.spriteids[1] = 21;
    set_sprite_tile(22, 22);
    alien3.spriteids[2] = 22;
    set_sprite_tile(23, 23);
    alien3.spriteids[3] = 23;

    moveGameCharacter(&alien3, alien3.x, alien3.y);
}


void setUpAlien4() {
    alien4.x = offScreenX;
    alien4.y = offScreenY;
    alien4.width = 16;
    alien4.height = 16;

    // load sprites for alien3
    set_sprite_tile(24, 24);
    alien4.spriteids[0] = 24;
    set_sprite_tile(25, 25);
    alien4.spriteids[1] = 25;
    set_sprite_tile(26, 26);
    alien4.spriteids[2] = 26;
    set_sprite_tile(27, 27);
    alien4.spriteids[3] = 27;

    moveGameCharacter(&alien4, alien4.x, alien4.y);
}


void menuScene() {
    // declare that min_font and standard_font is a font
    font_t standard_font, min_font;

    // initialize font system
    font_init();

    // load all the fonts
    color(DKGREY, WHITE, SOLID);  // set color
    standard_font = font_load(font_ibm);
    color(WHITE, BLACK, SOLID);  // set color
    min_font = font_load(font_min);

    // set the current font to standard_font
    font_set(standard_font);
    printf("\n\n    SPACE ALIENS");
    // set the current font to min_font
    font_set(min_font);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n     PRESS START    ");

    waitpad(J_START);
}


void main() {
    const UINT8 screenX = 152;
    const UINT8 screenY = 128;
    const UINT8 offTopScreen = 10;
    const UINT8 laserSpeed = 15;
    const UINT8 alienSpeed = 6;
    const UINT8 shipSpeed = 5;
    UINT8 randomNumber;
    
    menuScene();

    set_bkg_data(0, 6, background_tiles);
    set_bkg_tiles(0, 0, 20, 18, main_background_map);

    set_sprite_data(0, 28, gameSprites);
    setUpShip();
    setUpAlien();
    setUpLaser();
    setUpAlien1();
    setUpAlien2();
    setUpAlien3();
    setUpAlien4();
    
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    while(alien.y >= offTopScreen + spriteSize) {
        alien.x = 82;
        alien.y -= alienSpeed - 2;
        
        moveGameCharacter(&alien, alien.x, alien.y);
        performantDelay(5);        
    }

    
    while(1) {
        if (joypad() & J_LEFT) {
            if (ship.x <= spriteSize) {
                ship.x = spriteSize;
                moveGameCharacter(&ship, ship.x, ship.y);
            } else {
                ship.x -= shipSpeed;
                moveGameCharacter(&ship, ship.x, ship.y);
            }
        }
        if (joypad() & J_RIGHT) {
            if (ship.x >= screenX) {
                ship.x = screenX;
                moveGameCharacter(&ship, ship.x, ship.y);
            } else {
                ship.x += shipSpeed;
                moveGameCharacter(&ship, ship.x, ship.y);
            }
        }
        if (joypad() & J_UP) {
            if (ship.y <= 105) {
                ship.y = 105;
                moveGameCharacter(&ship, ship.x, ship.y);
            } else {
                ship.y -= shipSpeed;
                moveGameCharacter(&ship, ship.x, ship.y);
            }
        }
        if (joypad() & J_DOWN) {
            if (ship.y >= screenY) {
                ship.y = screenY;
                moveGameCharacter(&ship, ship.x, ship.y);
            } else {
                ship.y += shipSpeed;
                moveGameCharacter(&ship, ship.x, ship.y);
            }
        }
        if (laser.y < offTopScreen) {
            laser.x = offScreenX;
            laser.y = offScreenY;
            moveGameCharacter(&laser, laser.x, laser.y);
        }
        if ((joypad() & J_A) && (laser.y > screenY)) {
            laser.x = ship.x;
            laser.y = ship.y;
            moveGameCharacter(&laser, laser.x, laser.y);
        }

        laser.y -= laserSpeed;
        moveGameCharacter(&laser, laser.x, laser.y);
        
        // alien falls down
        alien.y += alienSpeed;
        moveGameCharacter(&alien, alien.x, alien.y);
        
        // This part of the code is a comment just for now, for convenience
        
        // alien1.y += alienSpeed;
        // moveGameCharacter(&alien1, alien1.x, alien1.y);
        // alien2.y += alienSpeed;
        // moveGameCharacter(&alien2, alien2.x, alien2.y);
        // alien3.y += alienSpeed;
        // moveGameCharacter(&alien3, alien3.x, alien3.y);
        // alien4.y += alienSpeed;
        // moveGameCharacter(&alien4, alien4.x, alien4.y);
        
        
        // if the alien is off screen, put it back up 
        //     on a random x coordinate
        if (alien.y > offScreenY) {
            alien.y = 0;
            randomNumber = (rand() % (screenX - spriteSize + 1) + spriteSize);
            alien.x = randomNumber;
            
            moveGameCharacter(&alien, alien.x, alien.y);
        }
            
        // This part of the code is a comment just for now, for convenience
        
        // if (alien1.y > offScreenY) {
        //     alien1.y = 0;
        //     randomNumber = (rand() % (screenX - spriteSize + 1) + spriteSize);
        //     alien1.x = randomNumber;
            
        //     moveGameCharacter(&alien1, alien1.x, alien1.y);
        // }
        
        // if (alien2.y > offScreenY) {
        //     alien2.y = 0;
        //     randomNumber = (rand() % (screenX - spriteSize + 1) + spriteSize);
        //     alien2.x = randomNumber;
            
        //     moveGameCharacter(&alien2, alien2.x, alien2.y);
        // }
            
        // if (alien3.y > offScreenY) {
        //     alien3.y = 0;
        //     randomNumber = (rand() % (screenX - spriteSize + 1) + spriteSize);
        //     alien3.x = randomNumber;
            
        //     moveGameCharacter(&alien3, alien3.x, alien3.y);

        // }
        // if (alien4.y > offScreenY) {
        //     alien4.y = 0;
        //     randomNumber = (rand() % (screenX - spriteSize + 1) + spriteSize);
        //     alien4.x = randomNumber;
            
        //     moveGameCharacter(&alien4, alien4.x, alien4.y);
        // }

        performantDelay(5);
    }
}
