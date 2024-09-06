#pragma once




class Timer
{
	static Timer Time_Inst;

	void ExecutionTime(void(*pred)(), Args args, ...);

private:
	Timer() {}
};

