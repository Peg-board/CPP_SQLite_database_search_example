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

// 점수를 저장할 구조체 s1
struct {
    int totalKor = 0;
    int totalMath = 0;
    int studentCount = 0;
}s1;

// 카디널리티 만큼 자동 반복
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


int error(char* message, sqlite3** db){
    cerr << message << sqlite3_errmsg(*db) << endl;
    sqlite3_close(*db);
    return 1;
}


void is_open(sqlite3** db, const char* dbPath){
    int rc;
    
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
    sqlite3* db;
    string dbPath = "/Users/seongjin/sqlite3/sj.db";
    const char* query = "SELECT * FROM grade";
    
    is_open(&db, dbPath.c_str());
    exec_query(db, query);
    sqlite3_close(db);
    
    return 0;
}
