#pragma once

#include <chrono>
#include <SDL/SDL.h>
float superTime()
{
    std::chrono::steady_clock clock;
    auto currentTime = clock.now();
    auto duration = currentTime.time_since_epoch();
    long long micros = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    return float(micros);
}
float currentTime()
{
    long long time = SDL_GetTicks();
    return time/1000.0;
}

