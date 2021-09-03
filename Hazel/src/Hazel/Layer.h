#pragma once

#include "hzpch.h"
#include "Core.h"
#include "Event/Event.h"

namespace Hazel
{
	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}
		virtual void OnImGuiRender() {}

		inline const std::string& GetName() { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}