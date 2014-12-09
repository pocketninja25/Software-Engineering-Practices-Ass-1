//#include <iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	virtual void WriteMessage() = 0;
//
//};
//
//class CMessage1:public CTest
//{
//public:
//	void WriteMessage();
//
//};
//
//void CMessage1::WriteMessage()
//{
//	cout << "Message from 1" << endl;
//}
//
//class CMessage2:public CTest{
//public:
//	void WriteMessage();
//
//};
//
//void CMessage2::WriteMessage()
//{
//	cout << "Message from 2" << endl;
//}
//
//
//int main()
//{
//	CTest* pMessages[4];
//	pMessages[0] = new CMessage1;
//	pMessages[1] = new CMessage2;
//	pMessages[2] = new CMessage1;
//	pMessages[3] = new CMessage2;
//
//
//	for (int i = 0; i < 4; i++)
//	{
//		pMessages[i]->WriteMessage();
//	}
//	
//
//
//
//	system("pause");
//	return 0;
//}