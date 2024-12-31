#include "mstpch.h"
#include "ImGuiLayer.h"
#include "imgui.h"

namespace Mistletoe
{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

	ImGuiLayer::~ImGuiLayer() {}

	ImGuiLayer::ImGuiLayer(const ImGuiLayer&) = default;

	ImGuiLayer& ImGuiLayer::operator=(const ImGuiLayer&) = default;

	ImGuiLayer::ImGuiLayer(ImGuiLayer&&) = default;

	ImGuiLayer& ImGuiLayer::operator=(ImGuiLayer&&) = default;

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{

	}

	void ImGuiLayer::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([this](Event& e) {
			return OnWindowCloseEvent(static_cast<WindowCloseEvent&>(e));
		});
		dispatcher.Dispatch<WindowResizeEvent>([this](Event& e) {
			return OnWindowResizeEvent(static_cast<WindowResizeEvent&>(e));
		});
		dispatcher.Dispatch<WindowFocusEvent>([this](Event& e) {
			return OnWindowFocusEvent(static_cast<WindowFocusEvent&>(e));
		});
		dispatcher.Dispatch<WindowLostFocusEvent>([this](Event& e) {
			return OnWindowLostFocusEvent(static_cast<WindowLostFocusEvent&>(e));
		});
		dispatcher.Dispatch<MouseButtonPressedEvent>([this](Event& e) {
			return OnMouseButtonPressedEvent(static_cast<MouseButtonPressedEvent&>(e));
		});
		dispatcher.Dispatch<MouseButtonReleasedEvent>([this](Event& e) {
			return OnMouseButtonReleasedEvent(static_cast<MouseButtonReleasedEvent&>(e));
		});
		dispatcher.Dispatch<MouseMovedEvent>([this](Event& e) {
			return OnMouseMovedEvent(static_cast<MouseMovedEvent&>(e));
		});
		dispatcher.Dispatch<MouseScrolledEvent>([this](Event& e) {
			return OnMouseMovedEvent(static_cast<MouseScrolledEvent&>(e));
		});
		dispatcher.Dispatch<KeyPressedEvent>([this](Event& e) {
			return OnKeyPressedEvent(static_cast<KeyPressedEvent&>(e));
		});
		dispatcher.Dispatch<KeyReleasedEvent>([this](Event& e) {
			return OnKeyReleasedEvent(static_cast<KeyReleasedEvent&>(e));
		});
	}

	bool ImGuiLayer::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		return false;
	}

	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		return false;
	}

	bool ImGuiLayer::OnWindowFocusEvent(WindowFocusEvent& e)
	{
		return false;
	}

	bool ImGuiLayer::OnWindowLostFocusEvent(WindowLostFocusEvent& e)
	{
		return false;
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;
		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());
		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();
		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		return false;
	}


}
