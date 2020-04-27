#pragma once
#include <stdint.h>
#include <glad/glad.h>

namespace multigl
{
	typedef uint16_t gl_command_id_t;
	namespace CommandIdEnum
	{
		enum Enum : gl_command_id_t
		{
			CullFace,
			FrontFace,
			Hint,
			LineWidth,
			PointSize,
			PolygonMode,
			Scissor,
			TexParameterf,
			TexParameterfv,
			TexParameteri,
			TexParameteriv,
			TexImage1D,
			TexImage2D,
			DrawBuffer,
			Clear,
			ClearColor,
			ClearStencil,
			ClearDepth,
			StencilMask,
			ColorMask,
			DepthMask,
			Disable,
			Enable,
			Finish,
			Flush,
			BlendFunc,
			LogicOp,
			StencilFunc,
			StencilOp,
			DepthFunc,
			PixelStoref,
			PixelStorei,
			ReadBuffer,
			ReadPixels,
			GetBooleanv,
			GetDoublev,
			GetError,
			GetFloatv,
			GetIntegerv,
			GetString,
			GetTexImage,
			GetTexParameterfv,
			GetTexParameteriv,
			GetTexLevelParameterfv,
			GetTexLevelParameteriv,
			IsEnabled,
			DepthRange,
			Viewport,
			DrawArrays,
			DrawElements,
			PolygonOffset,
			CopyTexImage1D,
			CopyTexImage2D,
			CopyTexSubImage1D,
			CopyTexSubImage2D,
			TexSubImage1D,
			TexSubImage2D,
			BindTexture,
			DeleteTextures,
			GenTexture,
			IsTexture,
			DrawRangeElements,
			TexImage3D,
			TexSubImage3D,
			CopyTexSubImage3D,
			ActiveTexture,
			SampleCoverage,
			CompressedTexImage3D,
			CompressedTexImage2D,
			CompressedTexImage1D,
			CompressedTexSubImage3D,
			CompressedTexSubImage2D,
			CompressedTexSubImage1D,
			GetCompressedTexImage,
			BlendFuncSeparate,
			MultiDrawArrays,
			MultiDrawElements,
			PointParameterf,
			PointParameterfv,
			PointParameteri,
			PointParameteriv,
			BlendColor,
			BlendEquation,
			GenQueries,
			DeleteQueries,
			IsQuery,
			BeginQuery,
			EndQuery,
			GetQueryiv,
			GetQueryObjectiv,
			GetQueryObjectuiv,
			BindBuffer,
			DeleteBuffers,
			GenBuffer,
			IsBuffer,
			BufferData,
			BufferSubData,
			GetBufferSubData,
			MapBuffer,
			UnmapBuffer,
			GetBufferParameteriv,
			GetBufferPointerv,
			BlendEquationSeparate,
			DrawBuffers,
			StencilOpSeparate,
			StencilFuncSeparate,
			StencilMaskSeparate,
			AttachShader,
			BindAttribLocation,
			CompileShader,
			CreateProgram,
			CreateShader,
			DeleteProgram,
			DeleteShader,
			DetachShader,
			DisableVertexAttribArray,
			EnableVertexAttribArray,
			GetActiveAttrib,
			GetActiveUniform,
			GetAttachedShaders,
			GetAttribLocation,
			GetProgramiv,
			GetProgramInfoLog,
			GetShaderiv,
			GetShaderInfoLog,
			GetShaderSource,
			GetUniformLocation,
			GetUniformfv,
			GetUniformiv,
			GetVertexAttribdv,
			GetVertexAttribfv,
			GetVertexAttribiv,
			GetVertexAttribPointerv,
			IsProgram,
			IsShader,
			LinkProgram,
			ShaderSource,
			UseProgram,
			Uniform1f,
			Uniform2f,
			Uniform3f,
			Uniform4f,
			Uniform1i,
			Uniform2i,
			Uniform3i,
			Uniform4i,
			Uniform1fv,
			Uniform2fv,
			Uniform3fv,
			Uniform4fv,
			Uniform1iv,
			Uniform2iv,
			Uniform3iv,
			Uniform4iv,
			UniformMatrix2fv,
			UniformMatrix3fv,
			UniformMatrix4fv,
			ValidateProgram,
			VertexAttrib1d,
			VertexAttrib1dv,
			VertexAttrib1f,
			VertexAttrib1fv,
			VertexAttrib1s,
			VertexAttrib1sv,
			VertexAttrib2d,
			VertexAttrib2dv,
			VertexAttrib2f,
			VertexAttrib2fv,
			VertexAttrib2s,
			VertexAttrib2sv,
			VertexAttrib3d,
			VertexAttrib3dv,
			VertexAttrib3f,
			VertexAttrib3fv,
			VertexAttrib3s,
			VertexAttrib3sv,
			VertexAttrib4Nbv,
			VertexAttrib4Niv,
			VertexAttrib4Nsv,
			VertexAttrib4Nub,
			VertexAttrib4Nubv,
			VertexAttrib4Nuiv,
			VertexAttrib4Nusv,
			VertexAttrib4bv,
			VertexAttrib4d,
			VertexAttrib4dv,
			VertexAttrib4f,
			VertexAttrib4fv,
			VertexAttrib4iv,
			VertexAttrib4s,
			VertexAttrib4sv,
			VertexAttrib4ubv,
			VertexAttrib4uiv,
			VertexAttrib4usv,
			VertexAttribPointer,
			UniformMatrix2x3fv,
			UniformMatrix3x2fv,
			UniformMatrix2x4fv,
			UniformMatrix4x2fv,
			UniformMatrix3x4fv,
			UniformMatrix4x3fv,
			ColorMaski,
			GetBooleani_v,
			GetIntegeri_v,
			Enablei,
			Disablei,
			IsEnabledi,
			BeginTransformFeedback,
			EndTransformFeedback,
			BindBufferRange,
			BindBufferBase,
			TransformFeedbackVaryings,
			GetTransformFeedbackVarying,
			ClampColor,
			BeginConditionalRender,
			EndConditionalRender,
			VertexAttribIPointer,
			GetVertexAttribIiv,
			GetVertexAttribIuiv,
			VertexAttribI1i,
			VertexAttribI2i,
			VertexAttribI3i,
			VertexAttribI4i,
			VertexAttribI1ui,
			VertexAttribI2ui,
			VertexAttribI3ui,
			VertexAttribI4ui,
			VertexAttribI1iv,
			VertexAttribI2iv,
			VertexAttribI3iv,
			VertexAttribI4iv,
			VertexAttribI1uiv,
			VertexAttribI2uiv,
			VertexAttribI3uiv,
			VertexAttribI4uiv,
			VertexAttribI4bv,
			VertexAttribI4sv,
			VertexAttribI4ubv,
			VertexAttribI4usv,
			GetUniformuiv,
			BindFragDataLocation,
			GetFragDataLocation,
			Uniform1ui,
			Uniform2ui,
			Uniform3ui,
			Uniform4ui,
			Uniform1uiv,
			Uniform2uiv,
			Uniform3uiv,
			Uniform4uiv,
			TexParameterIiv,
			TexParameterIuiv,
			GetTexParameterIiv,
			GetTexParameterIuiv,
			ClearBufferiv,
			ClearBufferuiv,
			ClearBufferfv,
			ClearBufferfi,
			GetStringi,
			IsRenderbuffer,
			BindRenderbuffer,
			DeleteRenderbuffers,
			GenRenderbuffer,
			RenderbufferStorage,
			GetRenderbufferParameteriv,
			IsFramebuffer,
			BindFramebuffer,
			DeleteFramebuffers,
			GenFramebuffer,
			CheckFramebufferStatus,
			FramebufferTexture1D,
			FramebufferTexture2D,
			FramebufferTexture3D,
			FramebufferRenderbuffer,
			GetFramebufferAttachmentParameteriv,
			GenerateMipmap,
			BlitFramebuffer,
			RenderbufferStorageMultisample,
			FramebufferTextureLayer,
			MapBufferRange,
			FlushMappedBufferRange,
			BindVertexArray,
			DeleteVertexArrays,
			GenVertexArray,
			IsVertexArray,
			DrawArraysInstanced,
			DrawElementsInstanced,
			TexBuffer,
			PrimitiveRestartIndex,
			CopyBufferSubData,
			GetUniformIndices,
			GetActiveUniformsiv,
			GetActiveUniformName,
			GetUniformBlockIndex,
			GetActiveUniformBlockiv,
			GetActiveUniformBlockName,
			UniformBlockBinding,
			DrawElementsBaseVertex,
			DrawRangeElementsBaseVertex,
			DrawElementsInstancedBaseVertex,
			MultiDrawElementsBaseVertex,
			ProvokingVertex,
			FenceSync,
			IsSync,
			DeleteSync,
			ClientWaitSync,
			WaitSync,
			GetInteger64v,
			GetSynciv,
			GetInteger64i_v,
			GetBufferParameteri64v,
			FramebufferTexture,
			TexImage2DMultisample,
			TexImage3DMultisample,
			GetMultisamplefv,
			SampleMaski,
			BindFragDataLocationIndexed,
			GetFragDataIndex,
			GenSamplers,
			DeleteSamplers,
			IsSampler,
			BindSampler,
			SamplerParameteri,
			SamplerParameteriv,
			SamplerParameterf,
			SamplerParameterfv,
			SamplerParameterIiv,
			SamplerParameterIuiv,
			GetSamplerParameteriv,
			GetSamplerParameterIiv,
			GetSamplerParameterfv,
			GetSamplerParameterIuiv,
			QueryCounter,
			GetQueryObjecti64v,
			GetQueryObjectui64v,
			VertexAttribDivisor,
			VertexAttribP1ui,
			VertexAttribP1uiv,
			VertexAttribP2ui,
			VertexAttribP2uiv,
			VertexAttribP3ui,
			VertexAttribP3uiv,
			VertexAttribP4ui,
			VertexAttribP4uiv,
			VertexP2ui,
			VertexP2uiv,
			VertexP3ui,
			VertexP3uiv,
			VertexP4ui,
			VertexP4uiv,
			TexCoordP1ui,
			TexCoordP1uiv,
			TexCoordP2ui,
			TexCoordP2uiv,
			TexCoordP3ui,
			TexCoordP3uiv,
			TexCoordP4ui,
			TexCoordP4uiv,
			MultiTexCoordP1ui,
			MultiTexCoordP1uiv,
			MultiTexCoordP2ui,
			MultiTexCoordP2uiv,
			MultiTexCoordP3ui,
			MultiTexCoordP3uiv,
			MultiTexCoordP4ui,
			MultiTexCoordP4uiv,
			NormalP3ui,
			NormalP3uiv,
			ColorP3ui,
			ColorP3uiv,
			ColorP4ui,
			ColorP4uiv,
			SecondaryColorP3ui,
			SecondaryColorP3uiv,
			MinSampleShading,
			BlendEquationi,
			BlendEquationSeparatei,
			BlendFunci,
			BlendFuncSeparatei,
			DrawArraysIndirect,
			DrawElementsIndirect,
			Uniform1d,
			Uniform2d,
			Uniform3d,
			Uniform4d,
			Uniform1dv,
			Uniform2dv,
			Uniform3dv,
			Uniform4dv,
			UniformMatrix2dv,
			UniformMatrix3dv,
			UniformMatrix4dv,
			UniformMatrix2x3dv,
			UniformMatrix2x4dv,
			UniformMatrix3x2dv,
			UniformMatrix3x4dv,
			UniformMatrix4x2dv,
			UniformMatrix4x3dv,
			GetUniformdv,
			GetSubroutineUniformLocation,
			GetSubroutineIndex,
			GetActiveSubroutineUniformiv,
			GetActiveSubroutineUniformName,
			GetActiveSubroutineName,
			UniformSubroutinesuiv,
			GetUniformSubroutineuiv,
			GetProgramStageiv,
			PatchParameteri,
			PatchParameterfv,
			BindTransformFeedback,
			DeleteTransformFeedbacks,
			GenTransformFeedbacks,
			IsTransformFeedback,
			PauseTransformFeedback,
			ResumeTransformFeedback,
			DrawTransformFeedback,
			DrawTransformFeedbackStream,
			BeginQueryIndexed,
			EndQueryIndexed,
			GetQueryIndexediv,
			ReleaseShaderCompiler,
			ShaderBinary,
			GetShaderPrecisionFormat,
			DepthRangef,
			ClearDepthf,
			GetProgramBinary,
			ProgramBinary,
			ProgramParameteri,
			UseProgramStages,
			ActiveShaderProgram,
			CreateShaderProgramv,
			BindProgramPipeline,
			DeleteProgramPipelines,
			GenProgramPipelines,
			IsProgramPipeline,
			GetProgramPipelineiv,
			ProgramUniform1i,
			ProgramUniform1iv,
			ProgramUniform1f,
			ProgramUniform1fv,
			ProgramUniform1d,
			ProgramUniform1dv,
			ProgramUniform1ui,
			ProgramUniform1uiv,
			ProgramUniform2i,
			ProgramUniform2iv,
			ProgramUniform2f,
			ProgramUniform2fv,
			ProgramUniform2d,
			ProgramUniform2dv,
			ProgramUniform2ui,
			ProgramUniform2uiv,
			ProgramUniform3i,
			ProgramUniform3iv,
			ProgramUniform3f,
			ProgramUniform3fv,
			ProgramUniform3d,
			ProgramUniform3dv,
			ProgramUniform3ui,
			ProgramUniform3uiv,
			ProgramUniform4i,
			ProgramUniform4iv,
			ProgramUniform4f,
			ProgramUniform4fv,
			ProgramUniform4d,
			ProgramUniform4dv,
			ProgramUniform4ui,
			ProgramUniform4uiv,
			ProgramUniformMatrix2fv,
			ProgramUniformMatrix3fv,
			ProgramUniformMatrix4fv,
			ProgramUniformMatrix2dv,
			ProgramUniformMatrix3dv,
			ProgramUniformMatrix4dv,
			ProgramUniformMatrix2x3fv,
			ProgramUniformMatrix3x2fv,
			ProgramUniformMatrix2x4fv,
			ProgramUniformMatrix4x2fv,
			ProgramUniformMatrix3x4fv,
			ProgramUniformMatrix4x3fv,
			ProgramUniformMatrix2x3dv,
			ProgramUniformMatrix3x2dv,
			ProgramUniformMatrix2x4dv,
			ProgramUniformMatrix4x2dv,
			ProgramUniformMatrix3x4dv,
			ProgramUniformMatrix4x3dv,
			ValidateProgramPipeline,
			GetProgramPipelineInfoLog,
			VertexAttribL1d,
			VertexAttribL2d,
			VertexAttribL3d,
			VertexAttribL4d,
			VertexAttribL1dv,
			VertexAttribL2dv,
			VertexAttribL3dv,
			VertexAttribL4dv,
			VertexAttribLPointer,
			GetVertexAttribLdv,
			ViewportArrayv,
			ViewportIndexedf,
			ViewportIndexedfv,
			ScissorArrayv,
			ScissorIndexed,
			ScissorIndexedv,
			DepthRangeArrayv,
			DepthRangeIndexed,
			GetFloati_v,
			GetDoublei_v,
			DrawArraysInstancedBaseInstance,
			DrawElementsInstancedBaseInstance,
			DrawElementsInstancedBaseVertexBaseInstance,
			GetInternalformativ,
			GetActiveAtomicCounterBufferiv,
			BindImageTexture,
			MemoryBarrier,
			TexStorage1D,
			TexStorage2D,
			TexStorage3D,
			DrawTransformFeedbackInstanced,
			DrawTransformFeedbackStreamInstanced,
			ClearBufferData,
			ClearBufferSubData,
			DispatchCompute,
			DispatchComputeIndirect,
			CopyImageSubData,
			FramebufferParameteri,
			GetFramebufferParameteriv,
			GetInternalformati64v,
			InvalidateTexSubImage,
			InvalidateTexImage,
			InvalidateBufferSubData,
			InvalidateBufferData,
			InvalidateFramebuffer,
			InvalidateSubFramebuffer,
			MultiDrawArraysIndirect,
			MultiDrawElementsIndirect,
			GetProgramInterfaceiv,
			GetProgramResourceIndex,
			GetProgramResourceName,
			GetProgramResourceiv,
			GetProgramResourceLocation,
			GetProgramResourceLocationIndex,
			ShaderStorageBlockBinding,
			TexBufferRange,
			TexStorage2DMultisample,
			TexStorage3DMultisample,
			TextureView,
			BindVertexBuffer,
			VertexAttribFormat,
			VertexAttribIFormat,
			VertexAttribLFormat,
			VertexAttribBinding,
			VertexBindingDivisor,
			DebugMessageControl,
			DebugMessageInsert,
			DebugMessageCallback,
			GetDebugMessageLog,
			PushDebugGroup,
			PopDebugGroup,
			ObjectLabel,
			GetObjectLabel,
			ObjectPtrLabel,
			GetObjectPtrLabel,
			GetPointerv,
			BufferStorage,
			ClearTexImage,
			ClearTexSubImage,
			BindBuffersBase,
			BindBuffersRange,
			BindTextures,
			BindSamplers,
			BindImageTextures,
			BindVertexBuffers,
			ClipControl,
			CreateTransformFeedbacks,
			TransformFeedbackBufferBase,
			TransformFeedbackBufferRange,
			GetTransformFeedbackiv,
			GetTransformFeedbacki_v,
			GetTransformFeedbacki64_v,
			CreateBuffer,
			NamedBufferStorage,
			NamedBufferData,
			NamedBufferSubData,
			CopyNamedBufferSubData,
			ClearNamedBufferData,
			ClearNamedBufferSubData,
			MapNamedBuffer,
			MapNamedBufferRange,
			UnmapNamedBuffer,
			FlushMappedNamedBufferRange,
			GetNamedBufferParameteriv,
			GetNamedBufferParameteri64v,
			GetNamedBufferPointerv,
			GetNamedBufferSubData,
			CreateFramebuffer,
			NamedFramebufferRenderbuffer,
			NamedFramebufferParameteri,
			NamedFramebufferTexture,
			NamedFramebufferTextureLayer,
			NamedFramebufferDrawBuffer,
			NamedFramebufferDrawBuffers,
			NamedFramebufferReadBuffer,
			InvalidateNamedFramebufferData,
			InvalidateNamedFramebufferSubData,
			ClearNamedFramebufferiv,
			ClearNamedFramebufferuiv,
			ClearNamedFramebufferfv,
			ClearNamedFramebufferfi,
			BlitNamedFramebuffer,
			CheckNamedFramebufferStatus,
			GetNamedFramebufferParameteriv,
			GetNamedFramebufferAttachmentParameteriv,
			CreateRenderbuffer,
			NamedRenderbufferStorage,
			NamedRenderbufferStorageMultisample,
			GetNamedRenderbufferParameteriv,
			CreateTexture,
			TextureBuffer,
			TextureBufferRange,
			TextureStorage1D,
			TextureStorage2D,
			TextureStorage3D,
			TextureStorage2DMultisample,
			TextureStorage3DMultisample,
			TextureSubImage1D,
			TextureSubImage2D,
			TextureSubImage3D,
			CompressedTextureSubImage1D,
			CompressedTextureSubImage2D,
			CompressedTextureSubImage3D,
			CopyTextureSubImage1D,
			CopyTextureSubImage2D,
			CopyTextureSubImage3D,
			TextureParameterf,
			TextureParameterfv,
			TextureParameteri,
			TextureParameterIiv,
			TextureParameterIuiv,
			TextureParameteriv,
			GenerateTextureMipmap,
			BindTextureUnit,
			GetTextureImage,
			GetCompressedTextureImage,
			GetTextureLevelParameterfv,
			GetTextureLevelParameteriv,
			GetTextureParameterfv,
			GetTextureParameterIiv,
			GetTextureParameterIuiv,
			GetTextureParameteriv,
			CreateVertexArray,
			DisableVertexArrayAttrib,
			EnableVertexArrayAttrib,
			VertexArrayElementBuffer,
			VertexArrayVertexBuffer,
			VertexArrayVertexBuffers,
			VertexArrayAttribBinding,
			VertexArrayAttribFormat,
			VertexArrayAttribIFormat,
			VertexArrayAttribLFormat,
			VertexArrayBindingDivisor,
			GetVertexArrayiv,
			GetVertexArrayIndexediv,
			GetVertexArrayIndexed64iv,
			CreateSamplers,
			CreateProgramPipelines,
			CreateQueries,
			GetQueryBufferObjecti64v,
			GetQueryBufferObjectiv,
			GetQueryBufferObjectui64v,
			GetQueryBufferObjectuiv,
			MemoryBarrierByRegion,
			GetTextureSubImage,
			GetCompressedTextureSubImage,
			GetGraphicsResetStatus,
			GetnCompressedTexImage,
			GetnTexImage,
			GetnUniformdv,
			GetnUniformfv,
			GetnUniformiv,
			GetnUniformuiv,
			ReadnPixels,
			GetnMapdv,
			GetnMapfv,
			GetnMapiv,
			GetnPixelMapfv,
			GetnPixelMapuiv,
			GetnPixelMapusv,
			GetnPolygonStipple,
			GetnColorTable,
			GetnConvolutionFilter,
			GetnSeparableFilter,
			GetnHistogram,
			GetnMinmax,
			TextureBarrier,
			Count
		};
	}
	typedef CommandIdEnum::Enum CommandId;

	namespace TextureUnitEnum
	{
		enum Enum : GLenum
		{
			Texture0 = GL_TEXTURE0,
			Texture1 = GL_TEXTURE1,
			Texture2 = GL_TEXTURE2,
			Texture3 = GL_TEXTURE3,
			Texture4 = GL_TEXTURE4,
			Texture5 = GL_TEXTURE5,
			Texture6 = GL_TEXTURE6,
			Texture7 = GL_TEXTURE7,
			Texture8 = GL_TEXTURE8,
			Texture9 = GL_TEXTURE9,
			Texture10 = GL_TEXTURE10,
			Texture11 = GL_TEXTURE11,
			Texture12 = GL_TEXTURE12,
			Texture13 = GL_TEXTURE13,
			Texture14 = GL_TEXTURE14,
			Texture15 = GL_TEXTURE15,
			Texture16 = GL_TEXTURE16,
			Texture17 = GL_TEXTURE17,
			Texture18 = GL_TEXTURE18,
			Texture19 = GL_TEXTURE19,
			Texture20 = GL_TEXTURE20,
			Texture21 = GL_TEXTURE21,
			Texture22 = GL_TEXTURE22,
			Texture23 = GL_TEXTURE23,
			Texture24 = GL_TEXTURE24,
			Texture25 = GL_TEXTURE25,
			Texture26 = GL_TEXTURE26,
			Texture27 = GL_TEXTURE27,
			Texture28 = GL_TEXTURE28,
			Texture29 = GL_TEXTURE29,
			Texture30 = GL_TEXTURE30,
			Texture31 = GL_TEXTURE31
		};
	}
	typedef TextureUnitEnum::Enum TextureUnit;

	namespace ConditionalRenderModeEnum
	{
		enum Enum : GLenum
		{
			QueryWait = GL_QUERY_WAIT,
			QueryNoWait = GL_QUERY_NO_WAIT,
			QueryByRegionWait = GL_QUERY_BY_REGION_WAIT,
			QueryByRegionNoWait = GL_QUERY_BY_REGION_NO_WAIT,
			QueryWaitInverted = GL_QUERY_WAIT_INVERTED,
			QueryNoWaitInverted = GL_QUERY_NO_WAIT_INVERTED,
			QueryByRegionWaitInverted = GL_QUERY_BY_REGION_WAIT_INVERTED,
			QueryByRegionNoWaitInverted = GL_QUERY_BY_REGION_NO_WAIT_INVERTED
		};
	}
	typedef ConditionalRenderModeEnum::Enum ConditionalRenderMode;

	namespace QueryTargetEnum
	{
		enum Enum : GLenum
		{
			SamplesPassed = GL_SAMPLES_PASSED,
			AnySamplesPassed = GL_ANY_SAMPLES_PASSED,
			AnySamplesPassedConservative = GL_ANY_SAMPLES_PASSED_CONSERVATIVE,
			PrimitivesGenerated = GL_PRIMITIVES_GENERATED,
			TransformFeedbackPrimitivesWritten = GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,
			TimeElapsed = GL_TIME_ELAPSED
		};
	}
	typedef QueryTargetEnum::Enum QueryTarget;

	namespace PrimitiveTypeEnum
	{
		enum Enum : GLenum
		{
			Lines = GL_LINES,
			LinesAdjacency = GL_LINES_ADJACENCY,
			LineLoop = GL_LINE_LOOP,
			LineStrip = GL_LINE_STRIP,
			LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
			Patches = GL_PATCHES,
			Points = GL_POINTS,
			Quads = GL_QUADS,
			Triangles = GL_TRIANGLES,
			TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
			TriangleFan = GL_TRIANGLE_FAN,
			TriangleStrip = GL_TRIANGLE_STRIP,
			TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY
		};
	}
	typedef PrimitiveTypeEnum::Enum PrimitiveType;

	namespace BufferTargetEnum
	{
		enum Enum : GLenum
		{
			ArrayBuffer = GL_ARRAY_BUFFER,
			AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
			CopyReadBuffer = GL_COPY_READ_BUFFER,
			CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
			DispatchIndirectBuffer = GL_DISPATCH_INDIRECT_BUFFER,
			DrawIndirectBuffer = GL_DRAW_INDIRECT_BUFFER,
			ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
			PixelPackBuffer = GL_PIXEL_PACK_BUFFER,
			PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
			QueryBuffer = GL_QUERY_BUFFER,
			ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
			TextureBuffer = GL_TEXTURE_BUFFER,
			TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
			UniformBuffer = GL_UNIFORM_BUFFER
		};
	}
	typedef BufferTargetEnum::Enum BufferTarget;

	namespace FramebufferTargetEnum
	{
		enum Enum : GLenum
		{
			Framebuffer = GL_FRAMEBUFFER,
			DrawFramebuffer = GL_DRAW_FRAMEBUFFER,
			ReadFramebuffer = GL_READ_FRAMEBUFFER
		};
	}
	typedef FramebufferTargetEnum::Enum FramebufferTarget;

	namespace BufferAccessARBEnum
	{
		enum Enum : GLenum
		{
			ReadOnly = GL_READ_ONLY,
			WriteOnly = GL_WRITE_ONLY,
			ReadWrite = GL_READ_WRITE
		};
	}
	typedef BufferAccessARBEnum::Enum BufferAccessARB;

	namespace InternalFormatEnum
	{
		enum Enum : GLenum
		{
			Red = GL_RED,
			R8 = GL_R8,
			R8Snorm = GL_R8_SNORM,
			R16 = GL_R16,
			R16Snorm = GL_R16_SNORM,
			R16F = GL_R16F,
			R32F = GL_R32F,
			R8I = GL_R8I,
			R16I = GL_R16I,
			R32I = GL_R32I,
			R8Ui = GL_R8UI,
			R16Ui = GL_R16UI,
			R32Ui = GL_R32UI,
			RG = GL_RG,
			RG8 = GL_RG8,
			RG8Snorm = GL_RG8_SNORM,
			RG16 = GL_RG16,
			RG16Snorm = GL_RG16_SNORM,
			RG16F = GL_RG16F,
			RG32F = GL_RG32F,
			RG8I = GL_RG8I,
			RG16I = GL_RG16I,
			RG32I = GL_RG32I,
			RG8Ui = GL_RG8UI,
			RG16Ui = GL_RG16UI,
			RG32Ui = GL_RG32UI,
			RGB = GL_RGB,
			RGB4 = GL_RGB4,
			RGB5 = GL_RGB5,
			RGB8 = GL_RGB8,
			RGB8Snorm = GL_RGB8_SNORM,
			RGB10 = GL_RGB10,
			RGB12 = GL_RGB12,
			RGB16 = GL_RGB16,
			RGB16F = GL_RGB16F,
			RGB16Snorm = GL_RGB16_SNORM,
			RGB32F = GL_RGB32F,
			RGB8I = GL_RGB8I,
			RGB16I = GL_RGB16I,
			RGB32I = GL_RGB32I,
			RGB8Ui = GL_RGB8UI,
			RGB16Ui = GL_RGB16UI,
			RGB32Ui = GL_RGB32UI,
			SRGB = GL_SRGB,
			SRGBAlpha = GL_SRGB_ALPHA,
			SRGB8 = GL_SRGB8,
			SRGB8Alpha8 = GL_SRGB8_ALPHA8,
			R3G3B2 = GL_R3_G3_B2,
			R11FG11FB10F = GL_R11F_G11F_B10F,
			RGB9E5 = GL_RGB9_E5,
			RGBA = GL_RGBA,
			RGBA4 = GL_RGBA4,
			RGB5A1 = GL_RGB5_A1,
			RGBA8 = GL_RGBA8,
			RGBA8Snorm = GL_RGBA8_SNORM,
			RGB10A2 = GL_RGB10_A2,
			RGBA12 = GL_RGBA12,
			RGBA16 = GL_RGBA16,
			RGBA16F = GL_RGBA16F,
			RGBA32F = GL_RGBA32F,
			RGBA8I = GL_RGBA8I,
			RGBA16I = GL_RGBA16I,
			RGBA32I = GL_RGBA32I,
			RGBA8Ui = GL_RGBA8UI,
			RGBA16Ui = GL_RGBA16UI,
			RGBA32Ui = GL_RGBA32UI,
			RGB10A2Ui = GL_RGB10_A2UI,
			DepthComponent = GL_DEPTH_COMPONENT,
			DepthComponent16 = GL_DEPTH_COMPONENT16,
			DepthComponent32F = GL_DEPTH_COMPONENT32F,
			DepthStencil = GL_DEPTH_STENCIL,
			Depth24Stencil8 = GL_DEPTH24_STENCIL8,
			Depth32FStencil8 = GL_DEPTH32F_STENCIL8,
			StencilIndex = GL_STENCIL_INDEX,
			StencilIndex1 = GL_STENCIL_INDEX1,
			StencilIndex4 = GL_STENCIL_INDEX4,
			StencilIndex8 = GL_STENCIL_INDEX8,
			StencilIndex16 = GL_STENCIL_INDEX16,
			CompressedRed = GL_COMPRESSED_RED,
			CompressedRG = GL_COMPRESSED_RG,
			CompressedRGB = GL_COMPRESSED_RGB,
			CompressedRGBA = GL_COMPRESSED_RGBA,
			CompressedSRGB = GL_COMPRESSED_SRGB,
			CompressedSRGBAlpha = GL_COMPRESSED_SRGB_ALPHA,
			CompressedRedRGtc1 = GL_COMPRESSED_RED_RGTC1,
			CompressedSignedRedRGtc1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
			CompressedR11Eac = GL_COMPRESSED_R11_EAC,
			CompressedSignedR11Eac = GL_COMPRESSED_SIGNED_R11_EAC,
			CompressedRGRGtc2 = GL_COMPRESSED_RG_RGTC2,
			CompressedSignedRGRGtc2 = GL_COMPRESSED_SIGNED_RG_RGTC2,
			CompressedRGBABptcUnorm = GL_COMPRESSED_RGBA_BPTC_UNORM,
			CompressedSRGBAlphaBptcUnorm = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
			CompressedRGBBptcSignedFloat = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
			CompressedRGBBptcUnsignedFloat = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
			CompressedRGB8Etc2 = GL_COMPRESSED_RGB8_ETC2,
			CompressedSRGB8Etc2 = GL_COMPRESSED_SRGB8_ETC2,
			CompressedRGB8PunchthroughAlpha1Etc2 = GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2,
			CompressedSRGB8PunchthroughAlpha1Etc2 = GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2,
			CompressedRGBA8Etc2Eac = GL_COMPRESSED_RGBA8_ETC2_EAC,
			CompressedSRGB8Alpha8Etc2Eac = GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC,
			CompressedRG11Eac = GL_COMPRESSED_RG11_EAC,
			CompressedSignedRG11Eac = GL_COMPRESSED_SIGNED_RG11_EAC,
			CompressedRGBS3TcDxt1Ext = GL_COMPRESSED_RGB_S3TC_DXT1_EXT,
			CompressedRGBAS3TcDxt1Ext = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
			CompressedRGBAS3TcDxt3Ext = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,
			CompressedRGBAS3TcDxt5Ext = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT
		};
	}
	typedef InternalFormatEnum::Enum InternalFormat;

	namespace RenderbufferTargetEnum
	{
		enum Enum : GLenum
		{
			Renderbuffer = GL_RENDERBUFFER
		};
	}
	typedef RenderbufferTargetEnum::Enum RenderbufferTarget;

	namespace TextureTargetEnum
	{
		enum Enum : GLenum
		{
			ProxyTexture1D = GL_PROXY_TEXTURE_1D,
			ProxyTexture1DArray = GL_PROXY_TEXTURE_1D_ARRAY,
			ProxyTexture2D = GL_PROXY_TEXTURE_2D,
			ProxyTexture2DArray = GL_PROXY_TEXTURE_2D_ARRAY,
			ProxyTexture2DMultisample = GL_PROXY_TEXTURE_2D_MULTISAMPLE,
			ProxyTexture2DMultisampleArray = GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY,
			ProxyTexture3D = GL_PROXY_TEXTURE_3D,
			ProxyTextureCubeMap = GL_PROXY_TEXTURE_CUBE_MAP,
			ProxyTextureCubeMapArray = GL_PROXY_TEXTURE_CUBE_MAP_ARRAY,
			ProxyTextureRectangle = GL_PROXY_TEXTURE_RECTANGLE,
			Texture1D = GL_TEXTURE_1D,
			Texture2D = GL_TEXTURE_2D,
			Texture3D = GL_TEXTURE_3D,
			TextureRectangle = GL_TEXTURE_RECTANGLE,
			TextureCubeMap = GL_TEXTURE_CUBE_MAP,
			TextureCubeMapPositiveX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
			TextureCubeMapNegativeX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
			TextureCubeMapPositiveY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
			TextureCubeMapNegativeY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
			TextureCubeMapPositiveZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
			TextureCubeMapNegativeZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
			TextureCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
			Texture1DArray = GL_TEXTURE_1D_ARRAY,
			Texture2DArray = GL_TEXTURE_2D_ARRAY,
			Texture2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
			Texture2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
		};
	}
	typedef TextureTargetEnum::Enum TextureTarget;

	namespace BindTransformFeedbackTargetEnum
	{
		enum Enum : GLenum
		{
			TransformFeedback = GL_TRANSFORM_FEEDBACK
		};
	}
	typedef BindTransformFeedbackTargetEnum::Enum BindTransformFeedbackTarget;

	namespace BlendEquationModeEXTEnum
	{
		enum Enum : GLenum
		{
			FuncAdd = GL_FUNC_ADD,
			FuncReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
			FuncSubtract = GL_FUNC_SUBTRACT,
			Max = GL_MAX,
			Min = GL_MIN
		};
	}
	typedef BlendEquationModeEXTEnum::Enum BlendEquationModeEXT;

	namespace BlendingFactorEnum
	{
		enum Enum : GLenum
		{
			Zero = GL_ZERO,
			One = GL_ONE,
			SrcColor = GL_SRC_COLOR,
			OneMinusSrcColor = GL_ONE_MINUS_SRC_COLOR,
			DstColor = GL_DST_COLOR,
			OneMinusDstColor = GL_ONE_MINUS_DST_COLOR,
			SrcAlpha = GL_SRC_ALPHA,
			OneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
			DstAlpha = GL_DST_ALPHA,
			OneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
			ConstantColor = GL_CONSTANT_COLOR,
			OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
			ConstantAlpha = GL_CONSTANT_ALPHA,
			OneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA,
			SrcAlphaSaturate = GL_SRC_ALPHA_SATURATE,
			Src1Color = GL_SRC1_COLOR,
			OneMinusSrc1Color = GL_ONE_MINUS_SRC1_COLOR,
			Src1Alpha = GL_SRC1_ALPHA,
			OneMinusSrc1Alpha = GL_ONE_MINUS_SRC1_ALPHA
		};
	}
	typedef BlendingFactorEnum::Enum BlendingFactor;

	namespace BlitFramebufferFilterEnum
	{
		enum Enum : GLenum
		{
			Nearest = GL_NEAREST,
			Linear = GL_LINEAR
		};
	}
	typedef BlitFramebufferFilterEnum::Enum BlitFramebufferFilter;

	namespace BufferUsageARBEnum
	{
		enum Enum : GLenum
		{
			StreamDraw = GL_STREAM_DRAW,
			StreamRead = GL_STREAM_READ,
			StreamCopy = GL_STREAM_COPY,
			StaticDraw = GL_STATIC_DRAW,
			StaticRead = GL_STATIC_READ,
			StaticCopy = GL_STATIC_COPY,
			DynamicDraw = GL_DYNAMIC_DRAW,
			DynamicRead = GL_DYNAMIC_READ,
			DynamicCopy = GL_DYNAMIC_COPY
		};
	}
	typedef BufferUsageARBEnum::Enum BufferUsageARB;

	namespace BufferStorageTargetEnum
	{
		enum Enum : GLenum
		{
			ArrayBuffer = GL_ARRAY_BUFFER,
			AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
			CopyReadBuffer = GL_COPY_READ_BUFFER,
			CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
			DispatchIndirectBuffer = GL_DISPATCH_INDIRECT_BUFFER,
			DrawIndirectBuffer = GL_DRAW_INDIRECT_BUFFER,
			ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
			PixelPackBuffer = GL_PIXEL_PACK_BUFFER,
			PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
			QueryBuffer = GL_QUERY_BUFFER,
			ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
			TextureBuffer = GL_TEXTURE_BUFFER,
			TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
			UniformBuffer = GL_UNIFORM_BUFFER
		};
	}
	typedef BufferStorageTargetEnum::Enum BufferStorageTarget;

	namespace FramebufferStatusEnum
	{
		enum Enum : GLenum
		{
			FramebufferComplete = GL_FRAMEBUFFER_COMPLETE,
			FramebufferUndefined = GL_FRAMEBUFFER_UNDEFINED,
			FramebufferIncompleteAttachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
			FramebufferIncompleteMissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
			FramebufferIncompleteDrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
			FramebufferIncompleteReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
			FramebufferUnsupported = GL_FRAMEBUFFER_UNSUPPORTED,
			FramebufferIncompleteMultisample = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
			FramebufferIncompleteLayerTargets = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
		};
	}
	typedef FramebufferStatusEnum::Enum FramebufferStatus;

	namespace ClampColorTargetARBEnum
	{
		enum Enum : GLenum
		{
			ClampReadColor = GL_CLAMP_READ_COLOR
		};
	}
	typedef ClampColorTargetARBEnum::Enum ClampColorTargetARB;

	namespace ClampColorModeARBEnum
	{
		enum Enum : GLenum
		{
			False = GL_FALSE,
			True = GL_TRUE,
			FixedOnly = GL_FIXED_ONLY
		};
	}
	typedef ClampColorModeARBEnum::Enum ClampColorModeARB;

	namespace PixelFormatEnum
	{
		enum Enum : GLenum
		{
			Alpha = GL_ALPHA,
			BGR = GL_BGR,
			BGRInteger = GL_BGR_INTEGER,
			BGRA = GL_BGRA,
			BGRAInteger = GL_BGRA_INTEGER,
			Blue = GL_BLUE,
			BlueInteger = GL_BLUE_INTEGER,
			DepthComponent = GL_DEPTH_COMPONENT,
			DepthStencil = GL_DEPTH_STENCIL,
			Green = GL_GREEN,
			GreenInteger = GL_GREEN_INTEGER,
			Red = GL_RED,
			RedInteger = GL_RED_INTEGER,
			RG = GL_RG,
			RGInteger = GL_RG_INTEGER,
			RGB = GL_RGB,
			RGBInteger = GL_RGB_INTEGER,
			RGBA = GL_RGBA,
			RGBAInteger = GL_RGBA_INTEGER,
			StencilIndex = GL_STENCIL_INDEX,
			UnsignedInt = GL_UNSIGNED_INT,
			UnsignedShort = GL_UNSIGNED_SHORT
		};
	}
	typedef PixelFormatEnum::Enum PixelFormat;

	namespace PixelTypeEnum
	{
		enum Enum : GLenum
		{
			Byte = GL_BYTE,
			Float = GL_FLOAT,
			Int = GL_INT,
			Short = GL_SHORT,
			UnsignedByte = GL_UNSIGNED_BYTE,
			UnsignedByte332 = GL_UNSIGNED_BYTE_3_3_2,
			UnsignedInt = GL_UNSIGNED_INT,
			UnsignedInt1010102 = GL_UNSIGNED_INT_10_10_10_2,
			UnsignedInt8888 = GL_UNSIGNED_INT_8_8_8_8,
			UnsignedShort = GL_UNSIGNED_SHORT,
			UnsignedShort4444 = GL_UNSIGNED_SHORT_4_4_4_4,
			UnsignedShort5551 = GL_UNSIGNED_SHORT_5_5_5_1
		};
	}
	typedef PixelTypeEnum::Enum PixelType;

	namespace BufferEnum
	{
		enum Enum : GLenum
		{
			Color = GL_COLOR,
			Depth = GL_DEPTH,
			Stencil = GL_STENCIL
		};
	}
	typedef BufferEnum::Enum Buffer;

	namespace SyncStatusEnum
	{
		enum Enum : GLenum
		{
			AlreadySignaled = GL_ALREADY_SIGNALED,
			TimeoutExpired = GL_TIMEOUT_EXPIRED,
			ConditionSatisfied = GL_CONDITION_SATISFIED,
			WaitFailed = GL_WAIT_FAILED
		};
	}
	typedef SyncStatusEnum::Enum SyncStatus;

	namespace ClipControlOriginEnum
	{
		enum Enum : GLenum
		{
			LowerLeft = GL_LOWER_LEFT,
			UpperLeft = GL_UPPER_LEFT
		};
	}
	typedef ClipControlOriginEnum::Enum ClipControlOrigin;

	namespace ClipControlDepthEnum
	{
		enum Enum : GLenum
		{
			NegativeOneToOne = GL_NEGATIVE_ONE_TO_ONE,
			ZeroToOne = GL_ZERO_TO_ONE
		};
	}
	typedef ClipControlDepthEnum::Enum ClipControlDepth;

	namespace ColorPointerTypeEnum
	{
		enum Enum : GLenum
		{
			Byte = GL_BYTE,
			Double = GL_DOUBLE,
			Float = GL_FLOAT,
			Int = GL_INT,
			Short = GL_SHORT,
			UnsignedByte = GL_UNSIGNED_BYTE,
			UnsignedInt = GL_UNSIGNED_INT,
			UnsignedShort = GL_UNSIGNED_SHORT
		};
	}
	typedef ColorPointerTypeEnum::Enum ColorPointerType;

	namespace CopyBufferSubDataTargetEnum
	{
		enum Enum : GLenum
		{
			ArrayBuffer = GL_ARRAY_BUFFER,
			AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
			CopyReadBuffer = GL_COPY_READ_BUFFER,
			CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
			DispatchIndirectBuffer = GL_DISPATCH_INDIRECT_BUFFER,
			DrawIndirectBuffer = GL_DRAW_INDIRECT_BUFFER,
			ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
			PixelPackBuffer = GL_PIXEL_PACK_BUFFER,
			PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
			QueryBuffer = GL_QUERY_BUFFER,
			ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
			TextureBuffer = GL_TEXTURE_BUFFER,
			TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
			UniformBuffer = GL_UNIFORM_BUFFER
		};
	}
	typedef CopyBufferSubDataTargetEnum::Enum CopyBufferSubDataTarget;

	namespace CopyImageSubDataTargetEnum
	{
		enum Enum : GLenum
		{
			Renderbuffer = GL_RENDERBUFFER,
			Texture1D = GL_TEXTURE_1D,
			Texture2D = GL_TEXTURE_2D,
			Texture3D = GL_TEXTURE_3D,
			TextureRectangle = GL_TEXTURE_RECTANGLE,
			TextureCubeMap = GL_TEXTURE_CUBE_MAP,
			TextureCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
			Texture1DArray = GL_TEXTURE_1D_ARRAY,
			Texture2DArray = GL_TEXTURE_2D_ARRAY,
			Texture2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
			Texture2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
		};
	}
	typedef CopyImageSubDataTargetEnum::Enum CopyImageSubDataTarget;

	namespace ShaderTypeEnum
	{
		enum Enum : GLenum
		{
			ComputeShader = GL_COMPUTE_SHADER,
			VertexShader = GL_VERTEX_SHADER,
			TessControlShader = GL_TESS_CONTROL_SHADER,
			TessEvaluationShader = GL_TESS_EVALUATION_SHADER,
			GeometryShader = GL_GEOMETRY_SHADER,
			FragmentShader = GL_FRAGMENT_SHADER
		};
	}
	typedef ShaderTypeEnum::Enum ShaderType;

	namespace CullFaceModeEnum
	{
		enum Enum : GLenum
		{
			Back = GL_BACK,
			Front = GL_FRONT,
			FrontAndBack = GL_FRONT_AND_BACK
		};
	}
	typedef CullFaceModeEnum::Enum CullFaceMode;

	namespace DebugSourceEnum
	{
		enum Enum : GLenum
		{
			DebugSourceApi = GL_DEBUG_SOURCE_API,
			DebugSourceWindowSystem = GL_DEBUG_SOURCE_WINDOW_SYSTEM,
			DebugSourceShaderCompiler = GL_DEBUG_SOURCE_SHADER_COMPILER,
			DebugSourceThirdParty = GL_DEBUG_SOURCE_THIRD_PARTY,
			DebugSourceApplication = GL_DEBUG_SOURCE_APPLICATION,
			DebugSourceOther = GL_DEBUG_SOURCE_OTHER,
			DontCare = GL_DONT_CARE
		};
	}
	typedef DebugSourceEnum::Enum DebugSource;

	namespace DebugTypeEnum
	{
		enum Enum : GLenum
		{
			DebugTypeError = GL_DEBUG_TYPE_ERROR,
			DebugTypeDeprecatedBehavior = GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,
			DebugTypeUndefinedBehavior = GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,
			DebugTypePortability = GL_DEBUG_TYPE_PORTABILITY,
			DebugTypePerformance = GL_DEBUG_TYPE_PERFORMANCE,
			DebugTypeMarker = GL_DEBUG_TYPE_MARKER,
			DebugTypePushGroup = GL_DEBUG_TYPE_PUSH_GROUP,
			DebugTypePopGroup = GL_DEBUG_TYPE_POP_GROUP,
			DebugTypeOther = GL_DEBUG_TYPE_OTHER,
			DontCare = GL_DONT_CARE
		};
	}
	typedef DebugTypeEnum::Enum DebugType;

	namespace DebugSeverityEnum
	{
		enum Enum : GLenum
		{
			DebugSeverityLow = GL_DEBUG_SEVERITY_LOW,
			DebugSeverityMedium = GL_DEBUG_SEVERITY_MEDIUM,
			DebugSeverityHigh = GL_DEBUG_SEVERITY_HIGH,
			DebugSeverityNotification = GL_DEBUG_SEVERITY_NOTIFICATION,
			DontCare = GL_DONT_CARE
		};
	}
	typedef DebugSeverityEnum::Enum DebugSeverity;

	namespace DepthFunctionEnum
	{
		enum Enum : GLenum
		{
			Always = GL_ALWAYS,
			Equal = GL_EQUAL,
			Gequal = GL_GEQUAL,
			Greater = GL_GREATER,
			Lequal = GL_LEQUAL,
			Less = GL_LESS,
			Never = GL_NEVER,
			Notequal = GL_NOTEQUAL
		};
	}
	typedef DepthFunctionEnum::Enum DepthFunction;

	namespace EnableCapEnum
	{
		enum Enum : GLenum
		{
			Blend = GL_BLEND,
			ClipDistance0 = GL_CLIP_DISTANCE0,
			ClipDistance1 = GL_CLIP_DISTANCE1,
			ClipDistance2 = GL_CLIP_DISTANCE2,
			ClipDistance3 = GL_CLIP_DISTANCE3,
			ClipDistance4 = GL_CLIP_DISTANCE4,
			ClipDistance5 = GL_CLIP_DISTANCE5,
			ClipDistance6 = GL_CLIP_DISTANCE6,
			ClipDistance7 = GL_CLIP_DISTANCE7,
			ColorLogicOp = GL_COLOR_LOGIC_OP,
			CullFace = GL_CULL_FACE,
			DebugOutput = GL_DEBUG_OUTPUT,
			DebugOutputSynchronous = GL_DEBUG_OUTPUT_SYNCHRONOUS,
			DepthClamp = GL_DEPTH_CLAMP,
			DepthTest = GL_DEPTH_TEST,
			Dither = GL_DITHER,
			FramebufferSRGB = GL_FRAMEBUFFER_SRGB,
			LineSmooth = GL_LINE_SMOOTH,
			Multisample = GL_MULTISAMPLE,
			PolygonOffsetFill = GL_POLYGON_OFFSET_FILL,
			PolygonOffsetLine = GL_POLYGON_OFFSET_LINE,
			PolygonOffsetPoint = GL_POLYGON_OFFSET_POINT,
			PolygonSmooth = GL_POLYGON_SMOOTH,
			PrimitiveRestart = GL_PRIMITIVE_RESTART,
			PrimitiveRestartFixedIndex = GL_PRIMITIVE_RESTART_FIXED_INDEX,
			ProgramPointSize = GL_PROGRAM_POINT_SIZE,
			RasterizerDiscard = GL_RASTERIZER_DISCARD,
			SampleAlphaToCoverage = GL_SAMPLE_ALPHA_TO_COVERAGE,
			SampleAlphaToOne = GL_SAMPLE_ALPHA_TO_ONE,
			SampleCoverage = GL_SAMPLE_COVERAGE,
			SampleMask = GL_SAMPLE_MASK,
			SampleShading = GL_SAMPLE_SHADING,
			ScissorTest = GL_SCISSOR_TEST,
			StencilTest = GL_STENCIL_TEST,
			Texture1D = GL_TEXTURE_1D,
			Texture2D = GL_TEXTURE_2D,
			TextureCubeMapSeamless = GL_TEXTURE_CUBE_MAP_SEAMLESS,
			VertexArray = GL_VERTEX_ARRAY
		};
	}
	typedef EnableCapEnum::Enum EnableCap;

	namespace DrawBufferModeEnum
	{
		enum Enum : GLenum
		{
			Back = GL_BACK,
			BackLeft = GL_BACK_LEFT,
			BackRight = GL_BACK_RIGHT,
			Front = GL_FRONT,
			FrontAndBack = GL_FRONT_AND_BACK,
			FrontLeft = GL_FRONT_LEFT,
			FrontRight = GL_FRONT_RIGHT,
			Left = GL_LEFT,
			None = GL_NONE,
			Right = GL_RIGHT,
			ColorAttachment0 = GL_COLOR_ATTACHMENT0,
			ColorAttachment1 = GL_COLOR_ATTACHMENT1,
			ColorAttachment2 = GL_COLOR_ATTACHMENT2,
			ColorAttachment3 = GL_COLOR_ATTACHMENT3,
			ColorAttachment4 = GL_COLOR_ATTACHMENT4,
			ColorAttachment5 = GL_COLOR_ATTACHMENT5,
			ColorAttachment6 = GL_COLOR_ATTACHMENT6,
			ColorAttachment7 = GL_COLOR_ATTACHMENT7,
			ColorAttachment8 = GL_COLOR_ATTACHMENT8,
			ColorAttachment9 = GL_COLOR_ATTACHMENT9,
			ColorAttachment10 = GL_COLOR_ATTACHMENT10,
			ColorAttachment11 = GL_COLOR_ATTACHMENT11,
			ColorAttachment12 = GL_COLOR_ATTACHMENT12,
			ColorAttachment13 = GL_COLOR_ATTACHMENT13,
			ColorAttachment14 = GL_COLOR_ATTACHMENT14,
			ColorAttachment15 = GL_COLOR_ATTACHMENT15,
			ColorAttachment16 = GL_COLOR_ATTACHMENT16,
			ColorAttachment17 = GL_COLOR_ATTACHMENT17,
			ColorAttachment18 = GL_COLOR_ATTACHMENT18,
			ColorAttachment19 = GL_COLOR_ATTACHMENT19,
			ColorAttachment20 = GL_COLOR_ATTACHMENT20,
			ColorAttachment21 = GL_COLOR_ATTACHMENT21,
			ColorAttachment22 = GL_COLOR_ATTACHMENT22,
			ColorAttachment23 = GL_COLOR_ATTACHMENT23,
			ColorAttachment24 = GL_COLOR_ATTACHMENT24,
			ColorAttachment25 = GL_COLOR_ATTACHMENT25,
			ColorAttachment26 = GL_COLOR_ATTACHMENT26,
			ColorAttachment27 = GL_COLOR_ATTACHMENT27,
			ColorAttachment28 = GL_COLOR_ATTACHMENT28,
			ColorAttachment29 = GL_COLOR_ATTACHMENT29,
			ColorAttachment30 = GL_COLOR_ATTACHMENT30,
			ColorAttachment31 = GL_COLOR_ATTACHMENT31
		};
	}
	typedef DrawBufferModeEnum::Enum DrawBufferMode;

	namespace DrawElementsTypeEnum
	{
		enum Enum : GLenum
		{
			UnsignedByte = GL_UNSIGNED_BYTE,
			UnsignedShort = GL_UNSIGNED_SHORT,
			UnsignedInt = GL_UNSIGNED_INT
		};
	}
	typedef DrawElementsTypeEnum::Enum DrawElementsType;

	namespace SyncConditionEnum
	{
		enum Enum : GLenum
		{
			SyncGpuCommandsComplete = GL_SYNC_GPU_COMMANDS_COMPLETE
		};
	}
	typedef SyncConditionEnum::Enum SyncCondition;

	namespace FramebufferParameterNameEnum
	{
		enum Enum : GLenum
		{
			FramebufferDefaultWidth = GL_FRAMEBUFFER_DEFAULT_WIDTH,
			FramebufferDefaultHeight = GL_FRAMEBUFFER_DEFAULT_HEIGHT,
			FramebufferDefaultLayers = GL_FRAMEBUFFER_DEFAULT_LAYERS,
			FramebufferDefaultSamples = GL_FRAMEBUFFER_DEFAULT_SAMPLES,
			FramebufferDefaultFixedSampleLocations = GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
		};
	}
	typedef FramebufferParameterNameEnum::Enum FramebufferParameterName;

	namespace FramebufferAttachmentEnum
	{
		enum Enum : GLenum
		{
			ColorAttachment0 = GL_COLOR_ATTACHMENT0,
			ColorAttachment1 = GL_COLOR_ATTACHMENT1,
			ColorAttachment2 = GL_COLOR_ATTACHMENT2,
			ColorAttachment3 = GL_COLOR_ATTACHMENT3,
			ColorAttachment4 = GL_COLOR_ATTACHMENT4,
			ColorAttachment5 = GL_COLOR_ATTACHMENT5,
			ColorAttachment6 = GL_COLOR_ATTACHMENT6,
			ColorAttachment7 = GL_COLOR_ATTACHMENT7,
			ColorAttachment8 = GL_COLOR_ATTACHMENT8,
			ColorAttachment9 = GL_COLOR_ATTACHMENT9,
			ColorAttachment10 = GL_COLOR_ATTACHMENT10,
			ColorAttachment11 = GL_COLOR_ATTACHMENT11,
			ColorAttachment12 = GL_COLOR_ATTACHMENT12,
			ColorAttachment13 = GL_COLOR_ATTACHMENT13,
			ColorAttachment14 = GL_COLOR_ATTACHMENT14,
			ColorAttachment15 = GL_COLOR_ATTACHMENT15,
			ColorAttachment16 = GL_COLOR_ATTACHMENT16,
			ColorAttachment17 = GL_COLOR_ATTACHMENT17,
			ColorAttachment18 = GL_COLOR_ATTACHMENT18,
			ColorAttachment19 = GL_COLOR_ATTACHMENT19,
			ColorAttachment20 = GL_COLOR_ATTACHMENT20,
			ColorAttachment21 = GL_COLOR_ATTACHMENT21,
			ColorAttachment22 = GL_COLOR_ATTACHMENT22,
			ColorAttachment23 = GL_COLOR_ATTACHMENT23,
			ColorAttachment24 = GL_COLOR_ATTACHMENT24,
			ColorAttachment25 = GL_COLOR_ATTACHMENT25,
			ColorAttachment26 = GL_COLOR_ATTACHMENT26,
			ColorAttachment27 = GL_COLOR_ATTACHMENT27,
			ColorAttachment28 = GL_COLOR_ATTACHMENT28,
			ColorAttachment29 = GL_COLOR_ATTACHMENT29,
			ColorAttachment30 = GL_COLOR_ATTACHMENT30,
			ColorAttachment31 = GL_COLOR_ATTACHMENT31,
			DepthAttachment = GL_DEPTH_ATTACHMENT,
			DepthStencilAttachment = GL_DEPTH_STENCIL_ATTACHMENT,
			StencilAttachment = GL_STENCIL_ATTACHMENT
		};
	}
	typedef FramebufferAttachmentEnum::Enum FramebufferAttachment;

	namespace FrontFaceDirectionEnum
	{
		enum Enum : GLenum
		{
			Ccw = GL_CCW,
			Cw = GL_CW
		};
	}
	typedef FrontFaceDirectionEnum::Enum FrontFaceDirection;

	namespace AtomicCounterBufferPNameEnum
	{
		enum Enum : GLenum
		{
			AtomicCounterBufferBinding = GL_ATOMIC_COUNTER_BUFFER_BINDING,
			AtomicCounterBufferDataSize = GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE,
			AtomicCounterBufferActiveAtomicCounters = GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS,
			AtomicCounterBufferActiveAtomicCounterIndices = GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES,
			AtomicCounterBufferReferencedByVertexShader = GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER,
			AtomicCounterBufferReferencedByTessControlShader = GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER,
			AtomicCounterBufferReferencedByTessEvaluationShader = GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER,
			AtomicCounterBufferReferencedByGeometryShader = GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER,
			AtomicCounterBufferReferencedByFragmentShader = GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER,
			AtomicCounterBufferReferencedByComputeShader = GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER
		};
	}
	typedef AtomicCounterBufferPNameEnum::Enum AtomicCounterBufferPName;

	namespace AttributeTypeEnum
	{
		enum Enum : GLenum
		{
			Float = GL_FLOAT,
			FloatVec2 = GL_FLOAT_VEC2,
			FloatVec3 = GL_FLOAT_VEC3,
			FloatVec4 = GL_FLOAT_VEC4,
			Double = GL_DOUBLE,
			DoubleVec2 = GL_DOUBLE_VEC2,
			DoubleVec3 = GL_DOUBLE_VEC3,
			DoubleVec4 = GL_DOUBLE_VEC4,
			Int = GL_INT,
			IntVec2 = GL_INT_VEC2,
			IntVec3 = GL_INT_VEC3,
			IntVec4 = GL_INT_VEC4,
			UnsignedInt = GL_UNSIGNED_INT,
			UnsignedIntVec2 = GL_UNSIGNED_INT_VEC2,
			UnsignedIntVec3 = GL_UNSIGNED_INT_VEC3,
			UnsignedIntVec4 = GL_UNSIGNED_INT_VEC4,
			Bool = GL_BOOL,
			BoolVec2 = GL_BOOL_VEC2,
			BoolVec3 = GL_BOOL_VEC3,
			BoolVec4 = GL_BOOL_VEC4,
			FloatMat2 = GL_FLOAT_MAT2,
			FloatMat3 = GL_FLOAT_MAT3,
			FloatMat4 = GL_FLOAT_MAT4,
			FloatMat2x3 = GL_FLOAT_MAT2x3,
			FloatMat2x4 = GL_FLOAT_MAT2x4,
			FloatMat3x2 = GL_FLOAT_MAT3x2,
			FloatMat3x4 = GL_FLOAT_MAT3x4,
			FloatMat4x2 = GL_FLOAT_MAT4x2,
			FloatMat4x3 = GL_FLOAT_MAT4x3,
			DoubleMat2 = GL_DOUBLE_MAT2,
			DoubleMat3 = GL_DOUBLE_MAT3,
			DoubleMat4 = GL_DOUBLE_MAT4,
			DoubleMat2x3 = GL_DOUBLE_MAT2x3,
			DoubleMat2x4 = GL_DOUBLE_MAT2x4,
			DoubleMat3x2 = GL_DOUBLE_MAT3x2,
			DoubleMat3x4 = GL_DOUBLE_MAT3x4,
			DoubleMat4x2 = GL_DOUBLE_MAT4x2,
			DoubleMat4x3 = GL_DOUBLE_MAT4x3,
			Sampler1D = GL_SAMPLER_1D,
			Sampler2D = GL_SAMPLER_2D,
			Sampler3D = GL_SAMPLER_3D,
			SamplerCube = GL_SAMPLER_CUBE,
			Sampler1DShadow = GL_SAMPLER_1D_SHADOW,
			Sampler2DShadow = GL_SAMPLER_2D_SHADOW,
			SamplerCubeMapArray = GL_SAMPLER_CUBE_MAP_ARRAY,
			Sampler1DArrayShadow = GL_SAMPLER_1D_ARRAY_SHADOW,
			Sampler2DArrayShadow = GL_SAMPLER_2D_ARRAY_SHADOW,
			Sampler2DMultisample = GL_SAMPLER_2D_MULTISAMPLE,
			Sampler2DMultisampleArray = GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
			SamplerCubeShadow = GL_SAMPLER_CUBE_SHADOW,
			SamplerCubeMapArrayShadow = GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
			SamplerBuffer = GL_SAMPLER_BUFFER,
			Sampler2DRect = GL_SAMPLER_2D_RECT,
			Sampler2DRectShadow = GL_SAMPLER_2D_RECT_SHADOW,
			IntSampler1D = GL_INT_SAMPLER_1D,
			IntSampler2D = GL_INT_SAMPLER_2D,
			IntSampler3D = GL_INT_SAMPLER_3D,
			IntSamplerCube = GL_INT_SAMPLER_CUBE,
			IntSampler1DArray = GL_INT_SAMPLER_1D_ARRAY,
			IntSampler2DArray = GL_INT_SAMPLER_2D_ARRAY,
			IntSamplerCubeMapArray = GL_INT_SAMPLER_CUBE_MAP_ARRAY,
			IntSampler2DMultisample = GL_INT_SAMPLER_2D_MULTISAMPLE,
			IntSampler2DMultisampleArray = GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
			IntSamplerBuffer = GL_INT_SAMPLER_BUFFER,
			IntSampler2DRect = GL_INT_SAMPLER_2D_RECT,
			UnsignedIntSampler1D = GL_UNSIGNED_INT_SAMPLER_1D,
			UnsignedIntSampler2D = GL_UNSIGNED_INT_SAMPLER_2D,
			UnsignedIntSampler3D = GL_UNSIGNED_INT_SAMPLER_3D,
			UnsignedIntSamplerCube = GL_UNSIGNED_INT_SAMPLER_CUBE,
			UnsignedIntSampler1DArray = GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
			UnsignedIntSampler2DArray = GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
			UnsignedIntSamplerCubeMapArray = GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
			UnsignedIntSampler2DMultisample = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
			UnsignedIntSampler2DMultisampleArray = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
			UnsignedIntSamplerBuffer = GL_UNSIGNED_INT_SAMPLER_BUFFER,
			UnsignedIntSampler2DRect = GL_UNSIGNED_INT_SAMPLER_2D_RECT,
			Image1D = GL_IMAGE_1D,
			Image2D = GL_IMAGE_2D,
			Image3D = GL_IMAGE_3D,
			Image2DRect = GL_IMAGE_2D_RECT,
			ImageCube = GL_IMAGE_CUBE,
			ImageBuffer = GL_IMAGE_BUFFER,
			Image1DArray = GL_IMAGE_1D_ARRAY,
			Image2DArray = GL_IMAGE_2D_ARRAY,
			ImageCubeMapArray = GL_IMAGE_CUBE_MAP_ARRAY,
			Image2DMultisample = GL_IMAGE_2D_MULTISAMPLE,
			Image2DMultisampleArray = GL_IMAGE_2D_MULTISAMPLE_ARRAY,
			IntImage1D = GL_INT_IMAGE_1D,
			IntImage2D = GL_INT_IMAGE_2D,
			IntImage3D = GL_INT_IMAGE_3D,
			IntImage2DRect = GL_INT_IMAGE_2D_RECT,
			IntImageCube = GL_INT_IMAGE_CUBE,
			IntImageBuffer = GL_INT_IMAGE_BUFFER,
			IntImage1DArray = GL_INT_IMAGE_1D_ARRAY,
			IntImage2DArray = GL_INT_IMAGE_2D_ARRAY,
			IntImageCubeMapArray = GL_INT_IMAGE_CUBE_MAP_ARRAY,
			IntImage2DMultisample = GL_INT_IMAGE_2D_MULTISAMPLE,
			IntImage2DMultisampleArray = GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
			UnsignedIntImage1D = GL_UNSIGNED_INT_IMAGE_1D,
			UnsignedIntImage2D = GL_UNSIGNED_INT_IMAGE_2D,
			UnsignedIntImage3D = GL_UNSIGNED_INT_IMAGE_3D,
			UnsignedIntImage2DRect = GL_UNSIGNED_INT_IMAGE_2D_RECT,
			UnsignedIntImageCube = GL_UNSIGNED_INT_IMAGE_CUBE,
			UnsignedIntImageBuffer = GL_UNSIGNED_INT_IMAGE_BUFFER,
			UnsignedIntImage1DArray = GL_UNSIGNED_INT_IMAGE_1D_ARRAY,
			UnsignedIntImage2DArray = GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
			UnsignedIntImageCubeMapArray = GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY,
			UnsignedIntImage2DMultisample = GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,
			UnsignedIntImage2DMultisampleArray = GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
		};
	}
	typedef AttributeTypeEnum::Enum AttributeType;

	namespace SubroutineParameterNameEnum
	{
		enum Enum : GLenum
		{
			NumCompatibleSubroutines = GL_NUM_COMPATIBLE_SUBROUTINES,
			CompatibleSubroutines = GL_COMPATIBLE_SUBROUTINES,
			UniformSize = GL_UNIFORM_SIZE,
			UniformNameLength = GL_UNIFORM_NAME_LENGTH
		};
	}
	typedef SubroutineParameterNameEnum::Enum SubroutineParameterName;

	namespace UniformTypeEnum
	{
		enum Enum : GLenum
		{
			Int = GL_INT,
			UnsignedInt = GL_UNSIGNED_INT,
			Float = GL_FLOAT,
			Double = GL_DOUBLE,
			FloatVec2 = GL_FLOAT_VEC2,
			FloatVec3 = GL_FLOAT_VEC3,
			FloatVec4 = GL_FLOAT_VEC4,
			IntVec2 = GL_INT_VEC2,
			IntVec3 = GL_INT_VEC3,
			IntVec4 = GL_INT_VEC4,
			Bool = GL_BOOL,
			BoolVec2 = GL_BOOL_VEC2,
			BoolVec3 = GL_BOOL_VEC3,
			BoolVec4 = GL_BOOL_VEC4,
			FloatMat2 = GL_FLOAT_MAT2,
			FloatMat3 = GL_FLOAT_MAT3,
			FloatMat4 = GL_FLOAT_MAT4,
			Sampler1D = GL_SAMPLER_1D,
			Sampler2D = GL_SAMPLER_2D,
			Sampler3D = GL_SAMPLER_3D,
			SamplerCube = GL_SAMPLER_CUBE,
			Sampler1DShadow = GL_SAMPLER_1D_SHADOW,
			Sampler2DShadow = GL_SAMPLER_2D_SHADOW,
			Sampler2DRect = GL_SAMPLER_2D_RECT,
			Sampler2DRectShadow = GL_SAMPLER_2D_RECT_SHADOW,
			FloatMat2x3 = GL_FLOAT_MAT2x3,
			FloatMat2x4 = GL_FLOAT_MAT2x4,
			FloatMat3x2 = GL_FLOAT_MAT3x2,
			FloatMat3x4 = GL_FLOAT_MAT3x4,
			FloatMat4x2 = GL_FLOAT_MAT4x2,
			FloatMat4x3 = GL_FLOAT_MAT4x3,
			Sampler1DArray = GL_SAMPLER_1D_ARRAY,
			Sampler2DArray = GL_SAMPLER_2D_ARRAY,
			SamplerBuffer = GL_SAMPLER_BUFFER,
			Sampler1DArrayShadow = GL_SAMPLER_1D_ARRAY_SHADOW,
			Sampler2DArrayShadow = GL_SAMPLER_2D_ARRAY_SHADOW,
			SamplerCubeShadow = GL_SAMPLER_CUBE_SHADOW,
			UnsignedIntVec2 = GL_UNSIGNED_INT_VEC2,
			UnsignedIntVec3 = GL_UNSIGNED_INT_VEC3,
			UnsignedIntVec4 = GL_UNSIGNED_INT_VEC4,
			IntSampler1D = GL_INT_SAMPLER_1D,
			IntSampler2D = GL_INT_SAMPLER_2D,
			IntSampler3D = GL_INT_SAMPLER_3D,
			IntSamplerCube = GL_INT_SAMPLER_CUBE,
			IntSampler2DRect = GL_INT_SAMPLER_2D_RECT,
			IntSampler1DArray = GL_INT_SAMPLER_1D_ARRAY,
			IntSampler2DArray = GL_INT_SAMPLER_2D_ARRAY,
			IntSamplerBuffer = GL_INT_SAMPLER_BUFFER,
			UnsignedIntSampler1D = GL_UNSIGNED_INT_SAMPLER_1D,
			UnsignedIntSampler2D = GL_UNSIGNED_INT_SAMPLER_2D,
			UnsignedIntSampler3D = GL_UNSIGNED_INT_SAMPLER_3D,
			UnsignedIntSamplerCube = GL_UNSIGNED_INT_SAMPLER_CUBE,
			UnsignedIntSampler2DRect = GL_UNSIGNED_INT_SAMPLER_2D_RECT,
			UnsignedIntSampler1DArray = GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
			UnsignedIntSampler2DArray = GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
			UnsignedIntSamplerBuffer = GL_UNSIGNED_INT_SAMPLER_BUFFER,
			DoubleMat2 = GL_DOUBLE_MAT2,
			DoubleMat3 = GL_DOUBLE_MAT3,
			DoubleMat4 = GL_DOUBLE_MAT4,
			DoubleMat2x3 = GL_DOUBLE_MAT2x3,
			DoubleMat2x4 = GL_DOUBLE_MAT2x4,
			DoubleMat3x2 = GL_DOUBLE_MAT3x2,
			DoubleMat3x4 = GL_DOUBLE_MAT3x4,
			DoubleMat4x2 = GL_DOUBLE_MAT4x2,
			DoubleMat4x3 = GL_DOUBLE_MAT4x3,
			DoubleVec2 = GL_DOUBLE_VEC2,
			DoubleVec3 = GL_DOUBLE_VEC3,
			DoubleVec4 = GL_DOUBLE_VEC4,
			SamplerCubeMapArray = GL_SAMPLER_CUBE_MAP_ARRAY,
			SamplerCubeMapArrayShadow = GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
			IntSamplerCubeMapArray = GL_INT_SAMPLER_CUBE_MAP_ARRAY,
			UnsignedIntSamplerCubeMapArray = GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
			Sampler2DMultisample = GL_SAMPLER_2D_MULTISAMPLE,
			IntSampler2DMultisample = GL_INT_SAMPLER_2D_MULTISAMPLE,
			UnsignedIntSampler2DMultisample = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
			Sampler2DMultisampleArray = GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
			IntSampler2DMultisampleArray = GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
			UnsignedIntSampler2DMultisampleArray = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
		};
	}
	typedef UniformTypeEnum::Enum UniformType;

	namespace UniformBlockPNameEnum
	{
		enum Enum : GLenum
		{
			UniformBlockBinding = GL_UNIFORM_BLOCK_BINDING,
			UniformBlockDataSize = GL_UNIFORM_BLOCK_DATA_SIZE,
			UniformBlockNameLength = GL_UNIFORM_BLOCK_NAME_LENGTH,
			UniformBlockActiveUniforms = GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS,
			UniformBlockActiveUniformIndices = GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES,
			UniformBlockReferencedByVertexShader = GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER,
			UniformBlockReferencedByTessControlShader = GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER,
			UniformBlockReferencedByTessEvaluationShader = GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER,
			UniformBlockReferencedByGeometryShader = GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER,
			UniformBlockReferencedByFragmentShader = GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER,
			UniformBlockReferencedByComputeShader = GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER
		};
	}
	typedef UniformBlockPNameEnum::Enum UniformBlockPName;

	namespace UniformPNameEnum
	{
		enum Enum : GLenum
		{
			UniformType = GL_UNIFORM_TYPE,
			UniformSize = GL_UNIFORM_SIZE,
			UniformNameLength = GL_UNIFORM_NAME_LENGTH,
			UniformBlockIndex = GL_UNIFORM_BLOCK_INDEX,
			UniformOffset = GL_UNIFORM_OFFSET,
			UniformArrayStride = GL_UNIFORM_ARRAY_STRIDE,
			UniformMatrixStride = GL_UNIFORM_MATRIX_STRIDE,
			UniformIsRowMajor = GL_UNIFORM_IS_ROW_MAJOR,
			UniformAtomicCounterBufferIndex = GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX
		};
	}
	typedef UniformPNameEnum::Enum UniformPName;

	namespace GetPNameEnum
	{
		enum Enum : GLenum
		{
			ActiveTexture = GL_ACTIVE_TEXTURE,
			AliasedLineWidthRange = GL_ALIASED_LINE_WIDTH_RANGE,
			ArrayBufferBinding = GL_ARRAY_BUFFER_BINDING,
			Blend = GL_BLEND,
			BlendColor = GL_BLEND_COLOR,
			BlendDst = GL_BLEND_DST,
			BlendDstAlpha = GL_BLEND_DST_ALPHA,
			BlendDstRGB = GL_BLEND_DST_RGB,
			BlendEquationAlpha = GL_BLEND_EQUATION_ALPHA,
			BlendEquationRGB = GL_BLEND_EQUATION_RGB,
			BlendSrc = GL_BLEND_SRC,
			BlendSrcAlpha = GL_BLEND_SRC_ALPHA,
			BlendSrcRGB = GL_BLEND_SRC_RGB,
			ColorClearValue = GL_COLOR_CLEAR_VALUE,
			ColorLogicOp = GL_COLOR_LOGIC_OP,
			ColorWritemask = GL_COLOR_WRITEMASK,
			CompressedTextureFormats = GL_COMPRESSED_TEXTURE_FORMATS,
			ContextFlags = GL_CONTEXT_FLAGS,
			CullFace = GL_CULL_FACE,
			CullFaceMode = GL_CULL_FACE_MODE,
			CurrentProgram = GL_CURRENT_PROGRAM,
			DebugGroupStackDepth = GL_DEBUG_GROUP_STACK_DEPTH,
			DepthClearValue = GL_DEPTH_CLEAR_VALUE,
			DepthFunc = GL_DEPTH_FUNC,
			DepthRange = GL_DEPTH_RANGE,
			DepthTest = GL_DEPTH_TEST,
			DepthWritemask = GL_DEPTH_WRITEMASK,
			DispatchIndirectBufferBinding = GL_DISPATCH_INDIRECT_BUFFER_BINDING,
			Dither = GL_DITHER,
			Doublebuffer = GL_DOUBLEBUFFER,
			DrawBuffer = GL_DRAW_BUFFER,
			DrawFramebufferBinding = GL_DRAW_FRAMEBUFFER_BINDING,
			ElementArrayBufferBinding = GL_ELEMENT_ARRAY_BUFFER_BINDING,
			FragmentShaderDerivativeHint = GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
			FrontFace = GL_FRONT_FACE,
			ImplementationColorReadFormat = GL_IMPLEMENTATION_COLOR_READ_FORMAT,
			ImplementationColorReadType = GL_IMPLEMENTATION_COLOR_READ_TYPE,
			LayerProvokingVertex = GL_LAYER_PROVOKING_VERTEX,
			LineSmooth = GL_LINE_SMOOTH,
			LineSmoothHint = GL_LINE_SMOOTH_HINT,
			LineWidth = GL_LINE_WIDTH,
			LineWidthGranularity = GL_LINE_WIDTH_GRANULARITY,
			LineWidthRange = GL_LINE_WIDTH_RANGE,
			LogicOpMode = GL_LOGIC_OP_MODE,
			MajorVersion = GL_MAJOR_VERSION,
			Max3DTextureSize = GL_MAX_3D_TEXTURE_SIZE,
			MaxArrayTextureLayers = GL_MAX_ARRAY_TEXTURE_LAYERS,
			MaxClipDistances = GL_MAX_CLIP_DISTANCES,
			MaxColorTextureSamples = GL_MAX_COLOR_TEXTURE_SAMPLES,
			MaxCombinedAtomicCounters = GL_MAX_COMBINED_ATOMIC_COUNTERS,
			MaxCombinedComputeUniformComponents = GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS,
			MaxCombinedFragmentUniformComponents = GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,
			MaxCombinedGeometryUniformComponents = GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS,
			MaxCombinedShaderStorageBlocks = GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS,
			MaxCombinedTextureImageUnits = GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
			MaxCombinedUniformBlocks = GL_MAX_COMBINED_UNIFORM_BLOCKS,
			MaxCombinedVertexUniformComponents = GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,
			MaxComputeAtomicCounters = GL_MAX_COMPUTE_ATOMIC_COUNTERS,
			MaxComputeAtomicCounterBuffers = GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS,
			MaxComputeShaderStorageBlocks = GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS,
			MaxComputeTextureImageUnits = GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS,
			MaxComputeUniformBlocks = GL_MAX_COMPUTE_UNIFORM_BLOCKS,
			MaxComputeUniformComponents = GL_MAX_COMPUTE_UNIFORM_COMPONENTS,
			MaxComputeWorkGroupCount = GL_MAX_COMPUTE_WORK_GROUP_COUNT,
			MaxComputeWorkGroupInvocations = GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,
			MaxComputeWorkGroupSize = GL_MAX_COMPUTE_WORK_GROUP_SIZE,
			MaxCubeMapTextureSize = GL_MAX_CUBE_MAP_TEXTURE_SIZE,
			MaxDebugGroupStackDepth = GL_MAX_DEBUG_GROUP_STACK_DEPTH,
			MaxDepthTextureSamples = GL_MAX_DEPTH_TEXTURE_SAMPLES,
			MaxDrawBuffers = GL_MAX_DRAW_BUFFERS,
			MaxDualSourceDrawBuffers = GL_MAX_DUAL_SOURCE_DRAW_BUFFERS,
			MaxElementsIndices = GL_MAX_ELEMENTS_INDICES,
			MaxElementsVertices = GL_MAX_ELEMENTS_VERTICES,
			MaxElementIndex = GL_MAX_ELEMENT_INDEX,
			MaxFragmentAtomicCounters = GL_MAX_FRAGMENT_ATOMIC_COUNTERS,
			MaxFragmentInputComponents = GL_MAX_FRAGMENT_INPUT_COMPONENTS,
			MaxFragmentShaderStorageBlocks = GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS,
			MaxFragmentUniformBlocks = GL_MAX_FRAGMENT_UNIFORM_BLOCKS,
			MaxFragmentUniformComponents = GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
			MaxFragmentUniformVectors = GL_MAX_FRAGMENT_UNIFORM_VECTORS,
			MaxFramebufferHeight = GL_MAX_FRAMEBUFFER_HEIGHT,
			MaxFramebufferLayers = GL_MAX_FRAMEBUFFER_LAYERS,
			MaxFramebufferSamples = GL_MAX_FRAMEBUFFER_SAMPLES,
			MaxFramebufferWidth = GL_MAX_FRAMEBUFFER_WIDTH,
			MaxGeometryAtomicCounters = GL_MAX_GEOMETRY_ATOMIC_COUNTERS,
			MaxGeometryInputComponents = GL_MAX_GEOMETRY_INPUT_COMPONENTS,
			MaxGeometryOutputComponents = GL_MAX_GEOMETRY_OUTPUT_COMPONENTS,
			MaxGeometryShaderStorageBlocks = GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS,
			MaxGeometryTextureImageUnits = GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS,
			MaxGeometryUniformBlocks = GL_MAX_GEOMETRY_UNIFORM_BLOCKS,
			MaxGeometryUniformComponents = GL_MAX_GEOMETRY_UNIFORM_COMPONENTS,
			MaxIntegerSamples = GL_MAX_INTEGER_SAMPLES,
			MaxLabelLength = GL_MAX_LABEL_LENGTH,
			MaxProgramTexelOffset = GL_MAX_PROGRAM_TEXEL_OFFSET,
			MaxRectangleTextureSize = GL_MAX_RECTANGLE_TEXTURE_SIZE,
			MaxRenderbufferSize = GL_MAX_RENDERBUFFER_SIZE,
			MaxSampleMaskWords = GL_MAX_SAMPLE_MASK_WORDS,
			MaxServerWaitTimeout = GL_MAX_SERVER_WAIT_TIMEOUT,
			MaxShaderStorageBufferBindings = GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS,
			MaxTessControlAtomicCounters = GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS,
			MaxTessControlShaderStorageBlocks = GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS,
			MaxTessEvaluationAtomicCounters = GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS,
			MaxTessEvaluationShaderStorageBlocks = GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS,
			MaxTextureBufferSize = GL_MAX_TEXTURE_BUFFER_SIZE,
			MaxTextureImageUnits = GL_MAX_TEXTURE_IMAGE_UNITS,
			MaxTextureLodBias = GL_MAX_TEXTURE_LOD_BIAS,
			MaxTextureSize = GL_MAX_TEXTURE_SIZE,
			MaxUniformBlockSize = GL_MAX_UNIFORM_BLOCK_SIZE,
			MaxUniformBufferBindings = GL_MAX_UNIFORM_BUFFER_BINDINGS,
			MaxUniformLocations = GL_MAX_UNIFORM_LOCATIONS,
			MaxVaryingComponents = GL_MAX_VARYING_COMPONENTS,
			MaxVaryingFloats = GL_MAX_VARYING_FLOATS,
			MaxVaryingVectors = GL_MAX_VARYING_VECTORS,
			MaxVertexAtomicCounters = GL_MAX_VERTEX_ATOMIC_COUNTERS,
			MaxVertexAttribs = GL_MAX_VERTEX_ATTRIBS,
			MaxVertexAttribBindings = GL_MAX_VERTEX_ATTRIB_BINDINGS,
			MaxVertexAttribRelativeOffset = GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET,
			MaxVertexOutputComponents = GL_MAX_VERTEX_OUTPUT_COMPONENTS,
			MaxVertexShaderStorageBlocks = GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS,
			MaxVertexTextureImageUnits = GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
			MaxVertexUniformBlocks = GL_MAX_VERTEX_UNIFORM_BLOCKS,
			MaxVertexUniformComponents = GL_MAX_VERTEX_UNIFORM_COMPONENTS,
			MaxVertexUniformVectors = GL_MAX_VERTEX_UNIFORM_VECTORS,
			MaxViewports = GL_MAX_VIEWPORTS,
			MaxViewportDims = GL_MAX_VIEWPORT_DIMS,
			MinorVersion = GL_MINOR_VERSION,
			MinMapBufferAlignment = GL_MIN_MAP_BUFFER_ALIGNMENT,
			MinProgramTexelOffset = GL_MIN_PROGRAM_TEXEL_OFFSET,
			NumCompressedTextureFormats = GL_NUM_COMPRESSED_TEXTURE_FORMATS,
			NumExtensions = GL_NUM_EXTENSIONS,
			NumProgramBinaryFormats = GL_NUM_PROGRAM_BINARY_FORMATS,
			NumShaderBinaryFormats = GL_NUM_SHADER_BINARY_FORMATS,
			PackAlignment = GL_PACK_ALIGNMENT,
			PackImageHeight = GL_PACK_IMAGE_HEIGHT,
			PackLsbFirst = GL_PACK_LSB_FIRST,
			PackRowLength = GL_PACK_ROW_LENGTH,
			PackSkipImages = GL_PACK_SKIP_IMAGES,
			PackSkipPixels = GL_PACK_SKIP_PIXELS,
			PackSkipRows = GL_PACK_SKIP_ROWS,
			PackSwapBytes = GL_PACK_SWAP_BYTES,
			PixelPackBufferBinding = GL_PIXEL_PACK_BUFFER_BINDING,
			PixelUnpackBufferBinding = GL_PIXEL_UNPACK_BUFFER_BINDING,
			PointFadeThresholdSize = GL_POINT_FADE_THRESHOLD_SIZE,
			PointSize = GL_POINT_SIZE,
			PointSizeGranularity = GL_POINT_SIZE_GRANULARITY,
			PointSizeRange = GL_POINT_SIZE_RANGE,
			PolygonMode = GL_POLYGON_MODE,
			PolygonOffsetFactor = GL_POLYGON_OFFSET_FACTOR,
			PolygonOffsetFill = GL_POLYGON_OFFSET_FILL,
			PolygonOffsetLine = GL_POLYGON_OFFSET_LINE,
			PolygonOffsetPoint = GL_POLYGON_OFFSET_POINT,
			PolygonOffsetUnits = GL_POLYGON_OFFSET_UNITS,
			PolygonSmooth = GL_POLYGON_SMOOTH,
			PolygonSmoothHint = GL_POLYGON_SMOOTH_HINT,
			PrimitiveRestartIndex = GL_PRIMITIVE_RESTART_INDEX,
			ProgramBinaryFormats = GL_PROGRAM_BINARY_FORMATS,
			ProgramPipelineBinding = GL_PROGRAM_PIPELINE_BINDING,
			ProgramPointSize = GL_PROGRAM_POINT_SIZE,
			ProvokingVertex = GL_PROVOKING_VERTEX,
			ReadBuffer = GL_READ_BUFFER,
			ReadFramebufferBinding = GL_READ_FRAMEBUFFER_BINDING,
			RenderbufferBinding = GL_RENDERBUFFER_BINDING,
			SamplerBinding = GL_SAMPLER_BINDING,
			Samples = GL_SAMPLES,
			SampleBuffers = GL_SAMPLE_BUFFERS,
			SampleCoverageInvert = GL_SAMPLE_COVERAGE_INVERT,
			SampleCoverageValue = GL_SAMPLE_COVERAGE_VALUE,
			ScissorBox = GL_SCISSOR_BOX,
			ScissorTest = GL_SCISSOR_TEST,
			ShaderCompiler = GL_SHADER_COMPILER,
			ShaderStorageBufferBinding = GL_SHADER_STORAGE_BUFFER_BINDING,
			ShaderStorageBufferOffsetAlignment = GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT,
			ShaderStorageBufferSize = GL_SHADER_STORAGE_BUFFER_SIZE,
			ShaderStorageBufferStart = GL_SHADER_STORAGE_BUFFER_START,
			SmoothLineWidthGranularity = GL_SMOOTH_LINE_WIDTH_GRANULARITY,
			SmoothLineWidthRange = GL_SMOOTH_LINE_WIDTH_RANGE,
			SmoothPointSizeGranularity = GL_SMOOTH_POINT_SIZE_GRANULARITY,
			SmoothPointSizeRange = GL_SMOOTH_POINT_SIZE_RANGE,
			StencilBackFail = GL_STENCIL_BACK_FAIL,
			StencilBackFunc = GL_STENCIL_BACK_FUNC,
			StencilBackPassDepthFail = GL_STENCIL_BACK_PASS_DEPTH_FAIL,
			StencilBackPassDepthPass = GL_STENCIL_BACK_PASS_DEPTH_PASS,
			StencilBackRef = GL_STENCIL_BACK_REF,
			StencilBackValueMask = GL_STENCIL_BACK_VALUE_MASK,
			StencilBackWritemask = GL_STENCIL_BACK_WRITEMASK,
			StencilClearValue = GL_STENCIL_CLEAR_VALUE,
			StencilFail = GL_STENCIL_FAIL,
			StencilFunc = GL_STENCIL_FUNC,
			StencilPassDepthFail = GL_STENCIL_PASS_DEPTH_FAIL,
			StencilPassDepthPass = GL_STENCIL_PASS_DEPTH_PASS,
			StencilRef = GL_STENCIL_REF,
			StencilTest = GL_STENCIL_TEST,
			StencilValueMask = GL_STENCIL_VALUE_MASK,
			StencilWritemask = GL_STENCIL_WRITEMASK,
			Stereo = GL_STEREO,
			SubpixelBits = GL_SUBPIXEL_BITS,
			Texture1D = GL_TEXTURE_1D,
			Texture2D = GL_TEXTURE_2D,
			TextureBinding1D = GL_TEXTURE_BINDING_1D,
			TextureBinding1DArray = GL_TEXTURE_BINDING_1D_ARRAY,
			TextureBinding2D = GL_TEXTURE_BINDING_2D,
			TextureBinding2DArray = GL_TEXTURE_BINDING_2D_ARRAY,
			TextureBinding2DMultisample = GL_TEXTURE_BINDING_2D_MULTISAMPLE,
			TextureBinding2DMultisampleArray = GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY,
			TextureBinding3D = GL_TEXTURE_BINDING_3D,
			TextureBindingBuffer = GL_TEXTURE_BINDING_BUFFER,
			TextureBindingCubeMap = GL_TEXTURE_BINDING_CUBE_MAP,
			TextureBindingRectangle = GL_TEXTURE_BINDING_RECTANGLE,
			TextureBufferOffsetAlignment = GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT,
			TextureCompressionHint = GL_TEXTURE_COMPRESSION_HINT,
			Timestamp = GL_TIMESTAMP,
			TransformFeedbackBufferBinding = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
			TransformFeedbackBufferSize = GL_TRANSFORM_FEEDBACK_BUFFER_SIZE,
			TransformFeedbackBufferStart = GL_TRANSFORM_FEEDBACK_BUFFER_START,
			UniformBufferBinding = GL_UNIFORM_BUFFER_BINDING,
			UniformBufferOffsetAlignment = GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT,
			UniformBufferSize = GL_UNIFORM_BUFFER_SIZE,
			UniformBufferStart = GL_UNIFORM_BUFFER_START,
			UnpackAlignment = GL_UNPACK_ALIGNMENT,
			UnpackImageHeight = GL_UNPACK_IMAGE_HEIGHT,
			UnpackLsbFirst = GL_UNPACK_LSB_FIRST,
			UnpackRowLength = GL_UNPACK_ROW_LENGTH,
			UnpackSkipImages = GL_UNPACK_SKIP_IMAGES,
			UnpackSkipPixels = GL_UNPACK_SKIP_PIXELS,
			UnpackSkipRows = GL_UNPACK_SKIP_ROWS,
			UnpackSwapBytes = GL_UNPACK_SWAP_BYTES,
			VertexArray = GL_VERTEX_ARRAY,
			VertexArrayBinding = GL_VERTEX_ARRAY_BINDING,
			VertexBindingDivisor = GL_VERTEX_BINDING_DIVISOR,
			VertexBindingOffset = GL_VERTEX_BINDING_OFFSET,
			VertexBindingStride = GL_VERTEX_BINDING_STRIDE,
			Viewport = GL_VIEWPORT,
			ViewportBoundsRange = GL_VIEWPORT_BOUNDS_RANGE,
			ViewportIndexProvokingVertex = GL_VIEWPORT_INDEX_PROVOKING_VERTEX,
			ViewportSubpixelBits = GL_VIEWPORT_SUBPIXEL_BITS
		};
	}
	typedef GetPNameEnum::Enum GetPName;

	namespace BufferPNameARBEnum
	{
		enum Enum : GLenum
		{
			BufferSize = GL_BUFFER_SIZE,
			BufferUsage = GL_BUFFER_USAGE,
			BufferAccess = GL_BUFFER_ACCESS,
			BufferAccessFlags = GL_BUFFER_ACCESS_FLAGS,
			BufferImmutableStorage = GL_BUFFER_IMMUTABLE_STORAGE,
			BufferMapped = GL_BUFFER_MAPPED,
			BufferMapOffset = GL_BUFFER_MAP_OFFSET,
			BufferMapLength = GL_BUFFER_MAP_LENGTH,
			BufferStorageFlags = GL_BUFFER_STORAGE_FLAGS
		};
	}
	typedef BufferPNameARBEnum::Enum BufferPNameARB;

	namespace BufferPointerNameARBEnum
	{
		enum Enum : GLenum
		{
			BufferMapPointer = GL_BUFFER_MAP_POINTER
		};
	}
	typedef BufferPointerNameARBEnum::Enum BufferPointerNameARB;

	namespace ErrorCodeEnum
	{
		enum Enum : GLenum
		{
			InvalidEnum = GL_INVALID_ENUM,
			InvalidFramebufferOperation = GL_INVALID_FRAMEBUFFER_OPERATION,
			InvalidOperation = GL_INVALID_OPERATION,
			InvalidValue = GL_INVALID_VALUE,
			NoError = GL_NO_ERROR,
			OutOfMemory = GL_OUT_OF_MEMORY,
			StackOverflow = GL_STACK_OVERFLOW,
			StackUnderflow = GL_STACK_UNDERFLOW
		};
	}
	typedef ErrorCodeEnum::Enum ErrorCode;

	namespace FramebufferAttachmentParameterNameEnum
	{
		enum Enum : GLenum
		{
			FramebufferAttachmentRedSize = GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE,
			FramebufferAttachmentGreenSize = GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE,
			FramebufferAttachmentBlueSize = GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE,
			FramebufferAttachmentAlphaSize = GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE,
			FramebufferAttachmentDepthSize = GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE,
			FramebufferAttachmentStencilSize = GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE,
			FramebufferAttachmentComponentType = GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE,
			FramebufferAttachmentColorEncoding = GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING,
			FramebufferAttachmentObjectName = GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME,
			FramebufferAttachmentObjectType = GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE,
			FramebufferAttachmentTextureLevel = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL,
			FramebufferAttachmentTextureCubeMapFace = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE,
			FramebufferAttachmentTextureLayer = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER,
			FramebufferAttachmentLayered = GL_FRAMEBUFFER_ATTACHMENT_LAYERED
		};
	}
	typedef FramebufferAttachmentParameterNameEnum::Enum FramebufferAttachmentParameterName;

	namespace GraphicsResetStatusEnum
	{
		enum Enum : GLenum
		{
			NoError = GL_NO_ERROR,
			GuiltyContextReset = GL_GUILTY_CONTEXT_RESET,
			InnocentContextReset = GL_INNOCENT_CONTEXT_RESET,
			UnknownContextReset = GL_UNKNOWN_CONTEXT_RESET
		};
	}
	typedef GraphicsResetStatusEnum::Enum GraphicsResetStatus;

	namespace InternalFormatPNameEnum
	{
		enum Enum : GLenum
		{
			NumSampleCounts = GL_NUM_SAMPLE_COUNTS,
			Samples = GL_SAMPLES,
			InternalformatSupported = GL_INTERNALFORMAT_SUPPORTED,
			InternalformatPreferred = GL_INTERNALFORMAT_PREFERRED,
			InternalformatRedSize = GL_INTERNALFORMAT_RED_SIZE,
			InternalformatGreenSize = GL_INTERNALFORMAT_GREEN_SIZE,
			InternalformatBlueSize = GL_INTERNALFORMAT_BLUE_SIZE,
			InternalformatAlphaSize = GL_INTERNALFORMAT_ALPHA_SIZE,
			InternalformatDepthSize = GL_INTERNALFORMAT_DEPTH_SIZE,
			InternalformatStencilSize = GL_INTERNALFORMAT_STENCIL_SIZE,
			InternalformatSharedSize = GL_INTERNALFORMAT_SHARED_SIZE,
			InternalformatRedType = GL_INTERNALFORMAT_RED_TYPE,
			InternalformatGreenType = GL_INTERNALFORMAT_GREEN_TYPE,
			InternalformatBlueType = GL_INTERNALFORMAT_BLUE_TYPE,
			InternalformatAlphaType = GL_INTERNALFORMAT_ALPHA_TYPE,
			InternalformatDepthType = GL_INTERNALFORMAT_DEPTH_TYPE,
			InternalformatStencilType = GL_INTERNALFORMAT_STENCIL_TYPE,
			MaxWidth = GL_MAX_WIDTH,
			MaxHeight = GL_MAX_HEIGHT,
			MaxDepth = GL_MAX_DEPTH,
			MaxLayers = GL_MAX_LAYERS,
			ColorComponents = GL_COLOR_COMPONENTS,
			ColorRenderable = GL_COLOR_RENDERABLE,
			DepthRenderable = GL_DEPTH_RENDERABLE,
			StencilRenderable = GL_STENCIL_RENDERABLE,
			FramebufferRenderable = GL_FRAMEBUFFER_RENDERABLE,
			FramebufferRenderableLayered = GL_FRAMEBUFFER_RENDERABLE_LAYERED,
			FramebufferBlend = GL_FRAMEBUFFER_BLEND,
			ReadPixels = GL_READ_PIXELS,
			ReadPixelsFormat = GL_READ_PIXELS_FORMAT,
			ReadPixelsType = GL_READ_PIXELS_TYPE,
			TextureImageFormat = GL_TEXTURE_IMAGE_FORMAT,
			TextureImageType = GL_TEXTURE_IMAGE_TYPE,
			GetTextureImageFormat = GL_GET_TEXTURE_IMAGE_FORMAT,
			GetTextureImageType = GL_GET_TEXTURE_IMAGE_TYPE,
			Mipmap = GL_MIPMAP,
			AutoGenerateMipmap = GL_AUTO_GENERATE_MIPMAP,
			ColorEncoding = GL_COLOR_ENCODING,
			SRGBRead = GL_SRGB_READ,
			SRGBWrite = GL_SRGB_WRITE,
			Filter = GL_FILTER,
			VertexTexture = GL_VERTEX_TEXTURE,
			TessControlTexture = GL_TESS_CONTROL_TEXTURE,
			TessEvaluationTexture = GL_TESS_EVALUATION_TEXTURE,
			GeometryTexture = GL_GEOMETRY_TEXTURE,
			FragmentTexture = GL_FRAGMENT_TEXTURE,
			ComputeTexture = GL_COMPUTE_TEXTURE,
			TextureShadow = GL_TEXTURE_SHADOW,
			TextureGather = GL_TEXTURE_GATHER,
			TextureGatherShadow = GL_TEXTURE_GATHER_SHADOW,
			ShaderImageLoad = GL_SHADER_IMAGE_LOAD,
			ShaderImageStore = GL_SHADER_IMAGE_STORE,
			ShaderImageAtomic = GL_SHADER_IMAGE_ATOMIC,
			ImageTexelSize = GL_IMAGE_TEXEL_SIZE,
			ImageCompatibilityClass = GL_IMAGE_COMPATIBILITY_CLASS,
			ImagePixelFormat = GL_IMAGE_PIXEL_FORMAT,
			ImagePixelType = GL_IMAGE_PIXEL_TYPE,
			ImageFormatCompatibilityType = GL_IMAGE_FORMAT_COMPATIBILITY_TYPE,
			SimultaneousTextureAndDepthTest = GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST,
			SimultaneousTextureAndStencilTest = GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST,
			SimultaneousTextureAndDepthWrite = GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE,
			SimultaneousTextureAndStencilWrite = GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE,
			TextureCompressed = GL_TEXTURE_COMPRESSED,
			TextureCompressedBlockWidth = GL_TEXTURE_COMPRESSED_BLOCK_WIDTH,
			TextureCompressedBlockHeight = GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT,
			TextureCompressedBlockSize = GL_TEXTURE_COMPRESSED_BLOCK_SIZE,
			ClearBuffer = GL_CLEAR_BUFFER,
			TextureView = GL_TEXTURE_VIEW,
			ViewCompatibilityClass = GL_VIEW_COMPATIBILITY_CLASS,
			ClearTexture = GL_CLEAR_TEXTURE
		};
	}
	typedef InternalFormatPNameEnum::Enum InternalFormatPName;

	namespace GetMultisamplePNameNVEnum
	{
		enum Enum : GLenum
		{
			SamplePosition = GL_SAMPLE_POSITION
		};
	}
	typedef GetMultisamplePNameNVEnum::Enum GetMultisamplePNameNV;

	namespace VertexBufferObjectParameterEnum
	{
		enum Enum : GLenum
		{
			BufferAccess = GL_BUFFER_ACCESS,
			BufferAccessFlags = GL_BUFFER_ACCESS_FLAGS,
			BufferImmutableStorage = GL_BUFFER_IMMUTABLE_STORAGE,
			BufferMapped = GL_BUFFER_MAPPED,
			BufferMapLength = GL_BUFFER_MAP_LENGTH,
			BufferMapOffset = GL_BUFFER_MAP_OFFSET,
			BufferSize = GL_BUFFER_SIZE,
			BufferStorageFlags = GL_BUFFER_STORAGE_FLAGS,
			BufferUsage = GL_BUFFER_USAGE
		};
	}
	typedef VertexBufferObjectParameterEnum::Enum VertexBufferObjectParameter;

	namespace GetFramebufferParameterEnum
	{
		enum Enum : GLenum
		{
			FramebufferDefaultWidth = GL_FRAMEBUFFER_DEFAULT_WIDTH,
			FramebufferDefaultHeight = GL_FRAMEBUFFER_DEFAULT_HEIGHT,
			FramebufferDefaultLayers = GL_FRAMEBUFFER_DEFAULT_LAYERS,
			FramebufferDefaultSamples = GL_FRAMEBUFFER_DEFAULT_SAMPLES,
			FramebufferDefaultFixedSampleLocations = GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS,
			Doublebuffer = GL_DOUBLEBUFFER,
			ImplementationColorReadFormat = GL_IMPLEMENTATION_COLOR_READ_FORMAT,
			ImplementationColorReadType = GL_IMPLEMENTATION_COLOR_READ_TYPE,
			Samples = GL_SAMPLES,
			SampleBuffers = GL_SAMPLE_BUFFERS,
			Stereo = GL_STEREO
		};
	}
	typedef GetFramebufferParameterEnum::Enum GetFramebufferParameter;

	namespace RenderbufferParameterNameEnum
	{
		enum Enum : GLenum
		{
			RenderbufferWidth = GL_RENDERBUFFER_WIDTH,
			RenderbufferHeight = GL_RENDERBUFFER_HEIGHT,
			RenderbufferInternalFormat = GL_RENDERBUFFER_INTERNAL_FORMAT,
			RenderbufferSamples = GL_RENDERBUFFER_SAMPLES,
			RenderbufferRedSize = GL_RENDERBUFFER_RED_SIZE,
			RenderbufferGreenSize = GL_RENDERBUFFER_GREEN_SIZE,
			RenderbufferBlueSize = GL_RENDERBUFFER_BLUE_SIZE,
			RenderbufferAlphaSize = GL_RENDERBUFFER_ALPHA_SIZE,
			RenderbufferDepthSize = GL_RENDERBUFFER_DEPTH_SIZE,
			RenderbufferStencilSize = GL_RENDERBUFFER_STENCIL_SIZE
		};
	}
	typedef RenderbufferParameterNameEnum::Enum RenderbufferParameterName;

	namespace ObjectIdentifierEnum
	{
		enum Enum : GLenum
		{
			Buffer = GL_BUFFER,
			Shader = GL_SHADER,
			Program = GL_PROGRAM,
			VertexArray = GL_VERTEX_ARRAY,
			Query = GL_QUERY,
			ProgramPipeline = GL_PROGRAM_PIPELINE,
			TransformFeedback = GL_TRANSFORM_FEEDBACK,
			Sampler = GL_SAMPLER,
			Texture = GL_TEXTURE,
			Renderbuffer = GL_RENDERBUFFER,
			Framebuffer = GL_FRAMEBUFFER
		};
	}
	typedef ObjectIdentifierEnum::Enum ObjectIdentifier;

	namespace GetPointervPNameEnum
	{
		enum Enum : GLenum
		{
			DebugCallbackFunction = GL_DEBUG_CALLBACK_FUNCTION,
			DebugCallbackUserParam = GL_DEBUG_CALLBACK_USER_PARAM
		};
	}
	typedef GetPointervPNameEnum::Enum GetPointervPName;

	namespace ProgramInterfaceEnum
	{
		enum Enum : GLenum
		{
			Uniform = GL_UNIFORM,
			UniformBlock = GL_UNIFORM_BLOCK,
			ProgramInput = GL_PROGRAM_INPUT,
			ProgramOutput = GL_PROGRAM_OUTPUT,
			VertexSubroutine = GL_VERTEX_SUBROUTINE,
			TessControlSubroutine = GL_TESS_CONTROL_SUBROUTINE,
			TessEvaluationSubroutine = GL_TESS_EVALUATION_SUBROUTINE,
			GeometrySubroutine = GL_GEOMETRY_SUBROUTINE,
			FragmentSubroutine = GL_FRAGMENT_SUBROUTINE,
			ComputeSubroutine = GL_COMPUTE_SUBROUTINE,
			VertexSubroutineUniform = GL_VERTEX_SUBROUTINE_UNIFORM,
			TessControlSubroutineUniform = GL_TESS_CONTROL_SUBROUTINE_UNIFORM,
			TessEvaluationSubroutineUniform = GL_TESS_EVALUATION_SUBROUTINE_UNIFORM,
			GeometrySubroutineUniform = GL_GEOMETRY_SUBROUTINE_UNIFORM,
			FragmentSubroutineUniform = GL_FRAGMENT_SUBROUTINE_UNIFORM,
			ComputeSubroutineUniform = GL_COMPUTE_SUBROUTINE_UNIFORM,
			TransformFeedbackVarying = GL_TRANSFORM_FEEDBACK_VARYING,
			TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
			BufferVariable = GL_BUFFER_VARIABLE,
			ShaderStorageBlock = GL_SHADER_STORAGE_BLOCK
		};
	}
	typedef ProgramInterfaceEnum::Enum ProgramInterface;

	namespace ProgramInterfacePNameEnum
	{
		enum Enum : GLenum
		{
			ActiveResources = GL_ACTIVE_RESOURCES,
			MaxNameLength = GL_MAX_NAME_LENGTH,
			MaxNumActiveVariables = GL_MAX_NUM_ACTIVE_VARIABLES,
			MaxNumCompatibleSubroutines = GL_MAX_NUM_COMPATIBLE_SUBROUTINES
		};
	}
	typedef ProgramInterfacePNameEnum::Enum ProgramInterfacePName;

	namespace PipelineParameterNameEnum
	{
		enum Enum : GLenum
		{
			ActiveProgram = GL_ACTIVE_PROGRAM,
			VertexShader = GL_VERTEX_SHADER,
			TessControlShader = GL_TESS_CONTROL_SHADER,
			TessEvaluationShader = GL_TESS_EVALUATION_SHADER,
			GeometryShader = GL_GEOMETRY_SHADER,
			FragmentShader = GL_FRAGMENT_SHADER,
			InfoLogLength = GL_INFO_LOG_LENGTH
		};
	}
	typedef PipelineParameterNameEnum::Enum PipelineParameterName;

	namespace ProgramResourcePropertyEnum
	{
		enum Enum : GLenum
		{
			ActiveVariables = GL_ACTIVE_VARIABLES,
			BufferBinding = GL_BUFFER_BINDING,
			NumActiveVariables = GL_NUM_ACTIVE_VARIABLES,
			ArraySize = GL_ARRAY_SIZE,
			ArrayStride = GL_ARRAY_STRIDE,
			BlockIndex = GL_BLOCK_INDEX,
			IsRowMajor = GL_IS_ROW_MAJOR,
			MatrixStride = GL_MATRIX_STRIDE,
			AtomicCounterBufferIndex = GL_ATOMIC_COUNTER_BUFFER_INDEX,
			BufferDataSize = GL_BUFFER_DATA_SIZE,
			NumCompatibleSubroutines = GL_NUM_COMPATIBLE_SUBROUTINES,
			CompatibleSubroutines = GL_COMPATIBLE_SUBROUTINES,
			IsPerPatch = GL_IS_PER_PATCH,
			Location = GL_LOCATION,
			Uniform = GL_UNIFORM,
			LocationComponent = GL_LOCATION_COMPONENT,
			LocationIndex = GL_LOCATION_INDEX,
			NameLength = GL_NAME_LENGTH,
			Offset = GL_OFFSET,
			ReferencedByVertexShader = GL_REFERENCED_BY_VERTEX_SHADER,
			ReferencedByTessControlShader = GL_REFERENCED_BY_TESS_CONTROL_SHADER,
			ReferencedByTessEvaluationShader = GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
			ReferencedByGeometryShader = GL_REFERENCED_BY_GEOMETRY_SHADER,
			ReferencedByFragmentShader = GL_REFERENCED_BY_FRAGMENT_SHADER,
			ReferencedByComputeShader = GL_REFERENCED_BY_COMPUTE_SHADER,
			TransformFeedbackBufferIndex = GL_TRANSFORM_FEEDBACK_BUFFER_INDEX,
			TransformFeedbackBufferStride = GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE,
			TopLevelArraySize = GL_TOP_LEVEL_ARRAY_SIZE,
			TopLevelArrayStride = GL_TOP_LEVEL_ARRAY_STRIDE,
			Type = GL_TYPE
		};
	}
	typedef ProgramResourcePropertyEnum::Enum ProgramResourceProperty;

	namespace ProgramStagePNameEnum
	{
		enum Enum : GLenum
		{
			ActiveSubroutineUniforms = GL_ACTIVE_SUBROUTINE_UNIFORMS,
			ActiveSubroutineUniformLocations = GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS,
			ActiveSubroutines = GL_ACTIVE_SUBROUTINES,
			ActiveSubroutineUniformMaxLength = GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH,
			ActiveSubroutineMaxLength = GL_ACTIVE_SUBROUTINE_MAX_LENGTH
		};
	}
	typedef ProgramStagePNameEnum::Enum ProgramStagePName;

	namespace ProgramPropertyARBEnum
	{
		enum Enum : GLenum
		{
			DeleteStatus = GL_DELETE_STATUS,
			LinkStatus = GL_LINK_STATUS,
			ValidateStatus = GL_VALIDATE_STATUS,
			InfoLogLength = GL_INFO_LOG_LENGTH,
			AttachedShaders = GL_ATTACHED_SHADERS,
			ActiveAtomicCounterBuffers = GL_ACTIVE_ATOMIC_COUNTER_BUFFERS,
			ActiveAttributes = GL_ACTIVE_ATTRIBUTES,
			ActiveAttributeMaxLength = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
			ActiveUniforms = GL_ACTIVE_UNIFORMS,
			ActiveUniformBlocks = GL_ACTIVE_UNIFORM_BLOCKS,
			ActiveUniformBlockMaxNameLength = GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH,
			ActiveUniformMaxLength = GL_ACTIVE_UNIFORM_MAX_LENGTH,
			ComputeWorkGroupSize = GL_COMPUTE_WORK_GROUP_SIZE,
			ProgramBinaryLength = GL_PROGRAM_BINARY_LENGTH,
			TransformFeedbackBufferMode = GL_TRANSFORM_FEEDBACK_BUFFER_MODE,
			TransformFeedbackVaryings = GL_TRANSFORM_FEEDBACK_VARYINGS,
			TransformFeedbackVaryingMaxLength = GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH,
			GeometryVerticesOut = GL_GEOMETRY_VERTICES_OUT,
			GeometryInputType = GL_GEOMETRY_INPUT_TYPE,
			GeometryOutputType = GL_GEOMETRY_OUTPUT_TYPE
		};
	}
	typedef ProgramPropertyARBEnum::Enum ProgramPropertyARB;

	namespace QueryObjectParameterNameEnum
	{
		enum Enum : GLenum
		{
			QueryResultAvailable = GL_QUERY_RESULT_AVAILABLE,
			QueryResult = GL_QUERY_RESULT,
			QueryResultNoWait = GL_QUERY_RESULT_NO_WAIT,
			QueryTarget = GL_QUERY_TARGET
		};
	}
	typedef QueryObjectParameterNameEnum::Enum QueryObjectParameterName;

	namespace QueryParameterNameEnum
	{
		enum Enum : GLenum
		{
			CurrentQuery = GL_CURRENT_QUERY,
			QueryCounterBits = GL_QUERY_COUNTER_BITS
		};
	}
	typedef QueryParameterNameEnum::Enum QueryParameterName;

	namespace SamplerParameterIEnum
	{
		enum Enum : GLenum
		{
			TextureWrapS = GL_TEXTURE_WRAP_S,
			TextureWrapT = GL_TEXTURE_WRAP_T,
			TextureWrapR = GL_TEXTURE_WRAP_R,
			TextureMinFilter = GL_TEXTURE_MIN_FILTER,
			TextureMagFilter = GL_TEXTURE_MAG_FILTER,
			TextureCompareMode = GL_TEXTURE_COMPARE_MODE,
			TextureCompareFunc = GL_TEXTURE_COMPARE_FUNC
		};
	}
	typedef SamplerParameterIEnum::Enum SamplerParameterI;

	namespace SamplerParameterFEnum
	{
		enum Enum : GLenum
		{
			TextureBorderColor = GL_TEXTURE_BORDER_COLOR,
			TextureMinLod = GL_TEXTURE_MIN_LOD,
			TextureMaxLod = GL_TEXTURE_MAX_LOD
		};
	}
	typedef SamplerParameterFEnum::Enum SamplerParameterF;

	namespace PrecisionTypeEnum
	{
		enum Enum : GLenum
		{
			LowFloat = GL_LOW_FLOAT,
			MediumFloat = GL_MEDIUM_FLOAT,
			HighFloat = GL_HIGH_FLOAT,
			LowInt = GL_LOW_INT,
			MediumInt = GL_MEDIUM_INT,
			HighInt = GL_HIGH_INT
		};
	}
	typedef PrecisionTypeEnum::Enum PrecisionType;

	namespace ShaderParameterNameEnum
	{
		enum Enum : GLenum
		{
			ShaderType = GL_SHADER_TYPE,
			DeleteStatus = GL_DELETE_STATUS,
			CompileStatus = GL_COMPILE_STATUS,
			InfoLogLength = GL_INFO_LOG_LENGTH,
			ShaderSourceLength = GL_SHADER_SOURCE_LENGTH
		};
	}
	typedef ShaderParameterNameEnum::Enum ShaderParameterName;

	namespace StringNameEnum
	{
		enum Enum : GLenum
		{
			Extensions = GL_EXTENSIONS,
			Renderer = GL_RENDERER,
			Vendor = GL_VENDOR,
			Version = GL_VERSION,
			ShadingLanguageVersion = GL_SHADING_LANGUAGE_VERSION
		};
	}
	typedef StringNameEnum::Enum StringName;

	namespace SyncParameterNameEnum
	{
		enum Enum : GLenum
		{
			ObjectType = GL_OBJECT_TYPE,
			SyncStatus = GL_SYNC_STATUS,
			SyncCondition = GL_SYNC_CONDITION,
			SyncFlags = GL_SYNC_FLAGS
		};
	}
	typedef SyncParameterNameEnum::Enum SyncParameterName;

	namespace GetTextureParameterEnum
	{
		enum Enum : GLenum
		{
			TextureAlphaSize = GL_TEXTURE_ALPHA_SIZE,
			TextureBlueSize = GL_TEXTURE_BLUE_SIZE,
			TextureBorderColor = GL_TEXTURE_BORDER_COLOR,
			TextureGreenSize = GL_TEXTURE_GREEN_SIZE,
			TextureHeight = GL_TEXTURE_HEIGHT,
			TextureInternalFormat = GL_TEXTURE_INTERNAL_FORMAT,
			TextureMagFilter = GL_TEXTURE_MAG_FILTER,
			TextureMinFilter = GL_TEXTURE_MIN_FILTER,
			TextureRedSize = GL_TEXTURE_RED_SIZE,
			TextureWidth = GL_TEXTURE_WIDTH,
			TextureWrapS = GL_TEXTURE_WRAP_S,
			TextureWrapT = GL_TEXTURE_WRAP_T
		};
	}
	typedef GetTextureParameterEnum::Enum GetTextureParameter;

	namespace GlslTypeTokenEnum
	{
		enum Enum : GLenum
		{
			Float = GL_FLOAT,
			FloatVec2 = GL_FLOAT_VEC2,
			FloatVec3 = GL_FLOAT_VEC3,
			FloatVec4 = GL_FLOAT_VEC4,
			Double = GL_DOUBLE,
			DoubleVec2 = GL_DOUBLE_VEC2,
			DoubleVec3 = GL_DOUBLE_VEC3,
			DoubleVec4 = GL_DOUBLE_VEC4,
			Int = GL_INT,
			IntVec2 = GL_INT_VEC2,
			IntVec3 = GL_INT_VEC3,
			IntVec4 = GL_INT_VEC4,
			UnsignedInt = GL_UNSIGNED_INT,
			UnsignedIntVec2 = GL_UNSIGNED_INT_VEC2,
			UnsignedIntVec3 = GL_UNSIGNED_INT_VEC3,
			UnsignedIntVec4 = GL_UNSIGNED_INT_VEC4,
			Bool = GL_BOOL,
			BoolVec2 = GL_BOOL_VEC2,
			BoolVec3 = GL_BOOL_VEC3,
			BoolVec4 = GL_BOOL_VEC4,
			FloatMat2 = GL_FLOAT_MAT2,
			FloatMat3 = GL_FLOAT_MAT3,
			FloatMat4 = GL_FLOAT_MAT4,
			FloatMat2x3 = GL_FLOAT_MAT2x3,
			FloatMat2x4 = GL_FLOAT_MAT2x4,
			FloatMat3x2 = GL_FLOAT_MAT3x2,
			FloatMat3x4 = GL_FLOAT_MAT3x4,
			FloatMat4x2 = GL_FLOAT_MAT4x2,
			FloatMat4x3 = GL_FLOAT_MAT4x3,
			DoubleMat2 = GL_DOUBLE_MAT2,
			DoubleMat3 = GL_DOUBLE_MAT3,
			DoubleMat4 = GL_DOUBLE_MAT4,
			Sampler1D = GL_SAMPLER_1D,
			Sampler2D = GL_SAMPLER_2D,
			Sampler3D = GL_SAMPLER_3D,
			SamplerCube = GL_SAMPLER_CUBE,
			Sampler1DShadow = GL_SAMPLER_1D_SHADOW,
			Sampler2DShadow = GL_SAMPLER_2D_SHADOW,
			Sampler1DArray = GL_SAMPLER_1D_ARRAY,
			Sampler2DArray = GL_SAMPLER_2D_ARRAY,
			SamplerCubeMapArray = GL_SAMPLER_CUBE_MAP_ARRAY,
			Sampler1DArrayShadow = GL_SAMPLER_1D_ARRAY_SHADOW,
			Sampler2DArrayShadow = GL_SAMPLER_2D_ARRAY_SHADOW,
			Sampler2DMultisample = GL_SAMPLER_2D_MULTISAMPLE,
			Sampler2DMultisampleArray = GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
			SamplerCubeShadow = GL_SAMPLER_CUBE_SHADOW,
			SamplerCubeMapArrayShadow = GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
			SamplerBuffer = GL_SAMPLER_BUFFER,
			Sampler2DRect = GL_SAMPLER_2D_RECT,
			Sampler2DRectShadow = GL_SAMPLER_2D_RECT_SHADOW,
			IntSampler1D = GL_INT_SAMPLER_1D,
			IntSampler2D = GL_INT_SAMPLER_2D,
			IntSampler3D = GL_INT_SAMPLER_3D,
			IntSamplerCube = GL_INT_SAMPLER_CUBE,
			IntSampler1DArray = GL_INT_SAMPLER_1D_ARRAY,
			IntSampler2DArray = GL_INT_SAMPLER_2D_ARRAY,
			IntSamplerCubeMapArray = GL_INT_SAMPLER_CUBE_MAP_ARRAY,
			IntSampler2DMultisample = GL_INT_SAMPLER_2D_MULTISAMPLE,
			IntSampler2DMultisampleArray = GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
			IntSamplerBuffer = GL_INT_SAMPLER_BUFFER,
			IntSampler2DRect = GL_INT_SAMPLER_2D_RECT,
			UnsignedIntSampler1D = GL_UNSIGNED_INT_SAMPLER_1D,
			UnsignedIntSampler2D = GL_UNSIGNED_INT_SAMPLER_2D,
			UnsignedIntSampler3D = GL_UNSIGNED_INT_SAMPLER_3D,
			UnsignedIntSamplerCube = GL_UNSIGNED_INT_SAMPLER_CUBE,
			UnsignedIntSampler1DArray = GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
			UnsignedIntSampler2DArray = GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
			UnsignedIntSamplerCubeMapArray = GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
			UnsignedIntSampler2DMultisample = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
			UnsignedIntSampler2DMultisampleArray = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
			UnsignedIntSamplerBuffer = GL_UNSIGNED_INT_SAMPLER_BUFFER,
			UnsignedIntSampler2DRect = GL_UNSIGNED_INT_SAMPLER_2D_RECT,
			Image1D = GL_IMAGE_1D,
			Image2D = GL_IMAGE_2D,
			Image3D = GL_IMAGE_3D,
			Image2DRect = GL_IMAGE_2D_RECT,
			ImageCube = GL_IMAGE_CUBE,
			ImageBuffer = GL_IMAGE_BUFFER,
			Image1DArray = GL_IMAGE_1D_ARRAY,
			Image2DArray = GL_IMAGE_2D_ARRAY,
			ImageCubeMapArray = GL_IMAGE_CUBE_MAP_ARRAY,
			Image2DMultisample = GL_IMAGE_2D_MULTISAMPLE,
			Image2DMultisampleArray = GL_IMAGE_2D_MULTISAMPLE_ARRAY,
			IntImage1D = GL_INT_IMAGE_1D,
			IntImage2D = GL_INT_IMAGE_2D,
			IntImage3D = GL_INT_IMAGE_3D,
			IntImage2DRect = GL_INT_IMAGE_2D_RECT,
			IntImageCube = GL_INT_IMAGE_CUBE,
			IntImageBuffer = GL_INT_IMAGE_BUFFER,
			IntImage1DArray = GL_INT_IMAGE_1D_ARRAY,
			IntImage2DArray = GL_INT_IMAGE_2D_ARRAY,
			IntImageCubeMapArray = GL_INT_IMAGE_CUBE_MAP_ARRAY,
			IntImage2DMultisample = GL_INT_IMAGE_2D_MULTISAMPLE,
			IntImage2DMultisampleArray = GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
			UnsignedIntImage1D = GL_UNSIGNED_INT_IMAGE_1D,
			UnsignedIntImage2D = GL_UNSIGNED_INT_IMAGE_2D,
			UnsignedIntImage3D = GL_UNSIGNED_INT_IMAGE_3D,
			UnsignedIntImage2DRect = GL_UNSIGNED_INT_IMAGE_2D_RECT,
			UnsignedIntImageCube = GL_UNSIGNED_INT_IMAGE_CUBE,
			UnsignedIntImageBuffer = GL_UNSIGNED_INT_IMAGE_BUFFER,
			UnsignedIntImage1DArray = GL_UNSIGNED_INT_IMAGE_1D_ARRAY,
			UnsignedIntImage2DArray = GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
			UnsignedIntImageCubeMapArray = GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY,
			UnsignedIntImage2DMultisample = GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,
			UnsignedIntImage2DMultisampleArray = GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
			UnsignedIntAtomicCounter = GL_UNSIGNED_INT_ATOMIC_COUNTER
		};
	}
	typedef GlslTypeTokenEnum::Enum GlslTypeToken;

	namespace TransformFeedbackPNameEnum
	{
		enum Enum : GLenum
		{
			TransformFeedbackBufferBinding = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
			TransformFeedbackBufferStart = GL_TRANSFORM_FEEDBACK_BUFFER_START,
			TransformFeedbackBufferSize = GL_TRANSFORM_FEEDBACK_BUFFER_SIZE,
			TransformFeedbackPaused = GL_TRANSFORM_FEEDBACK_PAUSED,
			TransformFeedbackActive = GL_TRANSFORM_FEEDBACK_ACTIVE
		};
	}
	typedef TransformFeedbackPNameEnum::Enum TransformFeedbackPName;

	namespace VertexArrayPNameEnum
	{
		enum Enum : GLenum
		{
			VertexAttribArrayEnabled = GL_VERTEX_ATTRIB_ARRAY_ENABLED,
			VertexAttribArraySize = GL_VERTEX_ATTRIB_ARRAY_SIZE,
			VertexAttribArrayStride = GL_VERTEX_ATTRIB_ARRAY_STRIDE,
			VertexAttribArrayType = GL_VERTEX_ATTRIB_ARRAY_TYPE,
			VertexAttribArrayNormalized = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED,
			VertexAttribArrayInteger = GL_VERTEX_ATTRIB_ARRAY_INTEGER,
			VertexAttribArrayLong = GL_VERTEX_ATTRIB_ARRAY_LONG,
			VertexAttribArrayDivisor = GL_VERTEX_ATTRIB_ARRAY_DIVISOR,
			VertexAttribRelativeOffset = GL_VERTEX_ATTRIB_RELATIVE_OFFSET
		};
	}
	typedef VertexArrayPNameEnum::Enum VertexArrayPName;

	namespace VertexAttribEnumEnum
	{
		enum Enum : GLenum
		{
			VertexAttribArrayBufferBinding = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING,
			VertexAttribArrayEnabled = GL_VERTEX_ATTRIB_ARRAY_ENABLED,
			VertexAttribArraySize = GL_VERTEX_ATTRIB_ARRAY_SIZE,
			VertexAttribArrayStride = GL_VERTEX_ATTRIB_ARRAY_STRIDE,
			VertexAttribArrayType = GL_VERTEX_ATTRIB_ARRAY_TYPE,
			VertexAttribArrayNormalized = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED,
			VertexAttribArrayInteger = GL_VERTEX_ATTRIB_ARRAY_INTEGER,
			VertexAttribArrayDivisor = GL_VERTEX_ATTRIB_ARRAY_DIVISOR,
			CurrentVertexAttrib = GL_CURRENT_VERTEX_ATTRIB
		};
	}
	typedef VertexAttribEnumEnum::Enum VertexAttribEnum;

	namespace VertexAttribPointerPropertyARBEnum
	{
		enum Enum : GLenum
		{
			VertexAttribArrayPointer = GL_VERTEX_ATTRIB_ARRAY_POINTER
		};
	}
	typedef VertexAttribPointerPropertyARBEnum::Enum VertexAttribPointerPropertyARB;

	namespace VertexAttribPropertyARBEnum
	{
		enum Enum : GLenum
		{
			VertexAttribArrayBufferBinding = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING,
			VertexAttribArrayEnabled = GL_VERTEX_ATTRIB_ARRAY_ENABLED,
			VertexAttribArraySize = GL_VERTEX_ATTRIB_ARRAY_SIZE,
			VertexAttribArrayStride = GL_VERTEX_ATTRIB_ARRAY_STRIDE,
			VertexAttribArrayType = GL_VERTEX_ATTRIB_ARRAY_TYPE,
			VertexAttribArrayNormalized = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED,
			VertexAttribArrayInteger = GL_VERTEX_ATTRIB_ARRAY_INTEGER,
			VertexAttribArrayLong = GL_VERTEX_ATTRIB_ARRAY_LONG,
			VertexAttribArrayDivisor = GL_VERTEX_ATTRIB_ARRAY_DIVISOR,
			VertexAttribBinding = GL_VERTEX_ATTRIB_BINDING,
			VertexAttribRelativeOffset = GL_VERTEX_ATTRIB_RELATIVE_OFFSET,
			CurrentVertexAttrib = GL_CURRENT_VERTEX_ATTRIB
		};
	}
	typedef VertexAttribPropertyARBEnum::Enum VertexAttribPropertyARB;

	namespace ColorTableTargetEnum
	{
		enum Enum : GLenum
		{
		};
	}
	typedef ColorTableTargetEnum::Enum ColorTableTarget;

	namespace ConvolutionTargetEnum
	{
		enum Enum : GLenum
		{
		};
	}
	typedef ConvolutionTargetEnum::Enum ConvolutionTarget;

	namespace HistogramTargetEXTEnum
	{
		enum Enum : GLenum
		{
		};
	}
	typedef HistogramTargetEXTEnum::Enum HistogramTargetEXT;

	namespace MapTargetEnum
	{
		enum Enum : GLenum
		{
		};
	}
	typedef MapTargetEnum::Enum MapTarget;

	namespace MapQueryEnum
	{
		enum Enum : GLenum
		{
		};
	}
	typedef MapQueryEnum::Enum MapQuery;

	namespace MinmaxTargetEXTEnum
	{
		enum Enum : GLenum
		{
		};
	}
	typedef MinmaxTargetEXTEnum::Enum MinmaxTargetEXT;

	namespace PixelMapEnum
	{
		enum Enum : GLenum
		{
		};
	}
	typedef PixelMapEnum::Enum PixelMap;

	namespace SeparableTargetEXTEnum
	{
		enum Enum : GLenum
		{
		};
	}
	typedef SeparableTargetEXTEnum::Enum SeparableTargetEXT;

	namespace HintTargetEnum
	{
		enum Enum : GLenum
		{
			FragmentShaderDerivativeHint = GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
			LineSmoothHint = GL_LINE_SMOOTH_HINT,
			PolygonSmoothHint = GL_POLYGON_SMOOTH_HINT,
			ProgramBinaryRetrievableHint = GL_PROGRAM_BINARY_RETRIEVABLE_HINT,
			TextureCompressionHint = GL_TEXTURE_COMPRESSION_HINT
		};
	}
	typedef HintTargetEnum::Enum HintTarget;

	namespace HintModeEnum
	{
		enum Enum : GLenum
		{
			DontCare = GL_DONT_CARE,
			Fastest = GL_FASTEST,
			Nicest = GL_NICEST
		};
	}
	typedef HintModeEnum::Enum HintMode;

	namespace InvalidateFramebufferAttachmentEnum
	{
		enum Enum : GLenum
		{
			ColorAttachment0 = GL_COLOR_ATTACHMENT0,
			ColorAttachment1 = GL_COLOR_ATTACHMENT1,
			ColorAttachment2 = GL_COLOR_ATTACHMENT2,
			ColorAttachment3 = GL_COLOR_ATTACHMENT3,
			ColorAttachment4 = GL_COLOR_ATTACHMENT4,
			ColorAttachment5 = GL_COLOR_ATTACHMENT5,
			ColorAttachment6 = GL_COLOR_ATTACHMENT6,
			ColorAttachment7 = GL_COLOR_ATTACHMENT7,
			ColorAttachment8 = GL_COLOR_ATTACHMENT8,
			ColorAttachment9 = GL_COLOR_ATTACHMENT9,
			ColorAttachment10 = GL_COLOR_ATTACHMENT10,
			ColorAttachment11 = GL_COLOR_ATTACHMENT11,
			ColorAttachment12 = GL_COLOR_ATTACHMENT12,
			ColorAttachment13 = GL_COLOR_ATTACHMENT13,
			ColorAttachment14 = GL_COLOR_ATTACHMENT14,
			ColorAttachment15 = GL_COLOR_ATTACHMENT15,
			ColorAttachment16 = GL_COLOR_ATTACHMENT16,
			ColorAttachment17 = GL_COLOR_ATTACHMENT17,
			ColorAttachment18 = GL_COLOR_ATTACHMENT18,
			ColorAttachment19 = GL_COLOR_ATTACHMENT19,
			ColorAttachment20 = GL_COLOR_ATTACHMENT20,
			ColorAttachment21 = GL_COLOR_ATTACHMENT21,
			ColorAttachment22 = GL_COLOR_ATTACHMENT22,
			ColorAttachment23 = GL_COLOR_ATTACHMENT23,
			ColorAttachment24 = GL_COLOR_ATTACHMENT24,
			ColorAttachment25 = GL_COLOR_ATTACHMENT25,
			ColorAttachment26 = GL_COLOR_ATTACHMENT26,
			ColorAttachment27 = GL_COLOR_ATTACHMENT27,
			ColorAttachment28 = GL_COLOR_ATTACHMENT28,
			ColorAttachment29 = GL_COLOR_ATTACHMENT29,
			ColorAttachment30 = GL_COLOR_ATTACHMENT30,
			ColorAttachment31 = GL_COLOR_ATTACHMENT31,
			DepthAttachment = GL_DEPTH_ATTACHMENT,
			DepthStencilAttachment = GL_DEPTH_STENCIL_ATTACHMENT,
			Stencil = GL_STENCIL,
			Color = GL_COLOR,
			Depth = GL_DEPTH
		};
	}
	typedef InvalidateFramebufferAttachmentEnum::Enum InvalidateFramebufferAttachment;

	namespace LogicOpEnum
	{
		enum Enum : GLenum
		{
			And = GL_AND,
			AndInverted = GL_AND_INVERTED,
			AndReverse = GL_AND_REVERSE,
			Clear = GL_CLEAR,
			Copy = GL_COPY,
			CopyInverted = GL_COPY_INVERTED,
			Equiv = GL_EQUIV,
			Invert = GL_INVERT,
			Nand = GL_NAND,
			Noop = GL_NOOP,
			Nor = GL_NOR,
			Or = GL_OR,
			OrInverted = GL_OR_INVERTED,
			OrReverse = GL_OR_REVERSE,
			Set = GL_SET,
			Xor = GL_XOR
		};
	}
	typedef LogicOpEnum::Enum LogicOp;

	namespace TexCoordPointerTypeEnum
	{
		enum Enum : GLenum
		{
			Double = GL_DOUBLE,
			Float = GL_FLOAT,
			Int = GL_INT,
			Short = GL_SHORT
		};
	}
	typedef TexCoordPointerTypeEnum::Enum TexCoordPointerType;

	namespace VertexBufferObjectUsageEnum
	{
		enum Enum : GLenum
		{
			StreamDraw = GL_STREAM_DRAW,
			StreamRead = GL_STREAM_READ,
			StreamCopy = GL_STREAM_COPY,
			StaticDraw = GL_STATIC_DRAW,
			StaticRead = GL_STATIC_READ,
			StaticCopy = GL_STATIC_COPY,
			DynamicDraw = GL_DYNAMIC_DRAW,
			DynamicRead = GL_DYNAMIC_READ,
			DynamicCopy = GL_DYNAMIC_COPY
		};
	}
	typedef VertexBufferObjectUsageEnum::Enum VertexBufferObjectUsage;

	namespace ColorBufferEnum
	{
		enum Enum : GLenum
		{
			None = GL_NONE,
			FrontLeft = GL_FRONT_LEFT,
			FrontRight = GL_FRONT_RIGHT,
			BackLeft = GL_BACK_LEFT,
			BackRight = GL_BACK_RIGHT,
			Front = GL_FRONT,
			Back = GL_BACK,
			Left = GL_LEFT,
			Right = GL_RIGHT,
			FrontAndBack = GL_FRONT_AND_BACK,
			ColorAttachment0 = GL_COLOR_ATTACHMENT0,
			ColorAttachment1 = GL_COLOR_ATTACHMENT1,
			ColorAttachment2 = GL_COLOR_ATTACHMENT2,
			ColorAttachment3 = GL_COLOR_ATTACHMENT3,
			ColorAttachment4 = GL_COLOR_ATTACHMENT4,
			ColorAttachment5 = GL_COLOR_ATTACHMENT5,
			ColorAttachment6 = GL_COLOR_ATTACHMENT6,
			ColorAttachment7 = GL_COLOR_ATTACHMENT7,
			ColorAttachment8 = GL_COLOR_ATTACHMENT8,
			ColorAttachment9 = GL_COLOR_ATTACHMENT9,
			ColorAttachment10 = GL_COLOR_ATTACHMENT10,
			ColorAttachment11 = GL_COLOR_ATTACHMENT11,
			ColorAttachment12 = GL_COLOR_ATTACHMENT12,
			ColorAttachment13 = GL_COLOR_ATTACHMENT13,
			ColorAttachment14 = GL_COLOR_ATTACHMENT14,
			ColorAttachment15 = GL_COLOR_ATTACHMENT15,
			ColorAttachment16 = GL_COLOR_ATTACHMENT16,
			ColorAttachment17 = GL_COLOR_ATTACHMENT17,
			ColorAttachment18 = GL_COLOR_ATTACHMENT18,
			ColorAttachment19 = GL_COLOR_ATTACHMENT19,
			ColorAttachment20 = GL_COLOR_ATTACHMENT20,
			ColorAttachment21 = GL_COLOR_ATTACHMENT21,
			ColorAttachment22 = GL_COLOR_ATTACHMENT22,
			ColorAttachment23 = GL_COLOR_ATTACHMENT23,
			ColorAttachment24 = GL_COLOR_ATTACHMENT24,
			ColorAttachment25 = GL_COLOR_ATTACHMENT25,
			ColorAttachment26 = GL_COLOR_ATTACHMENT26,
			ColorAttachment27 = GL_COLOR_ATTACHMENT27,
			ColorAttachment28 = GL_COLOR_ATTACHMENT28,
			ColorAttachment29 = GL_COLOR_ATTACHMENT29,
			ColorAttachment30 = GL_COLOR_ATTACHMENT30,
			ColorAttachment31 = GL_COLOR_ATTACHMENT31
		};
	}
	typedef ColorBufferEnum::Enum ColorBuffer;

	namespace NormalPointerTypeEnum
	{
		enum Enum : GLenum
		{
			Byte = GL_BYTE,
			Double = GL_DOUBLE,
			Float = GL_FLOAT,
			Int = GL_INT,
			Short = GL_SHORT
		};
	}
	typedef NormalPointerTypeEnum::Enum NormalPointerType;

	namespace PatchParameterNameEnum
	{
		enum Enum : GLenum
		{
			PatchVertices = GL_PATCH_VERTICES,
			PatchDefaultOuterLevel = GL_PATCH_DEFAULT_OUTER_LEVEL,
			PatchDefaultInnerLevel = GL_PATCH_DEFAULT_INNER_LEVEL
		};
	}
	typedef PatchParameterNameEnum::Enum PatchParameterName;

	namespace PixelStoreParameterEnum
	{
		enum Enum : GLenum
		{
			PackAlignment = GL_PACK_ALIGNMENT,
			PackImageHeight = GL_PACK_IMAGE_HEIGHT,
			PackLsbFirst = GL_PACK_LSB_FIRST,
			PackRowLength = GL_PACK_ROW_LENGTH,
			PackSkipImages = GL_PACK_SKIP_IMAGES,
			PackSkipPixels = GL_PACK_SKIP_PIXELS,
			PackSkipRows = GL_PACK_SKIP_ROWS,
			PackSwapBytes = GL_PACK_SWAP_BYTES,
			UnpackAlignment = GL_UNPACK_ALIGNMENT,
			UnpackImageHeight = GL_UNPACK_IMAGE_HEIGHT,
			UnpackLsbFirst = GL_UNPACK_LSB_FIRST,
			UnpackRowLength = GL_UNPACK_ROW_LENGTH,
			UnpackSkipImages = GL_UNPACK_SKIP_IMAGES,
			UnpackSkipPixels = GL_UNPACK_SKIP_PIXELS,
			UnpackSkipRows = GL_UNPACK_SKIP_ROWS,
			UnpackSwapBytes = GL_UNPACK_SWAP_BYTES
		};
	}
	typedef PixelStoreParameterEnum::Enum PixelStoreParameter;

	namespace PointParameterNameARBEnum
	{
		enum Enum : GLenum
		{
			PointFadeThresholdSize = GL_POINT_FADE_THRESHOLD_SIZE
		};
	}
	typedef PointParameterNameARBEnum::Enum PointParameterNameARB;

	namespace MaterialFaceEnum
	{
		enum Enum : GLenum
		{
			Back = GL_BACK,
			Front = GL_FRONT,
			FrontAndBack = GL_FRONT_AND_BACK
		};
	}
	typedef MaterialFaceEnum::Enum MaterialFace;

	namespace PolygonModeEnum
	{
		enum Enum : GLenum
		{
			Fill = GL_FILL,
			Line = GL_LINE,
			Point = GL_POINT
		};
	}
	typedef PolygonModeEnum::Enum PolygonMode;

	namespace ProgramParameterPNameEnum
	{
		enum Enum : GLenum
		{
			ProgramBinaryRetrievableHint = GL_PROGRAM_BINARY_RETRIEVABLE_HINT,
			ProgramSeparable = GL_PROGRAM_SEPARABLE
		};
	}
	typedef ProgramParameterPNameEnum::Enum ProgramParameterPName;

	namespace VertexProvokingModeEnum
	{
		enum Enum : GLenum
		{
			FirstVertexConvention = GL_FIRST_VERTEX_CONVENTION,
			LastVertexConvention = GL_LAST_VERTEX_CONVENTION
		};
	}
	typedef VertexProvokingModeEnum::Enum VertexProvokingMode;

	namespace QueryCounterTargetEnum
	{
		enum Enum : GLenum
		{
			Timestamp = GL_TIMESTAMP
		};
	}
	typedef QueryCounterTargetEnum::Enum QueryCounterTarget;

	namespace ReadBufferModeEnum
	{
		enum Enum : GLenum
		{
			None = GL_NONE,
			Back = GL_BACK,
			BackLeft = GL_BACK_LEFT,
			BackRight = GL_BACK_RIGHT,
			Front = GL_FRONT,
			FrontLeft = GL_FRONT_LEFT,
			FrontRight = GL_FRONT_RIGHT,
			Left = GL_LEFT,
			Right = GL_RIGHT,
			ColorAttachment0 = GL_COLOR_ATTACHMENT0,
			ColorAttachment1 = GL_COLOR_ATTACHMENT1,
			ColorAttachment2 = GL_COLOR_ATTACHMENT2,
			ColorAttachment3 = GL_COLOR_ATTACHMENT3,
			ColorAttachment4 = GL_COLOR_ATTACHMENT4,
			ColorAttachment5 = GL_COLOR_ATTACHMENT5,
			ColorAttachment6 = GL_COLOR_ATTACHMENT6,
			ColorAttachment7 = GL_COLOR_ATTACHMENT7,
			ColorAttachment8 = GL_COLOR_ATTACHMENT8,
			ColorAttachment9 = GL_COLOR_ATTACHMENT9,
			ColorAttachment10 = GL_COLOR_ATTACHMENT10,
			ColorAttachment11 = GL_COLOR_ATTACHMENT11,
			ColorAttachment12 = GL_COLOR_ATTACHMENT12,
			ColorAttachment13 = GL_COLOR_ATTACHMENT13,
			ColorAttachment14 = GL_COLOR_ATTACHMENT14,
			ColorAttachment15 = GL_COLOR_ATTACHMENT15
		};
	}
	typedef ReadBufferModeEnum::Enum ReadBufferMode;

	namespace StencilFunctionEnum
	{
		enum Enum : GLenum
		{
			Always = GL_ALWAYS,
			Equal = GL_EQUAL,
			Gequal = GL_GEQUAL,
			Greater = GL_GREATER,
			Lequal = GL_LEQUAL,
			Less = GL_LESS,
			Never = GL_NEVER,
			Notequal = GL_NOTEQUAL
		};
	}
	typedef StencilFunctionEnum::Enum StencilFunction;

	namespace StencilFaceDirectionEnum
	{
		enum Enum : GLenum
		{
			Front = GL_FRONT,
			Back = GL_BACK,
			FrontAndBack = GL_FRONT_AND_BACK
		};
	}
	typedef StencilFaceDirectionEnum::Enum StencilFaceDirection;

	namespace StencilOpEnum
	{
		enum Enum : GLenum
		{
			Decr = GL_DECR,
			DecrWrap = GL_DECR_WRAP,
			Incr = GL_INCR,
			IncrWrap = GL_INCR_WRAP,
			Invert = GL_INVERT,
			Keep = GL_KEEP,
			Replace = GL_REPLACE,
			Zero = GL_ZERO
		};
	}
	typedef StencilOpEnum::Enum StencilOp;

	namespace TextureParameterNameEnum
	{
		enum Enum : GLenum
		{
			TextureBorderColor = GL_TEXTURE_BORDER_COLOR,
			TextureMagFilter = GL_TEXTURE_MAG_FILTER,
			TextureMinFilter = GL_TEXTURE_MIN_FILTER,
			TextureWrapR = GL_TEXTURE_WRAP_R,
			TextureWrapS = GL_TEXTURE_WRAP_S,
			TextureWrapT = GL_TEXTURE_WRAP_T,
			TextureBaseLevel = GL_TEXTURE_BASE_LEVEL,
			TextureCompareMode = GL_TEXTURE_COMPARE_MODE,
			TextureCompareFunc = GL_TEXTURE_COMPARE_FUNC,
			TextureLodBias = GL_TEXTURE_LOD_BIAS,
			TextureMinLod = GL_TEXTURE_MIN_LOD,
			TextureMaxLod = GL_TEXTURE_MAX_LOD,
			TextureMaxLevel = GL_TEXTURE_MAX_LEVEL,
			TextureSwizzleR = GL_TEXTURE_SWIZZLE_R,
			TextureSwizzleG = GL_TEXTURE_SWIZZLE_G,
			TextureSwizzleB = GL_TEXTURE_SWIZZLE_B,
			TextureSwizzleA = GL_TEXTURE_SWIZZLE_A,
			TextureSwizzleRGBA = GL_TEXTURE_SWIZZLE_RGBA,
			DepthStencilTextureMode = GL_DEPTH_STENCIL_TEXTURE_MODE,
			TextureAlphaSize = GL_TEXTURE_ALPHA_SIZE,
			TextureBlueSize = GL_TEXTURE_BLUE_SIZE,
			TextureGreenSize = GL_TEXTURE_GREEN_SIZE,
			TextureHeight = GL_TEXTURE_HEIGHT,
			TextureInternalFormat = GL_TEXTURE_INTERNAL_FORMAT,
			TextureRedSize = GL_TEXTURE_RED_SIZE,
			TextureWidth = GL_TEXTURE_WIDTH
		};
	}
	typedef TextureParameterNameEnum::Enum TextureParameterName;

	namespace TransformFeedbackBufferModeEnum
	{
		enum Enum : GLenum
		{
			InterleavedAttribs = GL_INTERLEAVED_ATTRIBS,
			SeparateAttribs = GL_SEPARATE_ATTRIBS
		};
	}
	typedef TransformFeedbackBufferModeEnum::Enum TransformFeedbackBufferMode;

	namespace VertexAttribTypeEnum
	{
		enum Enum : GLenum
		{
			Byte = GL_BYTE,
			Short = GL_SHORT,
			Int = GL_INT,
			Fixed = GL_FIXED,
			Float = GL_FLOAT,
			HalfFloat = GL_HALF_FLOAT,
			Double = GL_DOUBLE,
			UnsignedByte = GL_UNSIGNED_BYTE,
			UnsignedShort = GL_UNSIGNED_SHORT,
			UnsignedInt = GL_UNSIGNED_INT,
			Int2101010Rev = GL_INT_2_10_10_10_REV,
			UnsignedInt2101010Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
			UnsignedInt10F11F11FRev = GL_UNSIGNED_INT_10F_11F_11F_REV
		};
	}
	typedef VertexAttribTypeEnum::Enum VertexAttribType;

	namespace VertexAttribITypeEnum
	{
		enum Enum : GLenum
		{
			Byte = GL_BYTE,
			UnsignedByte = GL_UNSIGNED_BYTE,
			Short = GL_SHORT,
			UnsignedShort = GL_UNSIGNED_SHORT,
			Int = GL_INT,
			UnsignedInt = GL_UNSIGNED_INT
		};
	}
	typedef VertexAttribITypeEnum::Enum VertexAttribIType;

	namespace VertexAttribLTypeEnum
	{
		enum Enum : GLenum
		{
			Double = GL_DOUBLE
		};
	}
	typedef VertexAttribLTypeEnum::Enum VertexAttribLType;

	namespace VertexAttribPointerTypeEnum
	{
		enum Enum : GLenum
		{
			Byte = GL_BYTE,
			UnsignedByte = GL_UNSIGNED_BYTE,
			Short = GL_SHORT,
			UnsignedShort = GL_UNSIGNED_SHORT,
			Int = GL_INT,
			UnsignedInt = GL_UNSIGNED_INT,
			Float = GL_FLOAT,
			Double = GL_DOUBLE,
			HalfFloat = GL_HALF_FLOAT,
			Fixed = GL_FIXED,
			Int2101010Rev = GL_INT_2_10_10_10_REV,
			UnsignedInt2101010Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
			UnsignedInt10F11F11FRev = GL_UNSIGNED_INT_10F_11F_11F_REV
		};
	}
	typedef VertexAttribPointerTypeEnum::Enum VertexAttribPointerType;

	namespace VertexPointerTypeEnum
	{
		enum Enum : GLenum
		{
			Double = GL_DOUBLE,
			Float = GL_FLOAT,
			Int = GL_INT,
			Short = GL_SHORT
		};
	}
	typedef VertexPointerTypeEnum::Enum VertexPointerType;
}
