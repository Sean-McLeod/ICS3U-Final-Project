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

GameCharacter ship;
GameCharacter alien;


void performantDelay(UINT8 loops) {
    UINT8 counter;

    for (counter = 0; counter < loops; counter++) {
        wait_vbl_done();
    }
}


void moveGameCharacter(GameCharacter* sprite, UINT8 coordinateX, UINT8 coordinateY) {
    const UBYTE spriteSize = 8;

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


void main() {
    set_bkg_data(0, 6, background_tiles);
    set_bkg_tiles(0, 0, 20, 18, main_background_map);
    
    set_sprite_data(0, 8, game_sprites);
    setUpShip();
    setUpAlien();
    
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    
    while(1) {
        if (joypad() & J_LEFT) {
            ship.x -= 3;
            moveGameCharacter(&ship, ship.x, ship.y);
        }
        if (joypad() & J_RIGHT) {
            ship.x += 3;
            moveGameCharacter(&ship, ship.x, ship.y);
        }
        if (joypad() & J_UP) {
            ship.y -= 3;
            moveGameCharacter(&ship, ship.x, ship.y);
        }
        if (joypad() & J_DOWN) {
            ship.y += 3;
            moveGameCharacter(&ship, ship.x, ship.y);
        }
        performantDelay(5);
    }
}
