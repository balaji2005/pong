#include "header.h"

int main() {
    initCanvas("Pong", 1000, 500);
    XEvent event;
    reset();
    while (!GAME_OVER) {
        nextEvent(event);
        if (keyPressEvent(event)) {
            if (charFromEvent(event) == '\33') {
                GAME_OVER = true;
            }
        }
    }
}