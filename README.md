# TEST

$$
\huge {\textsf {SQLite를 C++에서 사용하는 방법}}
$$

```
제작취지
SQLite를 c++에서 사용하는 방법을 초등학교 5학년이 보고 따라 할 수 있도록 만들었다.
```

```
환경
OS: macOS Sonoma
IDE: Xcode version 15.3 (15E204a)
```

# SQLite 설치

1. brew를 이용하여 설치

```bash
brew install sqlite3
```

1. 확인

```
sqlite3 --version
```

## 사진

# 데이터베이스 생성

 다음 명령을 사용하여 `my.db`라는 이름의 데이터베이스를 만든다.

```sql
sqlite3 my.db
```

## 사진

# 테이블 생성

데이터베이스가 생성되면 다음 SQL 쿼리를 사용하여 `people`이라는 이름의 테이블을 만든다.

```sql
CREATE TABLE people ( /* 이름이 "people"인 테이블(릴레이션) 생성 */

    id INTEGER PRIMARY KEY AUTOINCREMENT, /* id속성을 기본키로 지정, 자동으로 증가하는 속성(열)로 직접 대입할 수 없음 */

    name TEXT NOT NULL, /*널값을 혀용하지 않음*/

    phone_number TEXT NOT NULL /*널값을 혀용하지 않음*/

);
```

```sql
.table /* 테이블 확인 */
```

## 사진

# 데이터 삽입

다음 SQL 쿼리를 사용하여 데이터를 `people` 테이블에 삽입한다.
