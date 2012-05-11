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
        void toggleFullscreen();
    private:
        int m_preferredWidth;
        int m_preferredHeight;
        int m_maximumWidth;
        int m_maximumHeight;
};

#endif //DISPLAY_DEVICE
