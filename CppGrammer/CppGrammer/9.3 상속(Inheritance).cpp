// 상속. 객체지향프로그램의 뼈대
// 부모가 가진 멤버 변수, 함수들을 자식이 별도 구현없이 상속으로 통해 재사용할 수 있게함
#include "docwriter.h"

void main() {
	DocWriter dw;
	dw.SetFileName("exam.txt"); // 
	dw.SetContent("시험 잘봄!");
	dw.Write(); // 메모리에 있던 것을 보조기억장치에 씀

}