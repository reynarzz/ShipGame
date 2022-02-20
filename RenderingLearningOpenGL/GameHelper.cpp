#include "GameHelper.h"

 Scene* _scene = nullptr;
 glm::mat4 _projM_;
 glm::mat4 _viewM_;
 glm::mat4 _projMInv_;
 glm::mat4 _viewMInv_;
 ivec2 _screenSize_;

 unsigned char* _currentFrameBufferTex_;