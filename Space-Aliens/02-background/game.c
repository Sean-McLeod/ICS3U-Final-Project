// Copyright (c) 2021 Sean McLeod All rights reserved.
//
// Created by: Sean McLeod
// Created on: January 2021
// This is the "Space Aliens" program on the GameBoy

#include <stdio.h>
#include <gb/gb.h>

#include "main_background_tiles.c"
#include "main_background_map.c"


void main() {
    set_bkg_data(0, 6, background_tiles);
    set_bkg_tiles(0, 0, 20, 18, main_background_map);
    
    SHOW_BKG;
    DISPLAY_ON;
}
