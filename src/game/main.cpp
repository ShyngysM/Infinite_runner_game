#include <SDL.h>
#include <cstdlib> // atexit
#include <iostream>
#include <memory> // std::unique_ptr
#include <thread>

#include "inf_run.h"


using namespace std::chrono_literals;

int main() {
    /* SDL initialisieren */
    inf_run game;

    /* Event Loop */
    const auto time_per_frame = std::chrono::milliseconds(1000 / 60);

    for (;;) {
        auto time_begin = std::chrono::steady_clock::now();

        if (!game.processEvents()) {
            return 0;
        }

        game.update();

        game.render();

        auto time_end = std::chrono::steady_clock::now();
        auto time_delta = time_end - time_begin;

        if (time_delta < time_per_frame) {
            std::this_thread::sleep_for(time_per_frame - time_delta);
        }
    }

    return 0;
}

