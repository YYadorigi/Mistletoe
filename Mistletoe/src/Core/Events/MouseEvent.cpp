#include "mstpch.h"
#include "MouseEvent.h"

namespace Mistletoe
{
	int Mistletoe::MouseButtonEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Mouse)
			| static_cast<int>(EventCategory::MouseButton)
			| static_cast<int>(EventCategory::Input);
	}

	Mistletoe::MouseButtonEvent::MouseButtonEvent(int buttonCode) : buttonCode(buttonCode) {}

	Mistletoe::MouseButtonPressedEvent::MouseButtonPressedEvent(int buttonCode) : MouseButtonEvent(buttonCode) {}

	EventType Mistletoe::MouseButtonPressedEvent::GetStaticType()
	{
		return EventType::MouseButtonPressed;
	}

	EventType Mistletoe::MouseButtonPressedEvent::GetType() const
	{
		return EventType::MouseButtonPressed;
	}

	std::string Mistletoe::MouseButtonPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << buttonCode;
		return ss.str();
	}

	Mistletoe::MouseButtonReleasedEvent::MouseButtonReleasedEvent(int buttonCode) : MouseButtonEvent(buttonCode)
	{}

	EventType Mistletoe::MouseButtonReleasedEvent::GetStaticType()
	{
		return EventType::MouseButtonReleased;
	}

	EventType Mistletoe::MouseButtonReleasedEvent::GetType() const
	{
		return EventType::MouseButtonReleased;
	}

	std::string Mistletoe::MouseButtonReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << buttonCode;
		return ss.str();
	}

	Mistletoe::MouseMovedEvent::MouseMovedEvent(float xPos, float yPos) : xPos(xPos), yPos(yPos) {}

	EventType Mistletoe::MouseMovedEvent::GetStaticType()
	{
		return EventType::MouseMoved;
	}

	EventType Mistletoe::MouseMovedEvent::GetType() const
	{
		return EventType::MouseMoved;
	}

	int Mistletoe::MouseMovedEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Mouse)
			| static_cast<int>(EventCategory::Input);
	}

	std::string Mistletoe::MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << xPos << ", " << yPos;
		return ss.str();
	}

	Mistletoe::MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset) {}

	EventType Mistletoe::MouseScrolledEvent::GetStaticType()
	{
		return EventType::MouseScrolled;
	}

	EventType Mistletoe::MouseScrolledEvent::GetType() const
	{
		return EventType::MouseScrolled;
	}

	int Mistletoe::MouseScrolledEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Mouse)
			| static_cast<int>(EventCategory::Input);
	}

	std::string Mistletoe::MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
		return ss.str();
	}
}

