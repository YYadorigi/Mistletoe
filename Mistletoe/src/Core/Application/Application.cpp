#include "mstpch.h"
#include "Application.h"
#include "Core/Log/Log.h"
#include "Core/Events/Event.h"
#include "Core/Events/ApplicationEvent.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"
#include "Platform/WindowsWindow.h"

namespace Mistletoe
{
	Application::Application()
	{
#ifdef MST_PLATFORM_WINDOWS
		window = std::make_unique<WindowsWindow>();
#else
		window = nullptr;
#endif
		window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		running = true;
	}

	Application::~Application()
	{
		window.reset();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([this](Event& e) {
			running = false;
			return true;
		});
		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) {
			MST_CORE_INFO("WindowResizeEvent: {0}, {1}", e.GetWidth(), e.GetHeight());
			return true;
		});
		dispatcher.Dispatch<WindowFocusEvent>([this](WindowFocusEvent& e) {
			MST_CORE_INFO("WindowFocusEvent");
			return true;
		});
		dispatcher.Dispatch<WindowLostFocusEvent>([this](WindowLostFocusEvent& e) {
			MST_CORE_INFO("WindowLostFocusEvent");
			return true;
		});
		dispatcher.Dispatch<AppTickEvent>([this](AppTickEvent& e) {
			MST_CORE_INFO("AppTickEvent");
			return true;
		});
		dispatcher.Dispatch<AppUpdateEvent>([this](AppUpdateEvent& e) {
			MST_CORE_INFO("AppUpdateEvent");
			return true;
		});
		dispatcher.Dispatch<AppRenderEvent>([this](AppRenderEvent& e) {
			MST_CORE_INFO("AppRenderEvent");
			return true;
		});
		dispatcher.Dispatch<MouseButtonPressedEvent>([this](MouseButtonPressedEvent& e) {
			MST_CORE_INFO("MouseButtonPressedEvent: {0}", e.GetMouseButton());
			return true;
		});
		dispatcher.Dispatch<MouseButtonReleasedEvent>([this](MouseButtonReleasedEvent& e) {
			MST_CORE_INFO("MouseButtonReleasedEvent: {0}", e.GetMouseButton());
			return true;
		});
		dispatcher.Dispatch<MouseMovedEvent>([this](MouseMovedEvent& e) {
			MST_CORE_INFO("MouseMovedEvent: {0}, {1}", e.GetX(), e.GetY());
			return true;
		});
		dispatcher.Dispatch<MouseScrolledEvent>([this](MouseScrolledEvent& e) {
			MST_CORE_INFO("MouseScrolledEvent: {0}, {1}", e.GetXOffset(), e.GetYOffset());
			return true;
		});
		dispatcher.Dispatch<KeyPressedEvent>([this](KeyPressedEvent& e) {
			if (e.IsRepeated())
				MST_CORE_INFO("KeyPressedEvent: {0} (repeated)", e.GetKeyCode());
			else
				MST_CORE_INFO("KeyPressedEvent: {0}", e.GetKeyCode());
			return true;
		});
		dispatcher.Dispatch<KeyReleasedEvent>([this](KeyReleasedEvent& e) {
			MST_CORE_INFO("KeyReleasedEvent: {0}", e.GetKeyCode());
			return true;
		});
		dispatcher.Dispatch<KeyTypedEvent>([this](KeyTypedEvent& e) {
			MST_CORE_INFO("KeyTypedEvent: {0}", e.GetKeyCode());
			return true;
		});
	}

	void Application::Run()
	{
		while (running) {
			window->OnUpdate();
		}
	}
}