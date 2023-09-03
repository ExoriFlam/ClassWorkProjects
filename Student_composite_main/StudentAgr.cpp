#include "StudentAgr.h"
#include "ListTwoTemplate.h"

StudentAgr::StudentAgr()
{
	surname = "no surname";
	name = "no name";
	this->age = 0;
	vuz = "no vuz";
	marks = 0u;

}

StudentAgr::StudentAgr(const MyString& surname, const MyString& name, int age, const MyString& vuz, const MyArray& marks, const ListTwoTemplate<MyString>& subjects)
{
	this->surname = surname;
	this->name = name;
	this->age = age;
	this->vuz = vuz;
	this->marks = marks;
	this->subjects = subjects;
}

bool StudentAgr::operator<(const StudentAgr& other)
{
	return surname < other.surname;
}

double StudentAgr::get_avg()
{
	return this->marks.get_avg();
}

void StudentAgr::add_subject(const MyString& data)
{
	this->subjects.push_back(data);
}

void StudentAgr::save_txt(FILE* f) const
{
	
	fprintf(f, "Surname: %s\n", surname);
	fprintf(f, "Name: %s\n", name);
	fprintf(f, "Age: %d\n", age);
	int i = 0;
	fprintf(f, "Subjects: ");
	while (i < subjects.get_count())
	{
		fprintf(f, "%s\n", (char*)subjects.get_by_pos(i++));
		
	}
	
	fprintf(f, "Vuz: %s\n", vuz);
	fprintf(f, "Marks: ");
	for (int i = 0; i < this->marks.get_size(); i++)
	{
		fprintf(f, "%d ", this->marks[i]);
	}
	
}

void StudentAgr::save_to_bin_file(FILE* file) const
{
	surname.save_to_bin_file(file);
	name.save_to_bin_file(file);
	fwrite(&this->age, sizeof(this->age), 1, file);
	vuz.save_to_bin_file(file);
	marks.save_to_bin_file(file);
	subjects.save_to_bin_file(file);

	/*MyString tmp;
	int subj_count = subjects.get_count();
	fwrite(&subj_count, sizeof(subj_count), 1, file);

	for (int i = 0; i < subjects.get_count(); i++)
	{
		(tmp = subjects[i]).save_to_bin_file(file);
	}*/
	
}

void StudentAgr::read_from_bin_file(FILE* file)
{
	
	surname.read_from_bin_file(file);
	name.read_from_bin_file(file);
	fread(&this->age, sizeof(age), 1, file);
	vuz.read_from_bin_file(file);
	marks.read_from_bin_file(file);
	subjects.read_from_bin_file(file);

	/*MyString tmp;
	subjects.clear();
	int cnt{};
	fread(&cnt, sizeof(int), 1, file);

	while (cnt != subjects.get_count())
	{
		tmp.read_from_bin_file(file);
		subjects.push_back(tmp);
	}*/
	
}





ostream& operator<<(ostream& out, const StudentAgr& obj)
{
	out <<"\nФамилия:  " << obj.surname << endl;
	out <<"\nИмя:      " << obj.name << endl;
	out <<"\nВозраст:  " << obj.age << endl;
	out <<"\nВуз:      " << obj.vuz << endl;
	if (obj.marks.get_size())
	{
		out << "\nОценки:   " << obj.marks << endl;
		out << "\nСредний бал: " << obj.marks.get_avg();
	}
	else
	{
		out << "\nОценок нет.";
	}
	out <<"\nПредметы  "<<obj.subjects << endl;
	
	return out;
}
