#pragma once
#include "StudentAnswers.h"
#include "MultipleChoiseQuestion.h"
#include "Editor.h"

enum status {
    NonAuthorized,
    AuthorizedAsStudent,
    AuthorizedAsAdmin
};

enum choice {
    Nothing = -3,
    Exit,
    Return,
};

class Action;
class ChooseTestAction;
class StartTestAction;
class Action;
class AdminAction;
class UserAction;
class StartTestAction;
class ViewAllMarksAction;

class ClientAction {
    std::string userName;
    Action* action = nullptr;
    int authorizeStatus = NonAuthorized;
public:
    int savedChoice = Nothing;
    Editor* editor;
    StudentAnswers* studentAnswers;
    ClientAction(Action* action, Editor* editor, StudentAnswers* studentAnswers);

    void setUserName(std::string userName) {
        this->userName = userName;
    }
    std::string getUserName() {
        return userName;
    }
    int checkAccess() {
        return authorizeStatus;
    }
    void setAccess(status status) {
        authorizeStatus = status;
    }

    void setAction(Action* action);
    void returnAction();
    void start();
};

class Action
{
protected:
    ClientAction* client = nullptr;
    Action* previousAction = nullptr;
    void showAction();
public:
    ~Action();
    void setClient(ClientAction* client);
    void setPreviousAction(Action* previousAction);
    Action* getPreviousAction();
    virtual void execute() = 0;
};

class ChooseTestAction : public Action {
public:
    void execute();
};

class AuthorizeAction :  public Action
{
    void login(std::string userName);
public:
    void execute();
};

class AddTestAction : public Action {
    enum choosenTestType { SingleChoiceTest = 1, MultipleChoiceTest };
    void showTestTypes() const;
public:
    Question* addTest();
    void execute();
};

class AddSetAction : public Action {
public:
    void execute();
};

class DeleteTestAction :public Action {
public:
    void execute();
};

class ViewTestAction :public Action {
public:
    void execute();
};

class EditSetAction : public Action {
    enum editActions {
        AddTest = 1,
        DeleteTest,
        ViewTest
    };
    void showAction() const;
public:
    void execute();
};

class DeleteSetAction :public Action {
public:
    void execute();
};

class ViewAllMarksAction : public Action {
    int sumOfMarks(std::vector<int>* marks);
    void printMarks(std::vector<int>* marks);
    void showMarks(int choice);
public:
    void execute(); 
};

class StartTestAction : public Action {
    int* randomizeNumbers(int size);
    std::vector<int>* transformOrder(std::vector<int>* currentMarks, int* key);
    void startTest(std::string testName);
public:
    void execute();
};

class ViewMyMarksAction : public Action {
    int sumOfMarks(std::vector<int>* marks);
    void printMarks(std::vector<int>* marks);
public:
    void execute();
};

class AdminAction : public Action
{
    enum AdminChoice {
        StartTest = 1,
        ViewMarks,
        AddSetTest,
        EditSetTest,
        DeleteSetTest
    };
    void showAction() const;
public:
    void execute();
};

class UserAction : public Action {
    enum AdminChoice {
        StartTest = 1,
        ViewMarks
    };
    void showAction() const;
public:
    void execute();
};