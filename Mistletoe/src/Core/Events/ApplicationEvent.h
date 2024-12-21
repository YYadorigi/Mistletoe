#pragma once
#include <sstream>
#include "Event.h"

namespace Mistletoe
{
	class WindowCloseEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowClose) EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) {}
		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize) EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int width, height;
	};

	class WindowFocusEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowFocus) EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowLostFocus) EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowMovedEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowMoved) EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppTickEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(AppTick) EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppUpdateEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(AppUpdate) EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppRenderEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(AppRender) EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}