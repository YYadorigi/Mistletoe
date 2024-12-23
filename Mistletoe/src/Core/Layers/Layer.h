#pragma once
#include "Core/Events/Event.h"

namespace Mistletoe
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent(Event& e) = 0;

		inline const std::string& GetLayerName() const { return layerName; }
	protected:
		std::string layerName; // For debugging
	};
}


