#include <xcb/xcb.h>

int main(){
    int screenNum;
    xcb_connection_t *connection = xcb_connect(NULL,&screenNum);

    return 0;
}
