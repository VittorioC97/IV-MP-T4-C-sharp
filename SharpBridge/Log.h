#pragma once
namespace SharpBridge
{
	public ref class Log abstract sealed
	{
	public:
		static void Write(System::String^ line);
	};
}
