/**
 * @file graphics.h
 * @brief This file contains the implementation of the graphics functions allowing drawing on the screen of MINIX
 * 
*/

#include <lcom/lcf.h>

#include <stdint.h>
#include <stdio.h>

#include "VBE.h"

#ifndef _LCOM_GRAPHICS_H_
#define _LCOM_GRAPHICS_H_

/**
 * @brief Macro to get the number of bytes for a given number of bits
*/
#define numberOfBytesForBits(bits) ((bits + 7) / 8)

/**
 * @brief VBE mode info getter
*/
vbe_mode_info_t (get_vbe_mode_info)();

/**
 * @brief Sets the graphic mode
 * @param mode mode to set
 * @return 0 if successful, non 0 otherwise
*/
int (set_graphic_mode)(uint16_t mode);

/**
 * @brief Sets the frame buffer
 * @param mode mode to set
 * @return 0 if successful, non 0 otherwise
*/
int (set_frame_buffer)(uint16_t mode);

/**
 * @brief Swaps the buffers
 * It should be use after drawed a complete frame
 * It avoids flickering
*/
void (swap_buffers)();

/**
 * @brief Draws a pixel on the screen
 * @param x x coordinate
 * @param y y coordinate
 * @param color color to draw
 * @return 0 if successful, non 0 otherwise
*/
int (vg_draw_pixel)(uint16_t x, uint16_t y, uint32_t color);

/**
 * @brief Draws a xpm image on the screen
 * @param xpm_image xpm image to draw
 * @param xpm_map xpm color map pointer
 * @param x x coordinate
 * @param y y coordinate
 * @param mode mode to draw
 * @return 0 if successful, non 0 otherwise
*/
int (vg_draw_xpm)(xpm_image_t xpm_image, uint8_t *xpm_map, uint16_t x, uint16_t y, uint16_t mode);

/**
 * @brief Draws partial (axle of x) of a xpm image on the screen
 * @param xpm_image xpm image to draw
 * @param xpm_map xpm color map pointer
 * @param x x coordinate
 * @param y y coordinate
 * @param image_start_x x coordinate of the image to start drawing
 * @param mode mode to draw
 * @return 0 if successful, non 0 otherwise
*/
int (vg_draw_xpm_partial)(xpm_image_t xpm_image, uint8_t *xpm_map, uint16_t x, uint16_t y, uint16_t image_start_x, uint16_t mode);

/**
 * @brief Draws a xpm image on the screen from the bottom left corner
 * @param xpm_image xpm image to draw
 * @param xpm_map xpm color map pointer
 * @param x x coordinate
 * @param y y coordinate
 * @param mode mode to draw
 * @return 0 if successful, non 0 otherwise
*/
int (vg_draw_xpm_from_bottom_left_corner)(xpm_image_t xpm_image, uint8_t *xpm_map, uint16_t x, uint16_t y, uint16_t mode);

/**
 * @brief Draws a rectangle on the screen from the bottom left corner
 * @param x x coordinate
 * @param y y coordinate
 * @param width rectangle width
 * @param height rectangle height
 * @param color color to draw
 * @return 0 if successful, non 0 otherwise
*/
int (vg_draw_rectangle_from_bottom_left_corner)(int16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

/**
 * @brief Draws a rectangle border on the screen
 * @param x x coordinate of inner rectangle
 * @param y y coordinate of inner rectangle
 * @param width rectangle width
 * @param height rectangle height
 * @param border_width border width
 * @param color color to draw
 * @return 0 if successful, non 0 otherwise
*/
int (vg_draw_rectangle_border)(int16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t border_width, uint32_t color);

/**
 * @brief clears the screen
*/
int vg_clear_screen();

#endif
