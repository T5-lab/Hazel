#pragma once

#include "hzpch.h"
#include "Core.h"
#include "Event/Event.h"
#include "Hazel/Window.h"
#include "Hazel/LayerStack.h"

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

		static Application* s_Instance;
	};

	Hazel::Application* CreateApplication();
}