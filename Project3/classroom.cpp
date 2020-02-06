#include "classroom.hpp"

///
Classroom::Classroom()
{

}

// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
Student* Classroom::find_student(unsigned int UID, bool &found)
{
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        Student* s = _classList.IterateItems();
        if(s->GetID() == UID)
        {
            found = true;
            return s;
        }
    }
    found = false;
}

// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
void Classroom::PrintClassroomInformation() const
{
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        std::cout << "****************************************" << std::endl;
        _classList.IterateItems()->PrintData();
        std::cout << std::endl;
    }
}

/// modify code below this line
// ========================================
bool Classroom::AddStudent(const std::string &firstName, const std::string &lastName, unsigned int UID)
{
    /// adds the item to the list.
    /// does not add a student that already exists, based on the UID
    /// returns true if the student was successfully added
}

bool Classroom::RemoveStudent(unsigned int UID)
{
    /// removes the student from the list based on UID.
    /// returns true if the student was successfully removed
}

void Classroom::AddProjects(const List<Assignment> &projects)
{
    /// adds the projects to the required student's list of projects
}

void Classroom::AddExams(const List<Assignment> &projects)
{
    /// adds the exams to the required student's list of exams
}

void Classroom::SetFinalExams(const List<Assignment> &projects)
{
    /// sets the required student's FinalExam score.
}

