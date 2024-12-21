#pragma once
#include <string>
#include <functional>
#include "Core/Core.h"

namespace Mistletoe
{
	// Events in Mistletoe are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there. For the
	// future, a better strategy might be to buffer events in an event bus and process
	// them during the "event" part of the update stage.
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		KeyPressed, KeyReleased, KeyTyped,
	};
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryMouse = BIT(2),
		EventCategoryMouseButton = BIT(3),
		EventCategoryKeyboard = BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; } \
								virtual EventType GetEventType() const override { return EventType::##type; } \
								virtual const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlags() const override { return static_cast<int>(category); }

	class Event
	{
	public:
		Event() = default;
		~Event() = default;
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		inline bool IsInCategory(EventCategory category) const
		{
			return GetEventCategoryFlags() & static_cast<int>(category);
		}
		virtual std::string ToString() const { return GetName(); } // For debug only
	protected:
		bool handled = false;
	private:
		friend class EventDispatcher;
	};

	class EventDispatcher
	{
		template<typename T> using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : event(event) {}
		template<typename T> bool Dispatch(EventFn<T> func)
		{
			if (event.GetEventType() == T::GetStaticType()) {
				event.handled = func(*(T*)&event);
				return true;
			}
			return false;
		}
	private:
		Event& event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}