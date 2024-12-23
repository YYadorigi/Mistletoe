#pragma once
#include "Event.h"

namespace Mistletoe
{
	class WindowCloseEvent : public Event
	{
	public:
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height);
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }
	private:
		unsigned int width, height;
	};

	class WindowFocusEvent : public Event
	{
	public:
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
	};

	class AppTickEvent : public Event
	{
	public:
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
	};

	class AppUpdateEvent : public Event
	{
	public:
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
	};

	class AppRenderEvent : public Event
	{
	public:
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
	};
}