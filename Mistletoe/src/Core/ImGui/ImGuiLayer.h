#pragma once
#include "Core/Layers/Layer.h"

namespace Mistletoe
{
	class ImGuiLayer : Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override;

		ImGuiLayer(const ImGuiLayer&) = default;
		ImGuiLayer& operator=(const ImGuiLayer&) = default;
		ImGuiLayer(ImGuiLayer&&) = default;
		ImGuiLayer& operator=(ImGuiLayer&&) = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;
	protected:

	};
}

