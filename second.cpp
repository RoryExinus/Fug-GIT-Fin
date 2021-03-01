#include<iostream>
#include<string>
#include<vector>
#include<memory>    


class Animal {

	std::string type;
	std::string name;
public:
	Animal(std::string c_name, std::string c_type) {

		this->name = c_name;
		this->type = c_type;
	}
	~Animal() {};

	friend std::ostream& operator<< (std::ostream& out, const Animal& anml);
};

class Zoo {

	std::vector <Animal> anml_list;

public:
	Zoo(Animal c_anml) {

		anml_list.push_back(c_anml);
	}

	Zoo(std::vector <Animal> c_anml_list) {
		auto iter = anml_list.end();
		anml_list.insert(iter, c_anml_list.begin(), c_anml_list.end());
	}

	void remove_anml(int index) {

		std::vector<Animal>::iterator iter = anml_list.begin() + index;
		anml_list.erase(iter);
	}

	void add_anml(Animal anml) {

		anml_list.push_back(anml);
	}

	~Zoo() {};

	friend std::ostream& operator<< (std::ostream& out, const Zoo& r_zoo);

	Animal& operator [](int indx) {
		return anml_list[indx];
	}
};



std::ostream& operator << (std::ostream& out, const Zoo& r_zoo)
{
	for (int i = 0; i < r_zoo.anml_list.size(); i++)
	{
		out << "[" << i << "] " << r_zoo.anml_list[i];
	}
	out << std::endl;

	return out;
}

std::ostream& operator<< (std::ostream& out, const Animal& anml)
{
	out << "Name: " << anml.name << "\tType: " << anml.type << std::endl;

	return out;
}

int main() {

	std::vector <Animal> stc_animal = { {"Bob", "Lion"}, {"Messy", "Tiger"}, {"Gerry", "Monkey"},{"Janna" , "Parrot"} };
	Zoo rivne_zoo(stc_animal);
	std::cout << rivne_zoo;

	rivne_zoo.add_anml({ "Polka", "Rabbit" });
	std::cout << rivne_zoo;

	rivne_zoo.remove_anml(1);
	std::cout << rivne_zoo;


}