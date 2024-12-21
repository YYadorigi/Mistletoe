#pragma once
#include <sstream>
#include "Event.h"

namespace Mistletoe
{
	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return buttonCode; }
		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int buttonCode) : buttonCode(buttonCode) {}
		int buttonCode;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int buttonCode) : MouseButtonEvent(buttonCode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << buttonCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int buttonCode) : MouseButtonEvent(buttonCode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << buttonCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : x(x), y(y) {}
		inline float GetX() const { return x; }
		inline float GetY() const { return y; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << x << ", " << y;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved) EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float x, y;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset) {}
		inline float GetXOffset() const { return xOffset; }
		inline float GetYOffset() const { return yOffset; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled) EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float xOffset, yOffset;
	};
}