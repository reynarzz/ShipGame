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

    glm::mat4 Camera::getProj()
    {
        return _proj;
    }

    glm::mat4 Camera::getView()
    {
        return _viewTransform->getModelM();
    }
}