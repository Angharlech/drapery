
#pragma once

#include <Eigen/Core>
class PerspectiveTransform
{
    public:
        PerspectiveTransform();
        void set(float frustumScale, float frustumNear, float frustumFar, int width, int height);
        void resizeView(int width, int height);
        float* data();

    private:
        Eigen::Matrix4f m_matrix; 
        float m_frustumScale;
};



