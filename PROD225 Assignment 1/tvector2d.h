#ifndef __TVECTOR2D_H__
#define __TVECTOR2D_H__

template<typename T>
class Vector2D
{
public:
	T x;
	T y;

	Vector2D<T>()
	{

	}

	Vector2D<T>(T start_x, T start_y)
	{
		x = start_x;
		y = start_y;
	}

	void SetVector(const T& new_x, const T& new_y)
	{
		x = new_x;
		y = new_y;
	}

	Vector2D<T> operator+(const Vector2D<T>& InVector)
	{
		Vector2D<T> newVector;
		newVector.x = x + InVector.x;
		newVector.y = y + InVector.y;
		
		return newVector;
	}

	Vector2D<T> operator*(const int value)
	{
		Vector2D<T> newVector;
		newVector.x = x * value;
		newVector.y = y * value;

		return newVector;
	}

	bool operator== (const Vector2D<T>& CompareVector)
	{
		return this->x == CompareVector.x && this->y == CompareVector.y;
	}

	bool operator!= (const Vector2D<T>& CompareVector)
	{
		return this->x != CompareVector.x || this->y != CompareVector.y;
	}

	Vector2D<T> operator+= (const Vector2D<T>& InVector)
	{
		this->x += InVector.x;
		this->y += InVector.y;
	
		return *this;
	}

	int distance(const Vector2D<T>& SecondVector)
	{
		return abs(this->x - SecondVector.x) + abs(this->y - SecondVector.y);
	}
};

#endif /*__TVECTOR2D_H__*/