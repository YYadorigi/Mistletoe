#pragma once
#include <string>
#include <functional>
#include "Core/Core.h"

namespace Mistletoe
{
	template<typename T> using EventFn = std::function<bool(T&)>;
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus,
		AppTick, AppUpdate, AppRender,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		KeyPressed, KeyReleased,
	};
	enum class EventCategory
	{
		None = 0,
		Application = BIT(0),
		Input = BIT(1),
		Mouse = BIT(2),
		MouseButton = BIT(3),
		Keyboard = BIT(4),
	};

	class Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		inline bool IsInCategory(EventCategory category) const
		{
			return GetCategoryFlags() & static_cast<int>(category);
		}
		inline bool IsHandled() const { return handled; }
		virtual std::string ToString() const = 0; // For debugging
	protected:
		bool handled = false;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event);
		template<typename T> bool Dispatch(EventFn<T>& func)
		{
			if (event.GetType() == T::GetStaticType()) {
				event.handled = func(*dynamic_cast<T*>(&event));
				return true;
			}
			return false;
		};
		template<typename T> bool Dispatch(EventFn<T>&& func)
		{
			if (event.GetType() == T::GetStaticType()) {
				event.handled = func(*dynamic_cast<T*>(&event));
				return true;
			}
			return false;
		};
	private:
		Event& event;
	};
}