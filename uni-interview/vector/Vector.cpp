#include <bits/stdc++.h>

using namespace std;

//-----------------Data-Structure------------------------//

class Vector{

private:
	double* elem;
	int size;
	int maxSize;

public:
	Vector(): elem {new double[16]}, size {0}, maxSize {16}
	{}

	Vector(int sz) :elem {new double[sz]}, size {sz}, maxSize {size}
	{
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = 0;
		}
	};

	~Vector() {delete[] elem;};

	int sz() const{
		return size;
	}

	double& operator[](int i){
		return elem[i];
	}

	bool isEmpty(){
		return size == 0;
	}

	void push(double item){
		elem[size] = item;
		size++;
	}
	
};


//---------------------main-------------------------//

int main() {


	return 0;
}















