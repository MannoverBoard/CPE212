#include "classroom.hpp"


Classroom::Classroom()
{

}

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


bool Classroom::AddStudent(const std::string &firstName, const std::string &lastName, 
                    unsigned int UID)
{
    bool found = false;
    Student *another = find_student(UID, found);
    if(found)
    {
        return false;
    }

    Student s(firstName, lastName, UID);  


    _classList.AppendItem(s);
    return true;
}

bool Classroom::RemoveStudent(unsigned int UID)
{
    bool found = false;
    Student *s = find_student(UID, found);
    if(!found)
    {
        return false;
    }

    return _classList.DeleteItem(*s);
}

void Classroom::AddProjects(const List<Assignment> &projects)
{
    projects.ResetIterator();
    while(!projects.AtEnd())
    {
        bool found = false;
        Assignment* p = projects.IterateItems();
        Student *student = find_student(p->StudentUID, found);
        if(found)
        {
            student->AddProject(p->Grade);
        }
        else
        {
            student->AddProject(0.0f);
        }
    }
}

void Classroom::AddExams(const List<Assignment> &projects)
{
    projects.ResetIterator();
    while(!projects.AtEnd())
    {
        bool found = false;
        Assignment *p = projects.IterateItems();
        Student *student = find_student(p->StudentUID, found);
        if(found)
        {
            student->AddExam(p->Grade);
        }
        else
        {
            student->AddExam(0.0f);
        }
    }
}

void Classroom::SetFinalExams(const List<Assignment> &projects)
{
    projects.ResetIterator();
    while(!projects.AtEnd())
    {
        bool found = false;
        Assignment *p = projects.IterateItems();
        Student *student = find_student(p->StudentUID, found);
        if(found)
        {
            student->SetFinalExam(p->Grade);
        }
        else
        {
            student->SetFinalExam(0.0f);
        }
    }
}


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