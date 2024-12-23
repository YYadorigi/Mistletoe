#pragma once
#include "Event.h"

namespace Mistletoe
{
	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return buttonCode; }
		int GetCategoryFlags() const override;
	protected:
		MouseButtonEvent(int buttonCode);
		int buttonCode;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int buttonCode);
		static EventType GetStaticType();
		EventType GetType() const override;
		std::string ToString() const override;
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int buttonCode);
		static EventType GetStaticType();
		EventType GetType() const override;
		std::string ToString() const override;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xPos, float yPos);
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
		inline float GetX() const { return xPos; }
		inline float GetY() const { return yPos; }
	private:
		float xPos, yPos;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset);
		static EventType GetStaticType();
		EventType GetType() const override;
		int GetCategoryFlags() const override;
		std::string ToString() const override;
		inline float GetXOffset() const { return xOffset; }
		inline float GetYOffset() const { return yOffset; }
	private:
		float xOffset, yOffset;
	};
}