#pragma once
#include <memory>
#include "Layer.h"

namespace Mistletoe
{
	class LayerStack
	{
	public:
		LayerStack();

		void PushLayer(const std::shared_ptr<Layer>& layer);
		void PushOverlay(const std::shared_ptr<Layer>& overlay);
		void PopLayer(const std::shared_ptr<Layer>& layer);
		void PopOverlay(const std::shared_ptr<Layer>& overlay);

		inline std::vector<std::shared_ptr<Layer>>::iterator begin() { return layers.begin(); }
		inline std::vector<std::shared_ptr<Layer>>::iterator end() { return layers.end(); }
		inline bool empty() const { return layers.empty(); }
	private:
		std::vector<std::shared_ptr<Layer>> layers;
		std::vector<std::shared_ptr<Layer>>::iterator layerInsert;
	};
}