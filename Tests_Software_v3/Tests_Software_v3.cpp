#include <iostream>
#include "Test.h"
#include "SingleChoiseTest.h"
#include "MultipleChoiseQuestion.h"
#include "MatchingQuestion.h"

int main()
{
    Test test;
	Question* question = new SingleChoiceTest("Who are you?");;
	//question->addAnswer('a', "Master", false);
	//question->addAnswer('b', "Slave", true);
	//test.editor.addTest("FirstTest", question);
	//question = new MultipleChoiseQuestion("Who is your master?");
	//question->addAnswer('a', "S...", true);
	//question->addAnswer('b', "Stik", true);
	//test.editor.addTest("FirstTest", question);
	//question = new SingleChoiceTest("Why are you slave?");;
	//question->addAnswer('a', "I`m student", true);
	//question->addAnswer('b', "It`s a kind of mistake", false);
	//test.editor.addTest("FirstTest", question);
	//for (int i = 0; i < 3; i++) {
	//	Question* q = test.editor.getTest("FirstTest", i);
	//	q->display();
	//}
}