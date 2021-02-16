#include "cameraclearcmd.h"
#include <scene_graph.h>

using namespace rh::rw::engine;

RwCameraClearCmd::RwCameraClearCmd( RwCamera *camera, RwRGBA *color,
                                    int32_t clear_mode )
    : m_pCamera( camera ), m_nClearMode( clear_mode )
{
    m_aClearColor = color;
}
RwCameraClearCmd::~RwCameraClearCmd() = default;

bool RwCameraClearCmd::Execute()
{
    auto &frame       = GetCurrentSceneGraph()->mFrameInfo;
    frame.mClearColor = *m_aClearColor;
    frame.mClearFlags = m_nClearMode;
    frame.mClearDepth = 1.0f;
    return true;
}
