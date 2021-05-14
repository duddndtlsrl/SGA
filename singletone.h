#pragma once

template <typename T>
class singletone
{
protected:
	static T* _singletone;

	singletone() {}
	~singletone() {}

public:
	static T* getSingletone();
	void releaseSingletone();
};

template <typename T>
T* singletone<T> ::_singletone = 0;

template<typename T>
T* singletone<T> ::getSingletone()
{
	if (!_singletone)
	{
		_singletone = new T;
	}

	return _singletone;
}

template <typename T>
void singletone<T>::releaseSingletone()
{
	if (_singletone)
	{
		delete _singletone;
		_singletone = 0;
	}
}
