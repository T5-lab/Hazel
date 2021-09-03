#include <Hazel.h>

#include "imgui/imgui.h"

class ExampleLayer : public Hazel::Layer
{
public:

	ExampleLayer()
		: Layer("Example") 
	{
	}

	void OnUpdate() override
	{
		// HZ_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Hazel::Event& e) override
	{
		// HZ_TRACE(e);
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox;
}