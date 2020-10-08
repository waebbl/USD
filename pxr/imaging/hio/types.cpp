//
// Copyright 2020 Pixar
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
#include "pxr/pxr.h"
#include "pxr/imaging/hio/types.h"
#include "pxr/base/gf/half.h"
#include "pxr/base/tf/iterator.h"

PXR_NAMESPACE_OPEN_SCOPE

HioType 
HioGetHioType(HioFormat format)
{
    switch (format) {
        case HioFormatUNorm8:
        case HioFormatUNorm8Vec2:
        case HioFormatUNorm8Vec3:
        case HioFormatUNorm8Vec4:

        case HioFormatUNorm8srgb:
        case HioFormatUNorm8Vec2srgb:
        case HioFormatUNorm8Vec3srgb:
        case HioFormatUNorm8Vec4srgb:
        
        case HioFormatBC7UNorm8Vec4:
        case HioFormatBC7UNorm8Vec4srgb:
            return HioTypeUnsignedByte;

        case HioFormatSNorm8:
        case HioFormatSNorm8Vec2:
        case HioFormatSNorm8Vec3:
        case HioFormatSNorm8Vec4:
            return HioTypeSignedByte;

        case HioFormatFloat16:
        case HioFormatFloat16Vec2:
        case HioFormatFloat16Vec3:
        case HioFormatFloat16Vec4:
            return HioTypeHalfFloat;

        case HioFormatFloat32:
        case HioFormatFloat32Vec2:
        case HioFormatFloat32Vec3:
        case HioFormatFloat32Vec4:

        case HioFormatBC6FloatVec3:
        case HioFormatBC6UFloatVec3:
            return HioTypeFloat;

        case HioFormatDouble64:
        case HioFormatDouble64Vec2:
        case HioFormatDouble64Vec3:
        case HioFormatDouble64Vec4:
            return HioTypeDouble;

        case HioFormatUInt16:
        case HioFormatUInt16Vec2:
        case HioFormatUInt16Vec3:
        case HioFormatUInt16Vec4:
            return HioTypeUnsignedShort;

        case HioFormatInt16:
        case HioFormatInt16Vec2:
        case HioFormatInt16Vec3:
        case HioFormatInt16Vec4:
            return HioTypeSignedShort;

        case HioFormatUInt32:
        case HioFormatUInt32Vec2:
        case HioFormatUInt32Vec3:
        case HioFormatUInt32Vec4:
            return HioTypeUnsignedInt;

        case HioFormatInt32:
        case HioFormatInt32Vec2:
        case HioFormatInt32Vec3:
        case HioFormatInt32Vec4:
            return HioTypeInt;

        case HioFormatInvalid:
        case HioFormatCount:
            TF_CODING_ERROR("Unsupported HioFormat");
            return HioTypeUnsignedByte;
    }
    TF_CODING_ERROR("Missing Format");
    return HioTypeUnsignedByte;
}

int
HioGetComponentCount(HioFormat format)
{
    switch (format) {
        case HioFormatUNorm8:
        case HioFormatSNorm8:
        case HioFormatFloat16:
        case HioFormatFloat32:
        case HioFormatDouble64:
        case HioFormatUInt16:
        case HioFormatInt16:
        case HioFormatUInt32:
        case HioFormatInt32:
        case HioFormatUNorm8srgb:
            return 1;
        case HioFormatUNorm8Vec2:
        case HioFormatSNorm8Vec2:
        case HioFormatFloat16Vec2:
        case HioFormatFloat32Vec2:
        case HioFormatDouble64Vec2:
        case HioFormatUInt16Vec2:
        case HioFormatInt16Vec2:
        case HioFormatUInt32Vec2:
        case HioFormatInt32Vec2:
        case HioFormatUNorm8Vec2srgb:
            return 2;
        case HioFormatUNorm8Vec3:
        case HioFormatSNorm8Vec3:
        case HioFormatFloat16Vec3:
        case HioFormatFloat32Vec3:
        case HioFormatDouble64Vec3:
        case HioFormatUInt16Vec3:
        case HioFormatInt16Vec3:
        case HioFormatUInt32Vec3:
        case HioFormatInt32Vec3:
        case HioFormatUNorm8Vec3srgb:
        case HioFormatBC6FloatVec3:
        case HioFormatBC6UFloatVec3:
            return 3;
        case HioFormatUNorm8Vec4:
        case HioFormatSNorm8Vec4:
        case HioFormatFloat16Vec4:
        case HioFormatFloat32Vec4:
        case HioFormatDouble64Vec4:
        case HioFormatUInt16Vec4:
        case HioFormatInt16Vec4:
        case HioFormatUInt32Vec4:
        case HioFormatInt32Vec4:
        case HioFormatUNorm8Vec4srgb:
        case HioFormatBC7UNorm8Vec4:
        case HioFormatBC7UNorm8Vec4srgb:
            return 4;
        case HioFormatInvalid:
        case HioFormatCount:
            TF_CODING_ERROR("Unsupported format");
            return 1;
    }
    TF_CODING_ERROR("Missing Format");
    return 1;
}

size_t
HioGetDataSizeOfType(HioFormat format)
{
    switch (format) {
        case HioFormatUNorm8:
        case HioFormatUNorm8Vec2:
        case HioFormatUNorm8Vec3:
        case HioFormatUNorm8Vec4:

        case HioFormatUNorm8srgb:
        case HioFormatUNorm8Vec2srgb:
        case HioFormatUNorm8Vec3srgb:
        case HioFormatUNorm8Vec4srgb:

        case HioFormatBC7UNorm8Vec4:
        case HioFormatBC7UNorm8Vec4srgb:
            return sizeof(unsigned char);

        case HioFormatSNorm8:
        case HioFormatSNorm8Vec2:
        case HioFormatSNorm8Vec3:
        case HioFormatSNorm8Vec4:
            return sizeof(signed char);

        case HioFormatFloat16:
        case HioFormatFloat16Vec2:
        case HioFormatFloat16Vec3:
        case HioFormatFloat16Vec4:
            return sizeof(GfHalf);

        case HioFormatFloat32:
        case HioFormatFloat32Vec2:
        case HioFormatFloat32Vec3:
        case HioFormatFloat32Vec4:
        case HioFormatBC6FloatVec3:
        case HioFormatBC6UFloatVec3:
            return sizeof(float);

        case HioFormatDouble64:
        case HioFormatDouble64Vec2:
        case HioFormatDouble64Vec3:
        case HioFormatDouble64Vec4:
            return sizeof(double);

        case HioFormatUInt16:
        case HioFormatUInt16Vec2:
        case HioFormatUInt16Vec3:
        case HioFormatUInt16Vec4:
            return sizeof(unsigned short);

        case HioFormatInt16:
        case HioFormatInt16Vec2:
        case HioFormatInt16Vec3:
        case HioFormatInt16Vec4:
            return sizeof(signed short);

        case HioFormatUInt32:
        case HioFormatUInt32Vec2:
        case HioFormatUInt32Vec3:
        case HioFormatUInt32Vec4:
            return sizeof(unsigned int);

        case HioFormatInt32:
        case HioFormatInt32Vec2:
        case HioFormatInt32Vec3:
        case HioFormatInt32Vec4:
            return sizeof(int);

        case HioFormatInvalid:
        case HioFormatCount:
            TF_CODING_ERROR("Unsupported format");
            return 1;
    }
    TF_CODING_ERROR("Missing Format");
    return 1;
}

size_t
HioGetDataSizeOfFormat(HioFormat format,
                       size_t * const blockWidth,
                       size_t * const blockHeight)
{
    if (blockWidth) {
        *blockWidth = 1;
    }
    if (blockHeight) {
        *blockHeight = 1;
    }

    switch (format) {
        case HioFormatUNorm8:
        case HioFormatSNorm8:
        case HioFormatUNorm8srgb:
            return 1;
        case HioFormatUNorm8Vec2:
        case HioFormatSNorm8Vec2:
        case HioFormatUNorm8Vec2srgb:
            return 2;
        case HioFormatUNorm8Vec3:
        case HioFormatSNorm8Vec3:
        case HioFormatUNorm8Vec3srgb:
            return 3;
        case HioFormatUNorm8Vec4:
        case HioFormatSNorm8Vec4:
        case HioFormatUNorm8Vec4srgb:
            return 4;

        case HioFormatFloat16:
        case HioFormatUInt16:
        case HioFormatInt16:
            return 2;
        case HioFormatFloat16Vec2:
        case HioFormatUInt16Vec2:
        case HioFormatInt16Vec2:
            return 4;
        case HioFormatFloat16Vec3:
        case HioFormatUInt16Vec3:
        case HioFormatInt16Vec3:
            return 6;
        case HioFormatFloat16Vec4:
        case HioFormatUInt16Vec4:
        case HioFormatInt16Vec4:
            return 8;

        case HioFormatFloat32:
        case HioFormatUInt32:
        case HioFormatInt32:
            return 4;
        case HioFormatFloat32Vec2:
        case HioFormatUInt32Vec2:
        case HioFormatInt32Vec2:
            return 8;
        case HioFormatFloat32Vec3:
        case HioFormatUInt32Vec3:
        case HioFormatInt32Vec3:
            return 12;
        case HioFormatFloat32Vec4:
        case HioFormatUInt32Vec4:
        case HioFormatInt32Vec4:
            return 16;

        case HioFormatDouble64:
            return 8;
        case HioFormatDouble64Vec2:
            return 16;
        case HioFormatDouble64Vec3:
            return 24;
        case HioFormatDouble64Vec4:
            return 32;

        case HioFormatBC6FloatVec3:
        case HioFormatBC6UFloatVec3:
        case HioFormatBC7UNorm8Vec4:
        case HioFormatBC7UNorm8Vec4srgb:
            if (blockWidth) {
                *blockWidth = 4;
            }
            if (blockHeight) {
                *blockHeight = 4;
            }
            return 16;
        case HioFormatInvalid:
        case HioFormatCount:
            TF_CODING_ERROR("Unsupported format");
            return 0;
    }
    TF_CODING_ERROR("Missing Format");
    return 0;
}

bool 
HioIsCompressed(HioFormat format) 
{
    switch(format) {
        case HioFormatBC6FloatVec3:
        case HioFormatBC6UFloatVec3:
        case HioFormatBC7UNorm8Vec4:
        case HioFormatBC7UNorm8Vec4srgb:
            return true;
        default:
            return false;
    }
}

size_t
HioGetDataSize(const HioFormat hioFormat, const GfVec3i &dimensions)
{
    size_t blockWidth, blockHeight;
    const size_t bytesPerPixel = HioGetDataSizeOfFormat(hioFormat, &blockWidth, 
                                                                &blockHeight);

    size_t numPixels = ((dimensions[0] + blockWidth  - 1) / blockWidth ) *
                       ((dimensions[1] + blockHeight - 1) / blockHeight);
    return numPixels * bytesPerPixel * std::max(1, dimensions[2]);
}

PXR_NAMESPACE_CLOSE_SCOPE
