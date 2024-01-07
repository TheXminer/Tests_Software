#include "StartTestAction.h"
//
//int* StartTestAction::randomizeNumbers(int size)
//{
//    int* array = new int[size];
//    for (int i = 0; i < size; i++) {
//        array[i] = i;
//    }
//    return array;
//}
//
//std::vector<int>* StartTestAction::transformOrder(std::vector<int>* currentMarks, int* key)
//{
//    return currentMarks;
//}
//
//void StartTestAction::startTest(std::string testName)
//{
//    std::vector<Question*>* tests = client->editor->getSetOfTests(testName);
//    int size = tests->size();
//    int* numbersOrder = randomizeNumbers(size);
//    std::vector<int>* currentMarks = new std::vector<int>;
//    time_t start, end;
//    time(&start);
//    if (client->studentAnswers->isTestPassed(client->getUserName(), testName)) {
//        std::cout << "Test already passed :)" << std::endl;
//        return;
//    }
//    for (int i = 0; i < size; i++) {
//        std::cout << i + 1 << ". ";
//        tests->at(numbersOrder[i])->display();
//        int mark = tests->at(numbersOrder[i])->checkEnterQuestion();
//        //if (answer == Exit) {
//        //	user->Exit();
//        //	return;
//        //}
//        //if (tests->at(*numbersOrder)->checkAnswer(&answer))
//        //	currentMarks.push_back(1);
//        //else currentMarks.push_back(0);
//        currentMarks->push_back(mark);
//    }
//    time(&end);
//    studentAnswerData* answers = new studentAnswerData(end - start, transformOrder(currentMarks, numbersOrder));
//    client->studentAnswers->addStudentAnswer(client->getUserName(), testName, answers);
//    delete numbersOrder;
//}
