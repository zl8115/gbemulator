#pragma once

class FrameBuffer;

class IRenderer
{
public:
    virtual ~IRenderer() = default;
    virtual void Render(const FrameBuffer& buffer) = 0;
};
