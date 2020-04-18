#include "Robot.h"

Robot::Robot()
{
}

Robot::Robot(string name, gender_t gender, time_b birth,
	string* hobby, string* likeFood, string* likeSport, string* oral,
	string dream, Person* lover,
	int hobbyNum, int likeFoodNum, int likeSportNum, int oralNum): 
	m_name(name), m_gender(gender), m_birth(birth),
	m_dream(dream), m_lover(*lover),
	m_hobbyNum(hobbyNum), m_likeFoodNum(likeFoodNum),
	m_likeSportNum(likeSportNum), m_oralNum(oralNum)
{

	for (int i = 0; i < hobbyNum; ++i) {
		m_hobby.push_back(hobby[i]);
	}
	
	for (int i = 0; i < likeFoodNum; ++i) {
		m_likeFood.push_back(likeFood[i]);
	}

	for (int i = 0; i < likeSportNum; ++i) {
		m_likeSport.push_back(likeSport[i]);
	}

	for (int i = 0; i < oralNum; ++i) {
		m_oral.push_back(oral[i]);
	}
}

Robot::~Robot()
{
}
