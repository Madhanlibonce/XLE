// Copyright 2015 XLGAMES Inc.
//
// Distributed under the MIT License (See
// accompanying file "LICENSE" or the website
// http://www.opensource.org/licenses/mit-license.php)

#pragma once

#include "Resource.h"
#include "../../IDevice_Forward.h"
#include "../../IThreadContext_Forward.h"
#include "../../Resource.h"
#include "../../../Math/Vector.h"		// for Float4
#include "../../../Utility/Threading/ThreadingUtils.h"
#include "Forward.h"

namespace RenderCore { namespace Metal_Vulkan
{
    /// Container for Topology::Enum
    namespace Topology
    {
        enum Enum
        {
            PointList       = 1,    // D3D11_PRIMITIVE_TOPOLOGY_POINTLIST,
            LineList        = 2,    // D3D11_PRIMITIVE_TOPOLOGY_LINELIST,
            LineStrip       = 3,    // D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP,
            TriangleList    = 4,    // D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            TriangleStrip   = 5,    // D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP
            LineListAdj     = 10,   // D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ


            PatchList1 = 33,        // D3D11_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST	= 33,
	        PatchList2 = 34,        // D3D11_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST	= 34,
	        PatchList3 = 35,        // D3D11_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST	= 35,
	        PatchList4 = 36,        // D3D11_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST	= 36,
	        PatchList5 = 37,        // D3D11_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST	= 37,
	        PatchList6 = 38,        // D3D11_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST	= 38,
	        PatchList7 = 39,        // D3D11_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST	= 39,
	        PatchList8 = 40,        // D3D11_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST	= 40,
	        PatchList9 = 41,        // D3D11_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST	= 41,
	        PatchList10 = 42,       // D3D11_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST	= 42,
	        PatchList11 = 43,       // D3D11_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST	= 43,
	        PatchList12 = 44,       // D3D11_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST	= 44,
	        PatchList13 = 45,       // D3D11_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST	= 45,
	        PatchList14 = 46,       // D3D11_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST	= 46,
	        PatchList15 = 47,       // D3D11_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST	= 47,
	        PatchList16 = 48        // D3D11_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST	= 48
        };
    }

	class CommandList : public RefCountedObject
	{
	public:
		CommandList() {}
		CommandList(const CommandList&) = delete;
		CommandList& operator=(const CommandList&) = delete;
	};

    class ObjectFactory
    {
    public:
        void AttachCurrentModule() {}
		void DetachCurrentModule() {}

        ObjectFactory(IDevice* device) {}
        ObjectFactory() {}
        ~ObjectFactory() {}

        ObjectFactory(const ObjectFactory& cloneFrom) {}
        ObjectFactory(ObjectFactory&& moveFrom) never_throws {}
		ObjectFactory(Underlying::Resource&) {}
        ObjectFactory& operator=(const ObjectFactory& cloneFrom) {}
        ObjectFactory& operator=(ObjectFactory&& moveFrom) never_throws {}
    };

	class DeviceContext
    {
    public:
		template<int Count> void    Bind(const ResourceList<VertexBuffer, Count>& VBs, unsigned stride, unsigned offset=0) {}

        template<int Count> void    BindVS(const ResourceList<ShaderResourceView, Count>& shaderResources) {}
        template<int Count> void    BindPS(const ResourceList<ShaderResourceView, Count>& shaderResources) {}
        template<int Count> void    BindCS(const ResourceList<ShaderResourceView, Count>& shaderResources) {}
        template<int Count> void    BindGS(const ResourceList<ShaderResourceView, Count>& shaderResources) {}
        template<int Count> void    BindHS(const ResourceList<ShaderResourceView, Count>& shaderResources) {}
        template<int Count> void    BindDS(const ResourceList<ShaderResourceView, Count>& shaderResources) {}

        template<int Count> void    BindVS(const ResourceList<SamplerState, Count>& samplerStates) {}
        template<int Count> void    BindPS(const ResourceList<SamplerState, Count>& samplerStates) {}
        template<int Count> void    BindGS(const ResourceList<SamplerState, Count>& samplerStates) {}
        template<int Count> void    BindCS(const ResourceList<SamplerState, Count>& samplerStates) {}
        template<int Count> void    BindHS(const ResourceList<SamplerState, Count>& samplerStates) {}
        template<int Count> void    BindDS(const ResourceList<SamplerState, Count>& samplerStates) {}

        template<int Count> void    BindVS(const ResourceList<ConstantBuffer, Count>& constantBuffers) {}
        template<int Count> void    BindPS(const ResourceList<ConstantBuffer, Count>& constantBuffers) {}
        template<int Count> void    BindCS(const ResourceList<ConstantBuffer, Count>& constantBuffers) {}
        template<int Count> void    BindGS(const ResourceList<ConstantBuffer, Count>& constantBuffers) {}
        template<int Count> void    BindHS(const ResourceList<ConstantBuffer, Count>& constantBuffers) {}
        template<int Count> void    BindDS(const ResourceList<ConstantBuffer, Count>& constantBuffers) {}

		template<int Count> void    Bind(const ResourceList<RenderTargetView, Count>& renderTargets, const DepthStencilView* depthStencil) {}
		template<int Count> void    BindCS(const ResourceList<UnorderedAccessView, Count>& unorderedAccess) {}

		template<int Count> void    BindSO(const ResourceList<VertexBuffer, Count>& buffers, unsigned offset=0) {}

		template<int Count1, int Count2> void    Bind(const ResourceList<RenderTargetView, Count1>& renderTargets, const DepthStencilView* depthStencil, const ResourceList<UnorderedAccessView, Count2>& unorderedAccess) {}

		void        Bind(unsigned startSlot, unsigned bufferCount, const VertexBuffer* VBs[], const unsigned strides[], const unsigned offsets[]) {}
        void        Bind(const IndexBuffer& ib, NativeFormat::Enum indexFormat, unsigned offset=0) {}
        void        Bind(const BoundInputLayout& inputLayout) {}
        void        Bind(Topology::Enum topology) {}
        void        Bind(const VertexShader& vertexShader) {}
        void        Bind(const GeometryShader& geometryShader) {}
        void        Bind(const PixelShader& pixelShader) {}
        void        Bind(const ComputeShader& computeShader) {}
        void        Bind(const DomainShader& domainShader) {}
        void        Bind(const HullShader& hullShader) {}
        void        Bind(const ShaderProgram& shaderProgram) {}
        void        Bind(const DeepShaderProgram& deepShaderProgram) {}
        void        Bind(const RasterizerState& rasterizer) {}
        void        Bind(const BlendState& blender) {}
        void        Bind(const DepthStencilState& depthStencilState, unsigned stencilRef = 0x0) {}
        void        Bind(const ViewportDesc& viewport) {}

        void        Bind(const ShaderProgram& shaderProgram, const BoundClassInterfaces& dynLinkage) {}
        void        Bind(const DeepShaderProgram& deepShaderProgram, const BoundClassInterfaces& dynLinkage) {}

        T1(Type) void   UnbindVS(unsigned startSlot, unsigned count) {}
        T1(Type) void   UnbindGS(unsigned startSlot, unsigned count) {}
        T1(Type) void   UnbindPS(unsigned startSlot, unsigned count) {}
        T1(Type) void   UnbindCS(unsigned startSlot, unsigned count) {}
		T1(Type) void   UnbindDS(unsigned startSlot, unsigned count) {}
        T1(Type) void   Unbind() {}
        void            UnbindSO() {}

        void        Draw(unsigned vertexCount, unsigned startVertexLocation=0) {}
        void        DrawIndexed(unsigned indexCount, unsigned startIndexLocation=0, unsigned baseVertexLocation=0) {}
        void        DrawAuto() {}
        void        Dispatch(unsigned countX, unsigned countY=1, unsigned countZ=1) {}

        void        Clear(const RenderTargetView& renderTargets, const Float4& clearColour) {}
        void        Clear(const DepthStencilView& depthStencil, float depth, unsigned stencil) {}
        void        Clear(const UnorderedAccessView& unorderedAccess, unsigned values[4]) {}
        void        Clear(const UnorderedAccessView& unorderedAccess, float values[4]) {}
        void        ClearStencil(const DepthStencilView& depthStencil, unsigned stencil) {}

        static std::shared_ptr<DeviceContext> Get(IThreadContext& threadContext) {}

		void		CommitCommandList(CommandList&, bool) {}

		DeviceContext(const DeviceContext&) = delete;
		DeviceContext& operator=(const DeviceContext&) = delete;
    };
}}