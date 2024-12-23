#include "mstpch.h"
#include "Layer.h"

namespace Mistletoe
{
	Layer::Layer(const std::string& name) : layerName(name) {}

	Layer::~Layer() = default;

	Layer::Layer(const Layer&) = default;

	Layer& Layer::operator=(const Layer&) = default;

	Layer::Layer(Layer&&) = default;

	Layer& Layer::operator=(Layer&&) = default;
}
