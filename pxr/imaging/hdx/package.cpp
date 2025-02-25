//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#include "pxr/imaging/hdx/package.h"

#include "pxr/base/plug/plugin.h"
#include "pxr/base/plug/thisPlugin.h"
#include "pxr/base/tf/diagnostic.h"
#include "pxr/base/tf/fileUtils.h"
#include "pxr/base/tf/staticData.h"
#include "pxr/base/tf/stringUtils.h"
#include "pxr/imaging/hio/imageRegistry.h"

PXR_NAMESPACE_OPEN_SCOPE


static TfToken
_GetShaderPath(char const * shader)
{
    static PlugPluginPtr plugin = PLUG_THIS_PLUGIN;
    const std::string path =
        PlugFindPluginResource(plugin, TfStringCatPaths("shaders", shader));
    TF_VERIFY(!path.empty(), "Could not find shader: %s\n", shader);

    return TfToken(path);
}

static TfToken
_GetTexturePath(char const * texture)
{
    static PlugPluginPtr plugin = PLUG_THIS_PLUGIN;
    const std::string path =
        PlugFindPluginResource(plugin, TfStringCatPaths("textures", texture));
    TF_VERIFY(!path.empty(), "Could not find texture: %s\n", texture);

    return TfToken(path);
}

TfToken
HdxPackageFullscreenShader()
{
    static TfToken shader = _GetShaderPath("fullscreen.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassColorShader()
{
    static TfToken shader = _GetShaderPath("renderPassColorShader.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassColorAndSelectionShader()
{
    static TfToken shader =
        _GetShaderPath("renderPassColorAndSelectionShader.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassColorWithOccludedSelectionShader()
{
    static TfToken shader =
        _GetShaderPath("renderPassColorWithOccludedSelectionShader.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassIdShader()
{
    static TfToken shader = _GetShaderPath("renderPassIdShader.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassPickingShader()
{
    static TfToken shader = _GetShaderPath("renderPassPickingShader.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassShadowShader()
{
    static TfToken shader = _GetShaderPath("renderPassShadowShader.glslfx");
    return shader;
}

TfToken
HdxPackageColorChannelShader()
{
    static TfToken shader = _GetShaderPath("colorChannel.glslfx");
    return shader;
}

TfToken
HdxPackageColorCorrectionShader()
{
    static TfToken shader = _GetShaderPath("colorCorrection.glslfx");
    return shader;
}

TfToken
HdxPackageVisualizeAovShader()
{
    static TfToken shader = _GetShaderPath("visualize.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassOitShader()
{
    static TfToken shader = _GetShaderPath("renderPassOitShader.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassOitOpaqueShader()
{
    static TfToken shader = _GetShaderPath("renderPassOitOpaqueShader.glslfx");
    return shader;
}

TfToken
HdxPackageRenderPassOitVolumeShader()
{
    static TfToken shader = _GetShaderPath("renderPassOitVolumeShader.glslfx");
    return shader;
}

TfToken
HdxPackageOitResolveImageShader()
{
    static TfToken shader = _GetShaderPath("oitResolveImageShader.glslfx");
    return shader;
}

TfToken
HdxPackageOutlineShader()
{
    static TfToken shader = _GetShaderPath("outline.glslfx");
    return shader;
}

TfToken
HdxPackageSkydomeShader()
{
    static TfToken shader = _GetShaderPath("skydome.glslfx");
    return shader;
}

TfToken
HdxPackageDefaultDomeLightTexture()
{
    // Use the tex version of the Domelight's environment map if supported
    HioImageRegistry &hioImageReg = HioImageRegistry::GetInstance();
    static bool useTex = hioImageReg.IsSupportedImageFile("StinsonBeach.tex");

    static TfToken domeLightTexture = (useTex)
        ? _GetTexturePath("StinsonBeach.tex")
        : _GetTexturePath("StinsonBeach.exr");
    return domeLightTexture;
}

PXR_NAMESPACE_CLOSE_SCOPE
