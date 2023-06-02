#pragma once

#include "BaseDirector.h"
#include "CameraBuilder.h"

class BaseCameraDirector : public BaseDirector
{
public:
    virtual std::shared_ptr<Camera> load(std::shared_ptr<BaseCameraBuilder> builder, std::string &fileName) = 0;
};
