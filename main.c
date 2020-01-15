#include <allegro5/allegro_video.h>

ALLEGRO_VIDEO *play_of_the_game;

void allegro5_init(void) {

    if (!al_init_video_addon())
	    	game_abort("failed to install video");
    
}


void game_init(void) {
    play_of_the_game = al_open_video("play.ogv");
}

void game_draw(void) {

    if (active_scene == SCENE_VICTORY) {
    
        al_start_video(play_of_the_game, al_get_default_mixer());
        ALLEGRO_BITMAP* frame = al_get_video_frame(play_of_the_game);
        
        
        if (frame) {
            float sw = al_get_bitmap_width(frame);
				    float sh = al_get_bitmap_height(frame);
            al_draw_scaled_bitmap(frame, 0, 0, sw, sh, 0, 0, SCREEN_W, SCREEN_H, 0);
        }
        
        
        //loop
        if (!al_is_video_playing(play_of_the_game)) {
			      al_close_video(play_of_the_game);
			      play_of_the_game = al_open_video("play.ogv");
		    }
        
        
        
        
    }
}
