//
//  main.cpp
//  assignment
//
//  Created by 김성진 on 5/2/24.
//

#include <iostream>
#include <sqlite3.h>
#include <string>
using namespace std;

//점수를 저장할 구조체 s1
struct {
    int totalKor = 0;
    int totalMath = 0;
    int studentCount = 0;
}s1;

//callback(data, 갯수, char형 포인터 변수(C 스타일 문자열) 배열, char형 포인터 변수(C 스타일 문자열) 배열)
static int callback(void* data, int argc, char** argv, char** azColName) {
    int korScore = atoi(argv[2]);
    int mathScore = atoi(argv[3]);
    int sum = korScore + mathScore;
    double avg = sum / 2.0;
    
    cout << "학생 ID: " << argv[0] << ", 이름: " << argv[1] << endl;
    cout << "국어 점수: " << korScore << ", 수학 점수: " << mathScore;
    cout << "총점: " << sum << ", 평균: " << avg << endl << endl;
    
    s1.totalKor += korScore;
    s1.totalMath += mathScore;
    s1.studentCount++;
    
    return 0;
}

// 오류처리 함수
int error(char* message, sqlite3** db){
    cerr << message << sqlite3_errmsg(*db) << endl;
    sqlite3_close(*db); // 데이터베이스 연결을 끊고 자원 할당 해제
    return 1;
}

// 데이터베이스를 여는 함수
void is_open(sqlite3** db, const char* dbPath){
    int rc; // rc(return code): 작업의 성공여부를 나타냄
    
    // 데이터베이스 열기
    rc = sqlite3_open(dbPath, db);
    if(rc)
        error("데이터베이스 연결 실패: ", db);
    else
        cout << "데이터 베이스 열기 성공" << endl;
}

void exec_query(sqlite3* db, const char* query){
    int rc;
    char* error_message = nullptr;
    
    /*
     sqlite3_exec(sqlite3 *, const char* sql, int(*callback)(void*, int, char **, char**),
     void*, char** errmsg)
     */
    rc = sqlite3_exec(db, query, callback, 0, &error_message);
    
    if(rc != SQLITE_OK){
        cerr << "SQL error: " << error_message << endl;
        sqlite3_free(error_message);
    } else{
        cout << "성공적으로 쿼리가 실행되었습니다." << endl;
        cout << "국어 총점: " << s1.totalKor << ", 평균: " << (double)s1.totalKor / s1.studentCount << endl;
        cout << "수학 총점: " << s1.totalMath << ", 평균: " << (double)s1.totalMath / s1.studentCount << endl;
        
    }
        
        
}

int main() {
    sqlite3* db; // 데이터베이스 객체 포인터로, 핸들러이다.
    string dbPath = "/Users/seongjin/sqlite3/sj.db"; // 데이터베이스 경로
    const char* query = "SELECT * FROM grade"; // query문
    
    is_open(&db, dbPath.c_str()); // c.str(const char* 형태로 반환)

    exec_query(db, query);
    
    //데이터베이스를 닫는 함수
    sqlite3_close(db);
    
    return 0;
}
