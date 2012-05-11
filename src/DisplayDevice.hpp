#pragma once
#include <boost/function.hpp>

void toggleFullscreen();
void swapBuffers();

class DisplayDevice
{
    public:
        DisplayDevice();
        DisplayDevice(int width, int height, bool fullscreen);
        ~DisplayDevice();
        void toggleFullscreen();
        void swapBuffers();
        void setVideoMode(int width, int height, bool fullscreen);
        boost::function<void(const int& width, const int& height)> onWindowResize;
    private:
        int m_preferredWidth;
        int m_preferredHeight;
        int m_maximumWidth;
        int m_maximumHeight;
};

