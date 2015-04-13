
#include <gbitmap_colour_manipulator.h>

#ifdef PBL_COLOR

char* get_gbitmapformat_text(GBitmapFormat format){
	switch (format) {
		case GBitmapFormat1Bit: return "GBitmapFormat1Bit";
		case GBitmapFormat8Bit: return "GBitmapFormat8Bit";
		case GBitmapFormat1BitPalette: return "GBitmapFormat1BitPalette";
		case GBitmapFormat2BitPalette: return "GBitmapFormat2BitPalette";
		case GBitmapFormat4BitPalette: return "GBitmapFormat4BitPalette";

		default: return "UNKNOWN FORMAT";
	}

}

int get_num_palette_colors(GBitmap *b){

	GBitmapFormat format = gbitmap_get_format(b);

	switch (format) {
		case GBitmapFormat1Bit: return 0;
		case GBitmapFormat8Bit: return 0;
		case GBitmapFormat1BitPalette: return 2;
		case GBitmapFormat2BitPalette: return 4;
		case GBitmapFormat4BitPalette: return 16;

		default: return 0;
	}

}

void replace_gbitmap_color(GColor color_to_replace, GColor replace_with_color, GBitmap *im, BitmapLayer *bml){

	//First determine what the humber of colors in the palette
	int num_palette_items = get_num_palette_colors(im);

	//APP_LOG(APP_LOG_LEVEL_DEBUG, "Palette has %d items", num_palette_items);

	//Get the gbitmap's current palette
	GColor *current_palette = gbitmap_get_palette(im);

	//Iterate through the palette finding the color we want to replace and replacing 
	//it with the new color
	//APP_LOG(APP_LOG_LEVEL_DEBUG, "--replace_image_color Palette Start--");
	for(int i = 0; i < num_palette_items; i++){

		char * pal_i_col = get_gcolor_text(current_palette[i]);

		//APP_LOG(APP_LOG_LEVEL_DEBUG, "Palette[%d] = %s", i, pal_i_col);

		if(GColorEq(color_to_replace, current_palette[i])){
			current_palette[i] = replace_with_color;
			//APP_LOG(APP_LOG_LEVEL_DEBUG, "--------------replaced with %s", get_gcolor_text(current_palette[i]) );

			break;//the color can only appear once in the palette
		}

	}
	//APP_LOG(APP_LOG_LEVEL_DEBUG, "--Palette End--");

	//Mark the bitmaplayer dirty
	layer_mark_dirty(bitmap_layer_get_layer(bml));

}

bool gbitmap_color_palette_contains_color(GColor m_color, GBitmap *im){

	int num_palette_items = get_num_palette_colors(im);
	GColor *current_palette = gbitmap_get_palette(im);
	for(int i = 0; i < num_palette_items; i++){

		if(GColorEq(m_color, current_palette[i])){
			//APP_LOG(APP_LOG_LEVEL_DEBUG, "GBitmap contains: %s", get_gcolor_text(current_palette[i]));

			return true;
		}

	}

	//APP_LOG(APP_LOG_LEVEL_DEBUG, "GBitmap does not contain: %s", get_gcolor_text(m_color));
	return false;

}

void spit_gbitmap_color_palette(GBitmap *im){

	//First determine what the humber of colors in the palette
	int num_palette_items = get_num_palette_colors(im);

	//APP_LOG(APP_LOG_LEVEL_DEBUG, "Palette has %d items", num_palette_items);

	GColor *current_palette = gbitmap_get_palette(im);

	GColor new_palette[num_palette_items];

	memcpy(new_palette, current_palette, num_palette_items * sizeof(GColor));

	//APP_LOG(APP_LOG_LEVEL_DEBUG, "--Spit Palette Start--");
	for(int i = 0; i < num_palette_items; i++){

		//APP_LOG(APP_LOG_LEVEL_DEBUG, "Palette[%d] = %s", i, get_gcolor_text(new_palette[i]));

	}
	//APP_LOG(APP_LOG_LEVEL_DEBUG, "--Palette End--");

}

char* get_gcolor_text(GColor m_color){
	
	if(GColorEq(m_color, GColorBlack)) return "GColorBlack";
	if(GColorEq(m_color, GColorOxfordBlue)) return "GColorOxfordBlue";
	if(GColorEq(m_color, GColorDukeBlue)) return "GColorDukeBlue";
	if(GColorEq(m_color, GColorBlue)) return "GColorBlue";
	if(GColorEq(m_color, GColorDarkGreen)) return "GColorDarkGreen";
	if(GColorEq(m_color, GColorMidnightGreen)) return "GColorMidnightGreen";
	if(GColorEq(m_color, GColorCobaltBlue)) return "GColorCobaltBlue";
	if(GColorEq(m_color, GColorBlueMoon)) return "GColorCobaltBlue";
	if(GColorEq(m_color, GColorIslamicGreen)) return "GColorIslamicGreen";
	if(GColorEq(m_color, GColorJaegerGreen)) return "GColorJaegerGreen";
	if(GColorEq(m_color, GColorTiffanyBlue)) return "GColorTiffanyBlue";
	if(GColorEq(m_color, GColorVividCerulean)) return "GColorVividCerulean";
	if(GColorEq(m_color, GColorGreen)) return "GColorGreen";
	if(GColorEq(m_color, GColorMalachite)) return "GColorMalachite";
	if(GColorEq(m_color, GColorMediumSpringGreen)) return "GColorMediumSpringGreen";
	if(GColorEq(m_color, GColorCyan)) return "GColorCyan";
	if(GColorEq(m_color, GColorBulgarianRose)) return "GColorBulgarianRose";
	if(GColorEq(m_color, GColorImperialPurple)) return "GColorImperialPurple";
	if(GColorEq(m_color, GColorIndigo)) return "GColorIndigo";
	if(GColorEq(m_color, GColorElectricUltramarine)) return "GColorElectricUltramarine";
	if(GColorEq(m_color, GColorArmyGreen)) return "GColorArmyGreen";
	if(GColorEq(m_color, GColorDarkGray)) return "GColorDarkGray";
	if(GColorEq(m_color, GColorLiberty)) return "GColorLiberty";
	if(GColorEq(m_color, GColorVeryLightBlue)) return "GColorVeryLightBlue";
	if(GColorEq(m_color, GColorKellyGreen)) return "GColorKellyGreen";
	if(GColorEq(m_color, GColorMayGreen)) return "GColorMayGreen";
	if(GColorEq(m_color, GColorCadetBlue)) return "GColorCadetBlue";
	if(GColorEq(m_color, GColorPictonBlue)) return "GColorPictonBlue";
	if(GColorEq(m_color, GColorBrightGreen)) return "GColorBrightGreen";
	if(GColorEq(m_color, GColorScreaminGreen)) return "GColorScreaminGreen";
	if(GColorEq(m_color, GColorMediumAquamarine)) return "GColorMediumAquamarine";
	if(GColorEq(m_color, GColorElectricBlue)) return "GColorElectricBlue";
	if(GColorEq(m_color, GColorDarkCandyAppleRed)) return "GColorDarkCandyAppleRed";
	if(GColorEq(m_color, GColorJazzberryJam)) return "GColorJazzberryJam";
	if(GColorEq(m_color, GColorPurple)) return "if(GColorEq(m_color, GColorPurple";
	if(GColorEq(m_color, GColorVividViolet)) return "GColorVividViolet";
	if(GColorEq(m_color, GColorWindsorTan)) return "GColorWindsorTan";
	if(GColorEq(m_color, GColorRoseVale)) return "GColorWindsorTan";
	if(GColorEq(m_color, GColorPurpureus)) return "GColorPurpureus";
	if(GColorEq(m_color, GColorLavenderIndigo)) return "GColorLavenderIndigo";
	if(GColorEq(m_color, GColorLimerick)) return "GColorLimerick";
	if(GColorEq(m_color, GColorBrass)) return "GColorBrass";
	if(GColorEq(m_color, GColorLightGray)) return "GColorLightGray";
	if(GColorEq(m_color, GColorBabyBlueEyes)) return "GColorBabyBlueEyes";
	if(GColorEq(m_color, GColorSpringBud)) return "GColorSpringBud";
	if(GColorEq(m_color, GColorInchworm)) return "GColorInchworm";
	if(GColorEq(m_color, GColorMintGreen)) return "GColorMintGreen";
	if(GColorEq(m_color, GColorCeleste)) return "GColorCeleste";
	if(GColorEq(m_color, GColorRed)) return "GColorRed";
	if(GColorEq(m_color, GColorFolly)) return "GColorFolly";
	if(GColorEq(m_color, GColorFashionMagenta)) return "GColorFashionMagenta";
	if(GColorEq(m_color, GColorMagenta)) return "GColorMagenta";
	if(GColorEq(m_color, GColorOrange)) return "GColorOrange";
	if(GColorEq(m_color, GColorSunsetOrange)) return "GColorSunsetOrange";
	if(GColorEq(m_color, GColorBrilliantRose)) return "GColorBrilliantRose";
	if(GColorEq(m_color, GColorShockingPink)) return "GColorShockingPink";
	if(GColorEq(m_color, GColorChromeYellow)) return "GColorChromeYellow";
	if(GColorEq(m_color, GColorRajah)) return "GColorRajah";
	if(GColorEq(m_color, GColorMelon)) return "GColorMelon";
	if(GColorEq(m_color, GColorRichBrilliantLavender)) return "GColorRichBrilliantLavender";
	if(GColorEq(m_color, GColorYellow)) return "GColorYellow";
	if(GColorEq(m_color, GColorIcterine)) return "GColorIcterine";
	if(GColorEq(m_color, GColorPastelYellow)) return "GColorPastelYellow";
	if(GColorEq(m_color, GColorWhite)) return "GColorWhite";
	if(GColorEq(m_color, GColorClear)) return "GColorClear";

	return "UNKNOWN COLOR";


}
#endif