#include <stdio.h>
#include <stdlib.h>
#include <xcb/xcb.h>

xcb_connection_t *conn;
xcb_screen_t *screen;
const xcb_setup_t *setup;
xcb_generic_event_t *ev;

void dieout(){
    printf("Die out");
    xcb_disconnect(conn);
    exit(0);
}

void prepare(){
    conn = xcb_connect(NULL,NULL);
    setup = xcb_get_setup(conn);
    screen = xcb_setup_roots_iterator(setup).data;
}

int main(){
    prepare();
    xcb_flush(conn);
    while(1){
        ev = xcb_wait_for_event(conn);
        switch(ev->response_type){
            case XCB_KEY_PRESS:
                printf("Keyboard Pressed");
                break;
        } 
    }
    return 0;
}
