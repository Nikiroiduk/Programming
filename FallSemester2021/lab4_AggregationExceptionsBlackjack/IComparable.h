#pragma once

template <typename T>
class IComparable {
public:
	virtual ~IComparable() {};
	virtual bool operator==(const T& item) = 0;
};