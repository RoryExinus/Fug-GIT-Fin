#include<iostream>
#include<memory>    

class Vector {
	int x, y;

public:
	Vector(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Vector operator - (Vector a_vec) {
		Vector tmp_vec(this->x - a_vec.x, this->y - a_vec.y);
		return tmp_vec;
	}

	Vector operator + (Vector a_vec) {
		Vector tmp_vec(this->x + a_vec.x, this->y + a_vec.y);
		return tmp_vec;
	}
	friend std::ostream& operator << (std::ostream& out, const Vector& t_vec);
};


std::ostream& operator << (std::ostream& out, const Vector& t_vec) {

	out << "(" << t_vec.x << ";" << t_vec.y << ")" << std::endl;

	return out;
};

int main() {
	Vector f_vec(10, 5);
	Vector s_vec(2, 8);

	std::cout << "First vector: " << f_vec << std::endl;
	std::cout << "Second vector: " << s_vec << std::endl;
	std::cout << std::endl;
	std::cout << " + \t" << f_vec + s_vec;
	std::cout << " - \t" << f_vec - s_vec;

}