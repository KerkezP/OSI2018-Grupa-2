#pragma once
#include<string>

enum class difficulty { hard, hard_plus };

struct Answer {
	std::string text;
	bool is_Correct = 0;
};

class Question {
	std::string text;
	Answer answer[4];
	difficulty mode;
	int chooseQuestion();
	int queNum;
public:
	static int counter;
	void draw(int);
	int answerIt();
	Question(difficulty);
	Question();
	~Question();
};

int game2(int, double);
