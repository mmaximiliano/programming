#include <bits/stdc++.h>

using namespace std;

//-----------------Data-Structure------------------------//

class Vector{

private:
	double* elem;
	int size;
	double* last

public:
	Vector(): elem {double[]}, size {0}, last {elem}

	Vector(int sz) :elem {new double[sz]}, size {sz}
	{
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = 0;
		}
	}
	~Vector() {delete[] elem};

	int size() const{
		return size;
	}

	double& operator[](int i){
		return elem[i];
	}

	bool isEmpty(){
		return sz == 0;
	}

	void push(double item){

	}
	
};


//---------------------main-------------------------//

int main() {


	return 0;
}















