#pragma once

class FrameBuffer;

class IRenderer
{
public:
    virtual ~IRenderer() = default;
    virtual void Render(FrameBuffer& buffer) = 0;
};
