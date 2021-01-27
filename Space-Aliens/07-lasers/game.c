// Copyright (c) 2021 Sean McLeod All rights reserved.
//
// Created by: Sean McLeod
// Created on: January 2021
// This is the "Space Aliens" program on the GameBoy

#include <stdio.h>
#include <gb/gb.h>

#include "main_background_tiles.c"
#include "main_background_map.c"
#include <game_character.c>
#include <game_sprites.c>

#include <gb/drawing.h>
#include <gb/font.h>

GameCharacter ship;
GameCharacter alien;
GameCharacter laser;
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
    ship.x = 80;
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


void setUpAlien(){
    alien.x = 80;
    alien.y = 30;
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
    const UINT8 laserSpeed = 9;

    menuScene();

    set_bkg_data(0, 6, background_tiles);
    set_bkg_tiles(0, 0, 20, 18, main_background_map);

    set_sprite_data(0, 12, gameSprites);
    setUpShip();
    setUpAlien();
    setUpLaser();

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;


    while(1) {
        if (joypad() & J_LEFT) {
            if (ship.x <= spriteSize) {
                ship.x = spriteSize;
                moveGameCharacter(&ship, ship.x, ship.y);
            } else {
                ship.x -= 3;
                moveGameCharacter(&ship, ship.x, ship.y);
            }
        }
        if (joypad() & J_RIGHT) {
            if (ship.x >= screenX) {
                ship.x = screenX;
                moveGameCharacter(&ship, ship.x, ship.y);
            } else {
                ship.x += 3;
                moveGameCharacter(&ship, ship.x, ship.y);
            }
        }
        if (joypad() & J_UP) {
            if (ship.y <= 105) {
                ship.y = 105;
                moveGameCharacter(&ship, ship.x, ship.y);
            } else {
                ship.y -= 3;
                moveGameCharacter(&ship, ship.x, ship.y);
            }
        }
        if (joypad() & J_DOWN) {
            if (ship.y >= screenY) {
                ship.y = screenY;
                moveGameCharacter(&ship, ship.x, ship.y);
            } else {
                ship.y += 3;
                moveGameCharacter(&ship, ship.x, ship.y);
            }
        }
        // put laser off the screen if the laser touches the top of the screen
        if (laser.y < offTopScreen) {
            laser.x = offScreenX;
            laser.y = offScreenY;
            moveGameCharacter(&laser, laser.x, laser.y);
        }
        // when laser's x coordinate is off the screen, if the laser comes
        // within the y range of the screen, send it to off screen
        if (laser.x > screenX) {
            if (laser.y > offTopScreen && laser.y < screenY) {
                laser.x = offScreenX;
                laser.y = offScreenY;
                moveGameCharacter(&laser, laser.x, laser.y);
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
        
        performantDelay(5);
    }
}
