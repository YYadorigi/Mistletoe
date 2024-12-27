#include "mstpch.h"
#include "ImGuiLayer.h"
#include "imgui.h"

namespace Mistletoe
{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{

	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;


	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{

	}

	void ImGuiLayer::OnEvent(Event& e)
	{

	}

}
