#include "hzpch.h"
#include "Shader.h"
#include <fstream>
#include "glad/glad.h"

namespace Hazel
{
	Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		CreateProgram(vertexSrc, fragmentSrc);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_Program);
	}

	void Shader::Bind()
	{
		glUseProgram(m_Program);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::CreateProgram(const std::string & vertexSrc, const std::string & fragmentSrc)
	{
		m_Program = glCreateProgram();

		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexSrc);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

		glAttachShader(m_Program, vs);
		glAttachShader(m_Program, fs);
		glLinkProgram(m_Program);
		glValidateProgram(m_Program);

		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string & source)
	{
		unsigned int shader = glCreateShader(type);

		const char* src = source.c_str();
		glShaderSource(shader, 1, &src, 0);
		glCompileShader(shader);

		int res;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &res);
		if (!res)
		{
			int length;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			char* msg = (char*)alloca(sizeof(char) * length);

			glGetShaderInfoLog(shader, length, &length, msg);
			HZ_CORE_ERROR("Error in compiling shaders\n{0}", msg);

			glDeleteShader(shader);
		}

		return shader;
	}
	/* std::string Shader::ParseShader(const char * filepath)
	{
		std::ifstream stream(filepath);

		std::string line;
		std::stringstream ss;

		while (getline(stream, line))
			ss << line << "\n";

		std::cout << "Shader >>>>>> " << ss.str() << std::endl;
		return ss.str();
	} */
}