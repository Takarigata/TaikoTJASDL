#pragma once
#include "imgui.h"
#include "imconfig-SFML.h"
#include "Public/TJAMap.h"

class TJADebugWindows
{
public:

    void InitImGui();

    void RenderImGui();

    std::list<TJAMap*> MapList;
    
};
