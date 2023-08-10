#include "My_Array.h"
#include <iostream>
#include <ctime>
using namespace std;


MyArray::MyArray() : size{5u},arr { new int[size] {} } {}


MyArray::MyArray(int size, int init_val) : size{ static_cast<unsigned int>(size) }, arr{ new int[this->size]}
{
	for (unsigned int i = 0; i < this->size; i++)
		arr[i] = init_val;
}

MyArray::MyArray(int other_size, int* other_arr) : size{ static_cast<unsigned int>(other_size) }, arr{ new int[other_size] }
{
	if (arr)
	{
		for (int i = 0; i < other_size; i++)
		{
			arr[i] = other_arr[i];
		}
	}
	else
	{
		cout << "\nПамять не выделена";
		arr = nullptr;
		size = 0u;
	}
	
}

MyArray::MyArray(const MyArray& other) : size{other.size}, arr {new int[other.size]}
{
	if (arr)
	{
		for (unsigned int i = 0; i < other.size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	else
	{
		cout << "\nПамять не выделена";
		arr = nullptr;
		size = 0U;
	}
	
}

MyArray::MyArray(int other_size, int range_begin, int range_end) : size{ static_cast<unsigned int>(other_size) }, arr{ new int[other_size] }
{
	srand(time(nullptr));

	if (arr)
	{
		for (int i = 0; i < other_size; i++)
		{
	
			arr[i] = (rand() % (range_end - range_begin + 1)) + range_begin;
					 
		}

	}
	else
	{
		cout << "\nПамять не выделена";
		arr = nullptr;
		size = 0u;
	}


}

MyArray& MyArray::operator=(const MyArray& other)
{
	if (this == &other) return *this;
	if (this->size != other.size)
	{
		delete[]this->arr;
		this->arr = new int[other.size];
		this->size = other.size;
	}
	if (arr)
	{
		for (unsigned int i = 0; i < other.size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	else
	{
		cout << "\nПамять не выделена";
		arr = nullptr;
		size = 0U;
	}

}

int& MyArray::operator[](const int index)
{
	if (index < 0 || index > size) exit(1);
	return arr[index];
}

const int MyArray::operator[](const int index) const
{
	if (index < 0 || index > size) exit(1);
	return arr[index];
}

MyArray MyArray::operator+(const MyArray& other)const
{
	 
	unsigned int total_size{ this->size + other.size };
	MyArray temp(total_size, 0);
	
	for (unsigned int i = 0; i < temp.get_size(); i++)
	{
		if (i < this->size)
		{
			temp[i] = this->arr[i];
		}
		else
		{
			temp[i] = other.arr[i - this->size];
		}
	}

	return temp;
}

MyArray MyArray::operator+(const int val) const
{
	MyArray temp(this->size + val, 0);
	for (unsigned int i = 0; i < this->size; i++)
	{
		temp.arr[i] = this->arr[i];
	}

	return temp;
}

MyArray& MyArray::operator+=(int val)
{
	int* source_ptr = this->arr;
	this->arr = new int[this->size + static_cast<unsigned int>(val)] {};
	if (arr)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			arr[i] = source_ptr[i];
		}
		this->size += val;
		
		
	}
	else
	{
		cout << "\nПамять не выделена.";
		size = 0u;
	}

	delete[]source_ptr;
	source_ptr = nullptr;
	
	
	return *this;
}

MyArray& MyArray::operator+=(MyArray& other)
{
	MyArray temp(this->size + other.size,0);
	for (unsigned int i = 0; i < temp.size; i++)
	{
		if (i < this->size)
		{
			temp.arr[i] = this->arr[i];
		}
		else
		{
			temp.arr[i] = other.arr[i - this->size];
		}
	}
	*this = temp;
	return *this;
}

MyArray operator+(int val, const MyArray& other)
{
	if (val < 0) val *= -1;
	MyArray temp(other.size + val, 0);
	for (unsigned int i = static_cast<unsigned int>(val); i < temp.size; i++)
	{
		temp.arr[i] = other.arr[i - static_cast<unsigned int>(val)];
	}

	return temp;
}

ostream& operator<<(ostream& out, const MyArray& obj)
{
	for (unsigned int i = 0; i < obj.get_size(); i++)
	{
		out << obj[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, MyArray& obj)
{
	int tmp_input;

	cout << "\n Введите длину массива : ";
	in >> tmp_input;


	while (in.fail())							
	{
		cout << "\nДля ввода допустимы только цифры!";
		in.clear();								
		in.ignore(256, '\n');					
		in >> tmp_input;
	}


	obj.size = tmp_input >= 0 ? static_cast<unsigned int>(tmp_input) : 0;
	if (obj.arr)
	{
		delete[]obj.arr;
	}

	obj.arr = new int[obj.size] {};

	if (obj.arr)
	{
		cout << "\nВведите значения : ";
		for (unsigned int i = 0; i < obj.size; i++)
		{

			in >> obj.arr[i];

			while (in.fail())
			{
				cout << "\nДля ввода допустимы только цифры!!";
				in.clear();
				in.ignore(256, '\n');
				in >> obj.arr[i];
			}

		}

	}
	else
	{
		"\nПамять не выделена";
		obj.arr = nullptr;
		obj.size = 0u;
	}
	

	return in;
}



unsigned int MyArray::get_size()const
{
	return size;
}

int MyArray::get_avg()const
{
	int sum = 0;
	unsigned int temp_size = size;
	for (unsigned int i = 0; i < this->size; i++)
	{
		sum += arr[i];
	}
	temp_size = temp_size == 0 ? 1 : temp_size;
	return sum / static_cast<int>(temp_size);
}

void MyArray::push_back(int val)
{
	unsigned int new_size = this->size + 1u;
	int* temp_arr = new int[this->size];
	if (temp_arr)
	{
		for (unsigned int i = 0; i < this->size; i++)
		{
			temp_arr[i] = arr[i];
		}
		
		

		if (arr) delete[]arr;

		arr = new int[new_size];

		if (arr)
		{
			this->size = new_size;

			for (unsigned int i = 0; i < this->size; i++)
			{
				arr[i] = temp_arr[i];
			}
			arr[this->size - 1] = val;
		}
		else
		{
			cout << "\nПамять не выделена";
			arr = nullptr;
			size = 0u;
		}
		
	}
	else
	{
		cout << "\nПамять не выделена";
		temp_arr = nullptr;
		
	}

	if (temp_arr)
	{
		delete[]temp_arr;
		temp_arr = nullptr;
	}

}






MyArray::~MyArray()
{
	if (arr)
	{
		delete[]arr;
		arr = nullptr;
	}
	
}


