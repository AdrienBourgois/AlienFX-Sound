#include "stdafx.h"
#include "Ease.h"

EaseManager::EaseManager()
{
	chrono = new Chrono;
	chrono->set_time_point();
	oldTime = chrono->get_time_from_start();
}

EaseManager::~EaseManager()
{
	delete chrono;
	chrono = nullptr;
}

auto EaseManager::_update() -> void
{
    this->_updateDeltaTime();

    for (unsigned int i = 0; i < this->listEase.size(); ++i)
        this->listEase[i]->_update(this->deltaTime);
}

auto EaseManager::_erase(unsigned int id) -> void
{
    this->listEase.erase(this->listEase.begin() + id);
}

auto EaseManager::_play(unsigned int id) -> void
{
    this->listEase[id]->_play();
}

auto EaseManager::_pause(unsigned int id) -> void
{
    this->listEase[id]->_pause();
}

auto EaseManager::_rewind(unsigned int id) -> void
{
    this->listEase[id]->_rewind();
}

auto EaseManager::_inverse(unsigned int id) -> void
{
    this->listEase[id]->_inverse();
}

auto EaseManager::_updateDeltaTime() -> void
{
    if (this->oldTime == 0)
    {
		this->oldTime = chrono->get_time_from_start();
        return;
    }

    __int64 currentTime = chrono->get_time_from_start();
    this->deltaTime = currentTime - this->oldTime;
    this->oldTime = currentTime;
}

auto IEase::_update(__int64 deltaTime) -> void
{
    (void)deltaTime;
}