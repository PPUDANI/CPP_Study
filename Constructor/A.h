#pragma once

class A
{
public:
	// Constructor Destructor
	A();
	~A();

	// Delete Function
	A(const A& _Other) = delete;
	A(A&& _Other) noexcept = delete;
	A& operator=(const A& _Other) = delete;
	A& operator=(A&& _Other) noexcept = delete;

protected:

private:

};