#pragma once
#include <vector>
#include <iostream>
#include <sstream>

namespace LearNN
{
	/**
	 * Just a wrapper for std::vector
	 */

	template <typename T>
	class Vector : public std::vector<T>
	{
		public:

		using std::vector<T>::vector;

		void PushBack(T element)
		{
			this->push_back(element);
		}

		size_t Size() const
		{
			return (this->size());
		}

		void Clear()
		{
			this->clear();
		}

		void Reserve(size_t size)
		{
			this->reserve(size);
		}

		void Print(bool multiline = false) const
		{
			std::cout << ToString(multiline) << std::endl;
		}

		std::string ToString(bool multiline = false) const
		{
			std::ostringstream out;
			out << "[ ";
			for (int i = 0; i < this->size(); ++i)
			{
				out << (*this)[i];
				if (multiline && i != this->size() - 1)
					out << std::endl;
				else if (!multiline && i != this->size() - 1)
					out << ", ";
			}
			out << " ]";
			return (out.str());
		}

		friend std::ostream& operator<<(std::ostream& out, Vector<T>& v)
		{
			out << v.ToString();
			return (out);
		}

	};

	typedef Vector<double> InputVector;
	typedef Vector<double> OutputVector;
	typedef Vector<double> NumericalVector;
} 
