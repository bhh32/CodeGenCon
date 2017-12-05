#pragma once

template<typename T>
static auto AddRange(T start, T end)
{
	std::decay<decltype(*start)>::type total = 0;

	T iter = start;

	while (iter != end)
	{
		total += *iter; 
		++iter;
	}

	return total;
}