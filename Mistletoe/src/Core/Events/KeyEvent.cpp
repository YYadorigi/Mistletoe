#pragma once
#include "mstpch.h"
#include "KeyEvent.h"

namespace Mistletoe
{
	int Mistletoe::KeyEvent::GetCategoryFlags() const
	{
		return static_cast<int>(EventCategory::Keyboard) | static_cast<int>(EventCategory::Input);
	}

	KeyEvent::KeyEvent(int keyCode) : keyCode(keyCode) {}

	KeyPressedEvent::KeyPressedEvent(int keyCode, bool repeated) :KeyEvent(keyCode), repeated(repeated) {}

	EventType KeyPressedEvent::GetStaticType()
	{
		return EventType::KeyPressed;
	}

	EventType KeyPressedEvent::GetType() const
	{
		return EventType::KeyPressed;
	}

	std::string KeyPressedEvent::GetName() const
	{
		return "KeyPressedEvent";
	}

	std::string KeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << keyCode << " (repeat = " << repeated << ")";
		return ss.str();
	}

	KeyReleasedEvent::KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

	EventType KeyReleasedEvent::GetStaticType()
	{
		return EventType::KeyReleased;
	}

	EventType KeyReleasedEvent::GetType() const
	{
		return EventType::KeyReleased;
	}

	std::string KeyReleasedEvent::GetName() const
	{
		return "KeyReleasedEvent";
	}

	std::string KeyReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << keyCode;
		return ss.str();
	}

	KeyTypedEvent::KeyTypedEvent(int keyCode) : KeyEvent(keyCode) {}

	EventType KeyTypedEvent::GetStaticType()
	{
		return EventType::KeyTyped;
	}

	EventType KeyTypedEvent::GetType() const
	{
		return EventType::KeyTyped;
	}

	std::string KeyTypedEvent::GetName() const
	{
		return "KeyTypedEvent";
	}

	std::string KeyTypedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << keyCode;
		return ss.str();
	}
}