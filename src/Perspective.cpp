#include "Perspective.hpp"

PerspectiveTransform::PerspectiveTransform()
{
    m_matrix = Eigen::Matrix4f::Zero(); 
}

void PerspectiveTransform::set(float frustumScale, float frustumNear, float frustumFar, int width, int height)
{
    m_frustumScale = frustumScale;
    m_matrix = Eigen::Matrix4f::Zero(); 
    float aspect = width/(float)height;
    m_matrix(0,0) = m_frustumScale/aspect;
    m_matrix(1,1) = m_frustumScale;
    m_matrix(2,2) = (frustumFar + frustumNear) / (frustumNear - frustumFar);
    m_matrix(2,3) = (2 * frustumFar * frustumNear) / (frustumNear - frustumFar);
    m_matrix(3,2) = -1.0f;
}
void PerspectiveTransform::resizeView(int width, int height)
{
    float aspect = width/(float)height;
    m_matrix(0,0) = m_frustumScale/aspect;
}

float* PerspectiveTransform::data()
{
    return m_matrix.data();
}
