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
  //THIS CODE DOES NOT WORK IF THE ITERATOR IS EMPTY, SO MUCH RAGE
  Student* s = nullptr;
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        s = _classList.IterateItems();
        if(s==nullptr) { return s; }
        if(s->GetID() == UID)
        {
            found = true;
            return s;
        }
    }
    found = false;
    return s;
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
  bool found;
  const auto it = find_student(UID,found);
  if(found==true || it!=nullptr) { return false; } //already added
  _classList.AppendItem(Student(firstName,lastName,UID));
  return true;
}

bool Classroom::RemoveStudent(unsigned int UID)
{
  /// removes the student from the list based on UID.
  /// returns true if the student was successfully removed
  const auto s = Student("","",UID);//this is so dumb
  return _classList.DeleteItem(s);
}


void Classroom::AddProjects(const List<Assignment> &projects)
{
  /// adds the projects to the required student's list of projects
  auto callback = &Student::AddProject;
  Assignment* x{nullptr};
  Student*    s{nullptr};
  bool found{false};
  projects.ResetIterator();
  while(!projects.AtEnd())
  {
    x = projects.IterateItems();
    if(x==nullptr) { break; }
    const auto UID = x->StudentUID;
    s = find_student(UID,found);
    if(s==nullptr || !found){ continue; }
    (s->*callback)(x->Grade);
  }
}

void Classroom::AddExams(const List<Assignment> &projects) //what blatant COPY-PASTA the name didn't even change
{
  /// adds the exams to the required student's list of exams
  auto callback = &Student::AddExam;
  Assignment* x{nullptr};
  Student*    s{nullptr};
  bool found{false};
  projects.ResetIterator();
  while(!projects.AtEnd())
  {
    x = projects.IterateItems();
    if(x==nullptr) { break; }
    const auto UID = x->StudentUID;
    s = find_student(UID,found);
    if(s==nullptr || !found){ continue; }
    (s->*callback)(x->Grade);
  }
}

void Classroom::SetFinalExams(const List<Assignment> &projects)
{
  /// sets the required student's FinalExam score.
  auto callback = &Student::SetFinalExam;
  Assignment* x{nullptr};
  Student*    s{nullptr};
  bool found{false};
  projects.ResetIterator();
  while(!projects.AtEnd())
  {
    x = projects.IterateItems();
    if(x==nullptr) { break; }
    const auto UID = x->StudentUID;
    s = find_student(UID,found);
    if(s==nullptr || !found){ continue; }
    (s->*callback)(x->Grade);
  }
}
