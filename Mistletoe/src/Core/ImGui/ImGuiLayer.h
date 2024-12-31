#pragma once
#include "Core/Layers/Layer.h"
#include "Core/Events/Event.h"
#include "Core/Events/ApplicationEvent.h"
#include "Core/Events/MouseEvent.h"
#include "Core/Events/KeyEvent.h"

namespace Mistletoe
{
	class ImGuiLayer : Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override;

		ImGuiLayer(const ImGuiLayer&);
		ImGuiLayer& operator=(const ImGuiLayer&);
		ImGuiLayer(ImGuiLayer&&);
		ImGuiLayer& operator=(ImGuiLayer&&);

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;
	private:
		bool OnWindowCloseEvent(WindowCloseEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		bool OnWindowFocusEvent(WindowFocusEvent& e);
		bool OnWindowLostFocusEvent(WindowLostFocusEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseMovedEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
	private:
		float time = 0.0f;
	};
}

