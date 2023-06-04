	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;
	
	class User {
	private:
	    string username;
	    string password;
	
	public:
	    User(const string& username, const string& password)
	        : username(username), password(password) {}
	
	    string getUsername() const {
	        return username;
	    }
	
	    string getPassword() const {
	        return password;
	    }
	};
	
	class Person {
	private:
	    string FirstName;
	    string LastName;
	    int age;
	    int ID;
	
	public:
	    Person(string FirstName, string LastName, int age, int ID) {
	        setFirstName(FirstName);
	        setLastName(LastName);
	        setAge(age);
	        setID(ID);
	    }
	
	    void setFirstName(string Fname) {
	        FirstName = Fname;
	    }
	    void setLastName(string Lname) {
	        LastName = Lname;
	    }
	    void setAge(int age) {
	        this->age = age;
	    }
	    void setID(int id) {
	        ID = id;
	    }
	
	    string getFirstName() const {
	        return FirstName;
	    }
	    string getLastName() const {
	        return LastName;
	    }
	    int getAge() const {
	        return age;
	    }
	    int getID() const {
	        return ID;
	    }
	    virtual void Print() const = 0;
	};
	
	class Date_Time {
	private:
	    int day, month, year;
	    int hour, min, sec;
	
	public:
	    Date_Time(int month, int day, int year, int hour, int min, int sec) {
	        setDate(month, day, year);
	        setTime(hour, min, sec);
	    }
	
	    void setDate(int month, int day, int year) {
	        if (month > 0 && month <= 12) {
	            this->month = month;
	        }
	        else {
	            cout << "x...........Invalid Input!...........x" << endl;
	            month = 0;
	        }
	        if (day > 0 && day <= 31) {
	            this->day = day;
	        }
	        else {
	            cout << "x...........Invalid Input!...........x" << endl;
	            day = 0;
	        }
	        if (year > 0) {
	            this->year = year;
	        }
	        else {
	            cout << "x...........Invalid Input...........x" << endl;
	            year = 0;
	        }
	    }
	    void setTime(int hour, int min, int sec) {
	        if (hour >= 0 && hour < 23) {
	            this->hour = hour;
	        }
	        else {
	            cout << "\nx...........Invalid input For Hour!............x\n" << endl;
	            hour = 0;
	        }
	        if (min >= 0 && min < 60) {
	            this->min = min;
	        }
	        else {
	            cout << "\nx...........Invalid input For Minute!...........x\n" << endl;
	            min = 0;
	        }
	        if (sec >= 0 && sec < 60) {
	            this->sec = sec;
	        }
	        else {
	            cout << "\nx...........Invalid input For Seconds...........x\n" << endl;
	            sec = 0;
	        }
	    }
	
	    int getMonth() const {
	        return month;
	    }
	    int getDay() const {
	        return day;
	    }
	    int getYear() const {
	        return year;
	    }
	    int getHour() const {
	        return hour;
	    }
	    int getMinute() const {
	        return min;
	    }
	    int getSecond() const {
	        return sec;
	    }
	};
	
	class Patient : public Person {
	private:
	    string gender;
	    string contact;
	    string address;
	    string disease;
	    double bill;
	    Date_Time entry;
	    Date_Time exit;
	
	public:
		
	    Patient(string FirstName, string LastName, int age, int ID, string gender, string contact, string address, string disease, double bill, const Date_Time& entry, const Date_Time& exit)
	        : Person(FirstName, LastName, age, ID), gender(gender), contact(contact), address(address), disease(disease), bill(bill), entry(entry), exit(exit) {}
	
	    void setGender(string gender) {
	        this->gender = gender;
	    }
	    void setContact(string contact) {
	        this->contact = contact;
	    }
	    void setAddress(string address) {
	        this->address = address;
	    }
	    void setDisease(string disease) {
	        this->disease = disease;
	    }
	    void setBill(double bill) {
	        this->bill = bill;
	    }
	
	    string getGender() const {
	        return gender;
	    }
	    string getContact() const {
	        return contact;
	    }
	    string getAddress() const {
	        return address;
	    }
	    string getDisease() const {
	        return disease;
	    }
	    double getBill() const {
	        return bill;
	    }
	 const Date_Time& getEntry() const {
	        return entry;
	    }
	
	    const Date_Time& getExit() const {
	        return exit;
	    }
	   
	
	    void Print() const {
	        cout << "\n..........Patient Information..........\n" << endl;
	        cout << "ID: " << getID() << endl;
	        cout << "Name: " << getFirstName() << " " << getLastName() << endl;
	        cout << "Age: " << getAge() << endl;
	        cout << "Gender: " << getGender() << endl;
	        cout << "Contact: " << getContact() << endl;
	        cout << "Address: " << getAddress() << endl;
	        cout << "Disease: " << getDisease() << endl;
	        cout << "Bill: $" << getBill() << endl;
	        cout << "Entry Date: ";
	        cout << "Entry Date and Time: " << entry.getMonth() << "/" << entry.getDay() << "/" << entry.getYear() << " " << entry.getHour() << ":" << entry.getMinute() << ":" << entry.getSecond() << endl;
	        cout << "Exit Date and Time: " << exit.getMonth() << "/" << exit.getDay() << "/" << exit.getYear() << " " << exit.getHour() << ":" << exit.getMinute() << ":" << exit.getSecond() << endl;
	        cout << "-----------------------------------------" << endl;
	    }
	};
	
	class Doctors : public Person {
	private:
	    string specialization;
	
	public:
	   Doctors(string FirstName, string LastName, int age, int ID, string specialization)
	        : Person(FirstName, LastName, age, ID), specialization(specialization) {}
	
	    void setSpecialization(string specialization) {
	        this->specialization = specialization;
	    }
	
	    string getSpecialization() const {
	        return specialization;
	    }
	
	
	
	    void Print() const {
	        cout << "\n..........Doctor Information..........\n" << endl;
	        cout << "ID: " << getID() << endl;
	        cout << "Name: " << getFirstName() << " " << getLastName() << endl;
	        cout << "Age: " << getAge() << endl;
	        cout << "Specialization: " << getSpecialization() << endl;
	        cout << "----------------------------------------" << endl;
	    }
	};
	
	class Appointment {
	private:
	    const Doctors& doctor;
	    const Patient& patient;
	public:
	    Appointment(const Doctors& doctor, const Patient& patient) : doctor(doctor), patient(patient) {}
	
	    void display() const {
	        cout << "\nx..........Appointment Details..........x\n" << endl;
	        cout << "\n...Doctor:...\n " << "ID:"<<doctor.getID()<<doctor.getFirstName() << " " << doctor.getLastName() << endl;
	        cout << "\n...Patient:...\n" << "ID:"<<patient.getID()<<patient.getFirstName() << " " << patient.getLastName()<< endl;
	        cout << endl;
	    }
	};
	class Hospital {
	private:
	    string name;
	    vector<Doctors> doctors;
	    vector<Patient> patients;
	    vector<Appointment> appointments;
	    vector<User> users;
	
	public:
		Hospital() {
	        // Create some sample users
	        users.push_back(User("admin", "admin123"));
	     //   users.push_back(User("user", "user123"));
	    }
	    
	    void setHospital_name(string name) {
	        this->name = name;
	    }
	
	    string getHospital_name() const {
	        return name;
	    }
	
	    void setDoctors(const vector<Doctors>& doctors) {
	        this->doctors = doctors;
	    }
	
	    const vector<Doctors>& getDoctors() const {
	        return doctors;
	    }
	    
	  	bool login(const string& username, const string& password) {
	        for (const User& user : users) {
	            if (user.getUsername() == username && user.getPassword() == password) {
	                return true;
	            }
	        }
	        return false;
	    }
	    
		void searchDoctor(int doctorID) const {
	    bool found = false;
	    for (const Doctors& doctor : doctors) {
	        if (doctor.getID() == doctorID) {
	            doctor.Print();
	            found = true;
	            break;
	        }
	    }
	
	    if (!found) {
	        cout << "\nx..........No such doctor!..........x\n" << endl;
	    }
	}
	     void addDoctor(const Doctors& doctor) {
	        doctors.push_back(doctor);
	    }
	
	    void addPatient(const Patient& patient) {
	        patients.push_back(patient);
	    }
	
	    void displayDoctors() const {
	        cout << "\nx..........List of Doctors..........x\n" << endl;
	        for (const Doctors& doctor : doctors) {
	            doctor.Print();
	        }
	        cout << endl;
	    }
	
	    void displayPatients() const {
	        cout << "\nx..........List of Patients..........x\n" << endl;
	        for (const auto& patient : patients) {
	            patient.Print();
	        }
	        cout << endl;
	    }
	
	    void bookAppointment() {
	        int patientID, doctorID;
	        cout << "Enter the ID of the patient: ";
	        cin >> patientID;
	        cout << "Enter the ID of the doctor: ";
	        cin >> doctorID;
	  // Find the patient and doctor based on their IDs
	        Patient* patient = nullptr;
	        Doctors* doctor = nullptr;
	
	        for (auto& p : patients) {
	            if (p.getID() == patientID) {
	                patient = &p;
	                break;
	            }
	        }
	
	        for (auto& d : doctors) {
	            if (d.getID() == doctorID) {
	                doctor = &d;
	                break;
	            }
	        }
	
	        if (patient != nullptr && doctor != nullptr) {
	            Appointment appointment(*doctor, *patient);
	            appointments.push_back(appointment);
	            cout << "\nx..........Appointment booked successfully!..........x\n" << endl;
	        } else {
	            cout << "\nx..........Invalid patient ID or doctor ID. Please try again...........x\n" << endl;
	        }
	    }
	     void displayAppointments() const {
	        if (appointments.empty()) {
	            cout << "No appointments booked." << endl;
	        } else {
	            cout << "List of Appointments:" << endl;
	            for (const auto& appointment : appointments) {
	                appointment.display();
	            }
	        }
	        cout << endl;
	    }
	    void deletePatient(int patientID) {
	        auto it = std::find_if(patients.begin(), patients.end(), [patientID](const Patient& patient) {
	            return patient.getID() == patientID;
	        });
	
	        if (it != patients.end()) {
	            patients.erase(it);
	            std::cout << "\nx..........Patient with ID " << patientID << " deleted successfully!...........x\n" << std::endl;
	        } else {
	            std::cout << "\nx..........No patient with ID " << patientID << " found!..........x\n" << std::endl;
	        }
	    }
	
	    void deleteDoctor(int doctorID) {
	        auto it = std::find_if(doctors.begin(), doctors.end(), [doctorID](const Doctors& doctor) {
	            return doctor.getID() == doctorID;
	        });
	
	        if (it != doctors.end()) {
	            doctors.erase(it);
	            std::cout << "Doctor with ID " << doctorID << " deleted successfully." << std::endl;
	        } else {
	            std::cout << "\nx..........No doctor with ID " << doctorID << " found!..........x\n" << std::endl;
	        }
	    }
	
	};
	int main() {
		
		string username, password;
	    bool loggedIn = false;
	
	    cout << "Enter username: ";
	    cin >> username;
	    cout << "Enter password: ";
	    cin >> password;
	
	    Hospital hospital;
	
	    if (hospital.login(username, password)) {
	        cout << "Login successful!" << endl;
	        loggedIn = true;
	    }
		 else {
	        cout << "Invalid username or password. Please try again." << endl;
	    }
	    if(loggedIn){
	    	 hospital.setHospital_name("FAST Public Hospital");
	    cout<<"x....................."<< hospital.getHospital_name()<<".............................x\n\n"<<endl;
	    
	      int choice;
	    do {
	    	
	        cout << "<<<<<<..Menu..>>>>>>:" << endl;
	        cout << "1. Add Doctor" << endl;
	        cout << "2. Add Patient" << endl;
	        cout << "3. Book Appointment" << endl;
	        cout << "4. Search Doctors" << endl;
	        cout << "5. Display Patients" << endl;
	        cout << "6. Display Doctors" << endl;
	        cout << "7. Display Appointments" << endl;
	        cout << "8. Delete a Patient's Record'." << endl;
	        cout << "9. Delete a Doctor's Record'." << endl;
	        cout << "0. Exit" << endl;
	        cout << "Enter your choice: ";
	        cin >> choice;
	
	        switch (choice) {
	            case 1: {
	                 string firstName, lastName, specialization;
	                int age, ID;
	
	                cout << "Enter doctor details:" << endl;
	                cout << "First Name: ";
	                cin >> firstName;
	                cout << "Last Name: ";
	                cin >> lastName;
	                cout << "Age: ";
	                cin >> age;
	                cout << "ID: ";
	                cin >> ID;
	                cout << "Specialization: ";
	                cin >> specialization;
	
	                Doctors doctor(firstName, lastName, age, ID, specialization);
	              
	                hospital.addDoctor(doctor);
	
	                break;
	            }
	            case 2: {
	                string firstName, lastName, gender, contact, address, disease;
				    int age, ID;
				    double bill;
				
				    cout << "Enter patient details:" << endl;
				    cout << "First Name: ";
				    cin >> firstName;
				    cout << "Last Name: ";
				    cin >> lastName;
				    cout << "Age: ";
				    cin >> age;
				    cout << "ID: ";
				    cin >> ID;
				    cout << "Gender: ";
				    cin >> gender;
				    cout << "Contact: ";
				    cin >> contact;
				    cout << "Address: ";
				    cin >> address;
				    cout << "Disease: ";
				    cin >> disease;
				    cout << "Bill: ";
				    cin >> bill;
				
				    int entryMonth, entryDay, entryYear, entryHour, entryMin, entrySec;
				    cout << "Enter entry date and time (MM DD YYYY HH MM SS): ";
				    cin >> entryMonth >> entryDay >> entryYear >> entryHour >> entryMin >> entrySec;
				    Date_Time entry(entryMonth, entryDay, entryYear, entryHour, entryMin, entrySec);
				
				    int exitMonth, exitDay, exitYear, exitHour, exitMin, exitSec;
				    cout << "Enter exit date and time (MM DD YYYY HH MM SS): ";
				    cin >> exitMonth >> exitDay >> exitYear >> exitHour >> exitMin >> exitSec;
				    Date_Time exit(exitMonth, exitDay, exitYear, exitHour, exitMin, exitSec);
				
				    Patient patient(firstName, lastName, age, ID, gender, contact, address, disease, bill, entry, exit);
				
					hospital.addPatient(patient);
					cout << "\nx.........Patient added successfully!..........x\n" << endl;
	
	                break;
	            }
	            case 3: {
	               
					// Book appointment for a patient with a doctor
	
						hospital.bookAppointment();
					    break;
	                
	            }
	            case 4: {
	                int searchId;
				    std::cout << "\nEnter the ID of the Doctor , to search for: ";
				    std::cin >> searchId;
				    hospital.searchDoctor(searchId);
	                break;
	            }
	            case 5: {
	            	
	                hospital.displayPatients();
	                break;
	            }
	             case 6: {
	                hospital.displayDoctors();
	                break;
	            }
	            case 7: {
	                hospital.displayAppointments();
	                break;
	            }
	            case 8: {
	            	int Id;
				    std::cout << "\nEnter the ID of the Patient you want to delete: ";
				    std::cin >> Id;
	                hospital.deletePatient(Id);
	                break;
	            }
	            case 9: {
	          		int Id;
				    std::cout << "\nEnter the ID of the Doctor you want to delete: ";
				    std::cin >> Id;
	                hospital.deleteDoctor(Id);
	                break;
	            }
	            case 0:
	                cout << "\nExiting..." << endl;
	                break;
	            default:
	                cout << "\n..........Invalid choice!..........\n" << endl;
	                break;
	        }
	        cout << endl;
	    } while (choice != 0);
	
	    return 0;
		}
	   
	}
