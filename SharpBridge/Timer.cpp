#include <time.h>
#include <vector>
#include "Timer.h"

unsigned int SharpBridge::Timer::Manager::RegisterTimer(TimerFunc^ func, unsigned int interval, unsigned int repetitions, TimerParams^ params)
{
	unsigned int id = 0;
	for each(System::Collections::Generic::KeyValuePair<unsigned int, TimerData^> i in timers)
	{
		if(id != i.Key)
		{
			id = i.Key;
			break;
		}
		id++;
	}

	TimerData^ t = gcnew TimerData();
	t->func = func;
	t->params = params;
	t->interval = interval;
	t->repetitions = repetitions;
	t->countReps = 0;
	t->lastPulse = clock() + interval;

	timers[id] = t;
	return id;
}

void SharpBridge::Timer::Manager::DeleteTimer(unsigned int id)
{
	if(timers->ContainsKey(id)) timers->Remove(id);
}

void SharpBridge::Timer::Manager::Pulse(long ms)
{
	std::vector<unsigned int> done;
	try
	{
		for each(System::Collections::Generic::KeyValuePair<unsigned int, TimerData^> i in timers)
		{
			if(ms > i.Value->lastPulse)
			{
				i.Value->lastPulse = ms + i.Value->interval;
				i.Value->func(i.Value->params);

				if(i.Value->repetitions == 0) continue;

				i.Value->countReps++;
				if(i.Value->countReps >= i.Value->repetitions)
				{
					done.push_back(i.Key);
					break;
				}
			}
		}

		size_t i = 0, s = done.size();
		for(i; i < s; i++)
		{
			timers->Remove(done[i]);
		}
	}
	catch(std::exception&)
	{

	}
}