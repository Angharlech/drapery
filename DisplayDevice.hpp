#ifndef DISPLAY_DEVICE
#define DISPLAY_DEVICE

void setVideoMode(int width, int height, bool fullscreen);
void toggleFullscreen();
void swapBuffers();

class DisplayDevice
{
    public:
        DisplayDevice();
        DisplayDevice(int width, int height, bool fullscreen);
        ~DisplayDevice();
};

#endif //DISPLAY_DEVICE
