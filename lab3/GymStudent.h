#ifndef GYMSTUDENT_H
#define GYMSTUDENT_H

const int MAX_NUM_OF_SESS = 2;

/* ======================================
    TODO: Complete the class declaration of GymStudent
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
#include "GymSession.h"
#include "GymPerson.h"
using namespace std;

class GymStudent : public GymPerson{
    private: 
        int num_of_session;
        const GymSession* session_list[MAX_NUM_OF_SESS] ;
    public:
        GymStudent(const string& name, const string& gender);
        void join_session(const GymSession* sess);
        void print() const;
};

#endif