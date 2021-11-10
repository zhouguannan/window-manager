#include <cstdio>
#include <iostream>
#include <xcb/xcb.h>

using namespace std;

int main(){
    int screenNum;
    xcb_connection_t *connection = xcb_connect(NULL, &screenNum);
    
    const xcb_setup_t *setup = xcb_get_setup (connection);
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator (setup);  
   
    for (int i = 0; i < screenNum; ++i) {
        xcb_screen_next (&iter);
    } 
    xcb_screen_t *screen = iter.data;
    
    system("alacritty");

    xcb_disconnect(connection);
    return 0;
}
