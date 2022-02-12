#pragma once
#include "bitflags/bitflags.hpp"

BEGIN_BITFLAGS(SceneState)
FLAG(none)
FLAG(Visible)
FLAG(Updating)
FLAG(Render3D)
FLAG(HiearchyPanelHidden)
END_BITFLAGS(SceneState)

namespace SceneStates
{
    const SceneState Active = SceneState::Visible | SceneState::Updating;
    const SceneState EditorScene = Active | SceneState::HiearchyPanelHidden;
}

