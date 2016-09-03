#pragma once

#include "stdafx.h"
#include "Chrono.h"

enum easeState
{
	PAUSE = 0,
	PLAY = 1,
	REWIND = -1
};

class IEase
{
	public:
		IEase() = default;
		virtual ~IEase() = default;

		virtual auto _update(__int64) -> void = 0;
		virtual auto _play() -> void = 0;
		virtual auto _pause() -> void = 0;
		virtual auto _rewind() -> void = 0;
		virtual auto _inverse() -> void = 0;
};

template <typename T>
class Ease
:public IEase
{
	public:
		Ease() = delete;
		
	Ease(T min, T max, double time, T* adress)
	{
		this->min = min;
		this->max = max;
		this->time = time;
		this->adress = adress;

		*(this->adress) = this->min;

		this->value = *(this->adress);

		if (min < max)
			this->state = easeState::PLAY;
		else if (min == max)
			this->state = easeState::PAUSE;
		else
			this->state = easeState::REWIND;
	}
	~Ease() = default;

	auto _update(__int64 deltaTime) -> void
	{
		if ((state == easeState::PLAY && this->value >= max) || (state == easeState::REWIND && this->value <= max))
		{
			//std::cout << "Value : " << this->value << " - Min : " << (unsigned int)this->min << " - State : " << this->state << std::endl;
			//std::cout << "Return !" << std::endl;
			return;
		}

		if (this->min < this->max)
			this->unit = (this->max - this->min) / this->time / 1000;
		else if (this->min > this->max)
			this->unit = (this->min - this->max) / this->time / 1000;

		//std::cout << "Tmp : " << this->unit * deltaTime * this->state << std::endl;
		this->value += this->unit * deltaTime * this->state;
		//std::cout << "Value : " << this->value << " - Unit : " << this->unit << " - Delta : " << deltaTime << std::endl;

		*(this->adress) = static_cast<T>(this->value);
	}

	auto _pause() -> void
	{
		this->state = easeState::PAUSE;
	}

	auto _inverse() -> void
	{
		if (this->state == easeState::PLAY)
			this->state = easeState::REWIND;
		if (this->state == easeState::REWIND)
			this->state = easeState::PLAY;
	}

	auto _play() -> void
	{
		this->state = easeState::PLAY;
	}

	auto _rewind() -> void
	{
		this->state = easeState::REWIND;
	}

	private:
		T min;
		T max;
		double value;
		double time;
		T* adress;
		int state;
		double unit = 0;

};

class EaseManager 
{
	public:
		EaseManager();
		~EaseManager();

		EaseManager(EaseManager const&) = delete;
		EaseManager(EaseManager &&) = delete;
		auto operator=(EaseManager const&) -> EaseManager = delete;
		auto operator=(EaseManager &&) -> EaseManager = delete;

		auto _update() -> void;
		auto _updateDeltaTime() -> void;

		auto _play(unsigned int) -> void;
		auto _pause(unsigned int) -> void;
		auto _rewind(unsigned int) -> void;
		auto _inverse(unsigned int) -> void;

		template <typename T>
		auto _add(T min, T max, double time, T* adress) -> unsigned int
		{
			listEase.push_back(new Ease<T>(min, max, time, adress));
			return (int)listEase.size() - 1;
		}

		auto _erase(unsigned int) -> void;

	private:
		Chrono* chrono;
		std::vector<IEase*> listEase;
		__int64 oldTime = 0;
		__int64 deltaTime;
};
