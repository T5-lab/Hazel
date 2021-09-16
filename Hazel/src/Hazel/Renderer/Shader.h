#pragma once

#include "hzpch.h"

namespace Hazel
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind();
		void Unbind();
	private:
		void CreateProgram(const std::string& vertexSrc, const std::string& fragmentSrc);
		unsigned int CompileShader(unsigned int type, const std::string& source);
		// std::string ParseShader(const char* filepath);
	private:
		unsigned int m_Program;
	};
}