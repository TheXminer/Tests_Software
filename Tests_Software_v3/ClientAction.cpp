#include "ClientAction.h"

ClientAction::ClientAction(Action* action, Editor* editor, StudentAnswers* studentAnswers) {
    setAction(action);
    this->editor = editor;
    this->studentAnswers = studentAnswers;
}

void ClientAction::setAction(Action* action) {
    if (this->action) action->setPreviousAction(this->action);
    this->action = action;
    action->setClient(this);
}

void ClientAction::start() {
    if (!action)
        return;
    Action* curAction = action;
    action->execute();
}

void ClientAction::returnAction()
{
    if (!this->action)
        return;
    Action* previous = this->action->getPreviousAction();
    this->action->setPreviousAction(nullptr);
    delete this->action;
    this->action = previous;
}

void Action::showAction() {
    std::cout << "Available actions:" << std::endl;
    std::cout << "--(" << Exit << ") Exit" << std::endl;
    std::cout << "--(" << Return << ") Return" << std::endl;
}

Action::~Action() {
    if (!previousAction) {
        return;
    }
    previousAction->setClient(nullptr);
    delete previousAction;
    previousAction = nullptr;
}

void Action::setClient(ClientAction* client) {
    if (client)
        this->client = client;
}

void Action::setPreviousAction(Action* previousAction) {
    this->previousAction = previousAction;
}

Action* Action::getPreviousAction() {
    return previousAction;
}

int* StartTestAction::randomizeNumbers(int size)
{
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array;
}

std::vector<int>* StartTestAction::transformOrder(std::vector<int>* currentMarks, int* key)
{
    return currentMarks;
}

void StartTestAction::startTest(std::string testName)
{
    std::vector<Question*>* tests = client->editor->getSetOfTests(testName);
    int size = tests->size();
    int* numbersOrder = randomizeNumbers(size);
    std::vector<int>* currentMarks = new std::vector<int>;
    time_t start, end;
    time(&start);
    if (client->studentAnswers->isTestPassed(client->getUserName(), testName)) {
        std::cout << "Test already passed :)" << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". ";
        tests->at(numbersOrder[i])->display();
        int mark = tests->at(numbersOrder[i])->checkEnterQuestion();
        currentMarks->push_back(mark);
    }
    time(&end);
    studentAnswerData* answers = new studentAnswerData(end - start, transformOrder(currentMarks, numbersOrder));
    client->studentAnswers->addStudentAnswer(client->getUserName(), testName, answers);
    delete numbersOrder;
}

void AuthorizeAction::login(std::string userName)
{
    if (userName == "admin") {
        client->setUserName(userName);
        client->setAccess(AuthorizedAsAdmin);
        client->setAction(new AdminAction);
    }
    if (userName.find("user") != std::string::npos) {
        client->setUserName(userName);
        client->setAccess(AuthorizedAsStudent);
        client->setAction(new UserAction);
    }
}

void AuthorizeAction::execute() {
    if (previousAction) {
        client->savedChoice = Nothing;
        delete previousAction;
        previousAction = nullptr;
    }
    std::cout << "Log in. Enter your usernme (admin/user): ";
    std::string username;
    std::cin >> username;
    login(username);
}

void ChooseTestAction::execute(){//не дозволяє обрати варіанти -2, -1 при наявному тесті
    std::cout << "Choose test:" << std::endl;
    std::cout << "--(" << Exit << ") Exit" << std::endl;
    std::cout << "--(" << Return << ") Return" << std::endl;
    if (client->editor->nameOfTests.size() == 0) {
        std::cout << "There's nothing here :(" << std::endl;
    }
    else for (int i = 0; i < client->editor->nameOfTests.size(); i++) {
        std::cout << "--(" << i << ") " << client->editor->nameOfTests[i] << std::endl;
    }
    int userChoice = Nothing;
    //while (userChoice > client->editor->nameOfTests.size() - 1|| userChoice < Exit) {
    std::cin >> userChoice;
    //}
    client->savedChoice = userChoice;
    client->returnAction();
}

void ViewAllMarksAction::execute(){
    switch (client->savedChoice) {
    case Nothing:
        client->setAction(new ChooseTestAction);
        return;
    case Exit:
        client->setAction(new AuthorizeAction);
        return;
    case Return:
        client->savedChoice = Nothing;
        client->returnAction();
        return;
    }
    showMarks(client->savedChoice);
    showAction();
    while (client->savedChoice != Exit && client->savedChoice != Return) {
        std::cin >> client->savedChoice;
    }
}

void AddTestAction::showTestTypes() const
{
    std::cout << "Available types:" << std::endl;
    std::cout << "--(" << Exit << ") Exit" << std::endl;
    std::cout << "--(" << Return << ") Return" << std::endl;
    std::cout << "--(" << SingleChoiceTest << ") Single choise" << std::endl;
    std::cout << "--(" << MultipleChoiceTest << ") Multiple choise" << std::endl;
}

Question* AddTestAction::addTest() {
    showTestTypes();
    int choice;
    std::cin >> choice;
    Question* newQuestion = nullptr;
    if (!client)
        return nullptr;
    switch (choice) {
    case Exit:
        client->setAction(new AuthorizeAction);
        return nullptr;
    case Return:
        client->savedChoice = Return;
        client->returnAction();
        return nullptr;
    case SingleChoiceTest:
        newQuestion = new Question;
        if (!newQuestion->enterQuestion()) {
            delete newQuestion;
            newQuestion = nullptr;
        }
        return newQuestion;
    case MultipleChoiceTest:
        newQuestion = new MultipleChoiceQuestion;
        if (!newQuestion->enterQuestion()) {
            delete newQuestion;
            newQuestion = nullptr;
        }
        return newQuestion;
    }
    return nullptr;
}

void AddTestAction::execute() {
    Question* question = addTest();
    if (!question)
        return;
    client->editor->addTest(client->editor->nameOfTests[client->savedChoice], question);
    client->returnAction();
}

void AddSetAction::execute() {
    AddTestAction addTestAction;
    addTestAction.setClient(client);
    std::string testSetName;
    switch (client->savedChoice) {
    case Nothing:
        std::cout << "Enter name for set of tests: " << std::endl;
        std::cin.ignore();
        getline(std::cin, testSetName);
        while (true) {
            Question* question = addTestAction.addTest();
            if (!question)
                break;
            client->editor->addTest(testSetName, question);
        }
        return;
    case Exit:
        client->setAction(new AuthorizeAction);
        return;
    case Return:
        client->savedChoice = Nothing;
        client->returnAction();
        return;
    }
}

void DeleteTestAction::execute() {
    int number;
    std::cout << "Enter delete test number: ";
    std::cin >> number;
    client->editor->deleteTest(client->editor->nameOfTests[client->savedChoice], number - 1);
    client->savedChoice = Nothing;
    client->returnAction();
}

void ViewTestAction::execute() {
    std::vector<Question*>* testSet = client->editor->getSetOfTests(client->editor->nameOfTests[client->savedChoice]);
    for (int i = 0; i < testSet->size(); i++) {
        std::cout << i + 1 << ". ";
        testSet->at(i)->viewTest();
    }
    showAction();
    int choice;
    std::cin >> choice;
    switch (choice) {
    case Exit:
        client->setAction(new AuthorizeAction);
        return;
    case Return:
        client->savedChoice = Nothing;
        client->returnAction();
        return;
    }
}

void EditSetAction::execute() {
    if (client->savedChoice == Nothing) {
        client->setAction(new ChooseTestAction);
        return;
    }
    if (client->savedChoice == Return) {
        client->savedChoice = Nothing;
        client->returnAction();
        return;
    }
    showAction();
    int choice = Nothing;
    //while (choice <Exit || choice>client->editor->nameOfTests.size())
    std::cin >> choice;
    switch (choice) {
    case Exit:
        client->setAction(new AuthorizeAction);
        return;
    case Return:
        client->savedChoice = Nothing;
        client->returnAction();
        return;
    case AddTest:
        client->setAction(new AddTestAction);
        break;
    case DeleteTest:
        client->setAction(new DeleteTestAction);
        break;
    case ViewTest:
        client->setAction(new ViewTestAction);
        break;
    }
}

void EditSetAction::showAction() const {
    std::cout << "Choose action:" << std::endl;
    std::cout << "--(" << Exit << ") Exit" << std::endl;
    std::cout << "--(" << Return << ") Return" << std::endl;
    std::cout << "--(" << AddTest << ") Add new test" << std::endl;
    std::cout << "--(" << DeleteTest << ") Delete exist test" << std::endl;
    std::cout << "--(" << ViewTest << ") View all test" << std::endl;
}

void DeleteSetAction::execute() {
    switch (client->savedChoice) {
    case Nothing:
        client->setAction(new ChooseTestAction);
        return;
    case Exit:
        client->setAction(new AuthorizeAction);
        return;
    case Return:
        client->savedChoice = Nothing;
        client->returnAction();
        return;
    }
    client->editor->deleteSetOfTests(client->editor->nameOfTests[client->savedChoice]);
    client->savedChoice = Nothing;
}

int ViewAllMarksAction::sumOfMarks(std::vector<int>* marks) {
    int sum = 0;
    for (int i = 0; i < marks->size(); i++) {
        sum += marks->at(i);
    }
    return sum;
}

void ViewAllMarksAction::printMarks(std::vector<int>* marks) {
    int size = marks->size();
    for (int i = 0; i < size; i++) {
        std::cout << marks->at(i) << " ";
    }
    std::cout << std::endl;
}

void ViewAllMarksAction::showMarks(int choice) {
    bool isTyped = false;
    for (int i = 0; i < client->studentAnswers->studentsNames.size(); i++) {
        studentAnswerData* marks = client->studentAnswers->getStudentAnswers(client->studentAnswers->studentsNames[i], client->editor->nameOfTests[choice]);
        if (marks && marks->marks) {
            std::cout << client->studentAnswers->studentsNames[i] << " (" << marks->usedTime / 60 << "m " << marks->usedTime % 60 << "s, " << sumOfMarks(marks->marks) << "): ";
            printMarks(marks->marks);
            std::cout << std::endl;
            isTyped = true;
        }
    }
    if (!isTyped)
        std::cout << "Students haven`t completed tests yet :(" << std::endl;
}

void StartTestAction::execute() {
    switch (client->savedChoice) {
    case Nothing:
        client->setAction(new ChooseTestAction);
        return;
    case Exit:
        client->setAction(new AuthorizeAction);
        return;
    case Return:
        client->savedChoice = Nothing;
        client->returnAction();
        return;
    }
    startTest(client->editor->nameOfTests[client->savedChoice]);
    client->returnAction();
}

int ViewMyMarksAction::sumOfMarks(std::vector<int>* marks) {
    int sum = 0;
    for (int i = 0; i < marks->size(); i++) {
        sum += marks->at(i);
    }
    return sum;
}

void ViewMyMarksAction::printMarks(std::vector<int>* marks) {
    int size = marks->size();
    for (int i = 0; i < size; i++) {
        std::cout << marks->at(i) << " ";
    }
    std::cout << std::endl;
}

void ViewMyMarksAction::execute() {
    int size = client->editor->nameOfTests.size();
    for (int i = 0; i < size; i++) {
        studentAnswerData* answer = client->studentAnswers->getStudentAnswers(client->getUserName(), client->editor->nameOfTests[i]);
        if (!answer)
            continue;
        std::vector<int>* marks = answer->marks;
        time_t usedTime = answer->usedTime;
        if (marks) {
            std::cout << client->editor->nameOfTests[i] << " (" << usedTime / 60 % 60 << "m " << usedTime % 60 << "s, " << sumOfMarks(marks) << "): ";
            printMarks(marks);
        }
    }
    int choice = 0;
    showAction();
    while (true) {
        std::cin >> choice;
        if (choice == Exit) {
            client->setAction(new AuthorizeAction);
            return;
        }
        if (choice == Return) {
            client->savedChoice = Nothing;
            client->returnAction();
            return;
        }
    }
}

void AdminAction::showAction() const {
    std::cout << "Admin window\n";
    std::cout << "Available actions:" << std::endl;
    std::cout << "--(" << Exit << ") Exit" << std::endl;
    std::cout << "--(" << StartTest << ") Start test" << std::endl;
    std::cout << "--(" << ViewMarks << ") View marks" << std::endl;
    std::cout << "--(" << AddSetTest << ") Create new test" << std::endl;
    std::cout << "--(" << EditSetTest << ") Edit test" << std::endl;
    std::cout << "--(" << DeleteSetTest << ") Delete test" << std::endl;
}

void AdminAction::execute() {
    showAction();
    int choice;
    std::cin >> choice;
    switch (choice) {
    case Exit:
        std::cout << "Exit\n";
        client->savedChoice = Nothing;
        client->setAction(new AuthorizeAction);
        return;
    case StartTest:
        std::cout << "StartTest\n";
        client->savedChoice = Nothing;
        client->setAction(new StartTestAction);
        return;
    case ViewMarks:
        std::cout << "ViewMarks\n";
        client->savedChoice = Nothing;
        client->setAction(new ViewAllMarksAction);
        return;
    case AddSetTest:
        std::cout << "AddSetTest\n";
        client->savedChoice = Nothing;
        client->setAction(new AddSetAction);
        return;
    case EditSetTest:
        client->savedChoice = Nothing;
        client->setAction(new EditSetAction);
        return;
    case DeleteSetTest:
        client->savedChoice = Nothing;
        client->setAction(new DeleteSetAction);
        return;
    }
}

void UserAction::showAction() const {
    std::cout << "Admin window\n";
    std::cout << "Available actions:" << std::endl;
    std::cout << "--(" << Exit << ") Exit" << std::endl;
    std::cout << "--(" << StartTest << ") Start test" << std::endl;
    std::cout << "--(" << ViewMarks << ") View marks" << std::endl;
}

void UserAction::execute() {
    showAction();
    int choice;
    std::cin >> choice;
    switch (choice) {
    case Exit:
        std::cout << "Exit\n";
        client->setAction(new AuthorizeAction);
        return;
    case StartTest:
        std::cout << "StartTest\n";
        client->setAction(new StartTestAction);
        return;
    case ViewMarks:
        std::cout << "ViewMarks\n";
        client->setAction(new ViewMyMarksAction);
        return;
    }
}