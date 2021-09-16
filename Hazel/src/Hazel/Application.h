#pragma once

#include "hzpch.h"
#include "Core.h"
#include "Event/Event.h"
#include "Hazel/Window.h"
#include "Hazel/LayerStack.h"
#include "Renderer/Shader.h"

#include "ImGui/ImGuiLayer.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void Run();
		void OnEvent(Event& event);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(Event& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		Shader* m_Shader;

		static Application* s_Instance;
	};

	Hazel::Application* CreateApplication();
}