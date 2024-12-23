#include "mstpch.h"
#include "ApplicationEvent.h"

namespace Mistletoe
{
	EventType WindowCloseEvent::GetStaticType()
	{
		return EventType::WindowClose;
	}

	EventType WindowCloseEvent::GetType() const
	{
		return EventType::WindowClose;
	}

	int WindowCloseEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Application);
	}

	std::string WindowCloseEvent::ToString() const
	{
		return "WindowCloseEvent";
	}

	WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) {}

	EventType WindowResizeEvent::GetStaticType()
	{
		return EventType::WindowResize;
	}

	EventType WindowResizeEvent::GetType() const
	{
		return EventType::WindowResize;
	}

	int WindowResizeEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Application);
	}

	std::string WindowResizeEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << width << ", " << height;
		return ss.str();
	}

	EventType WindowFocusEvent::GetStaticType()
	{
		return EventType::WindowFocus;
	}

	EventType WindowFocusEvent::GetType() const
	{
		return EventType::WindowFocus;
	}

	int WindowFocusEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Application);
	}

	std::string WindowFocusEvent::ToString() const
	{
		return "WindowFocusEvent";
	}

	EventType WindowLostFocusEvent::GetStaticType()
	{
		return EventType::WindowLostFocus;
	}

	EventType WindowLostFocusEvent::GetType() const
	{
		return EventType::WindowLostFocus;
	}

	int WindowLostFocusEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Application);
	}

	std::string WindowLostFocusEvent::ToString() const
	{
		return "WindowLostFocusEvent";
	}

	EventType AppTickEvent::GetStaticType()
	{
		return EventType::AppTick;
	}

	EventType AppTickEvent::GetType() const
	{
		return EventType::AppTick;
	}

	int AppTickEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Application);
	}

	std::string AppTickEvent::ToString() const
	{
		return "AppTickEvent";
	}

	EventType AppUpdateEvent::GetStaticType()
	{
		return EventType::AppUpdate;
	}

	EventType AppUpdateEvent::GetType() const
	{
		return EventType::AppUpdate;
	}

	int AppUpdateEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Application);
	}

	std::string AppUpdateEvent::ToString() const
	{
		return "AppUpdateEvent";
	}

	EventType AppRenderEvent::GetStaticType()
	{
		return EventType::AppRender;
	}

	EventType AppRenderEvent::GetType() const
	{
		return EventType::AppRender;
	}

	int AppRenderEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Application);
	}

	std::string AppRenderEvent::ToString() const
	{
		return "AppRenderEvent";
	}
}