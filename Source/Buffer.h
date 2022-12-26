#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <vector>
#include <concepts>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Vertex.h"

namespace OpenGL {

	enum class VertexBuffer : unsigned int { VALUE = GL_VERTEX_ARRAY };
	enum class IndexBuffer : unsigned int { VALUE = GL_ELEMENT_ARRAY_BUFFER };
	enum class UnionBuffer : unsigned int { VALUE = GL_UNIFORM_BUFFER };

	template<typename TBuffer, typename TData>
	concept CBuffer = (
		(std::same_as<TBuffer, VertexBuffer> and (std::same_as<TData, float> or std::same_as<TData, Vertex>)) or
		(std::same_as<TBuffer, IndexBuffer> and std::same_as<TData, unsigned int>) or
		(std::same_as<TBuffer, UnionBuffer>)
		);

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	class Buffer
	{
	public:
		constexpr auto SetData(std::vector<TData> data);
		constexpr auto GetData() const;
		constexpr auto GetID() const;
		constexpr auto Bind();
		constexpr auto Unbind();
		Buffer();
		~Buffer();
	private:
		unsigned int mID{};
		std::vector<TData> mData{};
		constexpr auto SpecifyVertexBufferLayout();
	};

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	constexpr auto Buffer<TBuffer, TData>::SetData(std::vector<TData> data)
	{
		mData = data;

		if (std::same_as<TBuffer, VertexBuffer>)
		{
			SpecifyVertexBufferLayout();
		}
	}

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	constexpr auto Buffer<TBuffer, TData>::GetData() const
	{
		return mData;
	}

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	constexpr auto Buffer<TBuffer, TData>::GetID() const
	{
		return mID;
	}

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	constexpr auto Buffer<TBuffer, TData>::Bind()
	{
		glBindBuffer(static_cast<unsigned int>(TBuffer::VALUE), &mID);
	}

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	constexpr auto Buffer<TBuffer, TData>::Unbind()
	{
		glBindBuffer(static_cast<unsigned int>(TBuffer::VALUE), 0);
	}

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	Buffer<TBuffer, TData>::Buffer()
	{
		glGenBuffers(1, &mID);
	}

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	Buffer<TBuffer, TData>::~Buffer()
	{
		glDeleteBuffers(1, &mID);
	}

	template<typename TBuffer, typename TData>
		requires CBuffer<TBuffer, TData>
	constexpr auto Buffer<TBuffer, TData>::SpecifyVertexBufferLayout()
	{

	}
}

#endif

