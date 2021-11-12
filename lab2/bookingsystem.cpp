#include "bookingsystem.h"

#include <iostream>
#include <typeinfo>

using namespace std;


int BookingSystem::nextID = 0;

/* ===================================================
    TODO: Complete the type conversion constructor.
          Here we assume to allocate same capacity for tennisball, tenniscourt and person.
          Try to add only one extra line of code!
    HINT: Reuse the general constuctor we define below.
   =================================================== */ 
BookingSystem::BookingSystem(int capacity):BookingSystem(capacity,capacity,capacity)
{   
    // Finish constructing with printing.
    cout << "By using the conversion constructor!" << endl;
}

/* ===================================================
    TODO: Complete the other constructor
          numTennisBall, numTennisCourt, numPerson should be initialized to be 0
          maxNumTennisBall, maxNumTennisCourt, maxNumPerson should be initialized to their assigned values
   =================================================== */ 
BookingSystem::BookingSystem(int nTennisBall, int nTennisCourt, int capacity) 
{
    SN = nextID++;
    this->numTennisBall = 0;
    this->numTennisCourt = 0;
    this->numPerson = 0;
    this->maxNumPerson = capacity;
    this->maxNumTennisBall = nTennisBall;
    this->maxNumTennisCourt = nTennisCourt;
    // TODO: Allocate memory for tennisballs, tenniscourts and persons here.
    this->tennisballs = new TennisBall *[nTennisBall];
    for(int index=0;index<maxNumTennisBall;index++){
        this->tennisballs[index] = nullptr;
    }
    this->tenniscourts = new TennisCourt *[nTennisCourt];
    for(int index=0;index<maxNumTennisCourt;index++){
        this->tenniscourts[index] = nullptr;
    }
    this->persons = new Person *[capacity];
    for(int index=0;index<maxNumPerson;index++){
        this->persons[index] = nullptr;
    }

    // Finish constructing with printing.
    cout <<"#"<< SN<< " BookingSystem Constructed!" << endl;
}


/* ===================================================
    TODO: Complete the copy constructor
          Deep copy all data members of another restaurant
   =================================================== */ 
BookingSystem::BookingSystem(const BookingSystem &other)
{
    SN = nextID++;
    this->numTennisBall = other.numTennisBall;
    this->numTennisCourt = other.numTennisCourt;
    this->numPerson = other.numPerson;
    this->maxNumPerson = other.maxNumPerson;
    this->maxNumTennisBall = other.maxNumTennisBall;
    this->maxNumTennisCourt = other.maxNumTennisCourt;
    this->tennisballs = new TennisBall *[other.maxNumTennisBall];
    this->tenniscourts = new TennisCourt *[other.maxNumTennisCourt];
    this->persons = new Person *[other.maxNumPerson];

    // TODO: Clone TennisBalls.
    for(int index = 0;index<other.maxNumTennisBall;index++){
        if(other.tennisballs[index] != nullptr){
            this->tennisballs[index] = new TennisBall(*other.tennisballs[index]);
        }
    }

    // TODO: Clone TennisCourts.
    for(int index = 0;index<other.maxNumTennisCourt;index++){
        if(other.tenniscourts[index] != nullptr){
            this->tenniscourts[index] = new TennisCourt(*other.tenniscourts[index]);
        }
    }

    // TODO: Clone Persons.
    for(int index = 0;index<other.maxNumPerson;index++){
        if(other.persons[index] != nullptr){
            this->persons[index] = new Person(*other.persons[index]);
        }
    }
    
    // Finish copying with printing.
    cout <<"#"<< SN<< " BookingSystem Copied!" << endl; 
}


/* ===================================================
    TODO: Complete the destructor
   =================================================== */ 
BookingSystem::~BookingSystem()
{
    // TODO: Destruct TennisBalls.
    for(int index = 0;index < this->numTennisBall;index++){
        if(this->tennisballs[index] != nullptr) this->tennisballs[index]->~TennisBall();
    }
    delete[] this->tennisballs;

    // TODO: Destruct TennisCourts.
    for(int index = 0;index < this->numTennisCourt;index++){
        if(this->tenniscourts[index] != nullptr) this->tenniscourts[index]->~TennisCourt();
    }
    delete[] this->tenniscourts;

    // TODO: Destruct Persons.
    for(int index = 0;index < this->numPerson;index++){
       if(this->persons[index] != nullptr) this->persons[index]->~Person();
    }
    delete[] this->persons;
    
    // Finish destructing with printing.
    cout <<"#"<< SN<< " BookingSystem is Destructed." << endl;
}


void BookingSystem::releaseTennisBall()
{
    if (numTennisBall >= maxNumTennisBall)
    {
        cout << "Error: there is no TennisBall , release failed." << endl;
    }
    else
    {
        this->tennisballs[numTennisBall] = new TennisBall();
        this->numTennisBall += 1;
    }
}

void BookingSystem::releaseTennisCourt()
{
    if (numTennisCourt >= maxNumTennisCourt)
    {
        cout << "Error: there is no TennisCourt , release failed." << endl;
    }
    else
    {
        this->tenniscourts[numTennisCourt] = new TennisCourt();
        this->numTennisCourt += 1;
    }
}

void BookingSystem::makeBooking()
{
    if (numPerson >= maxNumPerson)
    {
        cout << "Error: Capacity Lack" << endl;
    }
    else if (numTennisBall < 1 || numTennisCourt < 1)
    {
        cout << "Error: no enough facilities for booking" << endl;
    } 
    else
    {
        /* ===================================================
           TODO: accept person's booking by allocating a Person object. 
            The person would like to reserve a tennis basll and a tennis court.
            The ownership of the top tennisball and tenniscourt is then transferred to the Person object,
            which means the TennisBall object and the TennisCourt object are now pointed by the new Person object instead.
        =================================================== */ 
        this->persons[numPerson] = new Person(this->tennisballs[numPerson], this->tenniscourts[numPerson]);
        this->numPerson +=1;
        this->numTennisBall -=1;
        this->numTennisCourt -=1;
        
        // Finish processing.
        cout <<"Booking is successful!!!" << endl;
    }
}

void BookingSystem::log() const
{
    cout << "----------------------" << endl;
    cout << "| Booking System Log |" << endl;
    cout << "----------------------" << endl;
    cout <<"#"<< SN<< " booking system has..." << endl;
    cout << "TennisBall: " << numTennisBall << "/" << maxNumTennisBall << endl;
    cout << "TennisCourt: " << numTennisCourt << "/" << maxNumTennisCourt << endl;
    cout << "Person: " << numPerson << "/" << maxNumPerson << endl;
}
