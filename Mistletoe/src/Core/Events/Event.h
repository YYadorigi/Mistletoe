#pragma once
#include "Core/Core.h"

namespace Mistletoe
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus,
		AppTick, AppUpdate, AppRender,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		KeyPressed, KeyReleased, KeyTyped,
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
		virtual std::string GetName() const = 0;
		inline bool IsInCategory(EventCategory category) const
		{
			return GetCategoryFlags() & static_cast<int>(category);
		}
		inline virtual std::string ToString() const { return GetName(); } // For debug only
	protected:
		bool handled = false;
	};

	class EventDispatcher
	{
		template<typename T> using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event);
		template<typename T> bool Dispatch(EventFn<T> func)
		{
			if (event.GetType() == T::GetStaticType()) {
				event.handled = func(*(T*)&event);
				return true;
			}
			return false;
		};
	private:
		Event& event;
	};
}