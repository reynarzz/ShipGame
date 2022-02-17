#include "Camera.h"

namespace Engine {
    Camera::Camera(): //: Entity("Camera"), 
        _proj(glm::mat4(1.0f)),
        _viewTransform(new Transform())
    {

    }

    void Camera::SetProj(float fov, float aspect, float n, float f)
    {
        _proj = glm::perspective(glm::radians(fov), aspect, n, f);
    }

    void Camera::SetOrtho(float left, float right, float bottom, float top) {
        _proj = glm::ortho(left, right, bottom, top, 1.0f, 100.0f);
    }

    glm::mat4 Camera::getProj()
    {
        return _proj;
    }

    glm::mat4 Camera::getView()
    {
        return _viewTransform->getModelM();
    }
}