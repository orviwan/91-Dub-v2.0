#include <pebble.h>

#ifdef PBL_COLOR
char* get_gbitmapformat_text(GBitmapFormat format);
char* get_gcolor_text(GColor m_color);
void replace_gbitmap_color(GColor color_to_replace, GColor replace_with_color, GBitmap *im, BitmapLayer *bml);
void spit_gbitmap_color_palette(GBitmap *im);
bool gbitmap_color_palette_contains_color(GColor m_color, GBitmap *im);
#endif