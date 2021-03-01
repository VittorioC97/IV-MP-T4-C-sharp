#pragma once

namespace SharpBridge
{
	namespace Timer
	{
		public ref class TimerParams
		{
		public:
			System::Collections::Generic::List<Object^>^ params = gcnew System::Collections::Generic::List<Object^>();
		};

		public delegate void TimerFunc(TimerParams^ params);

		ref class TimerData
		{
		public:
			unsigned int interval;
			unsigned int repetitions;
			TimerParams^ params;
			TimerFunc^ func;
			unsigned countReps;
			long lastPulse;

			TimerData(){}
		};

		public ref class Manager abstract sealed
		{
		private:
			static System::Collections::Generic::Dictionary<unsigned int, TimerData^>^ timers =
				gcnew System::Collections::Generic::Dictionary<unsigned int, TimerData^>();
		public:
			static unsigned int RegisterTimer(TimerFunc^ func, unsigned int interval, unsigned int repetitions, TimerParams^ params);
			static void DeleteTimer(unsigned int id);
			static void Pulse(long ms);
		};
	}
}

