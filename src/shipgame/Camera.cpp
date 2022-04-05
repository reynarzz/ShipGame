#include "GameHelper.h"

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
       // _proj = glm::ortho(-0.5, (9.0 * 2 - 1) + 0.5, -0.5, (16.0f * 2 - 1) + 0.5, 1.0, 100.0);
        _projInv = glm::inverse(_proj);
    }

    glm::mat4 Camera::getProj()
    {
        return _proj;
    }

    glm::mat4 Camera::getProjInv()
    {
        return _projInv;
    }

    glm::mat4 Camera::getViewInv()
    {
        return _viewTransform->getModelMInv();;
    }

    glm::mat4 Camera::getView()
    {
        return _viewTransform->getModelM();
    }
}