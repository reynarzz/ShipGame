#pragma once

#include <stdio.h>
#include <stdlib.h>

namespace Engine
{
    class AABB
    {
    public:

        AABB(float x = 0.0f, float y= 0.0f, float w = 1.0f, float h = 1.0f, bool solid = false);
        ~AABB();
        bool Collide(AABB* target);
        void UpdateBoundingBox(float x, float y, float w, float h);

        float _x;
        float _y;
        float _width;
        float _height;
        bool _solid;
    };
};