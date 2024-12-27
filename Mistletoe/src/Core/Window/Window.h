#pragma once
#include "Core/Events/Event.h"

namespace Mistletoe
{
	typedef std::function<void(Event&)> EventCallbackFn;
	struct WindowProps
	{
		std::string title;
		unsigned int width;
		unsigned int height;
		WindowProps();
		WindowProps(const std::string& title, unsigned int width, unsigned int height);
	};
	struct WindowData
	{
		WindowProps props;
		bool vSync;
		EventCallbackFn eventCallback;
		WindowData(const WindowProps& props);
	};

	// Interface representing a desktop system based Window
	// This is a pure virtual class independent of the platform
	class Window
	{
	public:
		Window(const WindowProps& props = WindowProps());
		virtual ~Window();

		virtual void OnUpdate() = 0;

		inline const std::string& GetTitle() const { return data.props.title; }
		inline unsigned int GetWidth() const { return data.props.width; }
		inline unsigned int GetHeight() const { return data.props.height; }

		virtual void SetVSync(bool enabled) = 0;
		inline bool GetVSync() const { return data.vSync; }

		inline void SetEventCallback(const EventCallbackFn& callback) { data.eventCallback = callback; }
	protected:
		Window(const Window&);
		Window& operator=(const Window&);
		Window(Window&&);
		Window& operator=(Window&&);
	protected:
		WindowData data;
	};
}
