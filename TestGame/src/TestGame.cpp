#include <memory>
#include "Mistletoe.h"

class TestGame : public Mistletoe::Application
{
public:
	TestGame()
	{

	}

	~TestGame() override
	{

	}

	void Run() override
	{
		printf("Stop!\n");
	}
};

std::shared_ptr<Mistletoe::Application> Mistletoe::CreateApplication()
{
	return std::make_shared<TestGame>();
}
