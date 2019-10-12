#pragma once

template<class T>
class Equal_t {
public:
	Equal_t(const T& value)
		:m_value(value){};

	bool operator()(const T* value) const { return *value == m_value; };

private:
	T m_value;
};

