#include <queue>

// C++ std::priority_queue is default to be max_heap. 

// to construct min heap you can use. std::greater;
// for example, if we want to create a min heap of ints.
std::priority_queue<int, std::vector<int>, std::greater<int>> pq(std::greater);

