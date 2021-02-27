#include "docwriter.h"
#include<fstream> // file System
using namespace std;

DocWriter::DocWriter() {
	_fileName = "NoName.txt";
	_content = "There is no content.";
}
// 객체 생성시 딱 한번
DocWriter::DocWriter(const string& fileName, const string& content) {
	_fileName = fileName;
	_content = content;
}
DocWriter::~DocWriter() {

}
// 안의 내용을 수시로 바꿀 수 있음
void DocWriter::SetFileName(const string& fileName) {
	_fileName = fileName;
}
void DocWriter::SetContent(const string& content) {
	_content = content;
}
void DocWriter::Write() {
	ofstream of(_fileName.c_str()); // File open
	// OutputFileSystem. c_str() : 문자열로 넘겨줄 때
	of << "# Content #\n\n";
	of << _content; // 실제 파일 쓰기 연산

}