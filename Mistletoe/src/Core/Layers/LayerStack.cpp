#include "mstpch.h"
#include "LayerStack.h"
#include "Core/Events/Event.h"
#include "Core/Events/ApplicationEvent.h"

namespace Mistletoe
{
	LayerStack::LayerStack()
	{
		layers = std::vector<std::shared_ptr<Layer>>();
		layerInsert = layers.begin();
	}

	void LayerStack::PushLayer(const std::shared_ptr<Layer>& layer)
	{
		layerInsert = layers.emplace(layerInsert, layer);
	}

	void LayerStack::PushLayer(std::shared_ptr<Layer>&& layer)
	{
		layerInsert = layers.emplace(layerInsert, layer);
	}

	void LayerStack::PushOverlay(const std::shared_ptr<Layer>& overlay)
	{
		layers.emplace_back(overlay);
	}

	void LayerStack::PushOverlay(std::shared_ptr<Layer>&& overlay)
	{
		layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(const std::shared_ptr<Layer>& layer)
	{
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end()) {
			layers.erase(it);
			if (layerInsert != layers.begin() && layerInsert != layers.end()) {
				layerInsert--;
			}
		}
	}

	void LayerStack::PopOverlay(const std::shared_ptr<Layer>& overlay)
	{
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if (it != layers.end()) {
			layers.erase(it);
		}
	}
}


