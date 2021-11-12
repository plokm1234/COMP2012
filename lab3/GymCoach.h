#ifndef GYMCOACH_H
#define GYMCOACH_H

/* ======================================
    TODO: Complete the class declaration of GymCoach
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
#include "GymClass.h"
#include "GymPerson.h"
#include <string>
using namespace std;

class GymCoach : public GymPerson{
    private: 
        float salary;
        GymClass* coach_class;
    public: 
        GymCoach(const string& name, const string& gender, float salary);
        void coach(GymClass* coach_class);
        void print() const;
};

#endif