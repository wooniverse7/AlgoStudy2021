#include "docwriter.h"
#include<fstream> // file System
using namespace std;

DocWriter::DocWriter() {
	_fileName = "NoName.txt";
	_content = "There is no content.";
}
// ��ü ������ �� �ѹ�
DocWriter::DocWriter(const string& fileName, const string& content) {
	_fileName = fileName;
	_content = content;
}
DocWriter::~DocWriter() {

}
// ���� ������ ���÷� �ٲ� �� ����
void DocWriter::SetFileName(const string& fileName) {
	_fileName = fileName;
}
void DocWriter::SetContent(const string& content) {
	_content = content;
}
void DocWriter::Write() {
	ofstream of(_fileName.c_str()); // File open
	// OutputFileSystem. c_str() : ���ڿ��� �Ѱ��� ��
	of << "# Content #\n\n";
	of << _content; // ���� ���� ���� ����

}