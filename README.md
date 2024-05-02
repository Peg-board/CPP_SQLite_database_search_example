# 2. 파티션 생성

<aside>
💡 윈도우 설치 중 파티션을 생성할 때 “새로 만들기”를 이용하면 파티션이 더럽게 생성된다.
명령어를 이용하여 깔끔하게 생성하자!

</aside>

# **`Main`**

```c
diskpart // diskpart 실행

list disk // 디스크 목록 보기

sel disk {해당 디스크 번호} // 설치할 디스크 선택

clean // 빠른 포맷

conv gpt // gpt 형식으로 변경

cre par efi size=100 // efi 파티션 생성
or 
cre par efi size=300 

format quick fs=fat32 //efi 파티션 fat32형식으로 포맷

cre par pri // 주 파티션 생성
or
create partition primary

format quick fs=ntfs // 주 파티션 ntfs형식으로 포맷

list par // 파티션 확인

exit // diskpart 종료

exit // cmd 종료

```


























# ㅁㄴㅇㅁㄴㅇㅁㄴㅇㅁㄴㅇㄴㅁㅇㅇ

'''asd
'''

![사진이름](사진링크)
줄바꿈 <br/>
