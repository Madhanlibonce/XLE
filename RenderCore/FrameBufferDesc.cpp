// Copyright 2015 XLGAMES Inc.
//
// Distributed under the MIT License (See
// accompanying file "LICENSE" or the website
// http://www.opensource.org/licenses/mit-license.php)

#pragma once

#include "FrameBufferDesc.h"
#include "../Utility/MemoryUtils.h"

namespace RenderCore
{
    SubpassDesc::SubpassDesc()
    : _depthStencil(Unused)
    {
    }

    SubpassDesc::SubpassDesc(
        std::initializer_list<AttachmentDesc::Name> output,
        unsigned depthStencil,
        std::initializer_list<AttachmentDesc::Name> input, 
        std::initializer_list<AttachmentDesc::Name> preserve,
        std::initializer_list<AttachmentDesc::Name> resolve)
    : _input(input.begin(), input.end())
    , _output(output.begin(), output.end())
    , _depthStencil(depthStencil)
    , _preserve(preserve.begin(), preserve.end())
    , _resolve(resolve.begin(), resolve.end())
    {
    }

    FrameBufferDesc::FrameBufferDesc(
        IteratorRange<AttachmentDesc*> attachments,
        IteratorRange<SubpassDesc*> subpasses,
        const TextureSamples& samples)
    : _attachments(attachments.begin(), attachments.end())
    , _subpasses(subpasses.begin(), subpasses.end())
    , _samples(samples)
    {
        // Calculate the hash value for this description by combining
        // together the hashes of the members.
        _hash = DefaultSeed64;
        _hash = HashCombine(samples._sampleCount | samples._samplingQuality << 8, _hash);
        _hash = HashCombine(Hash64(AsPointer(_attachments.begin()), AsPointer(_attachments.end())), _hash);
        _hash = HashCombine(Hash64(AsPointer(_subpasses.begin()), AsPointer(_subpasses.end())), _hash);
    }

	FrameBufferDesc::FrameBufferDesc()
    : _samples(TextureSamples::Create())
    , _hash(0)
    {
    }

    FrameBufferDesc::~FrameBufferDesc() {}
}
