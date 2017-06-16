#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
	
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	// read and store all the students data.
	// Invariant: students contains all the student records read so far
	//  maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		cin >> record.name;
		students.push_back(record);
	}
	
	sort(students.begin(), students.end(), compare);
	
	for (int i = 0; i < students.size(); i++) {
		
		// write the names and the grades
		
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		
		// calculate grades
		try {
			double final_grade = grade(students[i]);
			cout << final_grade << endl;
			
		} catch (domain_error e) {
			cout << e.what();
		}
		
	}
}
