#pragma once
#include "Scene.hpp"
#include "cbuffer.h"
#include <vector>

namespace My {
    struct DrawFrameContext : PerFrameConstants, frame_textures {
    };

    struct DrawBatchContext : PerBatchConstants {
        int32_t batchIndex;
        std::shared_ptr<SceneGeometryNode> node;
        material_textures material;

        virtual ~DrawBatchContext() = default;
    };

    struct Frame : global_textures {
        int32_t frameIndex;
        DrawFrameContext frameContext;
        std::vector<std::shared_ptr<DrawBatchContext>> batchContexts;
        LightInfo lightInfo;
    };
}
