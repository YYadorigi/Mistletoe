#pragma once
#include "Event.h"

namespace Mistletoe
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode; }
		int GetCategoryFlags() const override;
	protected:
		KeyEvent(int keyCode);
		int keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, bool repeated);
		static EventType GetStaticType();
		EventType GetType() const override;
		std::string GetName() const override;
		std::string ToString() const override;
		inline bool IsRepeated() const { return repeated; }
	private:
		bool repeated;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode);
		static EventType GetStaticType();
		EventType GetType() const override;
		std::string GetName() const override;
		std::string ToString() const override;
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keyCode);
		static EventType GetStaticType();
		EventType GetType() const override;
		std::string GetName() const override;
		std::string ToString() const override;
	};
}