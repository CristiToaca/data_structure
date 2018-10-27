#pragma once
#include <assert.h> 

namespace ct
{
namespace data_structure
{
	template <typename T>
	class DynamicArray
	{
	public:
		DynamicArray();
		~DynamicArray();

		//returns element at location i | O(1)
		T& Get(int i);

		//Sets element i to val | O(1)
		void Set(int i, T value);

		//Adds value to the end | O(n)
		void PushBack(T value);

		//delete element from the end | O(1)
		void PopBack();

		//Removes element at location i | O(n)
		void Remove(int i);

		//return the size of the array | O(1)
		int size() { return size_; }

		//return the capacity of the array | O(1)
		int capacity() { return capacity_; }

		bool empty() { return size_ > 0 ? false : true; }

	private:
		T* myArray_;
		int size_;
		int capacity_;
	};

	template <typename T>
	DynamicArray<T>::DynamicArray() : size_(0), capacity_(1)
	{
		myArray_ = new T[capacity_];
	}

	template <typename T>
	DynamicArray<T>::~DynamicArray()
	{
	}

	template <typename T>
	T& DynamicArray<T>::Get(int i)
	{
		assert(i >= 0 && i < size_);

		return myArray_[i];
	}

	template <typename T>
	void DynamicArray<T>::Set(int i, T value)
	{
		assert(i >= 0 && i < size_);

		myArray_[i] = value;
	}

	template <typename T>
	void DynamicArray<T>::PushBack(T value)
	{
		if (size_ == capacity_)
		{
			T* newArray = new T[2 * capacity_];
			for (int i = 0; i < size_; ++i)
				newArray[i] = myArray_[i];
			delete myArray_;
			myArray_ = newArray;
			capacity_ *= 2;
		}
		myArray_[size_] = value;
		++size_;
	}

	template <typename T>
	void DynamicArray<T>::PopBack()
	{
		if (!this->empty())
			myArray_[--size_].~T();

	}

	template <typename T>
	void DynamicArray<T>::Remove(int i)
	{
		assert(i >= 0 && i < size_);
		for (int j = i; j < size_ - 1; ++j)
			myArray_[j] = myArray_[j + 1];
		--size_;
	}

} // namespace data_structure
} // namespace ct