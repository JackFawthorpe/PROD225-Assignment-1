#ifndef __TARRAY_H__
#define __TARRAY_H__

template <typename T>
class TArray
{
public:
	int numberOfItems;
	T* arrayPointer;
	int maxNumberOfItems;

	TArray()
		:numberOfItems(0)
		,arrayPointer(new T[5])
		,maxNumberOfItems(5)
	{

	}

	~TArray()
	{
		delete[] arrayPointer;
	}


	void addElement(T& newElement)
	{
		if (numberOfItems == maxNumberOfItems)
		{
			changeSize(5);
		}
		arrayPointer[numberOfItems] = newElement;
		numberOfItems++;
	}


	T getElement(int& index) const
	{
		return arrayPointer[index];
	}

	void removeElement(int index)
	{
		for (int i = index; i < numberOfItems - 1; i++)
		{
			arrayPointer[i] = arrayPointer[i + 1];
		}
		numberOfItems--;
		if (numberOfItems + 10 <= maxNumberOfItems)
		{
			changeSize(-5);
		}
	}

	bool isValidIndex(int& index)
	{
		return index >= 0 && index < numberOfItems;
	}

	bool contains(T& element)
	{
		for (int i = 0; i < numberOfItems; i++)
		{
			if (element == arrayPointer[i])
			{
				return true;
			}
		}

		return false;
	}

	int num() const
	{
		return numberOfItems;
	}

private:

	void changeSize(int change)
	{
		T* newArray = new T[maxNumberOfItems + change];

		maxNumberOfItems += change;

		for (int i = 0; i < numberOfItems; i++) {
			newArray[i] = arrayPointer[i];
		}

		delete[] arrayPointer;
		arrayPointer = newArray;
	}

};

#endif /*__TARRAY_H__*/