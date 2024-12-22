#pragma once
#include "Core/Log/Log.h"
#include "Core/Events/Event.h"

namespace Mistletoe
{
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
		typedef std::function<void(Event&)> EventCallbackFn;
		EventCallbackFn eventCallback;
		WindowData();
		WindowData(const WindowProps& props);
	};

	// Interface representing a desktop system based Window
	// This is a pure virtual class independent of the platform
	class Window
	{
	public:
		Window();
		Window(const WindowData& data);
		virtual ~Window();

		virtual void OnUpdate() = 0;

		inline std::string GetTitle() const { return data.props.title; }
		inline unsigned int GetWidth() const { return data.props.width; }
		inline unsigned int GetHeight() const { return data.props.height; }

		inline virtual void SetVSync(bool enabled) { data.vSync = enabled; }
		inline bool GetVSync() const { return data.vSync; }

		inline virtual void SetEventCallback(const WindowData::EventCallbackFn& callback) { data.eventCallback = callback; }
	protected:
		WindowData data;
	};
}

